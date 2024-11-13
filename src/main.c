#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

#define WIDTH (800)
#define HEIGHT (600)

int main()
{
    InitWindow(WIDTH, HEIGHT, "Audioglyph");
    SetWindowSize(WIDTH, HEIGHT);
    SetTargetFPS(60);

		/* ---- Sizes START ----*/

		// Chapters Panel
		const int CHAPTERS_PANEL_WIDTH = 200;
		const int CHATPERS_PANEL_HEIGHT = HEIGHT;
		const int CHAPTERS_PANEL_X = (WIDTH - CHAPTERS_PANEL_WIDTH);
		const int CHAPTERS_PANEL_Y = 0;	

		// Top Menu
		const int TOP_MENU_WIDTH = (WIDTH - CHAPTERS_PANEL_WIDTH);
		const int TOP_MENU_HEIGHT = 35;
		const int TOP_MENU_X = 0;
		const int TOP_MENU_Y = 0;
		

		// Controls Panel
		const int CONTROLS_PANEL_WIDTH = (WIDTH - CHAPTERS_PANEL_WIDTH);
		const int CONTROLS_PANEL_HEIGHT = 150;
		const int CONTROLS_PANEL_X = 0;
		const int CONTROLS_PANEL_Y = (HEIGHT - CONTROLS_PANEL_HEIGHT);

		/* ---- Sizes END ----*/ 

		bool buttonClicked = false;

    while (!WindowShouldClose())
    {
			BeginDrawing();
			ClearBackground(RAYWHITE);

			// Top Menu Panel	
			GuiPanel((Rectangle) {TOP_MENU_X, TOP_MENU_Y, TOP_MENU_WIDTH, TOP_MENU_HEIGHT} , NULL); 

			// Chapters Panel
			GuiPanel((Rectangle) {CHAPTERS_PANEL_X, CHAPTERS_PANEL_Y, CHAPTERS_PANEL_WIDTH, CHATPERS_PANEL_HEIGHT}, "Chapters"); 

			// Controls Panel
			GuiPanel((Rectangle) {CONTROLS_PANEL_X, CONTROLS_PANEL_Y, CONTROLS_PANEL_WIDTH, CONTROLS_PANEL_HEIGHT}, "Controls");

			if(GuiButton((Rectangle) {CHAPTERS_PANEL_X + 10 , CHAPTERS_PANEL_Y + 50, CHAPTERS_PANEL_WIDTH - 20, 50}, "Chapter 1")){
				buttonClicked = true;
			}


      EndDrawing();
    }

    CloseWindow();
    return 0;
}