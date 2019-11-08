#pragma once

#include "common.h"

//MD5 block size
#define MD5_BLOCK_SIZE 64
//MD5 digest size
#define MD5_DIGEST_SIZE 16
//Minimum length of the padding string
#define MD5_MIN_PAD_SIZE 9

typedef struct
{
	union
	{
		uint32_t h[4];
		uint8_t digest[16];
	};
	union
	{
		uint32_t x[16];
		uint8_t buffer[64];
	};
	size_t size;
	uint64_t totalSize;
} Md5Context;

typedef uint32_t uint_t;

//MD5 related functions
error_t md5Compute(const void* data, size_t length, uint8_t* digest);
void md5Init(Md5Context* context);
void md5Update(Md5Context* context, const void* data, size_t length);
void md5Final(Md5Context* context, uint8_t* digest);
void md5FinalRaw(Md5Context* context, uint8_t* digest);
void md5ProcessBlock(Md5Context* context);