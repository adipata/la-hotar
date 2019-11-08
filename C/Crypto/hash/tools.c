#pragma once

#include "common.h"

void* osAllocMem(size_t size)
{
	//Allocate a memory block
	return malloc(size);
}

void osFreeMem(void* p)
{
	//Free memory block
	free(p);
}