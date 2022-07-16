/*
 * LocalTimeStamp.h
 *
 *  Created on: Jul 15, 2022
 *      Author: zyh01
 */

#ifndef DATATYPES_LOCALTIMESTAMP_H_
#define DATATYPES_LOCALTIMESTAMP_H_

#include <omnetpp.h>

class cLocalTimeStamp
{
    private:

        // Resources
        uint64_t    EpochID;
        simtime_t   Time;

    public:

        // Constructor
        cLocalTimeStamp();
        cLocalTimeStamp(uint64_t EpochID, simtime_t Time);
        cLocalTimeStamp( const cLocalTimeStamp &other );
        ~cLocalTimeStamp();

        // Getters
        uint64_t  GetEpochID() const;
        simtime_t GetTime() const;

        // Setters

        // Operators
        bool    operator== (const cLocalTimeStamp& other) const;
        cLocalTimeStamp& operator=( const cLocalTimeStamp& other );
        simtime_t operator-( const cLocalTimeStamp& other );
};

// ------------------------------------------------------
// Stream operators
// ------------------------------------------------------
std::ostream&   operator<<(std::ostream& os, const cLocalTimeStamp& o );





#endif /* DATATYPES_LOCALTIMESTAMP_H_ */
