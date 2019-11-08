#include "common.h"


void calc_digest(uint8_t* data, size_t length, uint8_t* digest) {
	error_t r = md5Compute(data, length,digest);
}