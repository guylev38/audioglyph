#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

#undef RAYGUI_IMPLEMENTATION
#define GUI_WINDOW_FILE_DIALOG_IMPLEMENTATION
#include "../include/gui_window_file_dialog.h"

#include "../include/tinyfiledialogs.h"

#define WIDTH (1024)
#define HEIGHT (768)


char** getChapterList(DIR *dir);

int main()
{
	InitWindow(WIDTH, HEIGHT, "Audioglyph");
	SetWindowMaxSize(WIDTH, HEIGHT);
	SetExitKey(KEY_ESCAPE);
	SetTargetFPS(60);
	GuiLoadStyle("themes/style_dark.rgs");
			

		/* ---- Sizes START ----*/

	// Chapters Panel
	const int CHAPTERS_PANEL_WIDTH = 250;
	const int CHAPTERS_PANEL_HEIGHT = HEIGHT;
	const int CHAPTERS_PANEL_X = (WIDTH - CHAPTERS_PANEL_WIDTH);
	const int CHAPTERS_PANEL_Y = 0;	
	const Rectangle CHAPTERS_PANEL_REC = {CHAPTERS_PANEL_X, CHAPTERS_PANEL_Y, CHAPTERS_PANEL_WIDTH, CHAPTERS_PANEL_HEIGHT};

	// Top Menu
	const int TOP_MENU_WIDTH = (WIDTH - CHAPTERS_PANEL_WIDTH); const int TOP_MENU_HEIGHT = 35;
	const int TOP_MENU_X = 0;
	const int TOP_MENU_Y = 0;
	const Rectangle TOP_MENU_REC = {TOP_MENU_X, TOP_MENU_Y, TOP_MENU_WIDTH, TOP_MENU_HEIGHT};
	

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

	/* ---- Sizes END ----*/ 

	bool openButtonClicked = false;

	const char *folderPath;
	Image cover;
	Texture coverTexture;

	while (!WindowShouldClose())
	{
		BeginDrawing();
		// Top Menu Panel	
		GuiPanel(TOP_MENU_REC, NULL); 

		// Chapters Panel
		GuiPanel(CHAPTERS_PANEL_REC, "Chapters"); 

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
			progress += 0.1f;
			folderPath = tinyfd_selectFolderDialog(
				"Select Folder",
				GetWorkingDirectory()
			);

			// Check if there is cover.png and if it exists 
			// load it.	
			if(folderPath){
				cover = LoadImage(TextFormat("%s" PATH_SEPERATOR "%s", folderPath, "cover.png"));
				if(IsImageValid(cover)){
					coverTexture = LoadTextureFromImage(cover);	
					UnloadImage(cover);
				}
			}
		}

		DrawTexture(coverTexture, 0, (TOP_MENU_HEIGHT - TOP_MENU_Y), WHITE);

		/* -------------------------------------- */
		EndDrawing();
	}

	CloseWindow();
	return 0;
}
