#include "main.h"
#include "my_string.h"

void my_memcpy(void *dest, void *src, uint32_t len)
{
	uint8_t *pdest;
	uint8_t *psrc;
	while(len--) {
		*pdest = *psrc;
		psrc++;
		pdest++;
	}
}

void my_memset(void *dest, uint8_t val, uint32_t len)
{
	uint8_t *p = (uint8_t *)dest;
	while(len--) {
		*p++ = val;
	}
}
