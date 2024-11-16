#ifndef CHAPTER_H
#define CHAPTER_H

#include <stdlib.h>
#include <dirent.h>
#include <stdbool.h>

typedef struct Chapter {
  char *name;
  char *path;
  int pos;
  bool isListenedTo;
} Chapter;


Chapter *getChapterList(DIR *dir, size_t *len, const char *dirPath);
const char **getChapterNames(Chapter *chapters, size_t len);
int extractChapterPos(const char *chapterName);
void sortChapters(Chapter *chapters, size_t len);
void freeChapterMemory(Chapter *chpaters, const char **names, size_t len);

#endif