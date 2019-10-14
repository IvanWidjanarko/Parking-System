#include <stdio.h>
#include <time.h>
#include <windows.h>

#define AwalMotor 6 //Jumlah Maksimal Sepeda Motor = 6-1 = 5
#define AwalMobil 4 //Jumlah Maksimal Mobil = 4-1 = 3
#define MaksMotor 1200 //Maksimal 1200 detik
#define MaksMobil 1240 //Maksimal 2400 detik
#define BiayaMotor 100 //Rp 100 per detik
#define BiayaMobil 500 //Rp 500 per detik
#define DendaMotor 1000000 //Denda Rp 1.000.000,00 jika lupa nomor tiket
#define DendaMobil 2000000 //Denda Rp 2.000.000,00 jika lupa nomor tiket

struct identitas{
    char Plat_Nomor[10];
    int Nomor_Tiket;
    int Tanggal;
    int Bulan;
    int Tahun;
    int Jam;
    int Menit;
    int Detik;
    int Jumlah_Kendaraan;
    int Lahan_Parkir;
}inMotor, inMobil, outMotor, outMobil, allMotor, allMobil;

void MasukParkir()
{
	time_t currentTime;
	time (&currentTime);
	struct tm *myTime = localtime(&currentTime);
	FILE *MasukMotor, *MasukMobil;
	system("cls");
	
	int e = Jenis();
	
	if (e==1)
	{
		int a=0;
		MasukMotor = fopen ("MasukMotor.txt", "a+");
		
		int i =Jumlah_Baris("MasukMotor.txt");
		if(i>=(AwalMotor))
		{
			gotoxy(30,18);
			printf("Maaf Parkiran Sepeda Motor Penuh\n");
			gotoxy(30,19);
			printf("Cobalah Beberapa Saat Lagi");
			gotoxy(30,20);
			system("Pause");
			fclose(MasukMotor);
			HomeLogo();
			Menu();
		}
		
		else
		{
			gotoxy(30,18);
			printf("Masukkan Plat Nomor kendaraan Anda [Contoh B1234ABC]: ");
		    scanf("%s", allMotor.Plat_Nomor);
		    
		    while(fscanf(MasukMotor, "Plat_Nomor: %s Tanggal: %d/%d/%d Waktu: %d:%d:%d Kendaraan_Ke: %d Tiket: %d\n", inMotor.Plat_Nomor, &inMotor.Tanggal, &inMotor.Bulan, &inMotor.Tahun, &inMotor.Jam, &inMotor.Menit, &inMotor.Detik, &inMotor.Jumlah_Kendaraan, &inMotor.Nomor_Tiket)!=EOF)
			{
		    	if(strcmp(allMotor.Plat_Nomor, inMotor.Plat_Nomor)==0)
		    	{
		    		a=1;
		    		break;
				}
			}
			
			if(a==1)
			{
				system("cls");
				gotoxy(30,18);
				printf("Maaf Nomor Kendaraan Anda Sudah Tercatat dan Belum Keluar dari Lahan Parkir\n");
				gotoxy(30,20);
				system("Pause");
				fclose(MasukMotor);
				HomeLogo();
				Menu();
			}
		    
		    else if(a==0)
		    {
				inMotor.Tanggal=myTime->tm_mday; inMotor.Bulan=myTime->tm_mon+1; inMotor.Tahun=myTime->tm_year-100; inMotor.Jam=myTime->tm_hour; inMotor.Menit=myTime->tm_min; inMotor.Detik=myTime->tm_sec;
				system("cls");
				gotoxy(35,19);
				printf("Mohon tunggu sejenak untuk memperoleh nomor tiket parkir Anda!\n");
				gotoxy(35,20);
				system("Pause");
				system("cls");
				
				inMotor.Jumlah_Kendaraan++;
				
				gotoxy(35,16);
				inMotor.Nomor_Tiket = inMotor.Tanggal*100000000 + inMotor.Bulan*1000000 + inMotor.Tahun*10000 + inMotor.Jam*100 + inMotor.Jumlah_Kendaraan;
				printf("Nomor Tiket Parkir Anda : %d\n", inMotor.Nomor_Tiket);
				gotoxy(35,17);
				printf("Mohon Dicatat Nomor Tiket Anda\n");
				gotoxy(35,18);
				printf("Jika tiket parkir hilang / lupa nomor tiket, maka akan dikenakan denda Rp %d\n", DendaMotor);
			    fprintf(MasukMotor, "Plat_Nomor: %s Tanggal: %d/%d/%d Waktu: %d:%d:%d Kendaraan_Ke: %d Tiket: %d\n", allMotor.Plat_Nomor, inMotor.Tanggal, inMotor.Bulan, inMotor.Tahun, inMotor.Jam, inMotor.Menit, inMotor.Detik, inMotor.Jumlah_Kendaraan, inMotor.Nomor_Tiket);
				fclose(MasukMotor);
				
				Ulang(1);
			}
		}
	}
	
	if (e==2)
	{
		int z=0;
		MasukMobil = fopen ("MasukMobil.txt", "a+");
		
		int i =Jumlah_Baris("MasukMobil.txt");
		if(i>=(AwalMobil))
		{
			gotoxy(30,18);
			printf("Maaf Parkiran Mobil Penuh\n");
			gotoxy(30,19);
			printf("Cobalah Beberapa Saat Lagi");
			gotoxy(30,20);
			system("Pause");
			fclose(MasukMobil);
			HomeLogo();
			Menu();
		}
		
		else
		{
			gotoxy(30,18);
			printf("Masukkan Plat Nomor kendaraan Anda [Contoh B1234ABC]: ");
		    scanf("%s", allMobil.Plat_Nomor);
		    
		    while(fscanf(MasukMobil, "Plat_Nomor: %s Tanggal: %d/%d/%d Waktu: %d:%d:%d Kendaraan_Ke: %d Tiket: %d\n", inMobil.Plat_Nomor, &inMobil.Tanggal, &inMobil.Bulan, &inMobil.Tahun, &inMobil.Jam, &inMobil.Menit, &inMobil.Detik, &inMobil.Jumlah_Kendaraan, &inMobil.Nomor_Tiket)!=EOF)
			{
		    	if(strcmp(allMobil.Plat_Nomor, inMobil.Plat_Nomor)==0)
		    	{
		    		z=1;
		    		break;
				}
			}
			
			if(z==1)
			{
				system("cls");
				gotoxy(30,18);
				printf("Maaf Nomor Kendaraan Anda Sudah Tercatat dan Belum Keluar dari Lahan Parkir\n");
				gotoxy(30,20);
				system("Pause");
				fclose(MasukMobil);
				HomeLogo();
				Menu();
			}
		    
		    else if(z==0)
		    {
				inMobil.Tanggal=myTime->tm_mday; inMobil.Bulan=myTime->tm_mon+1; inMobil.Tahun=myTime->tm_year-100; inMobil.Jam=myTime->tm_hour; inMobil.Menit=myTime->tm_min; inMobil.Detik=myTime->tm_sec;
				system("cls");
				gotoxy(35,19);
				printf("Mohon tunggu sejenak untuk memperoleh nomor tiket parkir Anda!\n");
				gotoxy(35,20);
				system("Pause");
				system("cls");
				
				inMobil.Jumlah_Kendaraan++;
				
				gotoxy(35,16);
				inMobil.Nomor_Tiket = inMobil.Tanggal*100000000 + inMobil.Bulan*1000000 + inMobil.Tahun*10000 + inMobil.Jam*100 + inMobil.Jumlah_Kendaraan;
				printf("Nomor Tiket Parkir Anda : %d\n", inMobil.Nomor_Tiket);
				gotoxy(35,17);
				printf("Mohon Dicatat Nomor Tiket Anda\n");
				gotoxy(35,18);
				printf("Jika tiket parkir hilang / lupa nomor tiket, maka akan dikenakan denda Rp %d\n", DendaMobil);
			    fprintf(MasukMobil, "Plat_Nomor: %s Tanggal: %d/%d/%d Waktu: %d:%d:%d Kendaraan_Ke: %d Tiket: %d\n", allMobil.Plat_Nomor, inMobil.Tanggal, inMobil.Bulan, inMobil.Tahun, inMobil.Jam, inMobil.Menit, inMobil.Detik, inMobil.Jumlah_Kendaraan, inMobil.Nomor_Tiket);
				fclose(MasukMobil);
				
				Ulang(1);
			}
		}
	}
}

void KeluarParkir()
{
	int y=0, x=0;
	time_t currentTime;
	time (&currentTime);
	struct tm *myTime = localtime(&currentTime);
	system("cls");
	
	int d=Jenis();
	
	if(d==1)
	{
		FILE *MasukBaruMotor, *MasukMotor;
		MasukBaruMotor = fopen ("RenameMotor.txt", "w");
		MasukMotor = fopen ("MasukMotor.txt", "r");
		
		int i =Jumlah_Baris("MasukMotor.txt");
		if(i<=1)
		{
			gotoxy(30,18);
			printf("Maaf Parkiran Sepeda Motor Kosong\n");
			gotoxy(30,19);
			printf("Tidak ada sepeda motor yang bisa keluar");
			gotoxy(30,20);
			system("Pause");
			fclose(MasukBaruMotor);
			fclose(MasukMotor);
			remove("RenameMotor.txt");
			HomeLogo();
			Menu();
		}
	
		else
		{	
			gotoxy(30,18);
			printf("Apakah Anda Ingat Nomor Tiket Anda?\n");
			int b = LupaTiket();
			
			if(b==1)
			{
				system("cls");
				gotoxy(30,19);
				printf("Masukkan Plat Nomor Kendaraan Anda [Contoh B1234ABC]: ");
			    scanf("%s", outMotor.Plat_Nomor);
			    gotoxy(30,20);
			    printf("Masukkan Nomor Tiket Anda : ");
			    scanf("%d", &outMotor.Nomor_Tiket);
			    outMotor.Tanggal=myTime->tm_mday; outMotor.Bulan=myTime->tm_mon+1; outMotor.Tahun=myTime->tm_year-100; outMotor.Jam=myTime->tm_hour; outMotor.Menit=myTime->tm_min; outMotor.Detik=myTime->tm_sec;
				
				while(fscanf(MasukMotor, "Plat_Nomor: %s Tanggal: %d/%d/%d Waktu: %d:%d:%d Kendaraan_Ke: %d Tiket: %d\n", inMotor.Plat_Nomor, &inMotor.Tanggal, &inMotor.Bulan, &inMotor.Tahun, &inMotor.Jam, &inMotor.Menit, &inMotor.Detik, &inMotor.Jumlah_Kendaraan, &inMotor.Nomor_Tiket)!=EOF)
				{
			    	if(strcmp(outMotor.Plat_Nomor, inMotor.Plat_Nomor)==0 && outMotor.Nomor_Tiket==inMotor.Nomor_Tiket)
			    	{
			    		y=1;
			    		continue;
					}
			    	else
			    	{
			    		fprintf(MasukBaruMotor, "Plat_Nomor: %s Tanggal: %d/%d/%d Waktu: %d:%d:%d Kendaraan_Ke: %d Tiket: %d\n",inMotor.Plat_Nomor, inMotor.Tanggal, inMotor.Bulan, inMotor.Tahun, inMotor.Jam, inMotor.Menit, inMotor.Detik, inMotor.Jumlah_Kendaraan, inMotor.Nomor_Tiket);
					}
				}
				
				if(y==1)
				{
					system("cls");
					int JamMotor = (outMotor.Jam-inMotor.Jam)*3600;
					int MenitMotor = (outMotor.Menit-inMotor.Menit)*60;
					int DetikMotor = (outMotor.Detik-inMotor.Detik);
					int TotalMotor = JamMotor+MenitMotor+DetikMotor;
					int HargaMotor;
					if (TotalMotor<=MaksMotor)
					{
						HargaMotor = TotalMotor*BiayaMotor;
					}
					else if(TotalMotor>MaksMotor)
					{
						int MaksimalMotor=(MaksMotor*BiayaMotor); //Harga Maksimal Rp. 120.000
						HargaMotor = MaksimalMotor;
					}
					gotoxy(35,19);
					printf("Biaya Parkir yang Harus Dibayar : Rp %d\n", HargaMotor);
					goto rename1;
				}
				
				else if(y==0)
				{
					system("cls");
					gotoxy(35,19);
					printf("Maaf Nomor Plat Kendaraan atau Nomor Tiket yang Anda Masukkan Salah!!!\n");
				}
				
				rename1:
				fclose(MasukMotor);
				fclose(MasukBaruMotor);
				remove("MasukMotor.txt");
				rename("RenameMotor.txt", "MasukMotor.txt");
				
				Ulang(2);
			}
			
			else if(b==2)
			{
				system("cls");
				gotoxy(30,19);
				printf("Masukkan Plat Nomor Kendaraan Anda [Contoh B1234ABC]: ");
			    scanf("%s", outMotor.Plat_Nomor);
			    outMotor.Tanggal=myTime->tm_mday; outMotor.Bulan=myTime->tm_mon+1; outMotor.Tahun=myTime->tm_year-100; outMotor.Jam=myTime->tm_hour; outMotor.Menit=myTime->tm_min; outMotor.Detik=myTime->tm_sec;
				
				while(fscanf(MasukMotor, "Plat_Nomor: %s Tanggal: %d/%d/%d Waktu: %d:%d:%d Kendaraan_Ke: %d Tiket: %d\n", inMotor.Plat_Nomor, &inMotor.Tanggal, &inMotor.Bulan, &inMotor.Tahun, &inMotor.Jam, &inMotor.Menit, &inMotor.Detik, &inMotor.Jumlah_Kendaraan, &inMotor.Nomor_Tiket)!=EOF)
				{
			    	if(strcmp(outMotor.Plat_Nomor, inMotor.Plat_Nomor)==0)
			    	{
			    		y=1;
			    		continue;
					}
			    	else
			    	{
			    		fprintf(MasukBaruMotor, "Plat_Nomor: %s Tanggal: %d/%d/%d Waktu: %d:%d:%d Kendaraan_Ke: %d Tiket: %d\n",inMotor.Plat_Nomor, inMotor.Tanggal, inMotor.Bulan, inMotor.Tahun, inMotor.Jam, inMotor.Menit, inMotor.Detik, inMotor.Jumlah_Kendaraan, inMotor.Nomor_Tiket);
					}
				}
				
				if(y==1)
				{
					system("cls");
					int HargaMotor = DendaMotor;
					gotoxy(35,19);
					printf("Biaya Parkir yang Harus Dibayar : Rp %d\n", HargaMotor);
					goto rename2;
				}
				
				else if(y==0)
				{
					system("cls");
					gotoxy(35,19);
					printf("Maaf Nomor Plat Kendaraan yang Anda Masukkan Salah!!!\n");
				}
				
				rename2:
				fclose(MasukMotor);
				fclose(MasukBaruMotor);
				remove("MasukMotor.txt");
				rename("RenameMotor.txt", "MasukMotor.txt");
				
				Ulang(2);
			}
		}
	}
	
	else if(d==2)
	{
		FILE *MasukBaruMobil, *MasukMobil;
		MasukBaruMobil = fopen ("RenameMobil.txt", "w");
		MasukMobil = fopen ("MasukMobil.txt", "r");
	
		int i =Jumlah_Baris("MasukMobil.txt");
		if(i<=1)
		{
			gotoxy(30,18);
			printf("Maaf Parkiran Kosong\n");
			gotoxy(30,19);
			printf("Tidak ada mobil yang bisa keluar");
			gotoxy(30,20);
			system("Pause");
			fclose(MasukBaruMobil);
			fclose(MasukMobil);
			remove("RenameMobil.txt");
			HomeLogo();
			Menu();
		}
	
		else
		{	
			gotoxy(30,18);
			printf("Apakah Anda Ingat Nomor Tiket Anda?\n");
			int b = LupaTiket();
			
			if(b==1)
			{
				system("cls");
				gotoxy(30,19);
				printf("Masukkan Plat Nomor Kendaraan Anda [Contoh B1234ABC]: ");
			    scanf("%s", outMobil.Plat_Nomor);
			    gotoxy(30,20);
			    printf("Masukkan Nomor Tiket Anda : ");
			    scanf("%d", &outMobil.Nomor_Tiket);
			    outMobil.Tanggal=myTime->tm_mday; outMobil.Bulan=myTime->tm_mon+1; outMobil.Tahun=myTime->tm_year-100; outMobil.Jam=myTime->tm_hour; outMobil.Menit=myTime->tm_min; outMobil.Detik=myTime->tm_sec;
				
				while(fscanf(MasukMobil, "Plat_Nomor: %s Tanggal: %d/%d/%d Waktu: %d:%d:%d Kendaraan_Ke: %d Tiket: %d\n", inMobil.Plat_Nomor, &inMobil.Tanggal, &inMobil.Bulan, &inMobil.Tahun, &inMobil.Jam, &inMobil.Menit, &inMobil.Detik, &inMobil.Jumlah_Kendaraan, &inMobil.Nomor_Tiket)!=EOF)
				{
			    	if(strcmp(outMobil.Plat_Nomor, inMobil.Plat_Nomor)==0 && outMobil.Nomor_Tiket==inMobil.Nomor_Tiket)
			    	{
			    		y=1;
			    		continue;
					}
			    	else
			    	{
			    		fprintf(MasukBaruMobil, "Plat_Nomor: %s Tanggal: %d/%d/%d Waktu: %d:%d:%d Kendaraan_Ke: %d Tiket: %d\n",inMobil.Plat_Nomor, inMobil.Tanggal, inMobil.Bulan, inMobil.Tahun, inMobil.Jam, inMobil.Menit, inMobil.Detik, inMobil.Jumlah_Kendaraan, inMobil.Nomor_Tiket);
					}
				}
				
				if(y==1)
				{
					system("cls");
					int JamMobil = (outMobil.Jam-inMobil.Jam)*3600;
					int MenitMobil = (outMobil.Menit-inMobil.Menit)*60;
					int DetikMobil = (outMobil.Detik-inMobil.Detik);
					int TotalMobil = JamMobil+MenitMobil+DetikMobil;
					int HargaMobil;
					if (TotalMobil<=MaksMobil)
					{
						HargaMobil = TotalMobil*BiayaMobil;
					}
					else if(TotalMobil>MaksMobil)
					{
						int MaksimalMobil=(MaksMobil*BiayaMobil); //Harga Maksimal Rp. 1.200.000
						HargaMobil = MaksimalMobil;
					}
					gotoxy(35,19);
					printf("Biaya Parkir yang Harus Dibayar : Rp %d\n", HargaMobil);
					goto rename3;
				}
				
				else if(y==0)
				{
					system("cls");
					gotoxy(35,19);
					printf("Maaf Nomor Plat Kendaraan atau Nomor Tiket yang Anda Masukkan Salah!!!\n");
				}
				
				rename3:
				fclose(MasukMobil);
				fclose(MasukBaruMobil);
				remove("MasukMobil.txt");
				rename("RenameMobil.txt", "MasukMobil.txt");
				
				Ulang(2);
			}
			
			else if(b==2)
			{
				system("cls");
				gotoxy(30,19);
				printf("Masukkan Plat Nomor Kendaraan Anda [Contoh B1234ABC]: ");
			    scanf("%s", outMobil.Plat_Nomor);
			    outMobil.Tanggal=myTime->tm_mday; outMobil.Bulan=myTime->tm_mon+1; outMobil.Tahun=myTime->tm_year-100; outMobil.Jam=myTime->tm_hour; outMobil.Menit=myTime->tm_min; outMobil.Detik=myTime->tm_sec;
				
				while(fscanf(MasukMobil, "Plat_Nomor: %s Tanggal: %d/%d/%d Waktu: %d:%d:%d Kendaraan_Ke: %d Tiket: %d\n", inMobil.Plat_Nomor, &inMobil.Tanggal, &inMobil.Bulan, &inMobil.Tahun, &inMobil.Jam, &inMobil.Menit, &inMobil.Detik, &inMobil.Jumlah_Kendaraan, &inMobil.Nomor_Tiket)!=EOF)
				{
			    	if(strcmp(outMobil.Plat_Nomor, inMobil.Plat_Nomor)==0)
			    	{
			    		y=1;
			    		continue;
					}
			    	else
			    	{
			    		fprintf(MasukBaruMobil, "Plat_Nomor: %s Tanggal: %d/%d/%d Waktu: %d:%d:%d Kendaraan_Ke: %d Tiket: %d\n",inMobil.Plat_Nomor, inMobil.Tanggal, inMobil.Bulan, inMobil.Tahun, inMobil.Jam, inMobil.Menit, inMobil.Detik, inMobil.Jumlah_Kendaraan, inMobil.Nomor_Tiket);
					}
				}
				
				if(y==1)
				{
					system("cls");
					int HargaMobil = DendaMobil;
					gotoxy(35,19);
					printf("Biaya Parkir yang Harus Dibayar : Rp %d\n", HargaMobil);
					goto rename4;
				}
				
				else if(y==0)
				{
					system("cls");
					gotoxy(35,19);
					printf("Maaf Nomor Plat Kendaraan yang Anda Masukkan Salah!!!\n");
				}
				
				rename4:
				fclose(MasukMobil);
				fclose(MasukBaruMobil);
				remove("MasukMobil.txt");
				rename("RenameMobil.txt", "MasukMobil.txt");
				
				Ulang(2);
			}
		}
	}	
}

void JumlahParkirTersedia()
{
	system("cls");
	
	int c=Jenis();
	
	if(c==1)
	{
		FILE *MasukMotor;
		MasukMotor = fopen ("MasukMotor.txt", "r");
		int i =Jumlah_Baris("MasukMotor.txt");
		int LahanMotor = AwalMotor-i;
		gotoxy(35,20);
		printf("Jumlah Lahan Parkir yang Tersedia adalah %d dari %d\n", LahanMotor, AwalMotor-1);
		gotoxy(35,21);
		system("Pause");
		fclose(MasukMotor);
	}
	
	else if(c==2)
	{
		FILE *MasukMobil;
		MasukMobil = fopen ("MasukMobil.txt", "r");
		int i =Jumlah_Baris("MasukMobil.txt");
		int LahanMobil = AwalMobil-i;
		gotoxy(35,20);
		printf("Jumlah Lahan Parkir yang Tersedia adalah %d dari %d\n", LahanMobil, AwalMobil-1);
		gotoxy(35,21);
		system("Pause");
		fclose(MasukMobil);
	}	
	
	HomeLogo();
	Menu();
}

int Jumlah_Baris(char *filename)
{
	FILE* myfile = fopen(filename, "r");
	int ch, number_of_lines = 0;
	do
	{
	    ch = fgetc(myfile);
	    if(ch == '\n')
	        number_of_lines++;
	}
	while (ch != EOF);
	if(ch != '\n')
	    number_of_lines++;
	fclose(myfile);
	
	return number_of_lines;
}

int Keluar()
{
	FILE *last;
	char x;
	system("cls");
	last = fopen("banner3.txt","r");
	x = fgetc(last);
	while(x!=EOF)
	{
		printf("%c",x);
		x=fgetc(last);
	}
	
	gotoxy(65,30);
	printf("U Can Quit, but U Can't Hide");
	
	return 0;
}
