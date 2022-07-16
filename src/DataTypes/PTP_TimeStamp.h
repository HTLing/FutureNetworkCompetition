/*
 * PTP_TimeStamp.h
 *
 *  Created on: Jul 16, 2022
 *      Author: zyh01
 */

#ifndef DATATYPES_PTP_TIMESTAMP_H_
#define DATATYPES_PTP_TIMESTAMP_H_

// ======================================================
// Includes
// ======================================================

#include <omnetpp.h>

#include "PTP_PrimitiveDataTypes.h"
#include "PTP_ByteBuffers.h"

// ======================================================
// Declarations
// ======================================================

// Time stamp, see clause 5.3.3 in IEEE 1588-2008
class cTimeStamp
{
    private:
        UInteger48              secondsField;                   // [s]
        UInteger32              nanosecondsField;               // [ns], always < 10^9

    protected:

    public:

        // Constructors
        cTimeStamp();
        cTimeStamp( UInteger48  secondsField,
                    UInteger32  nanosecondsField );
        cTimeStamp( simtime_t   timestamp        );
        cTimeStamp( BufPtpTimeStamp_t *pBuf );

        // Setters
        void    Set(UInteger48  secondsField,
                    UInteger32  nanosecondsField );

        void        ReadFromBuffer( BufPtpTimeStamp_t *pBuf );

        // Getters
        simtime_t   GetSimTime();
        UInteger48  GetSeconds() const;
        UInteger32  GetNanoSeconds() const;
        std::string GetString() const;

        void        SaveToBuffer( BufPtpTimeStamp_t *pBuf );

        // Operators
        bool            operator== (const cTimeStamp& other);
        bool            operator== (const simtime_t& other);
        cTimeStamp&     operator= (const cTimeStamp& other);
        cTimeStamp&     operator= (const simtime_t& other);
        cTimeStamp&     operator= (const int64_t& other_ps);

        friend std::ostream& operator<<(std::ostream& os, const cTimeStamp& o);

        // Debug functions
};




#endif /* DATATYPES_PTP_TIMESTAMP_H_ */
