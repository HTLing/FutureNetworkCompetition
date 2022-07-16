/*
 * PTP_ClockIdentity.cc
 *
 *  Created on: Jul 16, 2022
 *      Author: zyh01
 */


// ======================================================
// Includes
// ======================================================

#include <cstring>

#include "PTP_ClockIdentity.h"
#include "PTP_Constants.h"

#include  <iostream>
#include  <iomanip>

// ------------------------------------------------------
// Constructors
// ------------------------------------------------------

cClockIdentity::cClockIdentity()
{
    // Nullify clock ID on startup
    memset( Bytes, 0x00, PTP_CLOCK_IDENTITY_SIZE );
}

cClockIdentity::cClockIdentity( const char *Str )
{
    this->operator=(Str);
}

cClockIdentity::cClockIdentity( const MACAddress MAC )
{
    this->operator=(MAC);
}

cClockIdentity::cClockIdentity( const BufPtpClockId_t *pBuf )
{
    ReadFromBuffer( pBuf );
}

cClockIdentity::cClockIdentity( const cClockIdentity& other )
{
    memcpy( this->Bytes, other.Bytes, PTP_CLOCK_IDENTITY_SIZE );
}

cClockIdentity::~cClockIdentity()
{
}

// ------------------------------------------------------
// Setters
// ------------------------------------------------------
void
cClockIdentity::ReadFromBuffer( const BufPtpClockId_t *pBuf )
{
    memcpy( Bytes, pBuf->data, PTP_CLOCK_IDENTITY_SIZE );
}

// ------------------------------------------------------
// Getters
// ------------------------------------------------------
Octet
cClockIdentity::GetByteAt( size_t idx )
{
    return  this->Bytes[ idx ];
}

void
cClockIdentity::SaveToBuffer( BufPtpClockId_t *pBuf )
{
    memcpy( &pBuf->data, Bytes, PTP_CLOCK_IDENTITY_SIZE );
}

// ------------------------------------------------------
// Compare operators
// ------------------------------------------------------
bool
cClockIdentity::operator== (const cClockIdentity& other) const
{
    return (0 == memcmp( this->Bytes, other.Bytes, PTP_CLOCK_IDENTITY_SIZE ));
}

bool
cClockIdentity::operator!= (const cClockIdentity& other) const
{
    return !(this->operator ==(other));
}

bool
operator<(cClockIdentity const& lhs, cClockIdentity const& rhs)
{
    if( memcmp( lhs.Bytes, rhs.Bytes, PTP_CLOCK_IDENTITY_SIZE ) < 0 )
    {
        return true;
    }

    return false;
}

bool
operator>(cClockIdentity const& lhs, cClockIdentity const& rhs)
{
    if( memcmp( lhs.Bytes, rhs.Bytes, PTP_CLOCK_IDENTITY_SIZE ) > 0 )
    {
        return true;
    }

    return false;
}

// ------------------------------------------------------
// Assign operator
// ------------------------------------------------------
cClockIdentity &
cClockIdentity::operator= (const cClockIdentity& other)
{
    // Copy data
    memcpy( this->Bytes, other.Bytes, PTP_CLOCK_IDENTITY_SIZE );

   // By convention, always return *this
   return *this;
}

// ------------------------------------------------------
// Set Clock Identity from hexadecimal string
// ------------------------------------------------------
cClockIdentity  &
cClockIdentity::operator= (const char *Str)
{
    cStringTokenizer            Tokenizer(Str, " :-.,;");
    std::vector<std::string>    StringVector;

    StringVector    = Tokenizer.asVector();

    if
    (
        ( StringVector.size() != 0 ) &&
        ( StringVector.size() != PTP_CLOCK_IDENTITY_SIZE )
    )
    {
        // Wrong Clock ID size
        throw cRuntimeError("Parsing exception: Clock ID '%s' has wrong size (valid sizes are 0 and %d)", Str, PTP_CLOCK_IDENTITY_SIZE );
    }

    if( StringVector.size() == 0 )
    {
        memset( this->Bytes, 0x00, PTP_CLOCK_IDENTITY_SIZE );
    }
    else
    {
        for( size_t i = 0; i < PTP_CLOCK_IDENTITY_SIZE; i ++ )
        {
            unsigned int x;
            std::stringstream ss;

            // Convert string to hex value
            ss << std::hex << StringVector.at( i );
            ss >> x;

            // Check range
            if
            (
                ( x >= 0x00 )   &&
                ( x <= 0xFF )
            )
            {
                this->Bytes[ i ] = x;
            }
            else
            {
                // Unexpected value
                throw cRuntimeError("Parsing exception: Clock ID '%s' contains unexpected numerical value (bytes expected)", Str );
            }
        }
    }

    // By convention, always return *this
    return *this;
}

cClockIdentity &
cClockIdentity::operator= (const MACAddress MAC)
{
    // MAC to ClockIdentity assignment is specified in 7.5.2.2.2

    this->Bytes[ 0 ]    = MAC.getAddressByte( 0 );
    this->Bytes[ 1 ]    = MAC.getAddressByte( 1 );
    this->Bytes[ 2 ]    = MAC.getAddressByte( 2 );
    this->Bytes[ 3 ]    = 0xFF;
    this->Bytes[ 4 ]    = 0xFE;
    this->Bytes[ 5 ]    = MAC.getAddressByte( 3 );
    this->Bytes[ 6 ]    = MAC.getAddressByte( 4 );
    this->Bytes[ 7 ]    = MAC.getAddressByte( 5 );

    // By convention, always return *this
    return *this;
}

// ------------------------------------------------------
// Stream operators
// ------------------------------------------------------
std::ostream&
operator<<(std::ostream& os, const cClockIdentity& o)
{
    os << o.GetString(); // no endl!

    return os;
}

// ------------------------------------------------------
// Print clock identity
// ------------------------------------------------------
void
cClockIdentity::Print() const
{
    EV << "ClockIdentity: " << GetString() << endl;
}

std::string
cClockIdentity::GetString() const
{
    std::stringstream   ss;

    for( size_t i = 0; i < PTP_CLOCK_IDENTITY_SIZE; i ++ )
    {
        ss << std::setfill('0') << std::setw(2) << std::hex << (int)Bytes[i];

        if( i < PTP_CLOCK_IDENTITY_SIZE-1 )
        {
            ss << "-";
        }
    }

    return ss.str();
}

