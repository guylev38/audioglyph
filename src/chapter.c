#include <dirent.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include "chapter.h"
#include "utils.h"
#include "raylib.h"
#include "raygui.h"

Chapter *getChapterList(DIR *dir, size_t *len, const char *dirPath) {
	Chapter *chapterList = malloc(500 * sizeof(Chapter));
	struct dirent *entry;
	const char *path;
	size_t i = 0;

	while((entry = readdir(dir)) != NULL){
		if(entry->d_name[0] == '.')
			continue;
		if(IsFileExtension(entry->d_name, ".mp3")){
			path = TextFormat("%s/%s", dirPath, entry->d_name);
			chapterList[i].path = strdup(path);
			chapterList[i].name = removeFileExtension(entry->d_name);
			chapterList[i].isListenedTo = false;
			chapterList[i].pos = extractChapterPos(chapterList[i].name);
			if(chapterList[i].path == NULL || chapterList[i].name == NULL){
				perror("strdup");
				for(int j=0; j<i; j++){
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

const char **getChapterNames(Chapter *chapters, size_t len){
	const char **names = malloc(len * sizeof(char *));
	size_t i;
	for(i = 0; i<len; i++){
		names[i] = strdup(chapters[i].name);
		if(names[i] == NULL){
			perror("strdup");
			return NULL;
		}
	}
	names[len] = NULL;
	return names;
}

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

void sortChapters(Chapter *chapters, size_t len){
	// TODO: Maybe add support for epilogue and preface in the future.
	size_t i, j;
	int swapped;
	Chapter temp;

	for(i = 0; i < len - 1; i++){
		swapped = 0;
		for(j = 0; j < len - i - 1; j++){
			if(chapters[j].pos > chapters[j + 1].pos){
				temp = chapters[j];
				chapters[j] = chapters[j + 1];
				chapters[j + 1] = temp;
				swapped = 1;
			}	
		}

		if(swapped == 0) {
			break;
		}
	}
}

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