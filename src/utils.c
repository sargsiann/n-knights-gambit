#include "nkg.h"

void* safe_malloc(size_t size) 
{
	void* ptr = malloc(size);
	if (ptr == NULL) {
		exit_error("Memory allocation failed\n");	
	}
	return ptr;
}

void	exit_error(char *str)
{
	fprintf(stderr,"%s",str);
	exit(1);
}
