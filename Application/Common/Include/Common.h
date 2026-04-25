#ifndef APP_COMMON_H
#define APP_COMMON_H
/*
 *----------------------------------------------------------------------
 *  Common.h
 *
 *  Header file for application common sources
 *
 *
 *----------------------------------------------------------------------
 */

/*
 *----------------------------------------------------------------------
 *  File:              Common.h
 *  Created by:        Dhanyakumar H C (Student ID : 2024HT01096)
 *----------------------------------------------------------------------
 */

/*
 *----------------------------------------------------------------------
 *   Include Files
 *----------------------------------------------------------------------
 */
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <wchar.h>
#include <math.h>
#include <Time.h>
#include <ctype.h>
#include "CommonTypes.h"
#include "main.h"
#include "can.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"



/*
 *----------------------------------------------------------------------
 *   Public Defines
 *----------------------------------------------------------------------
 */


/*
 *----------------------------------------------------------------------
 *   Public Macros
 *----------------------------------------------------------------------
 */

#define USE(value)                              (void)value;

#define MAX_PARAM_DATA_LENGHT                    32
#define MAX_STRING_PARAM_LENGHT                 (MAX_PARAM_DATA_LENGHT-1)


extern UINT32 __SRAM_START;
extern UINT32 __SRAM_SIZE;



#define BYTE_SWAP_16_BIT(x)             __bswap16(x)
#define BYTE_SWAP_32_BIT(x)             __bswap32(x)


/*
 *----------------------------------------------------------------------
 *   Boot loader address and information
 *----------------------------------------------------------------------
 */

/*
 *----------------------------------------------------------------------
 *   LED - PWM and GPIO PIN mapping
 *----------------------------------------------------------------------
 */


/*
 *----------------------------------------------------------------------
 *   VALVE - PWM and GPIO PIN mapping
 *----------------------------------------------------------------------
 */



/*
 *----------------------------------------------------------------------
 *   SPI -  Signal GPIO PIN mapping
 *----------------------------------------------------------------------
 */



/*
 *----------------------------------------------------------------------
 *   POWER CONTROL GPIO PIN mapping
 *----------------------------------------------------------------------
 */


/*
 *----------------------------------------------------------------------
 *   HARDWARE REV GPIO PIN mapping
 *----------------------------------------------------------------------
 */



/*
 *----------------------------------------------------------------------
 *   Public Data Types
 *----------------------------------------------------------------------
 */





struct t_VersionInfoType
{
   UINT8 VersionMajor;
   UINT8 VersionMinor;
   UINT8 VersionRivision;
} __attribute__((__packed__));;

typedef struct t_VersionInfoType t_VersionInfoType;



typedef t_Status (*pt2Function)(void* pData);


union t_PARAM_VAR_TYPE
{
   FLOAT32  f_Val;                    // 4 bytes
   UINT32   u32_Val;                  // 4 bytes
   INT32    i32_Val;                  // 4 bytes
   UINT16   u16_Val;                  // 2 bytes
   INT16    i16_Val;                  // 2 bytes
   UINT8    u8_Val;                   // 1 byte
   INT8     i8_Val;                   // 1 byte
   CHAR     char_Val;                 // 1 byte
   UCHAR    uchar_Val;                // 1 byte

   // string type
   CHAR     char_String[MAX_STRING_PARAM_LENGHT];
   UINT8    dataArray[MAX_PARAM_DATA_LENGHT];
} __attribute__((packed));                //-------------
//                              Total Size  4 bytes
typedef union t_PARAM_VAR_TYPE t_PARAM_VAR_TYPE, *t_PARAM_VAR_PTR_TYPE;


typedef enum t_ParamDataType
{
   PDT_INT8 = 0,
   PDT_UINT8,
   PDT_CHAR,
   PDT_UCHAR,
   PDT_INT16,
   PDT_UINT16,
   PDT_INT32,
   PDT_UINT32,
   PDT_FLOAT,
   PDT_STRING,

   PDT_UNKNOWN
}t_ParamDataType;


typedef enum t_ParamAcessType
{
   PAT_READ = 0,
   PAT_WRITE,

   PAT_MAX,
}t_ParamAcessType;

/*
 *----------------------------------------------------------------------
 *   Public Variables (extern)
 *----------------------------------------------------------------------
 */


/*
 *----------------------------------------------------------------------
 *   Public Constants (extern)
 *----------------------------------------------------------------------
 */

/*
 *----------------------------------------------------------------------
 *   Public Function Prototypes (extern)
 *----------------------------------------------------------------------
 */
void MX_GPIO_Init(void);
void AppDelay(UINT32 MilliSec);

t_Status SystemClock_Config(void);
UINT8 Checksum_8BIT(UINT8 *pBuffer, UINT32 Size);
UINT16 CalculateChecksum_Fletcher16(UINT8 *pData, UINT16 Count);
UINT32 CalculateChecksum_Fletcher32(const UINT16 *pData, UINT32 Count);
UINT16 CountBitInbytes(void *pBuff, UINT16 NoOfBytes);
UCHAR *TrimWhiteSpaceInString(UCHAR *str);
void ExtractSubString(UCHAR *pInput, UCHAR *pOutput, UCHAR StartChar, UCHAR EndChar, UINT16 BuffSize);
BOOL StringToMacAddress(const CHAR *pMacAddress, UINT8* values);
BOOL StringToIPv4Address(const CHAR *pIPv4Address, UINT8* pValues);
BOOL IPv4AddressToString(const UINT8* pValues, CHAR *pIPv4Address, UINT8 BuffSize);
BOOL IPv6AddressToString(const UINT16* pValues, CHAR *pIPv6Address, UINT8 BuffSize);
BOOL MacAddressToString(const UINT8* pValues, CHAR *pMacAddress, UINT8 BuffSize);
const CHAR* GetProtocolString(t_Protocol Protocol);
const CHAR* GetAccessString(t_ParamAcessType access);
const CHAR* GetDataTypeString(t_ParamDataType datatype);
const CHAR* GetParameterNameString(UINT16 ParamID, t_Protocol Protocol);
UINT16  GetParameterIDFromString(const CHAR *pParameterName, t_Protocol Protocol);

t_Status GetProtocolIDandAddressFromString(const CHAR *pDeviceString, t_Protocol *pProtocol, UINT16 *pAddress);

#endif //APP_COMMON_H
/*
 *  End of file
 */

