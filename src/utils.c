#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "utils.h"

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

void formatTimeElapsed(char *buffer, float timePlayed){
	int minutesElapsed = (int)(timePlayed / 60);
	int secondsElapsed = (int)(timePlayed) % 60;
	sprintf(buffer, "%d:%02d", minutesElapsed, secondsElapsed);
}
void formatTrackLength(char *buffer, float trackLength){
	int minutesLength = (int)(trackLength / 60);
	int secondsLength = (int)(trackLength) % 60;
	sprintf(buffer, "%d:%02d", minutesLength, secondsLength);
}

