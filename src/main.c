#include <string.h>
#include <stdio.h>
#include <unistd.h>

#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

#undef RAYGUI_IMPLEMENTATION

#include "tinyfiledialogs.h"
#include "dirent.h"
#include "chapter.h"
#include "utils.h"

#define WIDTH (1024)
#define HEIGHT (768)
#define AUDIO_STREAM_BUFFER_SIZE (4096)

typedef struct {
	Font font;
	const char *folderPath;
	const char **names;
	DIR *selectedDir;
	Chapter *chapters;
	Chapter currentChapter;
	size_t chaptersLen;
	Image cover;
	Image logo;
	Texture2D defaultTexture;
	Texture coverTexture;
	float progress;
	int scrollIndex;
	int activeItem;
	int focus;
	Music bookTrack;
	float timePlayed;
	float trackLength;
	char *elapsedTimeBuffer;
	char *trackLengthBuffer;
	char *nowPlayingBuffer;
	int openButtonState;
	int playButtonState;
	int pauseButtonState;
	int stopButtonState;
	int minutesElapsed, secondsElapsed;
	int minutesLength, secondsLength;
	bool isTrackLoaded;
} AppState;

/* ----- Function Prototypes ----- */

void InitApp(AppState *state);
void DrawUI(AppState *state);
void LoadChapters(AppState *state);
void LoadCover(AppState *state);
void HandleButtons(AppState *state);
void UpdateMusic(AppState *state);
void Cleanup(AppState *state);

/* ------------------------------- */

/* ----- Global Static Variables ----- */

// Chapters Panel
const static int CHAPTERS_PANEL_WIDTH = 250;
const static int CHAPTERS_PANEL_HEIGHT = HEIGHT;
const static int CHAPTERS_PANEL_X = (WIDTH - CHAPTERS_PANEL_WIDTH);
const static int CHAPTERS_PANEL_Y = 0;	
const static Rectangle CHAPTERS_PANEL_REC = {CHAPTERS_PANEL_X, CHAPTERS_PANEL_Y, CHAPTERS_PANEL_WIDTH, CHAPTERS_PANEL_HEIGHT};

// Top Menu
const static int TOP_MENU_WIDTH = (WIDTH - CHAPTERS_PANEL_WIDTH); 
const static int TOP_MENU_HEIGHT = 35;
const static int TOP_MENU_X = 0;
const static int TOP_MENU_Y = 0;
const static Rectangle TOP_MENU_REC = {TOP_MENU_X, TOP_MENU_Y, TOP_MENU_WIDTH, TOP_MENU_HEIGHT};

// Chapters List View
const static int CHAPTERS_LIST_VIEW_WIDTH = CHAPTERS_PANEL_WIDTH;
const static int CHAPTERS_LIST_VIEW_HEIGHT = (HEIGHT - TOP_MENU_HEIGHT + 12);
const static int CHAPTERS_LIST_VIEW_X = CHAPTERS_PANEL_X;
const static int CHAPTERS_LIST_VIEW_Y = CHAPTERS_PANEL_Y + (TOP_MENU_HEIGHT - 12);
const static Rectangle CHAPTERS_LIST_VIEW_REC = { CHAPTERS_LIST_VIEW_X, CHAPTERS_LIST_VIEW_Y, CHAPTERS_LIST_VIEW_WIDTH, CHAPTERS_LIST_VIEW_HEIGHT };

// Controls Panel
const static int CONTROLS_PANEL_WIDTH = (WIDTH - CHAPTERS_PANEL_WIDTH);
const static int CONTROLS_PANEL_HEIGHT = 100;
const static int CONTROLS_PANEL_X = 0;
const static int CONTROLS_PANEL_Y = (HEIGHT - CONTROLS_PANEL_HEIGHT);
const static Rectangle CONTROLS_PANEL_REC = { CONTROLS_PANEL_X, CONTROLS_PANEL_Y, CONTROLS_PANEL_WIDTH, CONTROLS_PANEL_HEIGHT };

// Open Button
const static int OPEN_BUTTON_WIDTH = 50;
const static int OPEN_BUTTON_HEIGHT = 25;
const static int OPEN_BUTTON_X = TOP_MENU_X + 5;
const static int OPEN_BUTTON_Y = TOP_MENU_Y + 5;
const static Rectangle OPEN_BUTTON_REC = { OPEN_BUTTON_X, OPEN_BUTTON_Y, OPEN_BUTTON_WIDTH, OPEN_BUTTON_HEIGHT };

// Play Button
const static int PLAY_BUTTON_WIDTH = 25;
const static int PLAY_BUTTON_HEIGHT = 25;
const static int PLAY_BUTTON_X = CONTROLS_PANEL_X + 20;
const static int PLAY_BUTTON_Y = HEIGHT - (CONTROLS_PANEL_HEIGHT / 2);
const static Rectangle PLAY_BUTTON_REC = { PLAY_BUTTON_X, PLAY_BUTTON_Y, PLAY_BUTTON_WIDTH, PLAY_BUTTON_HEIGHT};

// Pause Button
const static int PAUSE_BUTTON_WIDTH = 25;
const static int PAUSE_BUTTON_HEIGHT = 25;
const static int PAUSE_BUTTON_X = PLAY_BUTTON_X + 30;
const static int PAUSE_BUTTON_Y = PLAY_BUTTON_Y;
const static Rectangle PAUSE_BUTTON_REC = { PAUSE_BUTTON_X, PAUSE_BUTTON_Y, PAUSE_BUTTON_WIDTH, PAUSE_BUTTON_HEIGHT};

// Stop Button
const static int STOP_BUTTON_WIDTH = 25;
const static int STOP_BUTTON_HEIGHT = 25;
const static int STOP_BUTTON_X = PAUSE_BUTTON_X + 30;
const static int STOP_BUTTON_Y = PLAY_BUTTON_Y;
const static Rectangle STOP_BUTTON_REC = { STOP_BUTTON_X, STOP_BUTTON_Y, STOP_BUTTON_WIDTH, STOP_BUTTON_HEIGHT };

// Progress Bar
const static int PROG_BAR_WIDTH = (CHAPTERS_PANEL_WIDTH - STOP_BUTTON_WIDTH) * 2;
const static int PROG_BAR_HEIGHT = 30;
const static int PROG_BAR_X = STOP_BUTTON_X + 100;
const static int PROG_BAR_Y = PLAY_BUTTON_Y - 3;
const static Rectangle PROG_BAR_REC = { PROG_BAR_X, PROG_BAR_Y, PROG_BAR_WIDTH, PROG_BAR_HEIGHT };

// Chapter Buttons in list view.
const static int CHAPTER_BUTTON_WIDTH = 125;
const static int CHAPTER_BUTTON_HEIGHT = 50;
const static int CHAPTER_BUTTON_X = (WIDTH - CHAPTERS_PANEL_WIDTH);
const static int CHAPTER_BUTTON_Y = (TOP_MENU_HEIGHT + 5);

// Now Playing Label
const static int NOW_PLAYING_LABEL_WIDTH = (TOP_MENU_WIDTH - OPEN_BUTTON_WIDTH);
const static int NOW_PLAYING_LABEL_HEIGHT = 25;
const static int NOW_PLAYING_LABEL_X = (OPEN_BUTTON_WIDTH + 20);
const static int NOW_PLAYING_LABEL_Y = OPEN_BUTTON_Y;
const static Rectangle NOW_PLAYING_LABEL_REC = { NOW_PLAYING_LABEL_X, NOW_PLAYING_LABEL_Y, NOW_PLAYING_LABEL_WIDTH, NOW_PLAYING_LABEL_HEIGHT };

/* ----------------------------------- */

int main()
{
	AppState state = {0};
	InitApp(&state);

	while (!WindowShouldClose())
	{
		UpdateMusic(&state); 
		BeginDrawing();
		DrawUI(&state);
		HandleButtons(&state);
		EndDrawing();
	}

	Cleanup(&state);
	CloseWindow(); // Close the window.
	return EXIT_SUCCESS;
}

void InitApp(AppState *state){
	InitWindow(WIDTH, HEIGHT, "Audioglyph");
	SetExitKey(KEY_ESCAPE);
	SetTargetFPS(60);
	SetAudioStreamBufferSizeDefault(AUDIO_STREAM_BUFFER_SIZE);
	InitAudioDevice();

	GuiLoadStyle("themes/style_dark.rgs"); // Set dark theme

	state->font = LoadFontEx("resources/UbuntuMono.ttf", 32, NULL, 0);	
	if(state->font.texture.id == 0){
		fprintf(stderr, "Failed to load font!\n");
		CloseWindow();
		exit(EXIT_FAILURE);	
	}
	state->logo = LoadImage("resources/logo.png");
	state->defaultTexture = LoadTextureFromImage(state->logo);	

	SetWindowIcon(state->logo);

	state->elapsedTimeBuffer = malloc(50 * sizeof(char));
	state->trackLengthBuffer = malloc(50 * sizeof(char));
	state->nowPlayingBuffer = malloc(50 * sizeof(char));
	if(state->elapsedTimeBuffer == NULL || state->trackLengthBuffer == NULL || state->nowPlayingBuffer == NULL){
		fprintf(stderr, "Failed to allocate memory for buffers");
		Cleanup(state);
		CloseWindow();
		exit(EXIT_FAILURE);
	}

	state->elapsedTimeBuffer[0] = '\0';
	state->trackLengthBuffer[0] = '\0';
	state->nowPlayingBuffer[0] = '\0';

	state->progress = 0.0f;
	state->chaptersLen = 0;
	state->isTrackLoaded = false;
	state->bookTrack = (Music){0};
}

void DrawUI(AppState *state){
	GuiSetFont(state->font);
	
	// Top Menu Panel	
	GuiPanel(TOP_MENU_REC, NULL); 

	// If the buffer is empty label should be only "Now Playing:"
	if(strlen(state->nowPlayingBuffer) <= 0){
		GuiLabel(NOW_PLAYING_LABEL_REC, "Now Playing: ");
	} else {
		GuiLabel(NOW_PLAYING_LABEL_REC, state->nowPlayingBuffer);
	}

	// Chapters Panel
	GuiPanel(CHAPTERS_PANEL_REC, "Chapters"); 

	// Controls Panel
	GuiPanel(CONTROLS_PANEL_REC, "Controls");

	// Play Button
	state->playButtonState = GuiButton(PLAY_BUTTON_REC, GuiIconText(131, NULL));
	// Pause Button
	state->pauseButtonState = GuiButton(PAUSE_BUTTON_REC, GuiIconText(132, NULL));
	// Stop Button
	state->stopButtonState = GuiButton(STOP_BUTTON_REC, GuiIconText(133, NULL));
	// Open Button
	state->openButtonState = GuiButton(OPEN_BUTTON_REC, GuiIconText(3, NULL));

	// Progress Bar
	GuiProgressBar(PROG_BAR_REC, state->elapsedTimeBuffer, state->trackLengthBuffer, &state->progress, 0.0f, 1.0f);

	// If the list view was initialized then update the current chapter.
	if(state->folderPath != NULL){
		GuiListViewEx(CHAPTERS_LIST_VIEW_REC, state->names, state->chaptersLen, &state->scrollIndex, &state->activeItem, &state->focus);	
		if(state->activeItem >= 0){
			state->currentChapter = state->chapters[state->activeItem];
			if(state->isTrackLoaded){
				UnloadMusicStream(state->bookTrack);
			}
			state->bookTrack = LoadMusicStream(state->currentChapter.path);
			state->isTrackLoaded = IsMusicValid(state->bookTrack);
			state->trackLength = GetMusicTimePlayed(state->bookTrack);
			state->progress = 0.0f;
			state->timePlayed = 0.0f;
			formatTimeElapsed(state->elapsedTimeBuffer, state->timePlayed);
			formatTrackLength(state->trackLengthBuffer, state->trackLength);
		}
	}	
}

void HandleButtons(AppState *state){
	if(state->playButtonState && IsMusicValid(state->bookTrack)){
		if(IsMusicStreamPlaying(state->bookTrack)){
			printf("Book track already playing!\n");
		}
		printf("Playing book track...\n");
		if(state->timePlayed > 0.0f){
			SeekMusicStream(state->bookTrack, state->timePlayed);
		}
		PlayMusicStream(state->bookTrack);
	}
	if(state->pauseButtonState && IsMusicStreamPlaying(state->bookTrack)){
		printf("Pausing book track...\n");
		PauseMusicStream(state->bookTrack);
		state->timePlayed = GetMusicTimePlayed(state->bookTrack);
	}

	if(state->stopButtonState && IsMusicValid(state->bookTrack)){
		printf("Stopping book track...\n");
		StopMusicStream(state->bookTrack);
		UnloadMusicStream(state->bookTrack);
		state->bookTrack = (Music){ 0 };
		state->timePlayed = 0.0f;
		state->trackLength = 0.0f;
		state->progress = 0;
		formatTimeElapsed(state->elapsedTimeBuffer, state->timePlayed);
		formatTrackLength(state->trackLengthBuffer, state->trackLength);
		state->nowPlayingBuffer[0] = '\0';
	}

	if(state->openButtonState){
		if(state->isTrackLoaded){
			// stop everything before loading other chapters
			StopMusicStream(state->bookTrack);
			UnloadMusicStream(state->bookTrack);
			state->bookTrack = (Music){0};
		}
		LoadChapters(state);
		LoadCover(state);
	}
}
void LoadChapters(AppState *state){
	char *prevFolderPath = state->folderPath;
	// Open folder dialog
	state->folderPath = tinyfd_selectFolderDialog(
		"Select Folder",
		GetWorkingDirectory()
	);
	printf("Folder Path: %s\n", state->folderPath);
	
	// Check if the folder was selected 
	if(state->folderPath != NULL){
		state->chaptersLen = 0;
		state->selectedDir = opendir(state->folderPath);
		if(state->selectedDir == NULL){
			perror("Failed to open folder");
			exit(EXIT_FAILURE);
		}

		/*
		* Convert each file into the Chapter struct
		* and then sort it. Afterwards get the names and 
		* pass them to the list view.
		*/
		state->chapters = getChapterList(state->selectedDir, &state->chaptersLen, state->folderPath);			
		sortChapters(state->chapters, state->chaptersLen);
		state->names = getChapterNames(state->chapters, state->chaptersLen);
		state->activeItem = GuiListViewEx(CHAPTERS_LIST_VIEW_REC, state->names, state->chaptersLen, &state->scrollIndex, &state->activeItem, &state->focus);	
	} else {
		state->folderPath = prevFolderPath;
		state->activeItem = GuiListViewEx(CHAPTERS_LIST_VIEW_REC, state->names, state->chaptersLen, &state->scrollIndex, &state->activeItem, &state->focus);	
	}
}

void LoadCover(AppState *state){
	int coverHeight = (HEIGHT - TOP_MENU_HEIGHT -  CONTROLS_PANEL_HEIGHT);
	int coverWidth = (WIDTH - CHAPTERS_PANEL_WIDTH);
	if(state->folderPath == NULL) return;
	// Try to load the cover image
	char *cover_path = getCoverFileName(state->folderPath);
	if(cover_path != NULL){
		state->cover = LoadImage(cover_path);
		ImageResize(&state->cover, coverWidth, coverHeight);
		if(IsImageValid(state->cover)){
			state->coverTexture = LoadTextureFromImage(state->cover);	
			UnloadImage(state->cover);
			DrawTexture(state->coverTexture, 0, (TOP_MENU_HEIGHT - TOP_MENU_Y), WHITE);
		}
	} else {
		printf("Cover not found");
		Image defaultCover = state->logo;
		ImageResize(&defaultCover, coverWidth, coverHeight);
		state->defaultTexture = LoadTextureFromImage(defaultCover);
		DrawTexture(state->defaultTexture, 0, (TOP_MENU_HEIGHT - TOP_MENU_Y), WHITE);
		UnloadTexture(state->coverTexture);
	}
}

void UpdateMusic(AppState *state){
	if(state->isTrackLoaded && IsMusicStreamPlaying(state->bookTrack)){
		state->progress = GetMusicTimePlayed(state->bookTrack) / GetMusicTimeLength(state->bookTrack);
		UpdateMusicStream(state->bookTrack);
		state->timePlayed = GetMusicTimePlayed(state->bookTrack);
		state->trackLength = GetMusicTimeLength(state->bookTrack);
		formatTimeElapsed(state->elapsedTimeBuffer, state->timePlayed);
		formatTrackLength(state->trackLengthBuffer, state->trackLength);
		sprintf(state->nowPlayingBuffer, "Now Playing: %s", state->currentChapter.name);
	}

	if(state->isTrackLoaded == false){
		formatTimeElapsed(state->elapsedTimeBuffer, state->timePlayed);
		formatTrackLength(state->trackLengthBuffer, state->trackLength);
	}
}

void Cleanup(AppState *state){
	if(state->chaptersLen > 0){
		freeChapterMemory(state->chapters, state->names, state->chaptersLen);
	}

	if(state->isTrackLoaded){
		UnloadMusicStream(state->bookTrack);
	}

	free(state->elapsedTimeBuffer);
	free(state->trackLengthBuffer);
	free(state->nowPlayingBuffer);

	UnloadTexture(state->coverTexture);
	UnloadTexture(state->defaultTexture);
	UnloadFont(state->font);
	CloseAudioDevice();
}