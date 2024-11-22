#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/stat.h>
#include "utils.h"
#include "raylib.h"

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

int fileExists(const char *filepath){
	struct stat buffer;
	return (stat(filepath, &buffer) == 0);
}

char *getCoverFileName(const char *dirPath){
	const char *pngPath = TextFormat("%s/%s", dirPath, "cover.png");
	const char *jpgPath = TextFormat("%s/%s", dirPath, "cover.jpg");
	if(fileExists(pngPath)){
		return pngPath;
	} else if(fileExists(jpgPath)){
		return jpgPath;
	} else {
		return NULL;
	}
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

