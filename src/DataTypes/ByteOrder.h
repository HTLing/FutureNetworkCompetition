/*
 * ByteOrder.h
 *
 *  Created on: Jul 16, 2022
 *      Author: zyh01
 */

#ifndef DATATYPES_BYTEORDER_H_
#define DATATYPES_BYTEORDER_H_


// ======================================================
// Includes
// ======================================================

#include "PTP_PrimitiveDataTypes.h"

#include <cstddef>

// ======================================================
// Declarations
// ======================================================

UInteger16  NetToHostUI16( UInteger16 UInt16 );
UInteger32  NetToHostUI32( UInteger32 UInt32 );
Integer16   NetToHostI16 ( Integer16  Int16  );
Integer32   NetToHostI32 ( Integer32  Int32  );
Integer64   NetToHostI64 ( Integer64  Int64  );

UInteger48  BufToHostUI48( Octet Buf[], size_t BufSize );

UInteger16  HostToNetUI16( UInteger16 UInt16 );
UInteger32  HostToNetUI32( UInteger32 UInt32 );
Integer16   HostToNetI16 ( Integer16  Int16  );
Integer32   HostToNetI32 ( Integer32  Int32  );
Integer64   HostToNetI64 ( Integer64  Int64  );

void        HostToBufUI48( UInteger48 UInt48, Octet Buf[], size_t BufSize );


#endif /* DATATYPES_BYTEORDER_H_ */
