#include <string.h>
#include <stdio.h>

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

int main()
{
	InitWindow(WIDTH, HEIGHT, "Audioglyph");
	SetExitKey(KEY_ESCAPE);
	SetTargetFPS(60);
	SetAudioStreamBufferSizeDefault(AUDIO_STREAM_BUFFER_SIZE);
	InitAudioDevice();

	GuiLoadStyle("themes/style_dark.rgs"); // Set dark theme
	Font font = LoadFontEx("resources/UbuntuMono.ttf", 32, NULL, 0);	
	if(font.texture.id == 0){
		fprintf(stderr, "Failed to load font!\n");
		CloseWindow();
		return EXIT_FAILURE;
	}


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
	int isPlayButtonClicked;

	// Pause Button
	const int PAUSE_BUTTON_WIDTH = 25;
	const int PAUSE_BUTTON_HEIGHT = 25;
	const int PAUSE_BUTTON_X = PLAY_BUTTON_X + 30;
	const int PAUSE_BUTTON_Y = PLAY_BUTTON_Y;
	const Rectangle PAUSE_BUTTON_REC = { PAUSE_BUTTON_X, PAUSE_BUTTON_Y, PAUSE_BUTTON_WIDTH, PAUSE_BUTTON_HEIGHT};
	int isPauseButtonClicked;

	// Stop Button
	const int STOP_BUTTON_WIDTH = 25;
	const int STOP_BUTTON_HEIGHT = 25;
	const int STOP_BUTTON_X = PAUSE_BUTTON_X + 30;
	const int STOP_BUTTON_Y = PLAY_BUTTON_Y;
	const Rectangle STOP_BUTTON_REC = { STOP_BUTTON_X, STOP_BUTTON_Y, STOP_BUTTON_WIDTH, STOP_BUTTON_HEIGHT};
	int isStopButtonClicked;

	// Progress Bar
	const int PROG_BAR_WIDTH = (CHAPTERS_PANEL_WIDTH - STOP_BUTTON_WIDTH) * 2;
	const int PROG_BAR_HEIGHT = 30;
	const int PROG_BAR_X = STOP_BUTTON_X + 100;
	const int PROG_BAR_Y = PLAY_BUTTON_Y - 3;
	const Rectangle PROG_BAR_REC = { PROG_BAR_X, PROG_BAR_Y, PROG_BAR_WIDTH, PROG_BAR_HEIGHT };
	float progress = 0.0f;

	// Chapter Buttons in list view.
	const int CHAPTER_BUTTON_WIDTH = 125;
	const int CHAPTER_BUTTON_HEIGHT = 50;
	const int CHAPTER_BUTTON_X = (WIDTH - CHAPTERS_PANEL_WIDTH);
	const int CHAPTER_BUTTON_Y = (TOP_MENU_HEIGHT + 5);

	// Now Playing Label
	const int NOW_PLAYING_LABEL_WIDTH = (TOP_MENU_WIDTH - OPEN_BUTTON_WIDTH);
	const int NOW_PLAYING_LABEL_HEIGHT = 25;
	const int NOW_PLAYING_LABEL_X = (OPEN_BUTTON_WIDTH + 20);
	const int NOW_PLAYING_LABEL_Y = OPEN_BUTTON_Y;
	const Rectangle NOW_PLAYING_LABEL_REC = { NOW_PLAYING_LABEL_X, NOW_PLAYING_LABEL_Y, NOW_PLAYING_LABEL_WIDTH, NOW_PLAYING_LABEL_HEIGHT };

	/* ---- Sizes END ----*/ 

	size_t i; // Iterator

	const char *folderPath;
	const char **names;
	DIR *selectedDir;
	Chapter *chapters;
	size_t chaptersLen = 0;
	Chapter currentChapter;
	Image cover;
	Texture coverTexture = { 0 };
	Music bookTrack = { 0 }; 
	bool isMusicLoaded = false;
	float timePlayed = 0.0f;
	float trackLength = 0.0f;
	int minutesElapsed, secondsElapsed;
	int minutesLength, secondsLength;
	char *elapsedTimeBuffer = malloc(5 * sizeof(char));
	char *trackLengthBuffer = malloc(5 * sizeof(char));
	char *nowPlayingBuffer = malloc(100 * sizeof(char));

	while (!WindowShouldClose())
	{ 

		if(isMusicLoaded && IsMusicStreamPlaying(bookTrack)){
			progress = GetMusicTimePlayed(bookTrack) / GetMusicTimeLength(bookTrack);
			UpdateMusicStream(bookTrack);
			timePlayed = GetMusicTimePlayed(bookTrack);
			trackLength = GetMusicTimeLength(bookTrack);
			formatTimeElapsed(elapsedTimeBuffer, timePlayed);
			formatTrackLength(trackLengthBuffer, trackLength);
			sprintf(nowPlayingBuffer, "Now Playing: %s", currentChapter.name);
		}

		BeginDrawing();

		GuiSetFont(font);
		
		// Top Menu Panel	
		GuiPanel(TOP_MENU_REC, NULL); 
		GuiLabel(NOW_PLAYING_LABEL_REC, nowPlayingBuffer);

		// Chapters Panel
		GuiPanel(CHAPTERS_PANEL_REC, "Chapters"); 

		// Controls Panel
		GuiPanel(CONTROLS_PANEL_REC, "Controls");

		// Play Button
		isPlayButtonClicked = GuiButton(PLAY_BUTTON_REC, GuiIconText(131, NULL));
		if(isPlayButtonClicked && IsMusicValid(bookTrack)){
			if(IsMusicStreamPlaying(bookTrack)){
				printf("Book track already playing!\n");
			}
			printf("Playing book track...\n");
			PlayMusicStream(bookTrack);
			if(timePlayed > 0.0f){
				SeekMusicStream(bookTrack, timePlayed);
			}
		}

		// Pause Button
		isPauseButtonClicked = GuiButton(PAUSE_BUTTON_REC, GuiIconText(132, NULL));
		if(isPauseButtonClicked && IsMusicStreamPlaying(bookTrack)){
			printf("Pausing book track...\n");
			PauseMusicStream(bookTrack);
			timePlayed = GetMusicTimePlayed(bookTrack);
		}

		// Stop Button
		isStopButtonClicked = GuiButton(STOP_BUTTON_REC, GuiIconText(133, NULL));
		if(isStopButtonClicked && IsMusicValid(bookTrack)){
			printf("Stopping book track...\n");
			StopMusicStream(bookTrack);
			timePlayed = 0.0f;
			trackLength = 0.0f;
			progress = 0;
			formatTimeElapsed(elapsedTimeBuffer, timePlayed);
			formatTrackLength(trackLengthBuffer, trackLength);
		}

		// Progress Bar
		GuiProgressBar(PROG_BAR_REC, elapsedTimeBuffer, trackLengthBuffer, &progress, 0.0f, 1.0f);

		// If the list view was initialized then update the current chapter.
		if(folderPath != NULL){
			GuiListViewEx(CHAPTERS_LIST_VIEW_REC, names, chaptersLen, &scrollIndex, &activeItem, &focus);	
			if(activeItem >= 0){
				currentChapter = chapters[activeItem];
				if(isMusicLoaded){
					UnloadMusicStream(bookTrack);
				}
				bookTrack = LoadMusicStream(currentChapter.path);
				isMusicLoaded = IsMusicValid(bookTrack);
				trackLength = GetMusicTimePlayed(bookTrack);
				progress = 0.0f;
				formatTimeElapsed(elapsedTimeBuffer, timePlayed);
				formatTrackLength(trackLengthBuffer, trackLength);
			}
		}	


		/* ----- Open Button, File Dialog and Render Chapters ----- */

		// Open Button
		if(GuiButton(OPEN_BUTTON_REC, GuiIconText(3, NULL))) {
			chaptersLen = 0;
			// Open folder dialog
			folderPath = tinyfd_selectFolderDialog(
				"Select Folder",
				GetWorkingDirectory()
			);
			
			// Check if the folder was selected 
			if(folderPath != NULL){
				selectedDir = opendir(folderPath);
				if(selectedDir == NULL){
					perror("Failed to open folder");
					return EXIT_FAILURE;
				}

				/*
				* Convert each file into the Chapter struct
				* and then sort it. Afterwards get the names and 
				* pass them to the list view.
				*/
				chapters = getChapterList(selectedDir, &chaptersLen, folderPath);			
				sortChapters(chapters, chaptersLen);
				names = getChapterNames(chapters, chaptersLen);
				activeItem = GuiListViewEx(CHAPTERS_LIST_VIEW_REC, names, chaptersLen, &scrollIndex, &activeItem, &focus);	

				// Try to load the cover image
				cover = LoadImage(TextFormat("%s/%s", folderPath, "cover.png"));
				if(IsImageValid(cover)){
					coverTexture = LoadTextureFromImage(cover);	
					UnloadImage(cover);
					DrawTexture(coverTexture, 0, (TOP_MENU_HEIGHT - TOP_MENU_Y), WHITE);
				} else {
					printf("Cover image not found\n");
				}
			} else {
				printf("Folder not selected\n");
			}
		}

		/* -------------------------------------- */
		
		EndDrawing();
	}

	// Free Memory
	if(chaptersLen > 0){
		freeChapterMemory(chapters, names, chaptersLen);
	}

	if(isMusicLoaded){
		UnloadMusicStream(bookTrack);
	}

	free(elapsedTimeBuffer);
	free(trackLengthBuffer);
	free(nowPlayingBuffer);

	UnloadTexture(coverTexture);
	UnloadFont(font);
	CloseAudioDevice();
	CloseWindow(); // Close the window.
	return EXIT_SUCCESS;
}