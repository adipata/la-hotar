#pragma once

#include "common.h"

#define cryptoAllocMem(size) osAllocMem(size)
#define cryptoFreeMem(p) osFreeMem(p)
#define cryptoMemcpy(dest, src, length) (void) memcpy(dest, src, length)

void* osAllocMem(size_t size);
void osFreeMem(void* p);

#define MIN(a, b) ((a) < (b) ? (a) : (b))

//Host byte order to little-endian byte order
#define HTOLE16(value) (value)
#define HTOLE32(value) (value)
#define HTOLE64(value) (value)
#define htole16(value) ((uint16_t) (value))
#define htole32(value) ((uint32_t) (value))
#define htole64(value) ((uint64_t) (value))

//Little-endian byte order to host byte order
#define LETOH16(value) (value)
#define LETOH32(value) (value)
#define LETOH64(value) (value)
#define letoh16(value) ((uint16_t) (value))
#define letoh32(value) ((uint32_t) (value))
#define letoh64(value) ((uint64_t) (value))

//Rotate left operation
#define ROL8(a, n) (((a) << (n)) | ((a) >> (8 - (n))))
#define ROL16(a, n) (((a) << (n)) | ((a) >> (16 - (n))))
#define ROL32(a, n) (((a) << (n)) | ((a) >> (32 - (n))))
#define ROL64(a, n) (((a) << (n)) | ((a) >> (64 - (n))))

//Rotate right operation
#define ROR8(a, n) (((a) >> (n)) | ((a) << (8 - (n))))
#define ROR16(a, n) (((a) >> (n)) | ((a) << (16 - (n))))
#define ROR32(a, n) (((a) >> (n)) | ((a) << (32 - (n))))
#define ROR64(a, n) (((a) >> (n)) | ((a) << (64 - (n))))

//Shift left operation
#define SHL8(a, n) ((a) << (n))
#define SHL16(a, n) ((a) << (n))
#define SHL32(a, n) ((a) << (n))
#define SHL64(a, n) ((a) << (n))

//Shift right operation
#define SHR8(a, n) ((a) >> (n))
#define SHR16(a, n) ((a) >> (n))
#define SHR32(a, n) ((a) >> (n))
#define SHR64(a, n) ((a) >> (n))

//Micellaneous macros
#define _U8(x) ((uint8_t) (x))
#define _U16(x) ((uint16_t) (x))
#define _U32(x) ((uint32_t) (x))
#define _U64(x) ((uint64_t) (x))

//Test if a 8-bit integer is zero
#define CRYPTO_TEST_Z_8(a) \
   _U8((_U8((_U8(a) | (~_U8(a) + 1U))) >> 7U) ^ 1U)

//Test if a 8-bit integer is nonzero
#define CRYPTO_TEST_NZ_8(a) \
   _U8(_U8((_U8(a) | (~_U8(a) + 1U))) >> 7U)

//Test if two 8-bit integers are equal
#define CRYPTO_TEST_EQ_8(a, b) \
   _U8((_U8(((_U8(a) ^ _U8(b)) | (~(_U8(a) ^ _U8(b)) + 1U))) >> 7U) ^ 1U)

//Test if two 8-bit integers are not equal
#define CRYPTO_TEST_NEQ_8(a, b) \
   _U8(_U8(((_U8(a) ^ _U8(b)) | (~(_U8(a) ^ _U8(b)) + 1U))) >> 7U)

//Test if a 8-bit integer is lower than another 8-bit integer
#define CRYPTO_TEST_LT_8(a, b) \
   _U8(_U8((((_U8(a) - _U8(b)) ^ _U8(b)) | (_U8(a) ^ _U8(b))) ^ _U8(a)) >> 7U)

//Test if a 8-bit integer is lower or equal than another 8-bit integer
#define CRYPTO_TEST_LTE_8(a, b) \
   _U8((_U8((((_U8(b) - _U8(a)) ^ _U8(a)) | (_U8(a) ^ _U8(b))) ^ _U8(b)) >> 7U) ^ 1U)

//Test if a 8-bit integer is greater than another 8-bit integer
#define CRYPTO_TEST_GT_8(a, b) \
   _U8(_U8((((_U8(b) - _U8(a)) ^ _U8(a)) | (_U8(a) ^ _U8(b))) ^ _U8(b)) >> 7U)

//Test if a 8-bit integer is greater or equal than another 8-bit integer
#define CRYPTO_TEST_GTE_8(a, b) \
   _U8((_U8((((_U8(a) - _U8(b)) ^ _U8(b)) | (_U8(a) ^ _U8(b))) ^ _U8(a)) >> 7U) ^ 1U)

//Select between two 8-bit integers
#define CRYPTO_SELECT_8(a, b, c) \
   _U8((_U8(a) & (_U8(c) - 1U)) | (_U8(b) & ~(_U8(c) - 1U)))

//Test if a 16-bit integer is zero
#define CRYPTO_TEST_Z_16(a) \
   _U16((_U16((_U16(a) | (~_U16(a) + 1U))) >> 15U) ^ 1U)

//Test if a 16-bit integer is nonzero
#define CRYPTO_TEST_NZ_16(a) \
   _U16(_U16((_U16(a) | (~_U16(a) + 1U))) >> 15U)

//Test if two 16-bit integers are equal
#define CRYPTO_TEST_EQ_16(a, b) \
   _U16((_U16(((_U16(a) ^ _U16(b)) | (~(_U16(a) ^ _U16(b)) + 1U))) >> 15U) ^ 1U)

//Test if two 16-bit integers are not equal
#define CRYPTO_TEST_NEQ_16(a, b) \
   _U16(_U16(((_U16(a) ^ _U16(b)) | (~(_U16(a) ^ _U16(b)) + 1U))) >> 15U)

//Test if a 16-bit integer is lower than another 16-bit integer
#define CRYPTO_TEST_LT_16(a, b) \
   _U16(_U16((((_U16(a) - _U16(b)) ^ _U16(b)) | (_U16(a) ^ _U16(b))) ^ _U16(a)) >> 15U)

//Test if a 16-bit integer is lower or equal than another 16-bit integer
#define CRYPTO_TEST_LTE_16(a, b) \
   _U16((_U16((((_U16(b) - _U16(a)) ^ _U16(a)) | (_U16(a) ^ _U16(b))) ^ _U16(b)) >> 15U) ^ 1U)

//Test if a 16-bit integer is greater than another 16-bit integer
#define CRYPTO_TEST_GT_16(a, b) \
   _U16(_U16((((_U16(b) - _U16(a)) ^ _U16(a)) | (_U16(a) ^ _U16(b))) ^ _U16(b)) >> 15U)

//Test if a 16-bit integer is greater or equal than another 16-bit integer
#define CRYPTO_TEST_GTE_16(a, b) \
   _U16((_U16((((_U16(a) - _U16(b)) ^ _U16(b)) | (_U16(a) ^ _U16(b))) ^ _U16(a)) >> 15U) ^ 1U)

//Select between two 16-bit integers
#define CRYPTO_SELECT_16(a, b, c) \
   _U16((_U16(a) & (_U16(c) - 1U)) | (_U16(b) & ~(_U16(c) - 1U)))

//Test if a 32-bit integer is zero
#define CRYPTO_TEST_Z_32(a) \
   _U32((_U32((_U32(a) | (~_U32(a) + 1U))) >> 31U) ^ 1U)

//Test if a 32-bit integer is nonzero
#define CRYPTO_TEST_NZ_32(a) \
   _U32(_U32((_U32(a) | (~_U32(a) + 1U))) >> 31U)

//Test if two 32-bit integers are equal
#define CRYPTO_TEST_EQ_32(a, b) \
   _U32((_U32(((_U32(a) ^ _U32(b)) | (~(_U32(a) ^ _U32(b)) + 1U))) >> 31U) ^ 1U)

//Test if two 32-bit integers are not equal
#define CRYPTO_TEST_NEQ_32(a, b) \
   _U32(_U32(((_U32(a) ^ _U32(b)) | (~(_U32(a) ^ _U32(b)) + 1U))) >> 31U)

//Test if a 32-bit integer is lower than another 32-bit integer
#define CRYPTO_TEST_LT_32(a, b) \
   _U32(_U32((((_U32(a) - _U32(b)) ^ _U32(b)) | (_U32(a) ^ _U32(b))) ^ _U32(a)) >> 31U)

//Test if a 32-bit integer is lower or equal than another 32-bit integer
#define CRYPTO_TEST_LTE_32(a, b) \
   _U32((_U32((((_U32(b) - _U32(a)) ^ _U32(a)) | (_U32(a) ^ _U32(b))) ^ _U32(b)) >> 31U) ^ 1U)

//Test if a 32-bit integer is greater than another 32-bit integer
#define CRYPTO_TEST_GT_32(a, b) \
   _U32(_U32((((_U32(b) - _U32(a)) ^ _U32(a)) | (_U32(a) ^ _U32(b))) ^ _U32(b)) >> 31U)

//Test if a 32-bit integer is greater or equal than another 32-bit integer
#define CRYPTO_TEST_GTE_32(a, b) \
   _U32((_U32((((_U32(a) - _U32(b)) ^ _U32(b)) | (_U32(a) ^ _U32(b))) ^ _U32(a)) >> 31U) ^ 1U)

//Select between two 32-bit integers
#define CRYPTO_SELECT_32(a, b, c) \
   _U32((_U32(a) & (_U32(c) - 1U)) | (_U32(b) & ~(_U32(c) - 1U)))

//Select between two 64-bit integers
#define CRYPTO_SELECT_64(a, b, c) \
   _U64((_U64(a) & (_U64(c) - 1U)) | (_U64(b) & ~(_U64(c) - 1U)))