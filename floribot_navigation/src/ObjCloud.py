'''
Created on 15.03.2013
@author: Jens Seifried
for : Floribot ROS_Stage/Real
Description: Script to find Objekts in Laserscan 
             and publish their cartesian coordinates
'''
#!/usr/bin/env python
import roslib; 
import rospy
import math
import string
from sensor_msgs.msg import LaserScan
from sensor_msgs.msg import PointCloud
from geometry_msgs.msg import Point32
from sensor_msgs.msg import ChannelFloat32


def listener():
    rospy.Subscriber("scan", LaserScan, callback)
    rospy.spin()  
      
def callback(data):
    #Variablen
    message1 = PointCloud()
    channel = ChannelFloat32()
    channel.values = [] 
    #Suchparameter    
    search_Range = 4.0
    radius = 0.05
    #Schleifen-Startbedingung
    i_os = i_oe =1
    i=1
    while i < len(data.ranges):
        if data.ranges[i] <= search_Range:
            if abs(data.ranges[i]-data.ranges[i-1])< radius:
                point = Point32()
                i_os = i_oe = i
                count = 1
                stop = 0
                while abs(data.ranges[i_oe]-data.ranges[i_oe-1])< radius and stop == 0:
                    count +=1
                    if i_oe < len(data.ranges)-1: i_oe+=1
                    if i_oe == len(data.ranges)-1: stop = 1
                    
                i = i_oe
                count /=2
                if i_os+count < len(data.ranges):
                    angle = data.angle_min+(i_os+count)*data.angle_increment
                    point.x = math.cos(angle)*data.ranges[i_os+count]#-radius
                    point.y = math.sin(angle)*data.ranges[i_os+count]#-radius
                    point.z = 0
                if i_os+count > len(data.ranges):
                    angle = data.angle_min+(len(data.ranges)-1)*data.angle_increment
                    point.x = math.cos(angle)*data.ranges[len(data.ranges)-1]#-radius
                    point.y = math.sin(angle)*data.ranges[len(data.ranges)-1]#-radius
                    point.z = 0                
                channel.values.append(math.degrees(angle))    
                message1.points.append(point)
        i+=1
     
    message1.header.seq = data.header.seq
    message1.header.stamp = data.header.stamp
    message1.header.frame_id = data.header.frame_id
    channel.name = "angle in degrees"
    message1.channels.append(channel) 
    
    #print message1
    #print len(message1.points)
    #print '#######################################################' 
    talker(message1)   

def talker(send):
    p = rospy.Publisher('ObjCloud', PointCloud)
    p.publish(send)       
    
    
if __name__ == '__main__':
    rospy.init_node('ObjektCloud', anonymous=True)
    listener()
    #print message
    