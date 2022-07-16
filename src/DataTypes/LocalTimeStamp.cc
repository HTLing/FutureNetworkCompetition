/*
 * LocalTimeStamp.cc
 *
 *  Created on: Jul 15, 2022
 *      Author: zyh01
 */


// ======================================================
// Includes
// ======================================================

#include "LocalTimeStamp.h"

// ------------------------------------------------------
// Constructors
// ------------------------------------------------------
cLocalTimeStamp::cLocalTimeStamp()
{
    this->EpochID   = 0;
    this->Time      = SIMTIME_ZERO;
}

cLocalTimeStamp::cLocalTimeStamp(uint64_t EpochID, simtime_t Time)
{
    this->EpochID   = EpochID;
    this->Time      = Time;
}

cLocalTimeStamp::cLocalTimeStamp( const cLocalTimeStamp &other )
{
    this->EpochID   = other.EpochID;
    this->Time      = other.Time;
}

// ------------------------------------------------------
// Destructor
// ------------------------------------------------------
cLocalTimeStamp::~cLocalTimeStamp()
{
}

// ------------------------------------------------------
// Getters
// ------------------------------------------------------
uint64_t
cLocalTimeStamp::GetEpochID() const
{
    return this->EpochID;
}

simtime_t
cLocalTimeStamp::GetTime() const
{
    return this->Time;
}

// ------------------------------------------------------
// Setters
// ------------------------------------------------------

// ------------------------------------------------------
// Operators
// ------------------------------------------------------
bool
cLocalTimeStamp::operator== (const cLocalTimeStamp& other) const
{
    if
    (
        ( this->EpochID == other.EpochID ) &&
        ( this->Time    == other.Time    )
    )
    {
        return true;
    }
    else
    {
        return false;
    }
}

cLocalTimeStamp&
cLocalTimeStamp::operator=( const cLocalTimeStamp& other )
{
    this->EpochID   = other.EpochID;
    this->Time      = other.Time;

    // By convention, always return *this
    return *this;
}

simtime_t
cLocalTimeStamp::operator-( const cLocalTimeStamp& other )
{
    if( this->EpochID == other.EpochID )
    {
        return this->Time - other.Time;
    }
    else
    {
        return SIMTIME_ZERO;
    }
}

std::ostream&
operator<<(std::ostream& os, const cLocalTimeStamp& o )
{
    os << "Epoch: " << o.GetEpochID() << ", Time: " << o.GetTime();

    return os;
}

