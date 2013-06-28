#! /usr/bin/env python
# -*- coding: utf-8 -*-
#
# Author: Björn Eistel
# Contact: <eistel@gmail.com>


# Python
import math as m
import serial
from select import select
import threading

# Project
from FixKineticParams import FIX_KINETIC_PARAMS

# ROS
import rospy
from geometry_msgs import msg as geoMsg




class CmdVelController(object):
    NODENAME = 'CmdVelController'
    SUBSCIBE_TOPIC = 'cmd_vel'

    CSSERIAL = None
    SERVO_CMD_STR = '#%d P%d\r'
    FKP = None

    oldTwist = None

    def __init__(self, fakerun=False):
        self.FKP = FIX_KINETIC_PARAMS()

        if not fakerun:
            self.initServos()

            #self.initSubscriber()



    ##################################################
    # KINEMATIC VALUE PREPARATION FOR SERVO          #
    ##################################################


    def computeWheelFrequency(self, v, theta):
        """
        computeWheelFrequency(self, list or tuple of float) -> list of float
        """
       
        print v,theta
        #theta*=1.7
        dx = 0.2005
        dy = 0.19
        dxy = m.sqrt(dx*dx+dy*dy)
        wheel_radian = 0.095

        dvt = theta * dxy
        dv = dvt / m.cos(m.atan2(dx,dy))

        vl = vr = v

        vl += dv *-1
        vr += dv


        vl /= wheel_radian
        vr /= wheel_radian

        #frql = vl / ((8.655--6.555) / (1000 - 1850)) + 1472  # 101902 -> left
        #frqr = vr / ((-8.018-6.412) / (1000 - 1850)) + 1484  # 102191 -> right

        frql = vl *  ( (1000 - 1850)/(8.655--6.555)) + 1484
        frqr = vr *  ( (1000 - 1850) / (8.018 -- 6.412)) + 1473


        print frql,frqr

        return [frql,frqr]

    ##################################################
    # SERVO PART                                     #
    ##################################################

    def initServos(self, servoCntPort=None):
        if servoCntPort is None:
            servoCntPort = self.FKP.WHEEL_SERVO_CNT_PORT

        serTmp = serial.Serial(port=servoCntPort, baudrate=115200, timeout=2)

        self.serialServoCnt = serTmp


    def getServoCmd(self, channel, freq):
        return self.SERVO_CMD_STR % (channel, freq)

    def setServoCmd(self, cmd):
        try:
            self.serialServoCnt.write(cmd)
        except:
            print 'ERROR WRITING TO SERVO!'


    def newCmd(self, v, theta):

        freq = self.computeWheelFrequency(v, theta)
        scmd = self.getServoCmd(0 ,int(freq[0])) + ' ' + self.getServoCmd(1 ,int(freq[1]))
        print scmd.encode('string-escape')

        self.setServoCmd(scmd)

    ##################################################
    # ROS SUBSCRIBER STUFF AND BRIDGE TO SERVO CMD   #
    ##################################################

    def initSubscriber(self):
        #topic-cmd-type: geometry_msgs.msg.Twist (imported as geoMsg[.Twist])
        rospy.init_node(self.NODENAME)
        rospy.Subscriber(self.SUBSCIBE_TOPIC, geoMsg.Twist, self.cmdVelCallback)


    def cmdVelCallback(self, twist):
        self.newCmd(twist.linear.x, twist.angular.z)


if __name__ == '__main__':
    cvc = CmdVelController(fakerun=False)
    #cvc.newCmd(0.25,0,m.pi*1.5)
    cvc.initSubscriber()
    rospy.spin()


