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
        self.CSSERIAL = threading.Lock()
        self.FKP = FIX_KINETIC_PARAMS()

        if not fakerun:
            self.initServos()
        
        #self.initSubscriber()


    ##################################################
    # KINEMATIC COMPUTE PART                         #
    ##################################################

    def computePhi(self, velX, velY, velTheta):

        phi1=-(m.cos(self.FKP.beta1 + self.FKP.alpha1) * velY
                - m.sin(self.FKP.beta1 + self.FKP.alpha1) * velX + m.cos(self.FKP.beta1)
                * self.FKP.ROBOT_DXY * velTheta) / self.FKP.WHEEL_RADIAN

        phi2=-(m.cos(self.FKP.beta2 + self.FKP.alpha2) * velY
                - m.sin(self.FKP.beta2 + self.FKP.alpha2) * velX + m.cos(self.FKP.beta2)
                * self.FKP.ROBOT_DXY * velTheta) / self.FKP.WHEEL_RADIAN

        phi3=-(m.cos(self.FKP.beta3 + self.FKP.alpha3) * velY
                - m.sin(self.FKP.beta3 + self.FKP.alpha3) * velX + m.cos(self.FKP.beta3)
                * self.FKP.ROBOT_DXY * velTheta) / self.FKP.WHEEL_RADIAN

        phi4=-(m.cos(self.FKP.beta4 + self.FKP.alpha4) * velY
                - m.sin(self.FKP.beta4 + self.FKP.alpha4) * velX + m.cos(self.FKP.beta4)
                * self.FKP.ROBOT_DXY * velTheta) / self.FKP.WHEEL_RADIAN

        return phi1, phi2, phi3, phi4


    ##################################################
    # KINEMATIC VALUE PREPARATION FOR SERVO          #
    ##################################################

    def norm_wheel_vel(self, vel):
        """
        norm_wheel_vel(self, list or tuple of float) -> list of float
        """
        return [item / self.FKP.WHEEL_VELOCITY_MAX for item in vel]

    def checkNormOverMax(self, norm_vel):
        for item in  norm_vel:
            if -1 < item > 1:
                return True
        else:
            return False

    def computeWheelFrequency(self, norm_vel):
        """
        computeWheelFrequency(self, list or tuple of float) -> list of float
        """
        # Todo: consider if floor in detail 'cast' to int is ok from logic side.
        # thinking int(float) should be faster than math.floor or math.round
        return [int(item * self.FKP.WHEEL_SERVO_RANGE + self.FKP.WHEEL_SERVO_FREQ_MID) for item in norm_vel]

    ##################################################
    # SERVO PART                                     #
    ##################################################

    def initServos(self, servoCntPort=None):
        if servoCntPort is None:
            servoCntPort = self.FKP.WHEEL_SERVO_CNT_PORT

        #print servoCntPort

        serTmp = serial.Serial(port=servoCntPort, baudrate=115200, timeout=2)

        self.CSSERIAL.acquire()
        #nop, self.serialServoCnt, nop = select([],[serTmp],[])
        self.serialServoCnt = serTmp
        #print self.serialServoCnt
        self.CSSERIAL.release()

    def getServoCmd(self, channel, freq):
        return self.SERVO_CMD_STR % (channel, freq)

    def setServoCmd(self, cmd):
        
        #print 'entering setServoCmd'
        
        self.CSSERIAL.acquire()
        
        #print 'entered critical section'

        try:
            #print 'trying to write to serial'
            self.serialServoCnt.write(cmd)
        except:
            print 'ERROR WRITING TO SERVO!'

        #print 'leave critical section'

        self.CSSERIAL.release()
        
        #print 'function setServoCmd end..'

    def newCmd(self, vx, vy, vtheta):
        #print 'enter newCmd'
        phis = self.computePhi(vx, vy, vtheta)
        
        print phis
        
        norm_phis = self.norm_wheel_vel(phis)
        
        
        if self.checkNormOverMax(norm_phis):
            return

        freq = self.computeWheelFrequency(norm_phis)
        
        scmd = self.getServoCmd(self.FKP.WHEEL_SERVO_CHANNEL_LEFT ,freq[1]) + ' ' + self.getServoCmd(self.FKP.WHEEL_SERVO_CHANNEL_RIGHT ,freq[2])
        print scmd.encode('string-escape')
        
        self.setServoCmd(scmd)

    ##################################################
    # ROS SUBSCRIBER STUFF AND BRIDGE TO SERVO CMD   #
    ##################################################

    def initSubscriber(self):
        #topic-cmd-type: geometry_msgs.msg.Twist (imported as geoMsg[.Twist])
        rospy.init_node(self.NODENAME)
        rospy.Subscriber(self.SUBSCIBE_TOPIC, geoMsg.Twist, self.cmdVelCallback)

    def compareTwist(self, twist1, twist2):
        if twist1 is None and twist2 is None:
            return True
        
        if twist1 is None:
            return False
            
        if twist2 is None:
            return False
            
        return  ((twist1.linear.x == twist1.linear.x) and
                 (twist1.linear.y == twist1.linear.y) and
                 (twist1.linear.z == twist1.linear.z) and
                 (twist1.angular.x == twist1.angular.x) and
                 (twist1.angular.y == twist1.angular.y) and
                 (twist1.angular.z == twist1.angular.z))

    def cmdVelCallback(self, twist):
        #FIXME: CALL from cmdVelCallback(self, twist) to newCmd(self, vx, vy, vtheta)
        from pprint import pprint
        #pprint(dir(twist))
        #print twist.linear.x, twist.linear.y, twist.angular.z
        #if self.oldTwist is not None:
            #print self.oldTwist.linear.x , twist.linear.x
        if not self.compareTwist(twist, self.oldTwist) or True:
            #print 'new cmd!'
            self.oldTwist = twist
            self.newCmd(twist.linear.x, twist.linear.y, twist.angular.z)


if __name__ == '__main__':
    cvc = CmdVelController()
    #cvc.newCmd(0.25,0,m.pi*1.5)
    cvc.initSubscriber()
    rospy.spin()
    

