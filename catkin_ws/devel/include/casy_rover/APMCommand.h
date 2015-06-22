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
 * Auto-generated by gensrv_cpp from file /home/odroid/catkin_ws/src/casy_rover/srv/APMCommand.srv
 *
 */


#ifndef CASY_ROVER_MESSAGE_APMCOMMAND_H
#define CASY_ROVER_MESSAGE_APMCOMMAND_H

#include <ros/service_traits.h>


#include <casy_rover/APMCommandRequest.h>
#include <casy_rover/APMCommandResponse.h>


namespace casy_rover
{

struct APMCommand
{

typedef APMCommandRequest Request;
typedef APMCommandResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct APMCommand
} // namespace casy_rover


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::casy_rover::APMCommand > {
  static const char* value()
  {
    return "121a7864eeada093e8e6c9456e1f36f7";
  }

  static const char* value(const ::casy_rover::APMCommand&) { return value(); }
};

template<>
struct DataType< ::casy_rover::APMCommand > {
  static const char* value()
  {
    return "casy_rover/APMCommand";
  }

  static const char* value(const ::casy_rover::APMCommand&) { return value(); }
};


// service_traits::MD5Sum< ::casy_rover::APMCommandRequest> should match 
// service_traits::MD5Sum< ::casy_rover::APMCommand > 
template<>
struct MD5Sum< ::casy_rover::APMCommandRequest>
{
  static const char* value()
  {
    return MD5Sum< ::casy_rover::APMCommand >::value();
  }
  static const char* value(const ::casy_rover::APMCommandRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::casy_rover::APMCommandRequest> should match 
// service_traits::DataType< ::casy_rover::APMCommand > 
template<>
struct DataType< ::casy_rover::APMCommandRequest>
{
  static const char* value()
  {
    return DataType< ::casy_rover::APMCommand >::value();
  }
  static const char* value(const ::casy_rover::APMCommandRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::casy_rover::APMCommandResponse> should match 
// service_traits::MD5Sum< ::casy_rover::APMCommand > 
template<>
struct MD5Sum< ::casy_rover::APMCommandResponse>
{
  static const char* value()
  {
    return MD5Sum< ::casy_rover::APMCommand >::value();
  }
  static const char* value(const ::casy_rover::APMCommandResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::casy_rover::APMCommandResponse> should match 
// service_traits::DataType< ::casy_rover::APMCommand > 
template<>
struct DataType< ::casy_rover::APMCommandResponse>
{
  static const char* value()
  {
    return DataType< ::casy_rover::APMCommand >::value();
  }
  static const char* value(const ::casy_rover::APMCommandResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // CASY_ROVER_MESSAGE_APMCOMMAND_H
