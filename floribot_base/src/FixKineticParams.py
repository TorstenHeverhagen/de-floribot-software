#! /usr/bin/env python
# -*- coding: utf-8 -*-
#
# Author: Björn Eistel
# Contact: <eistel@gmail.com>

class FIX_KINETIC_PARAMS(object):
    _COMPUTED = False
    _CACHE_FILE = 'fix_kinetic_params.pyser'

    ROBOT_DX = 0.2
    ROBOT_DY = 0.15
    ROBOT_DXY = None



    WHEEL_RADIAN = 0.095
    WHEEL_VELOCITY_MAX = 9.0

    WHEEL_SERVO_CNT_PORT = '/dev/ttyS1'
    WHEEL_SERVO_CHANNEL_LEFT = 0
    WHEEL_SERVO_CHANNEL_RIGHT = 1

    WHEEL_SERVO_FREQ_MID = 1466.0 # pulse duty factor
    WHEEL_SERVO_RANGE = -500.0
    WHEEL_SERVO_FREQ_MIN = None
    WHEEL_SERVO_FREQ_MAX = None

    alpha1 = None
    alpha2 = None
    alpha3 = None
    alpha4 = None

    beta1 = None
    beta2 = None
    beta3 = None
    beta4 = None

    phi1 = None
    phi2 = None
    phi3 = None
    phi4 = None

    def __init__(self, filename=None, autosave=True):
        if filename is not None:
            self._CACHE_FILE = filename

        self.loadFile()
        self.computeConstants()
        if autosave:
            self.saveFile()

    def loadFile(self, filename=None):
        if filename is None:
            filename = self._CACHE_FILE

        import cPickle

        try:
            fh = open(filename, 'rb')
            tmp_dict = cPickle.load(fh)
            fh.close()

            self.__dict__.update(tmp_dict)
            return True
        except IOError:
            return False

    def saveFile(self, filename=None):
        if filename is None:
            filename = self._CACHE_FILE

        import cPickle

        try:
            fh = open(filename,'wb')
            cPickle.dump(self.__dict__, fh, 2)
            fh.close()
            return True
        except IOError:
            return False

    def computeConstants(self, force=False):
        if not self._COMPUTED or force:

            import math as m

            # WHEEL SERVO

            self.WHEEL_SERVO_FREQ_MIN = self.WHEEL_SERVO_FREQ_MID - self.WHEEL_SERVO_RANGE
            self.WHEEL_SERVO_FREQ_MAX = self.WHEEL_SERVO_FREQ_MID + self.WHEEL_SERVO_RANGE

            # Mathematical operations from Benedict Bauer
            self.ROBOT_DXY = m.sqrt(self.ROBOT_DX * self.ROBOT_DX + self.ROBOT_DY * self.ROBOT_DY)

            self.alpha1 = m.atan(self.ROBOT_DY/self.ROBOT_DX)
            self.alpha2 = m.pi/2.0 + m.atan(self.ROBOT_DX/self.ROBOT_DY)
            self.alpha3 = -m.pi/2.0 - m.atan(self.ROBOT_DX/self.ROBOT_DY)
            self.alpha4 = -m.atan(self.ROBOT_DY/self.ROBOT_DX)

            self.beta1 = m.atan(self.ROBOT_DX/self.ROBOT_DY)
            self.beta2 = -m.atan(self.ROBOT_DX/self.ROBOT_DY)
            self.beta3 = -m.pi/2.0-m.atan(self.ROBOT_DY/self.ROBOT_DX)
            self.beta4 = m.pi/2.0+m.atan(self.ROBOT_DY/self.ROBOT_DX)

            self._COMPUTED = True
