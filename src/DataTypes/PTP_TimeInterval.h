/*
 * PTP_TimeInterval.h
 *
 *  Created on: Jul 16, 2022
 *      Author: zyh01
 */

#ifndef DATATYPES_PTP_TIMEINTERVAL_H_
#define DATATYPES_PTP_TIMEINTERVAL_H_


// ======================================================
// Includes
// ======================================================

#include <omnetpp.h>

#include <PTP_PrimitiveDataTypes.h>

// ======================================================
// Declarations
// ======================================================

// Time interval, see clause 5.3.2 in IEEE 1588-2008
class cTimeInterval
{
    private:
        Integer64               scaledNanoseconds;              // [ns], scaled by 2^16

    protected:

    public:
        // Constructors
        cTimeInterval();
        cTimeInterval( simtime_t t );
        cTimeInterval( Integer64 scaledNanoseconds );
        cTimeInterval( const cTimeInterval& other );

        // Destructor
        ~cTimeInterval();

        // Setters

        // Getters
        simtime_t       GetSimTime();
        std::string     GetString() const;
        Integer64       GetScaledNanoseconds() const;

        // Operators
        bool            operator== (const cTimeInterval& other);
        bool            operator!= (const cTimeInterval& other);
        bool            operator== (const simtime_t& other);
        bool            operator!= (const simtime_t& other);
        cTimeInterval&  operator= (const cTimeInterval& other);
        cTimeInterval&  operator= (const Integer64 ScaledNanoSeconds);
        cTimeInterval&  operator= (const simtime_t& other);

        const cTimeInterval operator+(const cTimeInterval &other) const;
        const cTimeInterval operator-(const cTimeInterval &other) const;
        const cTimeInterval operator*(const double        d) const;
        const cTimeInterval operator/(const double        d) const;
        const cTimeInterval operator-() const;

        cTimeInterval &operator+=(const cTimeInterval &other);
        cTimeInterval &operator-=(const cTimeInterval &other);
        cTimeInterval &operator*=(const double        d);
        cTimeInterval &operator/=(const double        d);

        friend std::ostream& operator<<(std::ostream& os, const cTimeInterval& o);
};




#endif /* DATATYPES_PTP_TIMEINTERVAL_H_ */
