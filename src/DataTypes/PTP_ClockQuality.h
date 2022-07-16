/*
 * PTP_ClockQuality.h
 *
 *  Created on: Jul 16, 2022
 *      Author: zyh01
 */

#ifndef DATATYPES_PTP_CLOCKQUALITY_H_
#define DATATYPES_PTP_CLOCKQUALITY_H_

// ======================================================
// Includes
// ======================================================

#include <string>

#include "PTP_PrimitiveDataTypes.h"
#include "PTP_ByteBuffers.h"

// ======================================================
// Declarations
// ======================================================

// Clock quality, see clause 5.3.7 and 8.2.1.3.1 in IEEE 1588-2008
class cClockQuality
{
    private:

        ClockClass_t            clockClass;                     //
        clockAccuracy_t         clockAccuracy;                  //
        UInteger16              offsetScaledLogVariance;        //

    protected:

    public:

        // Constructors
        cClockQuality();
        cClockQuality(  ClockClass_t        clockClass,
                        clockAccuracy_t     clockAccuracy,
                        UInteger16          offsetScaledLogVariance);
        cClockQuality(  BufPtpClockQual_t   *pBuf );
        cClockQuality( const cClockQuality& other );
        ~cClockQuality();

        // Setters
        void    SetClockClass           ( ClockClass_t      clockClass              );
        void    SetClockAccuracy        ( clockAccuracy_t   clockAccuracy           );
        void    SetOffsetScaledLogVar   ( UInteger16        offsetScaledLogVariance );

        void    ReadFromBuffer( BufPtpClockQual_t *pBuf );

        // Getters
        ClockClass_t        GetClockClass()         const;
        clockAccuracy_t     GetClockAccuracy()      const;
        UInteger16          GetOffsetScaledLogVar() const;

        void                SaveToBuffer( BufPtpClockQual_t *pBuf ) const;

        // API functions
        uint64_t    GetUInt64();

        // Operators
        bool            operator== (const cClockQuality& other) const;
        cClockQuality   &operator= (const cClockQuality& other);

        friend std::ostream& operator<<(std::ostream& os, const cClockQuality& o);

        // Debug functions
        void            Print();
        std::string     GetString();
};




#endif /* DATATYPES_PTP_CLOCKQUALITY_H_ */
