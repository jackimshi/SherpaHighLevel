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
 * Auto-generated by genmsg_cpp from file /home/odroid/catkin_ws/src/vision_opencv-indigo/opencv_apps/msg/CircleArray.msg
 *
 */


#ifndef OPENCV_APPS_MESSAGE_CIRCLEARRAY_H
#define OPENCV_APPS_MESSAGE_CIRCLEARRAY_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <opencv_apps/Circle.h>

namespace opencv_apps
{
template <class ContainerAllocator>
struct CircleArray_
{
  typedef CircleArray_<ContainerAllocator> Type;

  CircleArray_()
    : circles()  {
    }
  CircleArray_(const ContainerAllocator& _alloc)
    : circles(_alloc)  {
    }



   typedef std::vector< ::opencv_apps::Circle_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::opencv_apps::Circle_<ContainerAllocator> >::other >  _circles_type;
  _circles_type circles;




  typedef boost::shared_ptr< ::opencv_apps::CircleArray_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::opencv_apps::CircleArray_<ContainerAllocator> const> ConstPtr;

}; // struct CircleArray_

typedef ::opencv_apps::CircleArray_<std::allocator<void> > CircleArray;

typedef boost::shared_ptr< ::opencv_apps::CircleArray > CircleArrayPtr;
typedef boost::shared_ptr< ::opencv_apps::CircleArray const> CircleArrayConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::opencv_apps::CircleArray_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::opencv_apps::CircleArray_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace opencv_apps

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/indigo/share/geometry_msgs/cmake/../msg'], 'opencv_apps': ['/home/odroid/catkin_ws/src/vision_opencv-indigo/opencv_apps/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::opencv_apps::CircleArray_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::opencv_apps::CircleArray_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::opencv_apps::CircleArray_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::opencv_apps::CircleArray_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::opencv_apps::CircleArray_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::opencv_apps::CircleArray_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::opencv_apps::CircleArray_<ContainerAllocator> >
{
  static const char* value()
  {
    return "1970b146e338dd024c765e522039a727";
  }

  static const char* value(const ::opencv_apps::CircleArray_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x1970b146e338dd02ULL;
  static const uint64_t static_value2 = 0x4c765e522039a727ULL;
};

template<class ContainerAllocator>
struct DataType< ::opencv_apps::CircleArray_<ContainerAllocator> >
{
  static const char* value()
  {
    return "opencv_apps/CircleArray";
  }

  static const char* value(const ::opencv_apps::CircleArray_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::opencv_apps::CircleArray_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Circle[] circles\n\
\n\
\n\
================================================================================\n\
MSG: opencv_apps/Circle\n\
Point2D center\n\
float64 radius\n\
\n\
\n\
================================================================================\n\
MSG: opencv_apps/Point2D\n\
float64 x\n\
float64 y\n\
\n\
";
  }

  static const char* value(const ::opencv_apps::CircleArray_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::opencv_apps::CircleArray_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.circles);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct CircleArray_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::opencv_apps::CircleArray_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::opencv_apps::CircleArray_<ContainerAllocator>& v)
  {
    s << indent << "circles[]" << std::endl;
    for (size_t i = 0; i < v.circles.size(); ++i)
    {
      s << indent << "  circles[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::opencv_apps::Circle_<ContainerAllocator> >::stream(s, indent + "    ", v.circles[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // OPENCV_APPS_MESSAGE_CIRCLEARRAY_H
