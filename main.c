#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>

int puan;

int main()
{
    system("CLS");
    printf("**********************************\n");
    printf("* Piyango Oyununa Hosgeldiniz!! *");
    printf("\n**********************************\n");

    anaMenu();


    return 0;
}

int anaMenu()
{
	int secim;
	printf("\nLutfen Seciminizi Yapiniz\n");
	printf("\n**********************************\n");
	printf("\n[1]Oyun Oyna");
	printf("\n[2]Cikis\n");
	scanf("%d" , &secim);

	switch(secim){
		case 1:
			oyunOyna();break;
		case 2:
			printf("");break;
        default:
            main();  break;
	}
}

int oyunOyna()
{

	system("CLS");
    printf("Oyun Icin 6 Tane Farkli Sayi Giriniz!\nSayilardan Bildiginize Gore Puan Alacaksiniz!");
    printf("\n6 Dogru Tahmin 256 puan!\n5 Dogru Tahmin 128 puan!\n4 Dogru Tahmin 64 puan!\n3 Dogru Tahmin 32 puan!\n2 Dogru Tahmin 16 puan!\n");
    printf("\n**********************************\n");

    srand(time(NULL));


	int i , j; // döngüler için kullanýlan genel deðiþkenler
	int tut , sirala; // sýralama algoritmasý için kullanýlan bir deðiþken
	int kars , kars2; // karsilastirma için kullanýlan degiskenler
	int tutanSay = 0; // tutanSayisi için kullanýlan deðiþken
	int girilen[6]; // kullanýcýdan alýnan sayi dizisi
	int random[6]; // bilgisayarin random attýðý sayi dizisi

	for(i=0;i<6;i++)
	{
		printf("Lutfen 1 ile 54 arasindaki %d. sayiyi giriniz: " , i+1);
		scanf("%d" , &girilen[i]);

		if(girilen[i] < 1  ||  girilen[i] > 54 )
		{
			printf("Lutfen tekrar giriniz!!!\n");
			i=i-1;
		}

		for(j=0;j<i;j++)
		{
			if(girilen[i] == girilen[j]){
				printf("Farkli Sayi Girmelisiniz!\n");
				i = i-1;
			}
		}

	}

	printf("\nGirilen Sayilar -- ");


	for(sirala=0;sirala<6;sirala++) // Sýralama Döngüsü
	{
		for(j=0;j<6-1; j++)
		{
			if(girilen[j] > girilen[j+1])
			{
				tut = girilen[j];
				girilen[j] = girilen[j+1];
				girilen[j+1] = tut;

			}
		}
	}

	for(i=0;i<6;i++)
	{
		printf("%d\t " , girilen[i]);
	}


	printf("\n\nRandom Sayilar -- ");

	for(i=0;i<6;i++)
	{
		random[i]=1+rand()%20;
		if(random[i] < 1  ||  random[i] > 54 )
		{
			i=i-1;
		}

		for(j=0;j<i;j++)
		{
			if(random[i] == random[j]){
				i = i-1;
			}
		}
	}


	for(sirala=0;sirala<6;sirala++) // Sýralama Döngüsü
	{
		for(j=0;j<6-1; j++)
		{
			if(random[j] > random[j+1])
			{
				tut = random[j];
				random[j] = random[j+1];
				random[j+1] = tut;

			}
		}
	}

	for(i=0;i<6;i++)
	{
		printf("%d\t " , random[i]);
	}


	for(kars = 0;kars<6;kars++){
		for(kars2 = 0; kars2 <6; kars2++)
		{
			if(girilen[kars] == random[kars2])
			{
				tutanSay = tutanSay+1;
				break;
			}
		}
	}

	printf("\n\nTutan Sayisi : %d " , tutanSay);

	if(tutanSay == 3)
	{
		puan = puan +  32;
	}

	else if(tutanSay == 4)
	{
		puan =puan + 64;
	}

	else if(tutanSay == 2)
	{
		puan =puan + 16;
	}

	else if(tutanSay == 5)
	{
		puan = puan + 128;
	}

	else if (tutanSay == 6)
	{
		puan = puan + 256;
	}

	else
	{
		puan = puan + 0;
	}

	printf("\n\nPuaniniz : %d " , puan);

	oyunSorgu();



}

int oyunSorgu()
{
    char secim;

	printf("\n\nTekrar Oynamak Ister Misiniz? E/H");
	printf("\n**********************************\n");
	scanf("%c" , &secim);

	switch(secim){
		case 'e':
			oyunOyna();break;
		case 'E':
			oyunOyna();break;
        case 'h':
			main();break;
        case 'H':
			main();break;
        default:
            oyunSorgu(); break;
	}
}
