/*
 * PTP_PortIdentity.cc
 *
 *  Created on: Jul 16, 2022
 *      Author: zyh01
 */


// ======================================================
// Includes
// ======================================================

#include "PTP_PortIdentity.h"
#include "ByteOrder.h"

// ------------------------------------------------------
// Constructors
// ------------------------------------------------------
cPortIdentity::cPortIdentity()
{
    this->clockIdentity = "";
    this->portNumber    = 0;
}

cPortIdentity::cPortIdentity( const char *ClockStr, UInteger16 portNumber )
{
    this->clockIdentity = ClockStr;
    this->portNumber    = portNumber;
}

cPortIdentity::cPortIdentity( const cClockIdentity clockIdentity, const UInteger16 portNumber )
{
    this->clockIdentity = clockIdentity;
    this->portNumber    = portNumber;
}

cPortIdentity::cPortIdentity( const BufPtpPortId_t *pBuf )
{
    ReadFromBuffer( pBuf );
}

cPortIdentity::cPortIdentity( const cPortIdentity& other )
{
    this->clockIdentity = other.clockIdentity;
    this->portNumber    = other.portNumber;
}

cPortIdentity::~cPortIdentity()
{
}

// ------------------------------------------------------
// Instance methods
// ------------------------------------------------------
cClockIdentity&
cPortIdentity::ClockIdentity()
{
    return  this->clockIdentity;
}

// ------------------------------------------------------
// Setters
// ------------------------------------------------------
void
cPortIdentity::SetPortNumber( UInteger16 portNumber )
{
    this->portNumber = portNumber;
}

void
cPortIdentity::ReadFromBuffer( const BufPtpPortId_t *pBuf )
{
    this->clockIdentity.ReadFromBuffer( &pBuf->clockIdentity );
    this->portNumber = NetToHostUI16( pBuf->portNumber );
}

// ------------------------------------------------------
// Getters
// ------------------------------------------------------
UInteger16
cPortIdentity::GetPortNumber() const
{
    return  this->portNumber;
}

std::string
cPortIdentity::GetString() const
{
    std::stringstream   ss;

    ss << clockIdentity << ", Port " << portNumber; // no endl!

    return  ss.str();
}

Octet
cPortIdentity::GetByteAt( size_t idx )
{
    Octet   ret = 0;

    if( idx <= 7 )
    {
        ret = this->clockIdentity.GetByteAt( idx );
    }
    else if( idx == 8 )
    {
        ret = (Octet) (this->portNumber >> 8);
    }
    else if( idx == 9 )
    {
        ret = (Octet) this->portNumber;
    }

    return  ret;
}

void
cPortIdentity::SaveToBuffer( BufPtpPortId_t *pBuf )
{
    clockIdentity.SaveToBuffer( &pBuf->clockIdentity );

    pBuf->portNumber    = HostToNetUI16( portNumber );
}

// ------------------------------------------------------
// Compare operators
// ------------------------------------------------------
bool
cPortIdentity::operator== (const cPortIdentity& other) const
{
    if
    (
        ( this->clockIdentity   == other.clockIdentity  ) &&
        ( this->portNumber      == other.portNumber     )
    )
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool
cPortIdentity::operator!= (const cPortIdentity& other) const
{
    return !(this->operator ==(other));
}

bool
operator<(cPortIdentity const& lhs, cPortIdentity const& rhs)
{
    if( lhs.clockIdentity < rhs.clockIdentity)
        return true;

    if( lhs.clockIdentity == rhs.clockIdentity )
        return lhs.portNumber < rhs.portNumber;

    return false;
}

bool
operator>(cPortIdentity const& lhs, cPortIdentity const& rhs)
{
    if( lhs.clockIdentity > rhs.clockIdentity)
        return true;

    if( lhs.clockIdentity == rhs.clockIdentity )
        return lhs.portNumber > rhs.portNumber;

    return false;
}

// ------------------------------------------------------
// Assign operator
// ------------------------------------------------------
cPortIdentity&
cPortIdentity::operator= (const cPortIdentity& other)
{
    this->clockIdentity = other.clockIdentity;
    this->portNumber    = other.portNumber;

    // By convention, always return *this
    return *this;
}

cPortIdentity&
cPortIdentity::operator= (const cClockIdentity& Clock)
{
    this->clockIdentity = Clock;
    this->portNumber    = 0;

    // By convention, always return *this
    return *this;
}

// ------------------------------------------------------
// Stream operators
// ------------------------------------------------------
std::ostream&
operator<<(std::ostream& os, const cPortIdentity& o)
{
    os << o.GetString(); // no endl!

    return os;
}

// ------------------------------------------------------
// Debug functions
// ------------------------------------------------------
void
cPortIdentity::Print()
{
    EV << "PortIdentity: " << GetString() << endl;
}

