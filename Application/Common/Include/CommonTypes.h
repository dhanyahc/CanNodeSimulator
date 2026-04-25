#ifndef APP_COMMON_TYPES_H
#define APP_COMMON_TYPES_H
/*
 *----------------------------------------------------------------------
 *  CommonTypes.h
 *
 *  Common type defines
 *
 *----------------------------------------------------------------------
 */

/*
 *----------------------------------------------------------------------
 *  File:              CommonTypes.h
 *  Created by:        Dhanyakumar H C (Student ID : 2024HT01096)
 *----------------------------------------------------------------------
 */

/*
 *----------------------------------------------------------------------
 *   Include Files
 *----------------------------------------------------------------------
 */
#include "stm32f1xx_hal.h"

/*
 *----------------------------------------------------------------------
 *   Public Defines
 *----------------------------------------------------------------------
 */
#define MICRO_IS_LITTLE_ENDIAN
#define MAX_FILE_NAME_STRING_SIZE                  (128)
#define GENERIC_STRING_LENGTH_128                  128
#define GENERIC_STRING_LENGTH_255                  255

#define MAC_ADDR_LENGHT                            6
#define IPV4_ADDR_LENGHT                           4
#define IPV6_ADDR_LENGHT                          16


#define MAX_NUMBER_OF_ALARMS                      MAX_PARAM_DATA_LENGTH
#define MAX_NUMBER_OF_ALARMS_BYTES                (MAX_NUMBER_OF_ALARMS / 8)

/*
 *----------------------------------------------------------------------
 *   Public Macros
 *----------------------------------------------------------------------
 */

#define OFFSET_OF(structtype, structmember) /*lint --e(413)*/ (UINT16)((UINT8 *)&(((structtype *)0)->structmember) - (UINT8 *)0)

#define BITMAP_SIZE_TO_BYTES(n)   (((n) + 7) >> 3)

#define MINIMUM(a,b)  ((a < b) ? a : b)
#define MAXIMUM(a,b)  ((a > b) ? a : b)

#ifdef MICRO_IS_LITTLE_ENDIAN
   #define COPY_ENDIAN_CORRECT_16(dest, src)                      \
   {                                                              \
      ((EAUNION16*)&(dest))->u8.h = ((UNION16*)&(src))->u8.h;     \
      ((EAUNION16*)&(dest))->u8.l = ((UNION16*)&(src))->u8.l;     \
   }
#else
   #define COPY_ENDIAN_CORRECT_16(dest, src)                      \
   {                                                              \
         dest = src;                                              \
   }
#endif

#ifdef MICRO_IS_LITTLE_ENDIAN
   #define COPY_ENDIAN_CORRECT_32(dest, src)                      \
   {                                                              \
      ((EAUNION32*)&(dest))->u8.b3 = ((UNION32*)&(src))->u8.b3;   \
      ((EAUNION32*)&(dest))->u8.b2 = ((UNION32*)&(src))->u8.b2;   \
      ((EAUNION32*)&(dest))->u8.b1 = ((UNION32*)&(src))->u8.b1;   \
      ((EAUNION32*)&(dest))->u8.b0 = ((UNION32*)&(src))->u8.b0;   \
   }
#else
   #define COPY_ENDIAN_CORRECT_32(dest, src)                      \
   {                                                              \
         dest = src;                                              \
   }
#endif

/*
 *----------------------------------------------------------------------
 *   Public Data Types
 *----------------------------------------------------------------------
 */
typedef unsigned long int  UINT64;
typedef uint32_t           UINT32;
typedef uint16_t           UINT16;
typedef uint8_t            UINT8;
typedef uint8_t            BOOL;

typedef signed long int    INT64;
typedef int32_t            INT32;
typedef int16_t            INT16;
typedef int8_t             INT8;

typedef float              FLOAT32;
typedef double             DOUBLE;

typedef unsigned char      UCHAR;
typedef signed char        CHAR;
typedef char *             PCHAR;
typedef unsigned char *    PUCHAR;
typedef wchar_t            WUCHAR;
typedef wchar_t *          PWUCHAR;

#ifndef FALSE
#define FALSE 0
#endif

#ifndef TRUE
#define TRUE  1
#endif

#define BITS_PER_BYTE               8

#define STATIC static
#define CONST  const
#define VOID   void
#define EXTERN extern

// exclude following warning
#pragma GCC diagnostic ignored "-Wpointer-sign"             // we are using signed to unsigned conversion so we can ignore this warning and take care signedness in code
#pragma GCC diagnostic ignored "-Wmissing-braces"           // we ',' separated structure so we can ignore missing braces warning
#pragma GCC diagnostic ignored "-Wformat="                  // we  convert UINT16 to UIN32 , INT16 to INT32 formatting in sprint , so we can ignore this
#pragma GCC diagnostic ignored "-Wformat-truncation"        // we are using snprintf to avoid buffer overflow, but we are making sure destination size of enough for formatting


typedef enum t_ParamID
{
   PAR_ID_NONE = 0,
   PAR_ID_TEMPERATURE,
   PAR_ID_TEMPERATURE_SET_POINT,
   PAR_ID_DEV_STATUS,
   PAR_ID_PRESSURE,
   PAR_ID_DUTY_CYCLE,
   PAR_ID_ALARM_BITS,
   PAR_ID_DEV_NAME,


   PAR_ID_MAX

}t_ParamID;


typedef enum t_BitNumber
{
   BIT_0 = 0,
   BIT_1,
   BIT_2,
   BIT_3,
   BIT_4,
   BIT_5,
   BIT_6,
   BIT_7,
   BIT_8,
   BIT_9,
   BIT_10,
   BIT_11,
   BIT_12,
   BIT_13,
   BIT_14,
   BIT_15,
   BIT_16,
   BIT_17,
   BIT_18,
   BIT_19,
   BIT_20,
   BIT_21,
   BIT_22,
   BIT_23,
   BIT_24,
   BIT_25,
   BIT_26,
   BIT_27,
   BIT_28,
   BIT_29,
   BIT_30,
   BIT_31
}t_BitNumber;

typedef enum t_BitField
{
   BIT_MASK       = 0x00000001,
   BIT_FIELD_0    = 0x00000001,
   BIT_FIELD_1    = 0x00000002,
   BIT_FIELD_2    = 0x00000004,
   BIT_FIELD_3    = 0x00000008,
   BIT_FIELD_4    = 0x00000010,
   BIT_FIELD_5    = 0x00000020,
   BIT_FIELD_6    = 0x00000040,
   BIT_FIELD_7    = 0x00000080,
   BIT_FIELD_8    = 0x00000100,
   BIT_FIELD_9    = 0x00000200,
   BIT_FIELD_10   = 0x00000400,
   BIT_FIELD_11   = 0x00000800,
   BIT_FIELD_12   = 0x00001000,
   BIT_FIELD_13   = 0x00002000,
   BIT_FIELD_14   = 0x00004000,
   BIT_FIELD_15   = 0x00008000,
   BIT_FIELD_16   = 0x00010000,
   BIT_FIELD_17   = 0x00020000,
   BIT_FIELD_18   = 0x00040000,
   BIT_FIELD_19   = 0x00080000,
   BIT_FIELD_20   = 0x00100000,
   BIT_FIELD_21   = 0x00200000,
   BIT_FIELD_22   = 0x00400000,
   BIT_FIELD_23   = 0x00800000,
   BIT_FIELD_24   = 0x01000000,
   BIT_FIELD_25   = 0x02000000,
   BIT_FIELD_26   = 0x04000000,
   BIT_FIELD_27   = 0x08000000,
   BIT_FIELD_28   = 0x10000000,
   BIT_FIELD_29   = 0x20000000,
   BIT_FIELD_30   = 0x40000000,
   BIT_FIELD_31   = 0x80000000
}t_BitField;

typedef enum t_ReadWrite
{
   RW_READ = 0,
   RW_WRITE
}t_ReadWrite;

// FREE or BUSY


/* Baud Rate Macro */
typedef enum t_Baudrate
{
   BAUD_9600=0,
   BAUD_14400,
   BAUD_19200,
   BAUD_28800,
   BAUD_38400,
   BAUD_57600,
   BAUD_115200,

   BAUD_MAX
}t_Baudrate;

/* UART Databits Macro */
typedef enum t_Databits
{
   DATABITS_8 = 0,
   DATABITS_9,

   DATABITS_MAX
}t_Databits;


/* UART Parity Macro */
typedef enum t_Parity
{
   PARITY_NONE=0,
   PARITY_EVEN,
   PARITY_ODD,

   PARIT_MAX
}t_Parity;

/* UART Stopbits Macro */
typedef enum t_Stopits
{
   STOPBITS_ONE=0,
   STOPBITS_TWO,

   STOPBITS_MAX
}t_Stopits;

/* Timeout Macro for UART/USART */
typedef enum t_Timeout
{
   TMOUT_MS_500 = 0,

   TMOUT_MAX
}t_Timeout;





typedef enum t_Status
{
   STS_OK  = 0x00,
   STS_ERROR,
   STS_SOCKET_CREATE_MASTER_ERROR,
   STS_SOCKET_INIT_MASTER_FOR_MULTI_CLIENT_ERROR,
   STS_SOCKET_BIND_ERROR,
   STS_SOCKET_LISTEN_ERROR,
   STS_SOCKET_SELECT_ERROR,
   STS_SOCKET_ACCEPT_ERROR,
   STS_ERROR_NO_ELEMENT,
   STS_ERROR_INTERNAL,
   STS_ERROR_TIMEOUT,
   STS_ERROR_CLOCK_INIT,
   STS_ERROR_CLOCK_DE_INIT,
   STS_ERROR_UART_TX,
   STS_ERROR_UART_RX,
   STS_ERROR_WDG_INIT,
   STS_ERROR_MODULENOTDEFINED,
   STS_INVALID_FILENAME,
   STS_DISK_NOT_FOUND,
   STS_FILEREAD_COMPLETE,
   STS_ERROR_FILEMD5MISMATCH,
   STS_ERROR_FILEREAD,
   STS_ERROR_FILECLOSE,
   STS_ERROR_FILENOTFOUND,

   STS_ERROR_WATCHDOG_TASK_INIT,
   STS_ERROR_WATCHDOG_TASK_INIT_TIMEOUT,
   STS_ERROR_WATCHDOG_TASK_TIMER_CREATE_ERRROR,
   STS_ERROR_WATCHDOG_TASK_TIMER_START_ERRROR,
   STS_ERROR_WATCHDOG_TASK_NOT_INITIALIZED,
   STS_ERROR_WATCHDOG_TASK_NULL_PTR,
   STS_ERROR_WATCHDOG_IVALID_MSG_ID,
   STS_ERROR_WATCHDOG_Q_NULL_PTR,
   STS_ERROR_WATCHDOG_INTF_NULL_PTR,
   STS_ERROR_WATCHDOG_TASK_SEND_MSG,

   STS_ERROR_TERMINAL_TASK_INIT,
   STS_ERROR_TERMINAL_TASK_INIT_TIMEOUT,
   STS_ERROR_TERMINAL_TASK_TIMER_CREATE_ERRROR,
   STS_ERROR_TERMINAL_TASK_TIMER_START_ERRROR,
   STS_ERROR_TERMINAL_TASK_NOT_INITIALIZED,
   STS_ERROR_TERMINAL_TASK_NULL_PTR,
   STS_ERROR_TERMINAL_IVALID_MSG_ID,
   STS_ERROR_TERMINAL_Q_NULL_PTR,
   STS_ERROR_TERMINAL_INTF_NULL_PTR,
   STS_ERROR_TERMINAL_TASK_SEND_MSG,

   STS_ERROR_MODBUS_RTU_TASK_INIT,
   STS_ERROR_MODBUS_RTU_TASK_INIT_TIMEOUT,
   STS_ERROR_MODBUS_RTU_TASK_TIMER_CREATE_ERRROR,
   STS_ERROR_MODBUS_RTU_TASK_TIMER_START_ERRROR,
   STS_ERROR_MODBUS_RTU_TASK_NOT_INITIALIZED,
   STS_ERROR_MODBUS_RTU_TASK_NULL_PTR,
   STS_ERROR_MODBUS_RTU_TASK_IVALID_MSG_ID,
   STS_ERROR_MODBUS_RTU_TASK_Q_NULL_PTR,
   STS_ERROR_MODBUS_RTU_TASK_INTF_NULL_PTR,
   STS_ERROR_MODBUS_RTU_TASK_SEND_MSG,
   STS_ERROR_MODBUS_RTU_INVALID_UART_CONFIG,

   STS_ERROR_MQTT_CLIENT_TASK_INIT,
   STS_ERROR_MQTT_CLIENT_TASK_INIT_TIMEOUT,
   STS_ERROR_MQTT_CLIENT_TASK_TIMER_CREATE_ERRROR,
   STS_ERROR_MQTT_CLIENT_TASK_TIMER_START_ERRROR,
   STS_ERROR_MQTT_CLIENT_TASK_NOT_INITIALIZED,
   STS_ERROR_MQTT_CLIENT_TASK_NULL_PTR,
   STS_ERROR_MQTT_CLIENT_TASK_IVALID_MSG_ID,
   STS_ERROR_MQTT_CLIENT_TASK_Q_NULL_PTR,
   STS_ERROR_MQTT_CLIENT_TASK_INTF_NULL_PTR,
   STS_ERROR_MQTT_CLIENT_TASK_SEND_MSG,
   STS_ERROR_MQTT_CLIENT_INVALID_UART_CONFIG,

   STS_ERROR_CANOPEN_TASK_INIT,
   STS_ERROR_CANOPEN_TASK_INIT_TIMEOUT,
   STS_ERROR_CANOPEN_TASK_TIMER_CREATE_ERRROR,
   STS_ERROR_CANOPEN_TASK_TIMER_START_ERRROR,
   STS_ERROR_CANOPEN_TASK_NOT_INITIALIZED,
   STS_ERROR_CANOPEN_TASK_NULL_PTR,
   STS_ERROR_CANOPEN_TASK_IVALID_MSG_ID,
   STS_ERROR_CANOPEN_TASK_Q_NULL_PTR,
   STS_ERROR_CANOPEN_TASK_INTF_NULL_PTR,
   STS_ERROR_CANOPEN_TASK_SEND_MSG,
   STS_ERROR_CANOPEN_INVALID_UART_CONFIG,

   STS_ERROR_SERIAL_ASCII_TASK_INIT,
   STS_ERROR_SERIAL_ASCII_TASK_INIT_TIMEOUT,
   STS_ERROR_SERIAL_ASCII_TASK_TIMER_CREATE_ERRROR,
   STS_ERROR_SERIAL_ASCII_TASK_TIMER_START_ERRROR,
   STS_ERROR_SERIAL_ASCII_TASK_NOT_INITIALIZED,
   STS_ERROR_SERIAL_ASCII_TASK_NULL_PTR,
   STS_ERROR_SERIAL_ASCII_TASK_IVALID_MSG_ID,
   STS_ERROR_SERIAL_ASCII_TASK_Q_NULL_PTR,
   STS_ERROR_SERIAL_ASCII_TASK_INTF_NULL_PTR,
   STS_ERROR_SERIAL_ASCII_TASK_SEND_MSG,
   STS_ERROR_SERIAL_ASCII_INVALID_UART_CONFIG,

   STS_ERROR_ASCII_SERIAL_TASK_INIT,
   STS_ERROR_ASCII_SERIAL_TASK_INIT_TIMEOUT,
   STS_ERROR_ASCII_SERIAL_TASK_TIMER_CREATE_ERRROR,
   STS_ERROR_ASCII_SERIAL_TASK_TIMER_START_ERRROR,
   STS_ERROR_ASCII_SERIAL_TASK_NOT_INITIALIZED,
   STS_ERROR_ASCII_SERIAL_TASK_NULL_PTR,
   STS_ERROR_ASCII_SERIAL_TASK_IVALID_MSG_ID,
   STS_ERROR_ASCII_SERIAL_TASK_Q_NULL_PTR,
   STS_ERROR_ASCII_SERIAL_TASK_INTF_NULL_PTR,
   STS_ERROR_ASCII_SERIAL_TASK_SEND_MSG,
   STS_ERROR_ASCII_SERIAL_INVALID_UART_CONFIG,


   STS_ERROR_WEB_TASK_INIT,
   STS_ERROR_WEB_TASK_INIT_TIMEOUT,
   STS_ERROR_WEB_TASK_TIMER_CREATE_ERRROR,
   STS_ERROR_WEB_TASK_TIMER_START_ERRROR,
   STS_ERROR_WEB_TASK_NOT_INITIALIZED,
   STS_ERROR_WEB_TASK_NULL_PTR,
   STS_ERROR_WEB_TASK_IVALID_MSG_ID,
   STS_ERROR_WEB_TASK_Q_NULL_PTR,
   STS_ERROR_WEB_TASK_INTF_NULL_PTR,
   STS_ERROR_WEB_TASK_SEND_MSG,

   STS_MODBUS_EXCEPTION_ILLEGAL_FUNCTION,
   STS_MODBUS_EXCEPTION_ILLEGAL_DATA_ADDRESS,
   STS_MODBUS_EXCEPTION_ILLEGAL_DATA_VALUE,
   STS_MODBUS_EXCEPTION_SLAVE_DEVICE_FAILURE,
   STS_MODBUS_EXCEPTION_ACKNOWLEDGE,
   STS_MODBUS_EXCEPTION_SLAVE_BUSY,
   STS_MODBUS_EXCEPTION_NEGATIVE_ACKNOWLEDGE,
   STS_MODBUS_EXCEPTION_MEMORY_PARITY_ERROR,
   STS_MODBUS_EXCEPTION_GATEWAY_PATH_FAILED,
   STS_MODBUS_EXCEPTION_GATEWAY_TGT_FAILED,

   STS_FORMAT_ERROR,
   STS_BLANK_ERROR,
   STS_FLOAT_DECIMAL_POINT_FORMAT_ERROR,
   STS_COMMNUNICATION_ERROR,
   STS_NULL_POINTER,
   STS_INVALID_RANGE,
   STS_INVALID_PARAM,
   STS_PARAM_NOT_SUPPORTED,
   STS_INVALID_MODE,

   STS_ABORTED,
   STS_FAILED_TO_CREATE_TIMER,
   STS_QUEUE_IS_NOT_CREATED,
   STS_MSG_QUEUE_FULL,
   STS_MSG_QUEUE_EMPTY,
   STS_MEMORY_ALLOC_FAILURE,
   STS_INVALID_IO_EXP_ADDRESS,
   STS_IO_EXP_TIMEOUT,
   STS_IO_EXP_BUSY,
   STS_IO_EXP_ERROR,
   STS_IO_EXP_WRITE_ERROR,
   STS_IO_EXP_READ_ERROR,
   STS_ERROR_FILE_NOT_FOUND,
   STS_ERROR_FILE_CREATE,
   STS_ERROR_FILE_DELETE,
   STS_ERROR_FILE_OPEN,
   STS_ERROR_FILE_READ,
   STS_ERROR_FILE_WRITE,
   STS_ERROR_FILE_CHECKSUM,
   STS_ERROR_DIR_OPEN,
   STS_ERROR_DIR_NOT_FOUND,
   STS_ERROR_DIR_CREATE,
   STS_ERROR_DIR_READ,
   STS_ERROR_DIR_WRITE,
   STS_ERROR_DIR_DELETE,
   STS_ERROR_CHANGE_DIR,
   STS_ERROR_RNG_MODULE_INIT,
   STS_ERROR_RNG_RANDOM_NUM_GEN,
   STS_ERROR_CYCLONE_YARROW_INIT,
   STS_ERROR_CYCLONE_YARROW_SEED,
   STS_ERROR_CYCLONE_NET_CARD_INIT,
   STS_ERROR_CYCLONE_NET_CONFIGURE_INIT,
   STS_ERROR_CYCLONE_TLS_SESSION_CACHE,
   STS_ERROR_CYCLONE_DHCP_INIT,
   STS_ERROR_CYCLONE_DHCP_START,
   STS_ERROR_CYCLONE_SLAAC_INIT,
   STS_ERROR_CYCLONE_SLAAC_START,
   STS_ERROR_CYCLONE_HTTPS_INIT,
   STS_ERROR_CYCLONE_HTTPS_START,
   STS_ERROR_CYCLONE_FTPS_INIT,
   STS_ERROR_CYCLONE_FTPS_START,
   STS_ERROR_CYCLONE_SNTP_INIT,
   STS_ERROR_CYCLONE_SNTP_SET_TIMEOUT,
   STS_ERROR_CYCLONE_SNTP_SERVER_NAME,
   STS_ERROR_CYCLONE_SNTP_SET_SERVER_IP,
   STS_ERROR_CYCLONE_SNTP_REQUEST_REJECTED,
   STS_ERROR_CYCLONE_SNTP_GET_TIME_STAMP,
   STS_ERROR_CYCLONE_SMODBUSS_INIT,
   STS_ERROR_CYCLONE_SMODBUSS_START,
   STS_ERROR_CYCLONE_TELNET_INIT,
   STS_ERROR_CYCLONE_TELNET_START,

   STS_UNKNOWNHAL_ERROR,
}t_Status;






/************************************************************************/
/* Variable type definition                                             */
/************************************************************************/


typedef union
{
   UINT16   u16;
   UINT16   uw;
   INT16    s16;

   UINT8    b[2];
   INT8     sb[2];
   char     c[2];

   struct
   {
     UINT8 h;
     UINT8 l;
   } u8;

   struct
   {
     INT8 h;
     INT8 l;
   } s8;
}UNION16_BE;



typedef union
{
   UINT16   u16;
   UINT16   uw;
   INT16    s16;

   UINT8    b[2];
   INT8     sb[2];
   char     c[2];

   struct
   {
     UINT8 l;
     UINT8 h;
   } u8;

   struct
   {
     INT8 l;
     INT8 h;
   } s8;
} UNION16_LE;


typedef union
{
   UINT32   u32;
   UINT32   ul;
   INT32    s32;

   struct
   {
      UNION16_BE h;
      UNION16_BE l;
   } w;

   struct
   {
     UINT16 h;
     UINT16 l;
   } u16;

   struct
   {
     INT16 h;
     INT16 l;
   } s16;

   UINT8    b[4];
   INT8    sb[4];
   char     c[4];

   struct
   {
      UINT8 b3;
      UINT8 b2;
      UINT8 b1;
      UINT8 b0;
   } u8, ub;

   struct
   {
      INT8 b3;
      INT8 b2;
      INT8 b1;
      INT8 b0;
   } s8;
} UNION32_BE;

typedef union
{
   UINT32   u32;
   UINT32   ul;
   INT32    s32;

   struct
   {
     UNION16_LE   h;
     UNION16_LE   l;
   } w;

   struct
   {
     UINT16 l;
     UINT16 h;
   } u16;

   struct
   {
     INT16  l;
     INT16  h;
   } s16;

   UINT8    b[4];
   INT8     sb[4];
   char     c[4];

   struct
   {
      UINT8 b0;
      UINT8 b1;
      UINT8 b2;
      UINT8 b3;
   } u8, ub;

   struct
   {
      INT8 b0;
      INT8 b1;
      INT8 b2;
      INT8 b3;
   } s8;
} UNION32_LE;


#ifdef MICRO_IS_LITTLE_ENDIAN
typedef UNION32_LE   UNION32;
typedef UNION16_LE   UNION16;
#else
typedef UNION32_BE   UNION32;
typedef UNION16_BE   UNION16;
#endif

typedef enum t_Protocol
{
	MODBUS = 0,
	CAN,
	SERAIL_ASCII,

	PROTOCOL_MAX
}t_Protocol;

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



#endif //APP_COMMON_TYPES_H
/*
 *  End of file
 */


