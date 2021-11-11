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
#include "socket.h"
#include <iostream>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include "CommonUtil.h"
#include "CCarLifeLog.h"

using namespace std;

const int MAXCONNECTIONS = 10;

Socket::Socket() : m_sock ( -1 )
{
    memset(&m_addr, 0, sizeof ( m_addr ) );
}

Socket::~Socket()
{
    if ( is_valid() )::close ( m_sock );
}

bool Socket::create()
{
    m_sock = socket ( AF_INET, SOCK_STREAM, 0 );
    if ( ! is_valid() )
        return false;

    int on = 1;
    if ( setsockopt ( m_sock, SOL_SOCKET, SO_REUSEADDR, ( const char* ) &on, sizeof ( on ) ) == -1 )
        return false;

    return true;
}


u32 Socket::send ( const std::string s ) const
{
    return ::send ( m_sock, s.c_str(), s.size(), MSG_NOSIGNAL );
}


bool Socket::send(u8* buf,u32 len) const
{
    int number = 0;
    while( len > 0 )
    {
      
        number = ::send(m_sock, buf, len, MSG_NOSIGNAL);
      
        if( number > 0 )
        {
            len -= number;
            buf += number;
        }
        else
        {
	     CCarLifeLog::carLifeLogWithPrefix("writeData(): fd = ");
	     CCarLifeLog::carLifeLog(m_sock);
	     CCarLifeLog::carLifeLog(", ret = ");
	     CCarLifeLog::carLifeLog(number);
	     CCarLifeLog::carLifeLog(", errno = ");
	     CCarLifeLog::carLifeLog(errno);
	     CCarLifeLog::carLifeLog(": ");
	     CCarLifeLog::carLifeLog(strerror(errno));
	     CCarLifeLog::carLifeLog("\n");
            
            if(number < 0 && (errno == EINTR)) continue;
            return false;
        }
    }
    return true;
}

bool Socket::recv(u8* buf,u32 len) const
{
    //memset ( buf, 0, lenth );
    int number = 0;

    while( len > 0 )
    {
         number = ::recv(m_sock, buf, len, 0);
        if(  number > 0 )
        {
            len -= number;
            buf += number;
        }
        else
        {
	     CCarLifeLog::carLifeLogWithPrefix("writeData(): fd = ");
	     CCarLifeLog::carLifeLog(m_sock);
	     CCarLifeLog::carLifeLog(", ret = ");
	     CCarLifeLog::carLifeLog(number);
	     CCarLifeLog::carLifeLog(", errno = ");
	     CCarLifeLog::carLifeLog(errno);
	     CCarLifeLog::carLifeLog(": ");
	     CCarLifeLog::carLifeLog(strerror(errno));
	     CCarLifeLog::carLifeLog("\n");
           
            if(number < 0 && (errno == EINTR)) continue;
            return false;
        }
    }

    return true;
}


bool Socket::connect ( const std::string host, const u32 port, string interfaceName )
{
    if ( ! is_valid() ) { 
		CCarLifeLog::carLifeLogLnWithPrefix("connect: is_valid failed");
		
		return false;
    }

    m_addr.sin_family = AF_INET;
    m_addr.sin_port = htons ( port );

    int status = inet_pton ( AF_INET, host.c_str(), &m_addr.sin_addr );

    if ( errno == EAFNOSUPPORT ) {
		CCarLifeLog::carLifeLogLnWithPrefix("connect: errno == EAFNOSUPPORT failed");
		return false;
    }

    status = ::connect ( m_sock, ( sockaddr * ) &m_addr, sizeof ( m_addr ) );

    if ( status == 0 ) {	
        return true;
    }else{
    	CCarLifeLog::carLifeLogWithPrefix("connect status= ");
	CCarLifeLog::carLifeLog(status);
	CCarLifeLog::carLifeLogLn(" :failed");
        return false;
    }
}

void Socket::set_non_blocking ( const bool b )
{
    int opts;

    opts = fcntl ( m_sock, F_GETFL );

    if ( opts < 0 )
    {
        return;
    }

    if ( b )
        opts = ( opts | O_NONBLOCK );
    else
        opts = ( opts & ~O_NONBLOCK );

    fcntl ( m_sock,F_SETFL,opts );
}
