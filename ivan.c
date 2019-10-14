#include <stdio.h>
#include <windows.h>


void Type(char* a, int b)
{
	int i;
	for(i=0;i<strlen(a);i++)
	{
		printf("%c",a[i]);
		Sleep(b);
	}
}

void Welcome()
{
	system("cls");
	Sleep(50);
	gotoxy(75,20);
	Type("PARKING SYSTEM",30);
	gotoxy(74,21);
	Type("Park it, it Lost", 30);
	Sleep(1000);
	gotoxy(68,22);
    system("pause");
}

void Delay(int y)
{   
	int x,z;
    for(x=0;x<y;x++)
	{z=x;}
}
