/******************************************************************************
 * Copyright 2018 The Baidu Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/
#ifndef I_SOCKET_H
#define I_SOCKET_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <string>
#include <arpa/inet.h>
#include "CommonUtil.h"

class ISocket
{
public:
    virtual bool create()=0;
	
    // Server initialization
    //virtual bool bind ( const u32 port )=0;
    //virtual bool listen() const=0;
    //virtual bool accept ( Socket& ) const=0;

    // Client initialization
    virtual bool connect ( const std::string host, const u32 port, std::string interfaceName )=0;

    // Data Transimission
    virtual u32 send ( const std::string ) const=0;

    virtual bool recv(u8* buf,u32 lenth) const=0;
    virtual bool send(u8* buf,u32 lenth) const=0;

    virtual void set_non_blocking ( const bool )=0;

    virtual bool is_valid() const=0;

};
#endif // SOCKET_H





















