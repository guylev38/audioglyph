#include <string.h>
#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

#undef RAYGUI_IMPLEMENTATION

#include "../include/tinyfiledialogs.h"
#include "dirent.h"

#define WIDTH (1024)
#define HEIGHT (768)

<<<<<<< HEAD
typedef struct Chapter{
	char* name;
	char* path;
	int pos;
	bool isListenedTo;	
} Chapter;

Chapter *getChapterList(DIR *dir, size_t *len, const char *dirPath);
char *removeFileExtension(const char *filename);
const char **getChapterNames(Chapter *chapters, size_t len);
int extractChapterPos(const char *chapterName);
void sortChapters(Chapter *chapters, size_t len);
=======
char** getChapterList(DIR *dir, int *len);
>>>>>>> dev

int main()
{
	InitWindow(WIDTH, HEIGHT, "Audioglyph");
	SetWindowMaxSize(WIDTH, HEIGHT);
	SetExitKey(KEY_ESCAPE);
	SetTargetFPS(60);
	GuiLoadStyle("themes/style_dark.rgs");
			
<<<<<<< HEAD
	size_t i; // Iterator
=======
	int i; // Iterator
>>>>>>> dev

	/* ---- Sizes START ----*/

	// Chapters Panel
	const int CHAPTERS_PANEL_WIDTH = 250;
	const int CHAPTERS_PANEL_HEIGHT = HEIGHT;
	const int CHAPTERS_PANEL_X = (WIDTH - CHAPTERS_PANEL_WIDTH);
	const int CHAPTERS_PANEL_Y = 0;	
	const Rectangle CHAPTERS_PANEL_REC = {CHAPTERS_PANEL_X, CHAPTERS_PANEL_Y, CHAPTERS_PANEL_WIDTH, CHAPTERS_PANEL_HEIGHT};

	// Top Menu
	const int TOP_MENU_WIDTH = (WIDTH - CHAPTERS_PANEL_WIDTH); 
	const int TOP_MENU_HEIGHT = 35;
	const int TOP_MENU_X = 0;
	const int TOP_MENU_Y = 0;
	const Rectangle TOP_MENU_REC = {TOP_MENU_X, TOP_MENU_Y, TOP_MENU_WIDTH, TOP_MENU_HEIGHT};

	// Chapters List View
	const int CHAPTERS_LIST_VIEW_WIDTH = CHAPTERS_PANEL_WIDTH;
	const int CHAPTERS_LIST_VIEW_HEIGHT = (HEIGHT - TOP_MENU_HEIGHT + 12);
	const int CHAPTERS_LIST_VIEW_X = CHAPTERS_PANEL_X;
	const int CHAPTERS_LIST_VIEW_Y = CHAPTERS_PANEL_Y + (TOP_MENU_HEIGHT - 12);
	const Rectangle CHAPTERS_LIST_VIEW_REC = { CHAPTERS_LIST_VIEW_X, CHAPTERS_LIST_VIEW_Y, CHAPTERS_LIST_VIEW_WIDTH, CHAPTERS_LIST_VIEW_HEIGHT };
	int scrollIndex = 0;
	int activeItem = -1;
	int focus = activeItem;

	// Controls Panel
	const int CONTROLS_PANEL_WIDTH = (WIDTH - CHAPTERS_PANEL_WIDTH);
	const int CONTROLS_PANEL_HEIGHT = 100;
	const int CONTROLS_PANEL_X = 0;
	const int CONTROLS_PANEL_Y = (HEIGHT - CONTROLS_PANEL_HEIGHT);
	const Rectangle CONTROLS_PANEL_REC = { CONTROLS_PANEL_X, CONTROLS_PANEL_Y, CONTROLS_PANEL_WIDTH, CONTROLS_PANEL_HEIGHT };

	// Open Button
	const int OPEN_BUTTON_WIDTH = 50;
	const int OPEN_BUTTON_HEIGHT = 25;
	const int OPEN_BUTTON_X = TOP_MENU_X + 5;
	const int OPEN_BUTTON_Y = TOP_MENU_Y + 5;
	const Rectangle OPEN_BUTTON_REC = { OPEN_BUTTON_X, OPEN_BUTTON_Y, OPEN_BUTTON_WIDTH, OPEN_BUTTON_HEIGHT };

	// Play Button
	const int PLAY_BUTTON_WIDTH = 25;
	const int PLAY_BUTTON_HEIGHT = 25;
	const int PLAY_BUTTON_X = CONTROLS_PANEL_X + 20;
	const int PLAY_BUTTON_Y = HEIGHT - (CONTROLS_PANEL_HEIGHT / 2);
	const Rectangle PLAY_BUTTON_REC = { PLAY_BUTTON_X, PLAY_BUTTON_Y, PLAY_BUTTON_WIDTH, PLAY_BUTTON_HEIGHT};

	// Pause Button
	const int PAUSE_BUTTON_WIDTH = 25;
	const int PAUSE_BUTTON_HEIGHT = 25;
	const int PAUSE_BUTTON_X = PLAY_BUTTON_X + 30;
	const int PAUSE_BUTTON_Y = PLAY_BUTTON_Y;
	const Rectangle PAUSE_BUTTON_REC = { PAUSE_BUTTON_X, PAUSE_BUTTON_Y, PAUSE_BUTTON_WIDTH, PAUSE_BUTTON_HEIGHT};

	// Stop Button
	const int STOP_BUTTON_WIDTH = 25;
	const int STOP_BUTTON_HEIGHT = 25;
	const int STOP_BUTTON_X = PAUSE_BUTTON_X + 30;
	const int STOP_BUTTON_Y = PLAY_BUTTON_Y;
	const Rectangle STOP_BUTTON_REC = { STOP_BUTTON_X, STOP_BUTTON_Y, STOP_BUTTON_WIDTH, STOP_BUTTON_HEIGHT};

	const int PROG_BAR_WIDTH = (CHAPTERS_PANEL_WIDTH - STOP_BUTTON_WIDTH) * 2;
	const int PROG_BAR_HEIGHT = 30;
	const int PROG_BAR_X = STOP_BUTTON_X + 100;
	const int PROG_BAR_Y = PLAY_BUTTON_Y - 3;
	const Rectangle PROG_BAR_REC = { PROG_BAR_X, PROG_BAR_Y, PROG_BAR_WIDTH, PROG_BAR_HEIGHT };
	float progress = 0.0f;

	const int CHAPTER_BUTTON_WIDTH = 125;
	const int CHAPTER_BUTTON_HEIGHT = 50;
	const int CHAPTER_BUTTON_X = (WIDTH - CHAPTERS_PANEL_WIDTH);
	const int CHAPTER_BUTTON_Y = (TOP_MENU_HEIGHT + 5);

	/* ---- Sizes END ----*/ 

	bool openButtonClicked = false;

	const char *folderPath;
<<<<<<< HEAD
	Chapter *chapters;
	Chapter currentChapter;
	const char **names;
	size_t chaptersLen = 0;
=======
	char **chapterList;
	unsigned int numberOfChapters = 0;
>>>>>>> dev
	Image cover;
	Texture coverTexture;
	DIR *selectedDir;
	int listViewRes;

	DIR *selectedDir;

	while (!WindowShouldClose())
	{ 
		BeginDrawing();

		// Top Menu Panel	
		GuiPanel(TOP_MENU_REC, NULL); 

		// Chapters Panel
		GuiPanel(CHAPTERS_PANEL_REC, "Chapters"); 

		if(folderPath != NULL){
			listViewRes = GuiListViewEx(CHAPTERS_LIST_VIEW_REC, names, chaptersLen, &scrollIndex, &activeItem, &focus);	
			currentChapter = chapters[activeItem];
		}	
		// Controls Panel
		GuiPanel(CONTROLS_PANEL_REC, "Controls");

		// Play Button
		GuiButton(PLAY_BUTTON_REC, GuiIconText(131, NULL));

		// Pause Button
		GuiButton(PAUSE_BUTTON_REC, GuiIconText(132, NULL));

		// Stop Button
		GuiButton(STOP_BUTTON_REC, GuiIconText(133, NULL));

		// Progress Bar
		GuiProgressBar(PROG_BAR_REC, "0:00", "1:00", &progress, 0.0f, 1.0f);

		/* ----- Open Button and File Dialog ----- */

		// Open Button
		if(GuiButton(OPEN_BUTTON_REC, GuiIconText(3, NULL))) {
<<<<<<< HEAD
			chaptersLen = 0;
=======
			numberOfChapters = 0;
>>>>>>> dev
			folderPath = tinyfd_selectFolderDialog(
				"Select Folder",
				GetWorkingDirectory()
			);
			
			selectedDir = opendir(folderPath);
			if(selectedDir == NULL){
				perror("Failed to open folder");
				return EXIT_FAILURE;
			}

			chapterList = getChapterList(selectedDir, &numberOfChapters);			

<<<<<<< HEAD
			// Check if the folder was selected 
			if(folderPath != NULL){
				selectedDir = opendir(folderPath);
				if(selectedDir == NULL){
					perror("Failed to open folder");
					return EXIT_FAILURE;
				}

				chapters = getChapterList(selectedDir, &chaptersLen, folderPath);			
				sortChapters(chapters, chaptersLen);
				for(i = 0; i < chaptersLen; i++){
					printf("Chapter: %d\n", chapters[i].pos);
				}
			
				names = getChapterNames(chapters, chaptersLen);
				activeItem = GuiListViewEx(CHAPTERS_LIST_VIEW_REC, names, chaptersLen, &scrollIndex, &activeItem, &focus);	

=======
			// Check if there is cover.png and if it exists 
			// load it.	
			if(folderPath){
>>>>>>> dev
				cover = LoadImage(TextFormat("%s/%s", folderPath, "cover.png"));
				if(IsImageValid(cover)){
					coverTexture = LoadTextureFromImage(cover);	
					UnloadImage(cover);
					DrawTexture(coverTexture, 0, (TOP_MENU_HEIGHT - TOP_MENU_Y), WHITE);
<<<<<<< HEAD
				} else {
					printf("Cover image not found\n");
=======
>>>>>>> dev
				}
			} else {
				printf("Folder not selected\n");
			}
		}

		/* -------------------------------------- */
<<<<<<< HEAD
		
=======

>>>>>>> dev
		EndDrawing();
	}

	// Free Memory
<<<<<<< HEAD
	if(chaptersLen > 0){
		printf("it is not null\n");
		for(i = 0; i <chaptersLen; i++){
			printf("Freeing names[%zu]\n", i);
			free(names[i]);
		}
		printf("Freeing names...");
		free(names);
		names = NULL;

		for(i = 0; i<chaptersLen; i++){
			if(chapters[i].name != NULL){
				printf("Freeing chapters[%zu].name\n", i);
				free(chapters[i].name);
			}
			if(chapters[i].path != NULL){
				printf("Freeing chapters[%zu].path\n", i);
				free(chapters[i].path);
			}
		}
		if(chapters != NULL){
			printf("Freeing chapters...\n");
			free(chapters);
			chapters = NULL;
		}
	}

	UnloadTexture(coverTexture);
=======
	if(numberOfChapters > 0){
		printf("it is not null");
		for(i = 0; i<numberOfChapters; i++){
			free(chapterList[i]);
		}
		free(chapterList);
	}
>>>>>>> dev
	CloseWindow();
	return EXIT_SUCCESS;
}

<<<<<<< HEAD
Chapter *getChapterList(DIR *dir, size_t *len, const char *dirPath) {
	Chapter *chapterList = malloc(500 * sizeof(Chapter));
	struct dirent *entry;
	const char *path;
	size_t i = 0;
=======
char** getChapterList(DIR *dir, int *len) {
	char **chapterList = malloc(500 * sizeof(char*));
	struct dirent *entry;
	int i = 0;
>>>>>>> dev

	while((entry = readdir(dir)) != NULL){
		if(entry->d_name[0] == '.')
			continue;
		if(IsFileExtension(entry->d_name, ".mp3")){
<<<<<<< HEAD
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
=======
			chapterList[i] = strdup(entry->d_name);
			if(chapterList[i] == NULL){
				perror("strdup");
				for(int j=0; j<i; j++){
					free(chapterList[j]);
>>>>>>> dev
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
<<<<<<< HEAD
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
=======
>>>>>>> dev
}