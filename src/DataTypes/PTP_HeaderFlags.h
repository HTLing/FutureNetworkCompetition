/*
 * PTP_HeaderFlags.h
 *
 *  Created on: Jul 15, 2022
 *      Author: zyh01
 */

#ifndef DATATYPES_PTP_HEADERFLAGS_H_
#define DATATYPES_PTP_HEADERFLAGS_H_

// ======================================================
// Includes
// ======================================================

#include "PTP_PrimitiveDataTypes.h"
#include "PTP_Constants.h"
#include "PTP_ByteBuffers.h"

// ======================================================
// Declarations
// ======================================================

class cPtpHeaderFlags
{
    public:

        Boolean alternateMasterFlag;
        Boolean twoStepFlag;
        Boolean unicastFlag;
        Boolean ptpProfileSpecific_1;
        Boolean ptpProfileSpecific_2;
        Boolean reserved;
        Boolean leap61;
        Boolean leap59;
        Boolean currentUtcOffsetValid;
        Boolean ptpTimescale;
        Boolean timeTraceable;
        Boolean frequencyTraceable;

        // Constructors/Destructor
        cPtpHeaderFlags();
        cPtpHeaderFlags( const Octet flagField[] );
        cPtpHeaderFlags( const cPtpHeaderFlags& other );
        ~cPtpHeaderFlags();

        // Setters
        void    ReadFromBuffer( const Octet flagField[] );

        // Getters
        void    SaveToBuffer( Octet flagField[] );

        // Operators
        bool                operator== (const cPtpHeaderFlags& other)    const;
        bool                operator!= (const cPtpHeaderFlags& other)    const;
        cPtpHeaderFlags&    operator=  (const cPtpHeaderFlags& other);

        friend std::ostream& operator<<(std::ostream& os, const cPtpHeaderFlags& o);

        // Debug functions
        void            Print()     const;
        std::string     GetString() const;
};





#endif /* DATATYPES_PTP_HEADERFLAGS_H_ */
