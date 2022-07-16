/*
 * ByteOrder.cc
 *
 *  Created on: Jul 16, 2022
 *      Author: zyh01
 */


// ======================================================
// Includes
// ======================================================

#include "ByteOrder.h"

#include <platdep/sockets.h>    // Get htonl etc. for Windows and Linux

#include <omnetpp.h>

// ======================================================
// Definitions
// ======================================================


UInteger16
NetToHostUI16( UInteger16 UInt16 )
{
    return (UInteger16) ntohs( UInt16 );
}

UInteger32
NetToHostUI32( UInteger32 UInt32 )
{
    return (UInteger32) ntohl( UInt32 );
}

Integer16
NetToHostI16( Integer16  Int16  )
{
    return (Integer16) ntohs( Int16 );
}

Integer32
NetToHostI32( Integer32  Int32  )
{
    return (Integer32) ntohl( Int32 );
}

Integer64
NetToHostI64( Integer64  Int64  )
{
#ifdef _WIN32
    // Code-snippet from http://www.codeproject.com/Articles/4804/Basic-concepts-on-Endianness
    return (((Integer64)(ntohl((int)((Int64 << 32) >> 32))) << 32) | (unsigned int)ntohl(((int)(Int64 >> 32))));
#else
    return (Integer64) be64toh( Int64 );
#endif
}

UInteger48
BufToHostUI48( Octet Buf[], size_t BufSize )
{
    UInteger48 UInt48;

    if( BufSize != 6 )
        throw cRuntimeError( "Unexpected BufSize" );

    UInt48  = ((((UInteger48) Buf[0]) & 0xFF) << 40) |
              ((((UInteger48) Buf[1]) & 0xFF) << 32) |
              ((((UInteger48) Buf[2]) & 0xFF) << 24) |
              ((((UInteger48) Buf[3]) & 0xFF) << 16) |
              ((((UInteger48) Buf[4]) & 0xFF) <<  8) |
              ((((UInteger48) Buf[5]) & 0xFF) <<  0);

    return UInt48;
}

UInteger16
HostToNetUI16( UInteger16 UInt16 )
{
    return (UInteger16) htons( UInt16 );
}

UInteger32
HostToNetUI32( UInteger32 UInt32 )
{
    return (UInteger32) htonl( UInt32 );
}

Integer16
HostToNetI16( Integer16  Int16  )
{
    return (Integer16) htons( Int16 );
}

Integer32
HostToNetI32( Integer32  Int32  )
{
    return (Integer32) htonl( Int32 );
}

Integer64
HostToNetI64( Integer64  Int64  )
{
#ifdef _WIN32
    return NetToHostI64(Int64);
#else
    return (Integer64) htobe64( Int64 );
#endif
}

void
HostToBufUI48( UInteger48 UInt48, Octet Buf[], size_t BufSize )
{
    if( BufSize != 6 )
        throw cRuntimeError( "Unexpected BufSize" );

    Buf[0] = (Octet) ((UInt48 >> 40) & 0xFF);
    Buf[1] = (Octet) ((UInt48 >> 32) & 0xFF);
    Buf[2] = (Octet) ((UInt48 >> 24) & 0xFF);
    Buf[3] = (Octet) ((UInt48 >> 16) & 0xFF);
    Buf[4] = (Octet) ((UInt48 >>  8) & 0xFF);
    Buf[5] = (Octet) ((UInt48 >>  0) & 0xFF);
}




