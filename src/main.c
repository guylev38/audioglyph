#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

#undef RAYGUI_IMPLEMENTATION
#define GUI_WINDOW_FILE_DIALOG_IMPLEMENTATION
#include "../include/gui_window_file_dialog.h"


#define WIDTH (800)
#define HEIGHT (600)

int main()
{
	InitWindow(WIDTH, HEIGHT, "Audioglyph");
	SetWindowMaxSize(WIDTH, HEIGHT);
	SetExitKey(KEY_ESCAPE);
	SetTargetFPS(60);
	GuiLoadStyle("themes/style_dark.rgs");
			

		/* ---- Sizes START ----*/

	// Chapters Panel
	const int CHAPTERS_PANEL_WIDTH = 200;
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
	

	// Controls Panel
	const int CONTROLS_PANEL_WIDTH = (WIDTH - CHAPTERS_PANEL_WIDTH);
	const int CONTROLS_PANEL_HEIGHT = 100;
	const int CONTROLS_PANEL_X = 0;
	const int CONTROLS_PANEL_Y = (HEIGHT - CONTROLS_PANEL_HEIGHT);
	const Rectangle CONTROLS_PANEL_REC = { CONTROLS_PANEL_X, CONTROLS_PANEL_Y, CONTROLS_PANEL_WIDTH, CONTROLS_PANEL_HEIGHT };

	// Open Button
	const int OPEN_BUTTON_WIDTH = 25;
	const int OPEN_BUTTON_HEIGHT = 25;
	const int OPEN_BUTTON_X = TOP_MENU_X + 5;
	const int OPEN_BUTTON_Y = TOP_MENU_Y + 5;
	const Rectangle OPEN_BUTTON_REC = { OPEN_BUTTON_X, OPEN_BUTTON_Y, OPEN_BUTTON_WIDTH, OPEN_BUTTON_HEIGHT };

	// Play Button
	const int PLAY_BUTTON_WIDTH = 25;
	const int PLAY_BUTTON_HEIGHT = 25;
	const int PLAY_BUTTON_X = CONTROLS_PANEL_X + 20;
	const int PLAY_BUTTON_Y = HEIGHT - (CONTROLS_PANEL_HEIGHT / 2);
	printf("Play Button h : %d\n Controls panel h: %d\n", PLAY_BUTTON_HEIGHT, CONTROLS_PANEL_HEIGHT);
	const Rectangle PLAY_BUTTON_REC = { PLAY_BUTTON_X, PLAY_BUTTON_Y, PLAY_BUTTON_WIDTH, PLAY_BUTTON_HEIGHT};

	// Pause Button
	const int PAUSE_BUTTON_WIDTH = 25;
	const int PAUSE_BUTTON_HEIGHT = 25;
	const int PAUSE_BUTTON_X = PLAY_BUTTON_X + 30;
	const int PAUSE_BUTTON_Y = PLAY_BUTTON_Y;
	const Rectangle PAUSE_BUTTON_REC = { PAUSE_BUTTON_X, PAUSE_BUTTON_Y, PAUSE_BUTTON_WIDTH, PAUSE_BUTTON_HEIGHT};


	/* ---- Sizes END ----*/ 

	GuiWindowFileDialogState fileDialogState = InitGuiWindowFileDialog(GetWorkingDirectory());
	bool exitWindow = false;
	char fileNametoLoad[512] = { 0 };



	bool openButtonClicked = false;


	while (!WindowShouldClose())
	{
		BeginDrawing();

		// Top Menu Panel	
		GuiPanel(TOP_MENU_REC, NULL); 

		// Chapters Panel
		GuiPanel(CHAPTERS_PANEL_REC, "Chapters"); 

		// Controls Panel
		GuiPanel(CONTROLS_PANEL_REC, "Controls");


		if(fileDialogState.windowActive) GuiLock();

		// Open Button
		if(GuiButton(OPEN_BUTTON_REC, GuiIconText(3, NULL))) {
			fileDialogState.windowActive = true;
		}

		GuiUnlock();

		GuiButton(PLAY_BUTTON_REC, GuiIconText(131, NULL));
		GuiButton(PAUSE_BUTTON_REC, GuiIconText(132, NULL));
		// GuiButton(PAUSE_BUTTON_REC, GuiIconText(133, NULL));

		// if(GuiButton((Rectangle) {CHAPTERS_PANEL_X + 10 , CHAPTERS_PANEL_Y + 50, CHAPTERS_PANEL_WIDTH - 20, 50}, "Chapter 1")){
		// 	buttonClicked = true;
		// }

		GuiWindowFileDialog(&fileDialogState);

		EndDrawing();
	}

	CloseWindow();
	return 0;
}