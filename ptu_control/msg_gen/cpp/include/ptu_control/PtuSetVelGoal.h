/* Auto-generated by genmsg_cpp for file /home/floribot/ros_workspace/ptu_control/msg/PtuSetVelGoal.msg */
#ifndef PTU_CONTROL_MESSAGE_PTUSETVELGOAL_H
#define PTU_CONTROL_MESSAGE_PTUSETVELGOAL_H
#include <string>
#include <vector>
#include <map>
#include <ostream>
#include "ros/serialization.h"
#include "ros/builtin_message_traits.h"
#include "ros/message_operations.h"
#include "ros/time.h"

#include "ros/macros.h"

#include "ros/assert.h"


namespace ptu_control
{
template <class ContainerAllocator>
struct PtuSetVelGoal_ {
  typedef PtuSetVelGoal_<ContainerAllocator> Type;

  PtuSetVelGoal_()
  : pan_vel(0.0)
  , tilt_vel(0.0)
  {
  }

  PtuSetVelGoal_(const ContainerAllocator& _alloc)
  : pan_vel(0.0)
  , tilt_vel(0.0)
  {
  }

  typedef float _pan_vel_type;
  float pan_vel;

  typedef float _tilt_vel_type;
  float tilt_vel;


  typedef boost::shared_ptr< ::ptu_control::PtuSetVelGoal_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ptu_control::PtuSetVelGoal_<ContainerAllocator>  const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;
}; // struct PtuSetVelGoal
typedef  ::ptu_control::PtuSetVelGoal_<std::allocator<void> > PtuSetVelGoal;

typedef boost::shared_ptr< ::ptu_control::PtuSetVelGoal> PtuSetVelGoalPtr;
typedef boost::shared_ptr< ::ptu_control::PtuSetVelGoal const> PtuSetVelGoalConstPtr;


template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const  ::ptu_control::PtuSetVelGoal_<ContainerAllocator> & v)
{
  ros::message_operations::Printer< ::ptu_control::PtuSetVelGoal_<ContainerAllocator> >::stream(s, "", v);
  return s;}

} // namespace ptu_control

namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::ptu_control::PtuSetVelGoal_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::ptu_control::PtuSetVelGoal_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::ptu_control::PtuSetVelGoal_<ContainerAllocator> > {
  static const char* value() 
  {
    return "b7cd6f56e9f8de7ca60102f67cb2581f";
  }

  static const char* value(const  ::ptu_control::PtuSetVelGoal_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0xb7cd6f56e9f8de7cULL;
  static const uint64_t static_value2 = 0xa60102f67cb2581fULL;
};

template<class ContainerAllocator>
struct DataType< ::ptu_control::PtuSetVelGoal_<ContainerAllocator> > {
  static const char* value() 
  {
    return "ptu_control/PtuSetVelGoal";
  }

  static const char* value(const  ::ptu_control::PtuSetVelGoal_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::ptu_control::PtuSetVelGoal_<ContainerAllocator> > {
  static const char* value() 
  {
    return "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n\
# goal\n\
float32 pan_vel\n\
float32 tilt_vel\n\
\n\
";
  }

  static const char* value(const  ::ptu_control::PtuSetVelGoal_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator> struct IsFixedSize< ::ptu_control::PtuSetVelGoal_<ContainerAllocator> > : public TrueType {};
} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::ptu_control::PtuSetVelGoal_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.pan_vel);
    stream.next(m.tilt_vel);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct PtuSetVelGoal_
} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ptu_control::PtuSetVelGoal_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const  ::ptu_control::PtuSetVelGoal_<ContainerAllocator> & v) 
  {
    s << indent << "pan_vel: ";
    Printer<float>::stream(s, indent + "  ", v.pan_vel);
    s << indent << "tilt_vel: ";
    Printer<float>::stream(s, indent + "  ", v.tilt_vel);
  }
};


} // namespace message_operations
} // namespace ros

#endif // PTU_CONTROL_MESSAGE_PTUSETVELGOAL_H
