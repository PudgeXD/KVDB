#include <stdint.h>
#include <stdio.h>
#include "string.h"
#include "Buffer.h"
const uint64_t DEFAULT_INIT_HT_SIZE = 30;
const uint32_t DB_COUNT = 16;
typedef <Object*,Object*> ObjPair;
typedef <uint64_t,uint64_t> LongPair;

bool malloc_error() {
	cout << "new error: can't allocate more memory" <<endl;
	return false;
}

void* allocate(uint64_t size) {
	char* ptr = new char[size];
	return (void*)ptr;
}