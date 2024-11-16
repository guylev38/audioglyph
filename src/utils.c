#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/* 
* char *removeFileExtension(const char *filename)
* Removes the file extension from a given file name 
* and returns the name.
*/

char *removeFileExtension(const char *filename){
	const char *dot = strrchr(filename, '.');

	if(!dot || dot == filename){
		return strdup(filename);
	}

	size_t length = dot - filename;

	char *new_filename = malloc(length + 1);
	if(new_filename == NULL){
		perror("Failed to allocate memory for new filename");
		return NULL;
	}

	strncpy(new_filename, filename, length);
	new_filename[length] = '\0';

	return new_filename;
}
