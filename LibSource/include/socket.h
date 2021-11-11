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
#ifndef SOCKET_H
#define SOCKET_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <string>
#include <arpa/inet.h>
#include "CommonUtil.h"
#include "ISocket.h"

class Socket:public ISocket
{
public:
    Socket();
    virtual ~Socket();

    bool create();

     // Server initialization
    //bool bind ( const u32 port );
    //bool listen() const;
    //bool accept ( Socket& ) const;

    // Client initialization
    bool connect ( const std::string host, const u32 port, std::string interfaceName );

    // Data Transimission
    u32 send ( const std::string ) const;

    bool recv(u8* buf,u32 lenth) const;
    bool send(u8* buf,u32 lenth) const;

    void set_non_blocking ( const bool );

    bool is_valid() const
    {
        return m_sock != -1;
    }

public:
    int m_sock;
    sockaddr_in m_addr;


};
#endif // SOCKET_H
