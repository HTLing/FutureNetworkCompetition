/*
 * PTP_TimeStamp.cc
 *
 *  Created on: Jul 16, 2022
 *      Author: zyh01
 */


// ======================================================
// Includes
// ======================================================

#include "PTP_TimeStamp.h"

#include "ByteOrder.h"

// ------------------------------------------------------
// Constructors
// ------------------------------------------------------
cTimeStamp::cTimeStamp()
{
    secondsField        = 0;
    nanosecondsField    = 0;
}

cTimeStamp::cTimeStamp( UInteger48  secondsField,
                        UInteger32  nanosecondsField )
:   secondsField(secondsField),
    nanosecondsField(nanosecondsField)
{
}

cTimeStamp::cTimeStamp( simtime_t timestamp )
{
    this->operator=(timestamp);
}

cTimeStamp::cTimeStamp( BufPtpTimeStamp_t *pBuf )
{
    ReadFromBuffer( pBuf );
}

// ------------------------------------------------------
// Setters
// ------------------------------------------------------
void
cTimeStamp::Set(    UInteger48  secondsField,
                    UInteger32  nanosecondsField )
{
    this->secondsField      = secondsField;
    this->nanosecondsField  = nanosecondsField;
}

void
cTimeStamp::ReadFromBuffer( BufPtpTimeStamp_t *pBuf )
{
    secondsField        = BufToHostUI48( pBuf->seconds, sizeof(pBuf->seconds) );
    nanosecondsField    = NetToHostUI32( pBuf->nanoseconds );
}

// ------------------------------------------------------
// Getters
// ------------------------------------------------------

simtime_t
cTimeStamp::GetSimTime()
{
    int64_t     NanoSecs    = secondsField * 1E9 + nanosecondsField;

    return simtime_t(NanoSecs, SIMTIME_NS);
}

UInteger48
cTimeStamp::GetSeconds() const
{
    return secondsField;
}

UInteger32
cTimeStamp::GetNanoSeconds() const
{
    return nanosecondsField;
}

std::string
cTimeStamp::GetString() const
{
    std::stringstream   ss;

    ss << secondsField * 1E9 + nanosecondsField << " [ns]";

    return  ss.str();
}

void
cTimeStamp::SaveToBuffer( BufPtpTimeStamp_t *pBuf )
{
    HostToBufUI48( secondsField, pBuf->seconds, sizeof(pBuf->seconds) );
    pBuf->nanoseconds = HostToNetUI32( nanosecondsField );
}

// ------------------------------------------------------
// Compare operator (TimeStamp)
// ------------------------------------------------------
bool
cTimeStamp::operator== (const cTimeStamp& other)
{
    if
    (
        ( other.secondsField        == this->secondsField       ) &&
        ( other.nanosecondsField    == this->nanosecondsField   )
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
// Compare operator (simtime_t)
// ------------------------------------------------------
bool
cTimeStamp::operator== (const simtime_t& other)
{
    return other == GetSimTime();
}

// ------------------------------------------------------
// Assignment operator (TimeStamp)
// ------------------------------------------------------
cTimeStamp &
cTimeStamp::operator= (const cTimeStamp& other)
{
    this->secondsField      = other.secondsField;
    this->nanosecondsField  = other.nanosecondsField;

    // By convention, always return *this
    return *this;
}

// ------------------------------------------------------
// Assignment operator (simtime_t)
// ------------------------------------------------------
cTimeStamp &
cTimeStamp::operator= (const simtime_t& other)
{
    this->secondsField      = other.inUnit( SIMTIME_S );
    this->nanosecondsField  = other.remainderForUnit( SIMTIME_S ).inUnit( SIMTIME_NS );

    // By convention, always return *this
    return *this;
}

// ------------------------------------------------------
// Assignment operator (int64_t)
// ------------------------------------------------------
cTimeStamp &
cTimeStamp::operator= (const int64_t& other_ps)
{
    int64_t tmp;
    int64_t NanoSecs;
    int64_t Secs;

    tmp         = (other_ps / 1000);
    NanoSecs    = tmp % 1E9;
    Secs        = tmp / 1E9;

    this->secondsField      = Secs;
    this->nanosecondsField  = NanoSecs;

    // By convention, always return *this
    return *this;
}

// ------------------------------------------------------
// Ouput operators
// ------------------------------------------------------
std::ostream&
operator<<(std::ostream& os, const cTimeStamp& o)
{
    os << o.GetString(); // no endl!

    return os;
}


