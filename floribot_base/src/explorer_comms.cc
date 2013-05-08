
/*
 *  Player - One Hell of a Robot Server
 *  Copyright (C) 2007 - CoroWare Technologies Inc
 *
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <termios.h>
#include <fcntl.h>
#include <unistd.h>
#include <math.h>

#include "explorer_comms.h"

explorer_comm_t *explorer_comm_create(const char *serialPort)
{
    explorer_comm_t *r;

    r = (explorer_comm_t *) calloc(1, sizeof(explorer_comm_t));
    assert(r);
    r->fd = -1;
    strncpy(r->serialPort, serialPort, sizeof(r->serialPort) - 1);
    return (r);
}

void explorer_comm_destroy(explorer_comm_t * r)
{
    free(r);
}

int explorer_comm_open(explorer_comm_t * r)
{
    struct termios term;
    int flags;

    if (r->fd >= 0)
    {
        puts("explorer connection already open!");
        return -1;
    }

    // Open it.  non-blocking at first, in case there's no explorer
    if ((r->fd = open(r->serialPort,
                      O_RDWR | O_NONBLOCK, S_IRUSR | S_IWUSR)) < 0)
    {
        perror("explorer_comm_open():open():");
        return -1;
    }

    if (tcflush(r->fd, TCIFLUSH) < 0)
    {
        perror("explorer_comm_open():tcflush():");
        close(r->fd);
        r->fd = -1;
        return -1;
    }
    if (tcgetattr(r->fd, &term) < 0)
    {
        perror("explorer_comm_open():tcgetattr():");
        close(r->fd);
        r->fd = -1;
        return -1;
    }

    cfmakeraw(&term);
    cfsetispeed(&term, B115200);
    cfsetospeed(&term, B115200);

    if (tcsetattr(r->fd, TCSAFLUSH, &term) < 0)
    {
        perror("explorer_open():tcsetattr():");
        close(r->fd);
        r->fd = -1;
        return -1;
    }

    if (explorer_comm_init(r) < 0)
    {
        puts("failed to initialize connection");
        close(r->fd);
        r->fd = -1;
        return -1;
    }

    /* We know the robot is there; switch to blocking */
    /* ok, we got data, so now set NONBLOCK, and continue */
    if ((flags = fcntl(r->fd, F_GETFL)) < 0)
    {
        perror("explorer_comm_open():fcntl():");
        close(r->fd);
        r->fd = -1;
        return -1;
    }
    if (fcntl(r->fd, F_SETFL, flags ^ O_NONBLOCK) < 0)
    {
        perror("explorer_comm_open():fcntl()");
        close(r->fd);
        r->fd = -1;
        return -1;
    }

    puts("Explorer Servo controller opened successfully.");

    return 0;
}

static int setServo(explorer_comm_t * r, const int which, const int value)
{
    char buffer[32];

    /* validate our arguments */
    if ((which < 0) || (which >= 32))
    {
        return -1;
    }
    if ((value < 500) || (value > 2500))
    {
        return -1;
    }
    if (r == 0)
    {
        return -1;
    }
    if (r->fd > 0)
    {
        sprintf(buffer, "#%dP%d\r", which, value);
        write(r->fd, buffer, strlen(buffer));
        //printf("#%dP%d\n", which, value);
    }
    return 0;
}

int explorer_comm_init(explorer_comm_t * r)
{
    if ((setServo(r, 0, DRIVEMOTOR_CENTER) == -1) ||
        (setServo(r, 1, DRIVEMOTOR_CENTER) == -1))
    {
        return -1;
    }
    return 0;
}

int explorer_comm_close(explorer_comm_t * r)
{
    //unsigned char cmdbuf[1];

    explorer_comm_set_speeds(r, 0.0, 0.0);

    if (close(r->fd) < 0)
    {
        perror("explorer_comm_close():close():");
        return -1;
    }
    else
        return 0;
}

int explorer_comm_set_theta(explorer_comm_t * r, const unsigned int which, 
			   const double theta)
{
  int amount;
  if ((which == 4) || (which == 5))
    { // shoulder and elbow
      amount =  (int) (theta / M_PI * DIGITALARMSERVO_RANGE) + 
	DIGITALARMSERVO_CENTER - DIGITALARMSERVO_RANGE / 2;
    }
  else if (which == 7)
    {
      amount =  (int) (theta / M_PI * GRIPPERSERVO_RANGE) + 
	GRIPPERSERVO_CENTER - GRIPPERSERVO_RANGE / 2;
    }
  else {
    // assume analog servo
    amount = (int) (theta / M_PI * ANALOGARMSERVO_RANGE) + 
      ANALOGARMSERVO_CENTER - ANALOGARMSERVO_RANGE / 2;    
  }
    setServo(r, which, amount);
    return 0;
}

int explorer_comm_set_speeds(explorer_comm_t * r, const double tv, const double rv)
{
    double radTheta;
    double left;
    double right;

    radTheta = atan2(-rv,tv);

    if (tv > 0.0)
    {
        if (rv > 0.0)
        {
            /* quadrant I */
            left = (tv * cos(radTheta) + rv * sin(radTheta));
            right = (tv * cos(radTheta) - rv * sin(radTheta));
        }
        else
        {
            /* quadrant II */
            left = (tv * cos(radTheta) - rv * sin(radTheta));
            right = (tv * cos(radTheta) + rv * sin(radTheta));
        }
    }
    else
    {
        if (rv > 0.0)
        {
            /* quadrant IV */
            left = -(tv * cos(radTheta) - rv * sin(radTheta));
            right = -(tv * cos(radTheta) + rv * sin(radTheta));
        }
        else
        {
            /* quadrant III */
            left = -(tv * cos(radTheta) + rv * sin(radTheta));
            right = -(tv * cos(radTheta) - rv * sin(radTheta));
        }
    }

    if (left > 1.0)
    {
        left = 1.0;
    }
    if (left < -1.0)
    {
        left = -1.0;
    }
    if (right > 1.0)
    {
        right = 1.0;
    }
    if (right < -1.0)
    {
        right = -1.0;
    }

    // low numbers mean to drive forward
    setServo(r, 0, DRIVEMOTOR_CENTER - DRIVEMOTOR_RANGE * left);
    setServo(r, 1, DRIVEMOTOR_CENTER - DRIVEMOTOR_RANGE * right);

    return 0;
}
