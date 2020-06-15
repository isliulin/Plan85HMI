#ifndef TCN_DEF_H
#define TCN_DEF_H

/* ==========================================================================
 *
 *  File      : tcn_def.h
 *
 *  Purpose   : Common Interface Definitions (constants and data types)
 *
 *  Project   : Host Driver Software MD for SERVER2
 *              - TCN Software Architecture (d-000487-nnnnnn)
 *
 *  License   : Duagon Software License (see file 'license.txt')
 *
 * --------------------------------------------------------------------------
 *
 *  (C) COPYRIGHT, duagon AG, CH-8953 Dietikon, Switzerland
 *  All Rights Reserved.
 *
 * ==========================================================================
 */


/* ==========================================================================
 *
 *  Pre-processor Definitions:
 *  --------------------------
 *  - TCN_LE  - required for little-endian CPU, e.g. Intel
 *
 * ==========================================================================
 */


/* ==========================================================================
 *
 *  Include Files
 *
 * ==========================================================================
 */


/* ==========================================================================
 *
 *  Constants
 *
 * ==========================================================================
 */

/* --------------------------------------------------------------------------
 *  NOTE:
 *  The obvious few that compilers may define for you.
 *  But in case they don't:
 * --------------------------------------------------------------------------
 */
#ifndef NULL
#   define NULL     (0)
#endif

#ifndef TRUE
#   define TRUE     (1==1)
#endif

#ifndef FALSE
#   define FALSE    (!TRUE)
#endif


/* ==========================================================================
 *
 *  Data Types
 *
 * ==========================================================================
 */

/* --------------------------------------------------------------------------
 *  Constants for basic data types (8, 16 and 32 bits)
 * --------------------------------------------------------------------------
 */
#ifndef TCN_DEF_BASE_TYPE8
#   define TCN_DEF_BASE_TYPE8   char
#endif
#ifndef TCN_DEF_BASE_TYPE16
#   define TCN_DEF_BASE_TYPE16  short
#endif
#ifndef TCN_DEF_BASE_TYPE32
#   define TCN_DEF_BASE_TYPE32  long
#endif

/* --------------------------------------------------------------------------
 *  Data types with less than 8-bits
 * --------------------------------------------------------------------------
 */
typedef unsigned TCN_DEF_BASE_TYPE8     BOOLEAN1;

/* --------------------------------------------------------------------------
 *  8-bit data types
 * --------------------------------------------------------------------------
 */
typedef unsigned TCN_DEF_BASE_TYPE8     BITSET8;
typedef unsigned TCN_DEF_BASE_TYPE8     WORD8;
typedef unsigned TCN_DEF_BASE_TYPE8     ENUM8;
typedef unsigned TCN_DEF_BASE_TYPE8     UNSIGNED8;
typedef   signed TCN_DEF_BASE_TYPE8     INTEGER8;
typedef          TCN_DEF_BASE_TYPE8     CHARACTER8;

/* --------------------------------------------------------------------------
 *  16-bit data types
 * --------------------------------------------------------------------------
 */
typedef unsigned TCN_DEF_BASE_TYPE16    BITSET16;
typedef unsigned TCN_DEF_BASE_TYPE16    WORD16;
typedef unsigned TCN_DEF_BASE_TYPE16    UNSIGNED16;
typedef   signed TCN_DEF_BASE_TYPE16    INTEGER16;

/* --------------------------------------------------------------------------
 *  32-bit data types
 * --------------------------------------------------------------------------
 */
typedef unsigned TCN_DEF_BASE_TYPE32    BITSET32;
typedef unsigned TCN_DEF_BASE_TYPE32    WORD32;
typedef unsigned TCN_DEF_BASE_TYPE32    UNSIGNED32;
typedef   signed TCN_DEF_BASE_TYPE32    INTEGER32;

/* --------------------------------------------------------------------------
 *  Structured data types
 * --------------------------------------------------------------------------
 */
#define TCN_SIZEOF_STRUCT_STRING32 32
typedef struct
{
    CHARACTER8  character[32];
}   STRING32;


/* ==========================================================================
 *
 *  Macros
 *
 * ==========================================================================
 */

/* --------------------------------------------------------------------------
 *  Macros for declaration of variables and procedures.
 *  NOTE:
 *  extern "C" is used in mixed C/C++ headers to force C linkage on an
 *  external definition.
 * --------------------------------------------------------------------------
 */
#define TCN_DECL_LOCAL      static

#ifdef __cplusplus
#   define TCN_DECL_PUBLIC  extern "C"
#else
#   define TCN_DECL_PUBLIC  extern
#endif

#define TCN_DECL_CONST      const

#define TCN_DECL_VOLATILE   volatile

/* --------------------------------------------------------------------------
 *  Allow creation of procedure-like macros that are a single statement,
 *  and must be followed by a semi-colon.
 * --------------------------------------------------------------------------
 */
#define TCN_MACRO_START         do {
#define TCN_MACRO_END           } while (0)

#define TCN_EMPTY_STATEMENT     TCN_MACRO_START TCN_MACRO_END

#define TCN_UNUSED_PARAMETER(_type_, _name_)    \
    TCN_MACRO_START                             \
        _type_ __tmp1 = (_name_);               \
        _type_ __tmp2 = __tmp1;                 \
        __tmp1 = __tmp2;                        \
    TCN_MACRO_END

/* --------------------------------------------------------------------------
 *  Endian conversion macros
 * --------------------------------------------------------------------------
 */
#define TCN_MACRO_SWAP16(_address_)                                         \
    TCN_MACRO_START                                                         \
        WORD16      _value = *(WORD16*)(_address_);                         \
        WORD8       *_to   = (WORD8*)(_address_);                           \
        WORD8       *_from = (WORD8*)(&_value);                             \
                                                                            \
        _to[0] = _from[1];                                                  \
        _to[1] = _from[0];                                                  \
    TCN_MACRO_END

#define TCN_MACRO_SWAP32(_address_)                                         \
    TCN_MACRO_START                                                         \
        WORD32      _value = *(WORD32*)(_address_);                         \
        WORD8       *_to   = (WORD8*)(_address_);                           \
        WORD8       *_from = (WORD8*)(&_value);                             \
                                                                            \
        _to[0] = _from[3];                                                  \
        _to[1] = _from[2];                                                  \
        _to[2] = _from[1];                                                  \
        _to[3] = _from[0];                                                  \
    TCN_MACRO_END

#ifdef TCN_LE
#   define TCN_MACRO_CONVERT_CPU_TO_BE16(_x_)   TCN_MACRO_SWAP16((_x_))
#   define TCN_MACRO_CONVERT_CPU_TO_BE32(_x_)   TCN_MACRO_SWAP32((_x_))
#   define TCN_MACRO_CONVERT_BE16_TO_CPU(_x_)   TCN_MACRO_SWAP16((_x_))
#   define TCN_MACRO_CONVERT_BE32_TO_CPU(_x_)   TCN_MACRO_SWAP32((_x_))

#   define TCN_MACRO_CONVERT_CPU_TO_LE16(_x_)
#   define TCN_MACRO_CONVERT_CPU_TO_LE32(_x_)
#   define TCN_MACRO_CONVERT_LE16_TO_CPU(_x_)
#   define TCN_MACRO_CONVERT_LE32_TO_CPU(_x_)
#else /* #ifdef TCN_LE */
#   define TCN_MACRO_CONVERT_CPU_TO_BE16(_x_)
#   define TCN_MACRO_CONVERT_CPU_TO_BE32(_x_)
#   define TCN_MACRO_CONVERT_BE16_TO_CPU(_x_)
#   define TCN_MACRO_CONVERT_BE32_TO_CPU(_x_)

#   define TCN_MACRO_CONVERT_CPU_TO_LE16(_x_)   TCN_MACRO_SWAP16((_x_))
#   define TCN_MACRO_CONVERT_CPU_TO_LE32(_x_)   TCN_MACRO_SWAP32((_x_))
#   define TCN_MACRO_CONVERT_LE16_TO_CPU(_x_)   TCN_MACRO_SWAP16((_x_))
#   define TCN_MACRO_CONVERT_LE32_TO_CPU(_x_)   TCN_MACRO_SWAP32((_x_))
#endif /* #else */


#endif /* #ifndef TCN_DEF_H */
