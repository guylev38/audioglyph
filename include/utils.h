#ifndef UTILS_H
#define UTILS_H

char *removeFileExtension(const char *filename);
void formatTimeElapsed(char *buffer, float timePlayed);
void formatTrackLength(char *buffer, float trackLength);

#endif