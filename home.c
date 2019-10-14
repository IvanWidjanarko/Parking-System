#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <string.h>

#include "menu_choice.h"

#define panah_atas 80
#define panah_bawah 72
#define escape 27 
#define enter 13

#define AwalMotor 6 //Jumlah Maksimal Sepeda Motor = 6-1 = 5
#define AwalMobil 4 //Jumlah Maksimal Mobil = 4-1 = 3
#define MaksMotor 1200 //Maksimal 1200 detik
#define MaksMobil 2400 //Maksimal 2400 detik
#define BiayaMotor 100 //Rp 100 per detik
#define BiayaMobil 500 //Rp 500 per detik
#define DendaMotor 1000000 //Denda Rp 1.000.000,00 jika lupa nomor tiket
#define DendaMobil 2000000 //Denda Rp 2.000.000,00 jika lupa nomor tiket

void Help()
{
	gotoxy(0,34);
	printf("Note:\n");
	printf("1) Gunakanlah Panah Atas atau Bawah untuk menggerakan Cursor.\n");
	printf("2) Tekan ENTER untuk memilih menu.\n");
}

void Info()
{
	gotoxy(85,34);
	printf("Harga Tiket:\n");
	gotoxy(87,35);
	printf("Motor : Rp %d per detik, Maksimal : Rp %d, Denda : Rp %d\n", BiayaMotor, (MaksMotor*BiayaMotor), DendaMotor);
	gotoxy(87,36);
	printf("Mobil : Rp %d per detik, Maksimal : Rp %d, Denda : Rp %d\n", BiayaMobil, (MaksMobil*BiayaMobil), DendaMobil);
	
	gotoxy(85,38);
	printf("Jumlah Lahan Parkir:\n");
	gotoxy(87,39);
	printf("Motor : %d\n", AwalMotor-1);
	gotoxy(87,40);
	printf("Mobil : %d\n", AwalMobil-1);
}

void FrontLogo()
{
	system("color 0a");
	system("title Parking System");
	char txt[200], c;
	FILE *logo;
	Fullscreen();
	logo = fopen("banner.txt","r");
	c = fgetc(logo);
	while (c != EOF) 
    { 
        printf ("%c", c); 
        c = fgetc(logo); 
    } 
  	fclose(logo); 
  	printf("\n");
  	system("pause");
}

void Arrow(int a[])
{
	char panah=62;
	if (a[0]==1)
	{
		gotoxy(69,22);
		printf("%c%c%c",panah,panah,panah);
		gotoxy(69,24);
		printf("%c%c%c",0,0,0);
		gotoxy(69,26);
		printf("%c%c%c",0,0,0);
		gotoxy(69,28);
		printf("%c%c%c",0,0,0);
	}
	else if (a[1]==1)
	{
		gotoxy(69,22);
		printf("%c%c%c",0,0,0);
		gotoxy(69,24);
		printf("%c%c%c",panah,panah,panah);
		gotoxy(69,26);
		printf("%c%c%c",0,0,0);
		gotoxy(69,28);
		printf("%c%c%c",0,0,0);
	}
	else if (a[2]==1)
	{
		gotoxy(69,22);
		printf("%c%c%c",0,0,0);
		gotoxy(69,24);
		printf("%c%c%c",0,0,0);
		gotoxy(69,26);
		printf("%c%c%c",panah,panah,panah);
		gotoxy(69,28);
		printf("%c%c%c",0,0,0);
	}
	else if (a[3]==1)
	{
		gotoxy(69,22);
		printf("%c%c%c",0,0,0);
		gotoxy(69,24);
		printf("%c%c%c",0,0,0);
		gotoxy(69,26);
		printf("%c%c%c",0,0,0);
		gotoxy(69,28);
		printf("%c%c%c",panah,panah,panah);
	}
	gotoxy(0,37);
}

void Menu()
{
	char inp;
	int i=0,func_arr[4];
	memset(func_arr,0,sizeof(func_arr));
	func_arr[i]=1;
	gotoxy(73,22);
	printf("Masuk Parkir");
	gotoxy(73,24);
	printf("Keluar Parkir");
	gotoxy(73,26);
	printf("Jumlah Parkir Tersedia");
	gotoxy(73,28);
	printf("Keluar Aplikasi");
	Arrow(func_arr);
	Help();
	Info();
	gotoxy(0,37);
	inp = getch();
	while(inp!=enter)
	{
		gotoxy(0,0);
		if(inp==panah_atas)
		{
			i+=1;
			if(i==4)
			{i=0;}
			memset(func_arr,0,sizeof(func_arr));
			func_arr[i]=1;
			Arrow(func_arr);
		}
		else if(inp==panah_bawah)
		{
			i-=1;
			if(i==-1)
			{i=3;}
			memset(func_arr,0,sizeof(func_arr));
			func_arr[i]=1;
			Arrow(func_arr);
		}
		inp = getch();
	}
	gotoxy(0,50);
	if(func_arr[0]==1)
	{MasukParkir();}
	else if(func_arr[1]==1)
	{KeluarParkir();}
	else if(func_arr[2]==1)
	{JumlahParkirTersedia();}
	else if(func_arr[3]==1)
	{Keluar();}
}

void Ulang(int a)
{
	char inp;
	int i=0,func_arr[2];
	memset(func_arr,0,sizeof(func_arr));
	func_arr[i]=1;
	gotoxy(73,22);
	printf("Input Lagi");
	gotoxy(73,24);
	printf("Ke Menu");
	Arrow(func_arr);
	Help();
	gotoxy(0,37);
	inp = getch();
	while(inp!=enter)
	{
		gotoxy(0,0);
		if(inp==panah_atas)
		{
			i+=1;
			if(i==2)
			{i=0;}
			memset(func_arr,0,sizeof(func_arr));
			func_arr[i]=1;
			Arrow(func_arr);
		}
		else if(inp==panah_bawah)
		{
			i-=1;
			if(i==-1)
			{i=3;}
			memset(func_arr,0,sizeof(func_arr));
			func_arr[i]=1;
			Arrow(func_arr);
		}
		inp = getch();
	}
	gotoxy(0,50);
	if(func_arr[0]==1)
	{
		if(a==1)
		{
			MasukParkir();
		}
		
		else if(a==2)
		{
			KeluarParkir();
		}
	}
	else if(func_arr[1]==1)
	{
		system("cls");
		HomeLogo();
		Menu();
	}
}

int LupaTiket()
{
	char inp;
	int i=0,func_arr[2];
	memset(func_arr,0,sizeof(func_arr));
	func_arr[i]=1;
	gotoxy(73,22);
	printf("Lupa");
	gotoxy(73,24);
	printf("Ingat");
	Arrow(func_arr);
	Help();
	gotoxy(0,37);
	inp = getch();
	while(inp!=enter)
	{
		gotoxy(0,0);
		if(inp==panah_atas)
		{
			i+=1;
			if(i==2)
			{i=0;}
			memset(func_arr,0,sizeof(func_arr));
			func_arr[i]=1;
			Arrow(func_arr);
		}
		else if(inp==panah_bawah)
		{
			i-=1;
			if(i==-1)
			{i=1;}
			memset(func_arr,0,sizeof(func_arr));
			func_arr[i]=1;
			Arrow(func_arr);
		}
		inp = getch();
	}
	gotoxy(0,50);
	if(func_arr[0]==1)
	{
	{system("cls"); int a = Lupa(); return a;}
	}
	else if(func_arr[1]==1)
	{return 1;}
}

int Lupa()
{
	char inp;
	int i=0,func_arr[2];
	memset(func_arr,0,sizeof(func_arr));
	func_arr[i]=1;
	gotoxy(30,18);
	printf("Apakah Anda Ingin Tetap Keluar?\n");
	gotoxy(73,22);
	printf("Tetap Keluar (Denda Rp 1.000.000,00)");
	gotoxy(73,24);
	printf("Batal");
	Arrow(func_arr);
	Help();
	gotoxy(0,37);
	inp = getch();
	while(inp!=enter)
	{
		gotoxy(0,0);
		if(inp==panah_atas)
		{
			i+=1;
			if(i==2)
			{i=0;}
			memset(func_arr,0,sizeof(func_arr));
			func_arr[i]=1;
			Arrow(func_arr);
		}
		else if(inp==panah_bawah)
		{
			i-=1;
			if(i==-1)
			{i=1;}
			memset(func_arr,0,sizeof(func_arr));
			func_arr[i]=1;
			Arrow(func_arr);
		}
		inp = getch();
	}
	gotoxy(0,50);
	if(func_arr[0]==1)
	{return 2;}
	else if(func_arr[1]==1)
	{system("cls"); HomeLogo(); Menu();}
}

int Jenis()
{
	char inp;
	int i=0,func_arr[3];
	memset(func_arr,0,sizeof(func_arr));
	func_arr[i]=1;
	gotoxy(73,22);
	printf("Sepeda Motor");
	gotoxy(73,24);
	printf("Mobil");
	gotoxy(73,26);
	printf("Ke Menu");
	Arrow(func_arr);
	Help();
	gotoxy(0,37);
	inp = getch();
	while(inp!=enter)
	{
		gotoxy(0,0);
		if(inp==panah_atas)
		{
			i+=1;
			if(i==3)
			{i=0;}
			memset(func_arr,0,sizeof(func_arr));
			func_arr[i]=1;
			Arrow(func_arr);
		}
		else if(inp==panah_bawah)
		{
			i-=1;
			if(i==-1)
			{i=2;}
			memset(func_arr,0,sizeof(func_arr));
			func_arr[i]=1;
			Arrow(func_arr);
		}
		inp = getch();
	}
	gotoxy(0,50);
	if(func_arr[0]==1)
	{
		system("cls");
		return 1;
	}
	else if(func_arr[1]==1)
	{
		system("cls");
		return 2;
	}
	else if(func_arr[2]==1)
	{
		system("cls");
		HomeLogo();
		Menu();
	}
}

void HomeLogo()
{
	system("cls");
	char txt2[200], c2;
	FILE *logo2;
	logo2 = fopen("banner2.txt","r");
	c2 = fgetc(logo2);
	while (c2 != EOF) 
    { 
        printf ("%c", c2); 
        c2 = fgetc(logo2); 
    } 
  	fclose(logo2);
}
