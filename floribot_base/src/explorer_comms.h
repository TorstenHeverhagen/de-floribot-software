/*
 *  Player - One Hell of a Robot Server
 *  Copyright (C) 2010 - CoroWare Technologies Inc
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

#ifndef EXPLORER_COMMS_H
#define EXPLORER_COMMS_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <limits.h>

  /** approximate diameter of the robot (assumed as circle) **/
#define EXPLORER_DIAMETER 0.30

  /** the pulse width considered to be STOP by the servo **/
#define ANALOGARMSERVO_CENTER	1500
  /** the range of the pulse with acceptable, 
      centered at ANALOGARMSERVO_CENTER **/
#define ANALOGARMSERVO_RANGE	2000

  /** the pulse width considered to be STOP by the gripper servo **/
#define GRIPPERSERVO_CENTER	1500
  /** the range of the pulse with acceptable, 
      centered at GRIPPERSERVO_CENTER **/
#define GRIPPERSERVO_RANGE	1000

  /** the pulse width considered to be STOP by the servo **/
#define DIGITALARMSERVO_CENTER	1500
  /** the range of the pulse with acceptable, 
      centered at DIGITALARMSERVO_CENTER **/
#define DIGITALARMSERVO_RANGE	1500

  /** the pulse width considered to be STOP by the base **/
#define DRIVEMOTOR_CENTER	1466
  /** the range of the pulse with acceptable, centered at DRIVEMOTOR_CENTER **/
#define DRIVEMOTOR_RANGE	1000

  /** your standard MIN macro **/
#ifndef MIN
#define MIN(a,b) ((a < b) ? (a) : (b))
#endif

  /** your standard MAX macro **/
#ifndef MAX
#define MAX(a,b) ((a > b) ? (a) : (b))
#endif

/** PATH_MAX macro **/
#ifndef PATH_MAX
#define PATH_MAX 20
#endif

  /** Structure that summarizes all the information needed to communicate 
   * with the serial port and the SSC32 on the other side.
   **/
  typedef struct
  {
    /* Serial port to which the robot is connected */
    char serialPort[PATH_MAX];
    /* File descriptor associated with serial connection (-1 if no valid connection) */
    int fd;
    /* Integrated odometric position [m m rad] */
    double ox, oy, oa;
    
    /* Volts */
    double voltage;
  } explorer_comm_t;
  
  /**
   * @brief creates and initializes a serial port structure
   * @param serial_port string indicating the serial port to open ("/dev/ttyS0")
   * @return pointer to a serial port structure
   **/
  explorer_comm_t *explorer_comm_create(const char *serial_port);

  /**
   * @brief destroys an existing serial port struct
   * @param r the serial port structure to destroy
   **/
  void explorer_comm_destroy(explorer_comm_t * r);

  /**
   * @brief opens an already-created serial port struct
   * @param r the serial port structure indicating the serial port to open
   * @return 0 on success, -1 on error
   **/
  int explorer_comm_open(explorer_comm_t * r);

  /**
   * @brief initializes the SSC32 on the other side of the serial port, setting
   * the left and right motor channels to STOP.
   * @param r the serial port to communicate through
   * @return 0 on success, -1 on error
   **/
  int explorer_comm_init(explorer_comm_t * r);

  /**
   * @brief closes an already-open serial port
   * @param r the serial port to close
   * @return 0 on success, -1 on error
   **/
  int explorer_comm_close(explorer_comm_t * r);

  /**
   * @brief sets the speeds of the left and right channels on the robot
   * @param r the serial port over which to talk to the SSC32 controller
   * @param tv desired translational velocity (between -1.0 and +1.0)
   * @param rv desired rotational power (between -1.0 and +1.0)
   * @return 0 on success, -1 on error
   **/
  int explorer_comm_set_speeds(explorer_comm_t * r, const double tv, const double rv);

  /**
   * @brief sets a joint angle on a servo
   * @param r the serial port  over which to talk to the SSC32 controller
   * @param which the servo to set (4,5,6,7 are shoulder, elbow, wrist, and 
   * gripper respectively)
   * @param theta the desired target angle (0..PI)
   * @return 0 on success, -1 on error
   **/
  int explorer_comm_set_theta(explorer_comm_t* r, const unsigned int which, 
			     const double theta);
  
#ifdef __cplusplus
}
#endif

#endif
