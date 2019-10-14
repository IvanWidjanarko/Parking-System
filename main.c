#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <math.h>

#include "home.h"
#include "ivan.h"
#include "menu_choice.h"

void Fullscreen();
void gotoxy(int x, int y);

int main()
{
	FrontLogo();
	system("cls");
	Welcome();
	HomeLogo();
	Menu(); 
}

void Fullscreen()
{  keybd_event(VK_MENU,
				0x38,
				0,
				0);
	keybd_event(VK_RETURN,
				0x1c,
				0,
				0);
	keybd_event(VK_RETURN,
				0x1c,
				KEYEVENTF_KEYUP,
				0);
	keybd_event(VK_MENU,
				0x38,
				KEYEVENTF_KEYUP,
				0);
}

void gotoxy(int x, int y)
{
	COORD koordinat;
	koordinat.X = x;
	koordinat.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), koordinat);
}
