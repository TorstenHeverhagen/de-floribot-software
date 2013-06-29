/* Auto-generated by genmsg_cpp for file /home/floribot/ros_workspace/phidgets/msg/phsensor_params.msg */
#ifndef PHIDGETS_MESSAGE_PHSENSOR_PARAMS_H
#define PHIDGETS_MESSAGE_PHSENSOR_PARAMS_H
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

#include "std_msgs/Header.h"

namespace phidgets
{
template <class ContainerAllocator>
struct phsensor_params_ {
  typedef phsensor_params_<ContainerAllocator> Type;

  phsensor_params_()
  : header()
  , value(0.0)
  , potential(0.0)
  {
  }

  phsensor_params_(const ContainerAllocator& _alloc)
  : header(_alloc)
  , value(0.0)
  , potential(0.0)
  {
  }

  typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
   ::std_msgs::Header_<ContainerAllocator>  header;

  typedef float _value_type;
  float value;

  typedef float _potential_type;
  float potential;


  typedef boost::shared_ptr< ::phidgets::phsensor_params_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::phidgets::phsensor_params_<ContainerAllocator>  const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;
}; // struct phsensor_params
typedef  ::phidgets::phsensor_params_<std::allocator<void> > phsensor_params;

typedef boost::shared_ptr< ::phidgets::phsensor_params> phsensor_paramsPtr;
typedef boost::shared_ptr< ::phidgets::phsensor_params const> phsensor_paramsConstPtr;


template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const  ::phidgets::phsensor_params_<ContainerAllocator> & v)
{
  ros::message_operations::Printer< ::phidgets::phsensor_params_<ContainerAllocator> >::stream(s, "", v);
  return s;}

} // namespace phidgets

namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::phidgets::phsensor_params_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::phidgets::phsensor_params_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::phidgets::phsensor_params_<ContainerAllocator> > {
  static const char* value() 
  {
    return "446c7325052f4b06c5d23c921a285e1e";
  }

  static const char* value(const  ::phidgets::phsensor_params_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0x446c7325052f4b06ULL;
  static const uint64_t static_value2 = 0xc5d23c921a285e1eULL;
};

template<class ContainerAllocator>
struct DataType< ::phidgets::phsensor_params_<ContainerAllocator> > {
  static const char* value() 
  {
    return "phidgets/phsensor_params";
  }

  static const char* value(const  ::phidgets::phsensor_params_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::phidgets::phsensor_params_<ContainerAllocator> > {
  static const char* value() 
  {
    return "Header header\n\
float32 value\n\
float32 potential\n\
\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.secs: seconds (stamp_secs) since epoch\n\
# * stamp.nsecs: nanoseconds since stamp_secs\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
\n\
";
  }

  static const char* value(const  ::phidgets::phsensor_params_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator> struct HasHeader< ::phidgets::phsensor_params_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct HasHeader< const ::phidgets::phsensor_params_<ContainerAllocator> > : public TrueType {};
} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::phidgets::phsensor_params_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.header);
    stream.next(m.value);
    stream.next(m.potential);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct phsensor_params_
} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::phidgets::phsensor_params_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const  ::phidgets::phsensor_params_<ContainerAllocator> & v) 
  {
    s << indent << "header: ";
s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "value: ";
    Printer<float>::stream(s, indent + "  ", v.value);
    s << indent << "potential: ";
    Printer<float>::stream(s, indent + "  ", v.potential);
  }
};


} // namespace message_operations
} // namespace ros

#endif // PHIDGETS_MESSAGE_PHSENSOR_PARAMS_H

