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
 * Auto-generated by genmsg_cpp from file /home/odroid/catkin_ws/src/guidance_node_amsl/msg/Reference.msg
 *
 */


#ifndef GUIDANCE_NODE_AMSL_MESSAGE_REFERENCE_H
#define GUIDANCE_NODE_AMSL_MESSAGE_REFERENCE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace guidance_node_amsl
{
template <class ContainerAllocator>
struct Reference_
{
  typedef Reference_<ContainerAllocator> Type;

  Reference_()
    : Latitude(0)
    , Longitude(0)
    , AltitudeRelative(0)
    , Yawangle(0.0)
    , Mode(0)  {
    }
  Reference_(const ContainerAllocator& _alloc)
    : Latitude(0)
    , Longitude(0)
    , AltitudeRelative(0)
    , Yawangle(0.0)
    , Mode(0)  {
    }



   typedef int32_t _Latitude_type;
  _Latitude_type Latitude;

   typedef int32_t _Longitude_type;
  _Longitude_type Longitude;

   typedef int32_t _AltitudeRelative_type;
  _AltitudeRelative_type AltitudeRelative;

   typedef float _Yawangle_type;
  _Yawangle_type Yawangle;

   typedef int8_t _Mode_type;
  _Mode_type Mode;




  typedef boost::shared_ptr< ::guidance_node_amsl::Reference_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::guidance_node_amsl::Reference_<ContainerAllocator> const> ConstPtr;

}; // struct Reference_

typedef ::guidance_node_amsl::Reference_<std::allocator<void> > Reference;

typedef boost::shared_ptr< ::guidance_node_amsl::Reference > ReferencePtr;
typedef boost::shared_ptr< ::guidance_node_amsl::Reference const> ReferenceConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::guidance_node_amsl::Reference_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::guidance_node_amsl::Reference_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace guidance_node_amsl

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'guidance_node_amsl': ['/home/odroid/catkin_ws/src/guidance_node_amsl/msg'], 'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::guidance_node_amsl::Reference_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::guidance_node_amsl::Reference_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::guidance_node_amsl::Reference_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::guidance_node_amsl::Reference_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::guidance_node_amsl::Reference_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::guidance_node_amsl::Reference_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::guidance_node_amsl::Reference_<ContainerAllocator> >
{
  static const char* value()
  {
    return "993e02597e619163c0d46925fb7696ce";
  }

  static const char* value(const ::guidance_node_amsl::Reference_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x993e02597e619163ULL;
  static const uint64_t static_value2 = 0xc0d46925fb7696ceULL;
};

template<class ContainerAllocator>
struct DataType< ::guidance_node_amsl::Reference_<ContainerAllocator> >
{
  static const char* value()
  {
    return "guidance_node_amsl/Reference";
  }

  static const char* value(const ::guidance_node_amsl::Reference_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::guidance_node_amsl::Reference_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# expressed as * 1E7\n\
int32 Latitude\n\
# expressed as * 1E7\n\
int32 Longitude\n\
# expressed as * 1000 (millimeters)\n\
int32 AltitudeRelative\n\
# (-pi...pi)\n\
float32 Yawangle\n\
#reference abs or rel\n\
int8 Mode\n\
";
  }

  static const char* value(const ::guidance_node_amsl::Reference_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::guidance_node_amsl::Reference_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.Latitude);
      stream.next(m.Longitude);
      stream.next(m.AltitudeRelative);
      stream.next(m.Yawangle);
      stream.next(m.Mode);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct Reference_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::guidance_node_amsl::Reference_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::guidance_node_amsl::Reference_<ContainerAllocator>& v)
  {
    s << indent << "Latitude: ";
    Printer<int32_t>::stream(s, indent + "  ", v.Latitude);
    s << indent << "Longitude: ";
    Printer<int32_t>::stream(s, indent + "  ", v.Longitude);
    s << indent << "AltitudeRelative: ";
    Printer<int32_t>::stream(s, indent + "  ", v.AltitudeRelative);
    s << indent << "Yawangle: ";
    Printer<float>::stream(s, indent + "  ", v.Yawangle);
    s << indent << "Mode: ";
    Printer<int8_t>::stream(s, indent + "  ", v.Mode);
  }
};

} // namespace message_operations
} // namespace ros

#endif // GUIDANCE_NODE_AMSL_MESSAGE_REFERENCE_H
