/*
 * PTP_ClockIdentity.h
 *
 *  Created on: Jul 16, 2022
 *      Author: zyh01
 */

#ifndef DATATYPES_PTP_CLOCKIDENTITY_H_
#define DATATYPES_PTP_CLOCKIDENTITY_H_


// ======================================================
// Includes
// ======================================================

#include "inet/linklayer/common/MacAddress.h"

#include "PTP_PrimitiveDataTypes.h"
#include "PTP_Constants.h"
#include "PTP_ByteBuffers.h"

// ======================================================
// Declarations
// ======================================================

// Clock identity, see clause 5.3.4 and 7.5.2.2 in IEEE 1588-2008
class cClockIdentity
{
    private:
        Octet   Bytes[ PTP_CLOCK_IDENTITY_SIZE ];

    protected:

    public:
        // Constructors/Destructor
        cClockIdentity();
        cClockIdentity( const char *Str );
        cClockIdentity( const MACAddress MAC );
        cClockIdentity( const BufPtpClockId_t *pBuf );
        cClockIdentity( const cClockIdentity& other );
        ~cClockIdentity();

        // Setters
        void    ReadFromBuffer( const BufPtpClockId_t *pBuf );

        // Getters
        Octet   GetByteAt( size_t idx );
        void    SaveToBuffer( BufPtpClockId_t *pBuf );

        // Operators
        bool            operator== (const cClockIdentity& other)    const;
        bool            operator!= (const cClockIdentity& other)    const;
        friend bool     operator<(cClockIdentity const& lhs, cClockIdentity const& rhs);
        friend bool     operator>(cClockIdentity const& lhs, cClockIdentity const& rhs);
        cClockIdentity& operator= (const cClockIdentity& other);
        cClockIdentity& operator= (const char *Str);
        cClockIdentity& operator= (const MACAddress MAC);

        friend std::ostream& operator<<(std::ostream& os, const cClockIdentity& o);

        // Debug functions
        void            Print()     const;
        std::string     GetString() const;
};


#endif /* DATATYPES_PTP_CLOCKIDENTITY_H_ */
