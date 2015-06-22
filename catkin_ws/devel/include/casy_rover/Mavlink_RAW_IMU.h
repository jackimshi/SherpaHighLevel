/* Software License Agreement (BSD License)
 *
 * Copyright (c) 2011, Willow Garage, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above
 *    copyright notice, this list of conditions and the following
 *    disclaimer in the documentation and/or other materials provided
 *    with the distribution.
 *  * Neither the name of Willow Garage, Inc. nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * Auto-generated by genmsg_cpp from file /home/odroid/catkin_ws/src/casy_rover/msg/Mavlink_RAW_IMU.msg
 *
 */


#ifndef CASY_ROVER_MESSAGE_MAVLINK_RAW_IMU_H
#define CASY_ROVER_MESSAGE_MAVLINK_RAW_IMU_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>

namespace casy_rover
{
template <class ContainerAllocator>
struct Mavlink_RAW_IMU_
{
  typedef Mavlink_RAW_IMU_<ContainerAllocator> Type;

  Mavlink_RAW_IMU_()
    : header()
    , time_usec(0)
    , xacc(0)
    , yacc(0)
    , zacc(0)
    , xgyro(0)
    , ygyro(0)
    , zgyro(0)
    , xmag(0)
    , ymag(0)
    , zmag(0)  {
    }
  Mavlink_RAW_IMU_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , time_usec(0)
    , xacc(0)
    , yacc(0)
    , zacc(0)
    , xgyro(0)
    , ygyro(0)
    , zgyro(0)
    , xmag(0)
    , ymag(0)
    , zmag(0)  {
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef uint64_t _time_usec_type;
  _time_usec_type time_usec;

   typedef int32_t _xacc_type;
  _xacc_type xacc;

   typedef int32_t _yacc_type;
  _yacc_type yacc;

   typedef int32_t _zacc_type;
  _zacc_type zacc;

   typedef int32_t _xgyro_type;
  _xgyro_type xgyro;

   typedef int32_t _ygyro_type;
  _ygyro_type ygyro;

   typedef int32_t _zgyro_type;
  _zgyro_type zgyro;

   typedef int32_t _xmag_type;
  _xmag_type xmag;

   typedef int32_t _ymag_type;
  _ymag_type ymag;

   typedef int32_t _zmag_type;
  _zmag_type zmag;




  typedef boost::shared_ptr< ::casy_rover::Mavlink_RAW_IMU_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::casy_rover::Mavlink_RAW_IMU_<ContainerAllocator> const> ConstPtr;

}; // struct Mavlink_RAW_IMU_

typedef ::casy_rover::Mavlink_RAW_IMU_<std::allocator<void> > Mavlink_RAW_IMU;

typedef boost::shared_ptr< ::casy_rover::Mavlink_RAW_IMU > Mavlink_RAW_IMUPtr;
typedef boost::shared_ptr< ::casy_rover::Mavlink_RAW_IMU const> Mavlink_RAW_IMUConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::casy_rover::Mavlink_RAW_IMU_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::casy_rover::Mavlink_RAW_IMU_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace casy_rover

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': True}
// {'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/indigo/share/geometry_msgs/cmake/../msg'], 'casy_rover': ['/home/odroid/catkin_ws/src/casy_rover/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::casy_rover::Mavlink_RAW_IMU_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::casy_rover::Mavlink_RAW_IMU_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::casy_rover::Mavlink_RAW_IMU_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::casy_rover::Mavlink_RAW_IMU_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::casy_rover::Mavlink_RAW_IMU_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::casy_rover::Mavlink_RAW_IMU_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::casy_rover::Mavlink_RAW_IMU_<ContainerAllocator> >
{
  static const char* value()
  {
    return "f00561d290c2da804223c20d12427677";
  }

  static const char* value(const ::casy_rover::Mavlink_RAW_IMU_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xf00561d290c2da80ULL;
  static const uint64_t static_value2 = 0x4223c20d12427677ULL;
};

template<class ContainerAllocator>
struct DataType< ::casy_rover::Mavlink_RAW_IMU_<ContainerAllocator> >
{
  static const char* value()
  {
    return "casy_rover/Mavlink_RAW_IMU";
  }

  static const char* value(const ::casy_rover::Mavlink_RAW_IMU_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::casy_rover::Mavlink_RAW_IMU_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Header header\n\
#time since boot\n\
uint64 time_usec\n\
#linear acc\n\
int32 xacc\n\
int32 yacc\n\
int32 zacc\n\
#gyro\n\
int32 xgyro\n\
int32 ygyro\n\
int32 zgyro\n\
#magnetic field\n\
int32 xmag  \n\
int32 ymag\n\
int32 zmag\n\
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
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n\
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
";
  }

  static const char* value(const ::casy_rover::Mavlink_RAW_IMU_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::casy_rover::Mavlink_RAW_IMU_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.time_usec);
      stream.next(m.xacc);
      stream.next(m.yacc);
      stream.next(m.zacc);
      stream.next(m.xgyro);
      stream.next(m.ygyro);
      stream.next(m.zgyro);
      stream.next(m.xmag);
      stream.next(m.ymag);
      stream.next(m.zmag);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct Mavlink_RAW_IMU_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::casy_rover::Mavlink_RAW_IMU_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::casy_rover::Mavlink_RAW_IMU_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "time_usec: ";
    Printer<uint64_t>::stream(s, indent + "  ", v.time_usec);
    s << indent << "xacc: ";
    Printer<int32_t>::stream(s, indent + "  ", v.xacc);
    s << indent << "yacc: ";
    Printer<int32_t>::stream(s, indent + "  ", v.yacc);
    s << indent << "zacc: ";
    Printer<int32_t>::stream(s, indent + "  ", v.zacc);
    s << indent << "xgyro: ";
    Printer<int32_t>::stream(s, indent + "  ", v.xgyro);
    s << indent << "ygyro: ";
    Printer<int32_t>::stream(s, indent + "  ", v.ygyro);
    s << indent << "zgyro: ";
    Printer<int32_t>::stream(s, indent + "  ", v.zgyro);
    s << indent << "xmag: ";
    Printer<int32_t>::stream(s, indent + "  ", v.xmag);
    s << indent << "ymag: ";
    Printer<int32_t>::stream(s, indent + "  ", v.ymag);
    s << indent << "zmag: ";
    Printer<int32_t>::stream(s, indent + "  ", v.zmag);
  }
};

} // namespace message_operations
} // namespace ros

#endif // CASY_ROVER_MESSAGE_MAVLINK_RAW_IMU_H
