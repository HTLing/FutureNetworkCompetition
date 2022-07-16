/*
 * PTP_Constants.h
 *
 *  Created on: Jul 15, 2022
 *      Author: zyh01
 */

#ifndef DATATYPES_INCLUDES_PTP_CONSTANTS_H_
#define DATATYPES_INCLUDES_PTP_CONSTANTS_H_


#define PTP_CLOCK_IDENTITY_SIZE             8                           // Length of Clock Identity array
#define PTP_DEFAULT_PHASE_CHANGE_RATE       0x7FFFFFFF                  //
#define PTP_UTC_OFFSET_2006                 33                          // [s]
#define PTP_VERSION_IEEE_1588_2008          2                           // Version number of IEEE 1588-2008

#define PTP_MSG_ANNOUNCE_LEN                64                          // Message lengths as given in 13
#define PTP_MSG_SYNC_LEN                    44                          //
#define PTP_MSG_FOLLOW_UP_LEN               44                          //
#define PTP_MSG_DEL_REQ_LEN                 44                          //
#define PTP_MSG_DEL_RESP_LEN                54                          //
#define PTP_MSG_PDEL_REQ_LEN                54                          //
#define PTP_MSG_PDEL_RESP_LEN               54                          //
#define PTP_MSG_PDEL_RESP_FU_LEN            54                          //


#define PTP_FOREIGN_MASTER_TIME_WINDOW      4                           // [announceInterval], 9.3.2.4.4
#define PTP_FOREIGN_MASTER_THRESHOLD        2                           // [announce messages], 9.3.2.4.4

#define PTP_LOG_MSG_INTVL_DELAY_REQ         0x7F                        // Table 24
#define PTP_LOG_MSG_INTVL_SIGNALING         0x7F                        //
#define PTP_LOG_MSG_INTVL_MANAGEMENT        0x7F                        //
#define PTP_LOG_MSG_INTVL_PDELAY_REQ        0x7F                        //
#define PTP_LOG_MSG_INTVL_PDELAY_RESP       0x7F                        //
#define PTP_LOG_MSG_INTVL_PDELAY_RESP_FU    0x7F                        //

#define PTP_MSG_CTRL_SYNC                   0x00                        // Table 23
#define PTP_MSG_CTRL_DEL_REQ                0x01                        //
#define PTP_MSG_CTRL_FOLLOW_UP              0x02                        //
#define PTP_MSG_CTRL_DEL_RESP               0x03                        //
#define PTP_MSG_CTRL_MGMT                   0x04                        //
#define PTP_MSG_CTRL_OTHERS                 0x05


#endif /* DATATYPES_INCLUDES_PTP_CONSTANTS_H_ */
