#include <dirent.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include "chapter.h"
#include "utils.h"
#include "raylib.h"
#include "raygui.h"

/*
* Chapter *getChapterList(DIR *dir, size_t *len, const char *dirPath)
* Returns a list of Chapter structs with the path to each chapter file
* from the dir given.
*/ 
Chapter *getChapterList(DIR *dir, size_t *len, const char *dirPath) {
	Chapter *chapterList = NULL;
	struct dirent *entry;
	const char *path;
	size_t i = 0;
	size_t capacity = 10;

	chapterList = malloc(capacity * sizeof(Chapter));
	if(chapterList == NULL){
		perror("malloc");
		return NULL;
	}

	while((entry = readdir(dir)) != NULL){
		if(entry->d_name[0] == '.')
			continue;

		if(IsFileExtension(entry->d_name, ".mp3")){
			// If exceeding the capcity double it
			if(i >= capacity){
				capacity *= 2;
				Chapter *temp = realloc(chapterList, capacity * sizeof(Chapter));
				if(temp == NULL){
					perror("realloc");
					free(chapterList);
					return NULL;
				}
				chapterList = temp;
			}

			path = TextFormat("%s/%s", dirPath, entry->d_name);
			chapterList[i].path = strdup(path);
			chapterList[i].name = removeFileExtension(entry->d_name);
			chapterList[i].isListenedTo = false;
			chapterList[i].pos = extractChapterPos(chapterList[i].name);

			if(chapterList[i].path == NULL || chapterList[i].name == NULL){
				perror("strdup");

				for(size_t j=0; j<i; j++){
					free(chapterList[j].name);
					free(chapterList[j].path);
				}
				free(chapterList);
				return NULL;
			}

			++(*len);
		++i;
		}
	}

	closedir(dir);
	return chapterList;
}

/*
* const char **getChapterNames(Chapter *chapters, size_t len)
* Returns a array of strings containing the name property
* from each of the elements of the chapter array.
*/

const char **getChapterNames(Chapter *chapters, size_t len){
	const char **names = calloc(len + 1, sizeof(char *));
	size_t i;

	if(names == NULL){
		perror("calloc");
		return NULL;
	}

	for(i = 0; i<len; i++){
		names[i] = strdup(chapters[i].name);
		if(names[i] == NULL){
			perror("strdup");
			// Free the allocated memory
			for(size_t j = 0; j < i; j++){
				free(names[j]);
			}
			free(names);
			return NULL;
		}
	}

	names[len] = NULL;
	return names;
}

/*
* int extractChapterPos(const char *chapterName)
* Returns the number of the chapter (pos) from given chapter name.
*/ 
int extractChapterPos(const char *chapterName){
	int number = 0;
	int found = 0;
	const char *ptr = chapterName;

	while(*ptr){
		if(isdigit(*ptr)){
			number = number * 10 + (*ptr - '0');
			found = 1;
		} else if (found){
			break;
		}
		ptr++;
	}
	return found ? number : -1;
}

// Helper for sortChapters
int compareChapters(const void *a, const void *b){
	const Chapter *chapA = (const Chapter *)a;
	const Chapter *chapB = (const Chapter *)b;

	return (chapA->pos) - (chapB->pos);
}

/*
* void sortChapters(Chapter *chapters, size_t len)
* Sorts the given chapters array with qsort from the standart library.
*/
void sortChapters(Chapter *chapters, size_t len){
	qsort(chapters, len, sizeof(Chapter), compareChapters);
}

/*
* void freeChapterMemory(Chapter *chapters, const char **names, size_t len)
* Frees the memory allocated to the chapters array and the names array.
*/
void freeChapterMemory(Chapter *chapters, const char **names, size_t len)
{
    for (size_t i = 0; i < len; i++)
    {
        free(names[i]);
        free(chapters[i].name);
        free(chapters[i].path);
    }
    free(names);
    free(chapters);
}