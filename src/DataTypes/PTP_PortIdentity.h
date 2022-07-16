/*
 * PTP_PortIdentity.h
 *
 *  Created on: Jul 16, 2022
 *      Author: zyh01
 */

#ifndef DATATYPES_PTP_PORTIDENTITY_H_
#define DATATYPES_PTP_PORTIDENTITY_H_


// ======================================================
// Includes
// ======================================================

#include "PTP_ClockIdentity.h"
#include "PTP_PrimitiveDataTypes.h"
#include "PTP_ByteBuffers.h"

// ======================================================
// Declarations
// ======================================================

// Port identity, see clause 5.3.5 and 7.5.2 in IEEE 1588-2008
class cPortIdentity
{
    private:
        cClockIdentity          clockIdentity;                  //
        UInteger16              portNumber;                     // 1-N, where N is the number of ports

    protected:

    public:

        // Constructors
        cPortIdentity();
        cPortIdentity( const char *ClockStr, UInteger16 portNumber );
        cPortIdentity( const cClockIdentity clockIdentity, const UInteger16 portNumber );
        cPortIdentity( const BufPtpPortId_t *pBuf );
        cPortIdentity( const cPortIdentity& other );
        ~cPortIdentity();


        // Instance methods
        cClockIdentity&     ClockIdentity();

        // Setters
        void            SetPortNumber( UInteger16   portNumber );
        void            ReadFromBuffer( const BufPtpPortId_t *pBuf );

        //Getters
        UInteger16      GetPortNumber() const;
        std::string     GetString()     const;
        Octet           GetByteAt( size_t idx );

        void            SaveToBuffer( BufPtpPortId_t *pBuf );

        // Operators
        bool            operator== (const cPortIdentity& other) const;
        bool            operator!= (const cPortIdentity& other) const;
        friend bool     operator<(cPortIdentity const& lhs, cPortIdentity const& rhs);
        friend bool     operator>(cPortIdentity const& lhs, cPortIdentity const& rhs);

        cPortIdentity&  operator= (const cPortIdentity& other);
        cPortIdentity&  operator= (const cClockIdentity& Clock);

        friend std::ostream& operator<<(std::ostream& os, const cPortIdentity& o);

        // Debug functions
        void    Print();
};



#endif /* DATATYPES_PTP_PORTIDENTITY_H_ */
