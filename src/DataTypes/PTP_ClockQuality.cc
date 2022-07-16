/*
 * PTP_ClockQuality.cc
 *
 *  Created on: Jul 16, 2022
 *      Author: zyh01
 */

// ======================================================
// Includes
// ======================================================

#include "PTP_ClockQuality.h"

#include <omnetpp.h>
#include <sstream>

#include "ByteOrder.h"


// ------------------------------------------------------
// Constructor
// ------------------------------------------------------
cClockQuality::cClockQuality()
{
    // Initialize with dummy values
    this->clockAccuracy             = CLOCK_ACCURACY_UNKNOWN;
    this->clockClass                = CLOCK_CLASS_DEFAULT;
    this->offsetScaledLogVariance   = 0;
}

cClockQuality::cClockQuality(   ClockClass_t        clockClass,
                                clockAccuracy_t     clockAccuracy,
                                UInteger16          offsetScaledLogVariance)
: clockClass(clockClass),
  clockAccuracy(clockAccuracy),
  offsetScaledLogVariance(offsetScaledLogVariance)
{
}

cClockQuality::cClockQuality( BufPtpClockQual_t *pBuf )
{
    ReadFromBuffer( pBuf );
}

cClockQuality::cClockQuality( const cClockQuality& other )
{
    this->clockAccuracy             = other.clockAccuracy;
    this->clockClass                = other.clockClass;
    this->offsetScaledLogVariance   = other.offsetScaledLogVariance;
}

cClockQuality::~cClockQuality()
{
}

// ------------------------------------------------------
// Setters
// ------------------------------------------------------
void
cClockQuality::SetClockClass( ClockClass_t clockClass )
{
    this->clockClass    = clockClass;
}

void
cClockQuality::SetClockAccuracy( clockAccuracy_t clockAccuracy )
{
    this->clockAccuracy = clockAccuracy;
}

void
cClockQuality::SetOffsetScaledLogVar( UInteger16 offsetScaledLogVariance )
{
    this->offsetScaledLogVariance   = offsetScaledLogVariance;
}

void
cClockQuality::ReadFromBuffer( BufPtpClockQual_t *pBuf )
{
    this->clockClass                = (ClockClass_t)    pBuf->clockClass;
    this->clockAccuracy             = (clockAccuracy_t) pBuf->clockAccuracy;
    this->offsetScaledLogVariance   = NetToHostUI16( pBuf->offsetScaledLogVariance );
}

// ------------------------------------------------------
// Getters
// ------------------------------------------------------
ClockClass_t
cClockQuality::GetClockClass() const
{
    return  this->clockClass;
}

clockAccuracy_t
cClockQuality::GetClockAccuracy() const
{
    return  this->clockAccuracy;
}

UInteger16
cClockQuality::GetOffsetScaledLogVar() const
{
    return  this->offsetScaledLogVariance;
}

void
cClockQuality::SaveToBuffer( BufPtpClockQual_t *pBuf ) const
{
    pBuf->clockClass               = clockClass;
    pBuf->clockAccuracy            = clockAccuracy;
    pBuf->offsetScaledLogVariance  = HostToNetUI16( offsetScaledLogVariance );
}

// ------------------------------------------------------
// API functions
// ------------------------------------------------------
uint64_t    cClockQuality::GetUInt64()
{
    uint64_t    cClockQuality;

    UInteger8   clockClass              = this->clockClass;
    UInteger8   clockAccuracy           = this->clockAccuracy;
    UInteger16  offsetScaledLogVariance = this->offsetScaledLogVariance;

    cClockQuality   =   0;
    cClockQuality   +=  clockClass;
    cClockQuality   <<= 8;
    cClockQuality   += clockAccuracy;
    cClockQuality   <<= 16;
    cClockQuality   += offsetScaledLogVariance;

    return  cClockQuality;
}

// ------------------------------------------------------
// Compare operator
// ------------------------------------------------------
bool
cClockQuality::operator== (const cClockQuality& other) const
{
    if
    (
        ( other.clockAccuracy           == this->clockAccuracy              ) &&
        ( other.clockClass              == this->clockClass                 ) &&
        ( other.offsetScaledLogVariance == this->offsetScaledLogVariance    )
    )
    {
        return true;
    }
    else
    {
        return false;
    }
}

// ------------------------------------------------------
// Assign operator
// ------------------------------------------------------
cClockQuality &
cClockQuality::operator= (const cClockQuality& other)
{
    this->clockAccuracy             = other.clockAccuracy;
    this->clockClass                = other.clockClass;
    this->offsetScaledLogVariance   = other.offsetScaledLogVariance;

    // By convention, always return *this
    return *this;
}

// ------------------------------------------------------
// Stream operators
// ------------------------------------------------------
std::ostream&
operator<<(std::ostream& os, const cClockQuality& o)
{
    os << "Accuracy: " << o.clockAccuracy << ", Class: " << o.clockClass << ", OffsetScaledLogVar: " << o.offsetScaledLogVariance;

    return os;
}

// ------------------------------------------------------
// Debug functions
// ------------------------------------------------------
void
cClockQuality::Print()
{
    EV << "ClockQuality: " << GetString() << endl;
}

std::string
cClockQuality::GetString()
{
    std::stringstream   ss;

    ss << "<";

    ss << (int) this->clockAccuracy << ":";
    ss << (int) this->clockClass    << ":";
    ss << (int) this->offsetScaledLogVariance;

    ss << ">";

    return ss.str();
}


