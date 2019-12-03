#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
//#include <ctype.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#define NB_FONCTIONALITES 8
/////////////////////////////////// *** LES MODULES POUR AFFICHE LE MENU *** //////////////////////////////////////////////////////
//define les tableaux 1 lignage
#define _1 192
#define _2 193
#define _3 217
#define _4 195
#define _5 197
#define _6 180
#define _7 218
#define _8 194
#define _9 191
#define _0 179
#define _ 196
//define un etablea 2 soulignage
#define __1 200
#define __2 202
#define __3 188
#define __4 204
#define __5 206
#define __6 185
#define __7 201
#define __8 203
#define __9 187
#define __0 186
#define __ 205
//////////////////////////////////////// *** MODULE POUR  GO TO UNE PLACE SPECIFIE *** //////////////////////////////////////////
void gotoxy(int xpos, int ypos)
{
        COORD scrn;
        HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);

        scrn.X = xpos-1;
        scrn.Y = ypos;
        SetConsoleCursorPosition(hOuput, scrn);
}
///////////////////////////////// **** MODULE DES COULEURS *** /////////////////////////////////////////////////////////
void color(int t,int f)
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(H,f*16+t);
}
//////////////////////////////// *** MODULE POUR STOPER LE SYSTEME *** /////////////////////////////////////////////////
int delay(int x) // faire un puase au system pendant c millierseconds
{
	clock_t t1,t2;
	float tmp;
	t1=clock();
	do
	{
		t2=clock();
		tmp=(float)(t2-t1)*1000/CLOCKS_PER_SEC ;

	} while (tmp < x);
	return 0;

}
//////////////////////////// *** MODULE POUR EFFACER L'ECRAN *** ///////////////////////////////////////////////////////////////
void clr_pro(int t,int lig )
{
	int i,j ;
	for (i=110;i>=0;i--)
	{
		if (i == 54) break;
		for (j=lig;j<40;j++)
		{
			gotoxy(i,j);

			color(0,0);
			printf(" ");
			gotoxy(109-i,38-j);
			printf(" ");
		}
		delay(t);
	}
	gotoxy(109,39);

	return ;
}
///////////////////////////////////////// *** MODULE POUR AFFICHE LE CHARGEMENT *** /////////////////////////////////////////////
void chargement()
{
	int h ;
	color(0,15);
	gotoxy(45,20);
	printf("Chargement en cours");
	for (h=0;h<100;h++)
	{
		gotoxy(6+h,22);
		color(9,9);
		printf("  ");
		color(0,15);
		gotoxy(53,21);
		printf("%d%c",h+1,37);
		gotoxy(130,39);
		color(15,15);
		printf(" ");
		if ((h >60) && (h <80)) delay(90);
		else delay(20);
	}
	gotoxy(38,30);
	color(15,0);
	printf("press any key to continue ...");
	getch();
	clr_pro(0,0);
	return ;
}
/////////////////////////////////////////// *** MODULE POUR L'ECRIRE *** ////////////////////////////////////////////////////
int ecrire(char ss[],int tm) // ecrier une chaine de caractaire avec un delay entre les caracteres
{
	int uu ;
	for (uu=0;uu<strlen(ss);uu++)
	{
		delay(tm);
		printf("%c",ss[uu]);

	}
	return 0;
}
/////////////////////////////////////////// *** MODULE POUR ECRIRE ESI *** ///////////////////////////////////////////////////
void esi (int x, int y,int fond,int couleur,int t)
{
	color(couleur,couleur);
	// E
	gotoxy(x,y);
	printf("*******");
	delay(t);
	gotoxy(x,y+1);
	printf("*******");
	delay(t);
	gotoxy(x,y+2);
	printf("**");
	delay(t);
	gotoxy(x,y+3);
	printf("*****");
	delay(t);
	gotoxy(x,y+4);
	printf("*****");
	delay(t);
	gotoxy(x,y+5);
	printf("**");
	delay(t);
	gotoxy(x,y+6);
	printf("*******");
	delay(t);
	gotoxy(x,y+7);
	printf("*******");
	delay(t);
	// S
	gotoxy(x+8,y+7);
	printf("*******");
	delay(t);
	gotoxy(x+8,y+6);
	printf("*******");
	delay(t);
	gotoxy(x+8+5,y+5);
	printf("**");
	delay(t);
	gotoxy(x+8,y+4);
	printf("*******");
	delay(t);
	gotoxy(x+8,y+3);
	printf("*******");
	delay(t);
	gotoxy(x+8,y+2);
	printf("**");
	delay(t);
	gotoxy(x+8,y+1);
	printf("*******");
	delay(t);
	gotoxy(x+8,y);
	printf("*******");
	delay(t);
	// I
	int ii=0,jj=0;
	for (jj=0;jj<6;jj++)
	{
        for (ii = 0;ii<3;ii++)
        {
            gotoxy(x+16+ii,y+7-jj);
            printf("*");
            delay(t);
        }
	}
	// tete
	for (ii=0;ii<3;ii++)
	{
	switch (ii)
	{
	case 0 : color(4,7);
			break;
	case 1 : color(10,7);
			break;
	case 2 : color(9,7);
			break ;
	}
	gotoxy(x+16,y+1);
	printf("%c",_1);
	delay(t);
	gotoxy(x+17,y+1);
	printf("%c",_);
	delay(t);
	gotoxy(x+18,y+1);
	printf("%c",_3);
	delay(t);
	gotoxy(x+16,y);
	printf("%c",_7);
	delay(t);
	gotoxy(x+17,y);
	printf("%c",_);
	delay(t);
	gotoxy(x+18,y);
	printf("%c",_9);
	delay(t);
	}
	color(9,7);
    gotoxy(x+21,y+1);
    ecrire("Ecole nationale\n",20);
    gotoxy(x+21,y+3);
    ecrire("Superieure\n",20);
    gotoxy(x+21,y+5);
    ecrire("d'Informatique",20);
	gotoxy(110,39);
	printf("\n\n\n");
	return;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////
void textbackground(int bcolor)
{
     WORD wColor;
     //We will need this handle to get the current background attribute
     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;

     //We use csbi for the wAttributes word.
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
        //make a color form the current backgound and our forground color
          wColor = (csbi.wAttributes & 0xF) | ((bcolor  << 4 ) & 0xF0);
          SetConsoleTextAttribute(hStdOut, wColor);

     }
}
int wherey()
{
        CONSOLE_SCREEN_BUFFER_INFO coninfo;

        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &coninfo);
        return coninfo.dwCursorPosition.Y;
}

void entete_menu()
{
    system("cls");
    printf("\t\t");
    color(15,1);
    printf("-----------------------------------------------------------------------\n");
    color(0,0);
    printf("\t\t");
    color(15,1);
    printf("|                 Realise par : SEBBAGH DJAMEL EDDINE                 |\n");
    color(0,0);
    printf("\t\t");
    color(15,1);
    printf("-----------------------------------------------------------------------\n\n\n");
}

int afficher(int i) //concerne affichage de menu
{
    color(0,0);
    entete_menu();
    char * tab[]={"1-> elements 1\n","2-> elements 2\n","3-> elements 3\n","4-> elements 4\n","5-> elements 5\n","6-> elements 6\n","7-> elements 7\n","8-> Quitter\n\n"};
    int j=0;
    while (j<8)
    {
        if (j+1 == i)  textbackground(12);
        else textbackground(0);
        {
            gotoxy(10,wherey());
            printf("%s\n",tab[j]);
        }
        j++;
    }
    textbackground(0);
   int choix=i;
   return choix;
}
void menu() {
    int sauv=1,stop=0;
    system("title TP SFSD ");
    system("mode con LINES=40 COLS=110");
    system("color F0");
    esi(35,5,8,0,10);
    chargement();
    color(15,0);
    entete_menu();
    afficher(sauv);
    while(stop==0)
    {
        char c;
        c=getch();
        if (c =='1')
         sauv=afficher(1);
        else if (c=='2')
         sauv=afficher(2);
        else if (c=='3')
         sauv=afficher(3);
         else if (c=='4')
         sauv=afficher(4);
         else if (c=='5')
         sauv=afficher(5);
         else if (c=='6')
         sauv=afficher(6);
         else if (c=='7')
         sauv=afficher(7);
         else if (c=='8')
         sauv=afficher(8);
        else if (c==72)
            {if ((sauv-1)>=1) sauv=afficher(sauv-1);else sauv=afficher(NB_FONCTIONALITES);}
        else if (c==80)
            {if ((sauv+1)<=NB_FONCTIONALITES) sauv=afficher(sauv+1);else sauv=afficher(1);}
        else if (c==13)

        switch(sauv)
        {
            case 1 :
                    system("pause");
                    sauv=afficher(1);
                    break;
            case 2 :
                    system("pause");
                    sauv=afficher(2);
                    break;
            case 3 :
                    system("pause");
                    sauv=afficher(3);
                    break;
            case 4 :
                    system("pause");
                    sauv=afficher(4);
                    break;
            case 5 :
                    system("pause");
                    sauv=afficher(5);
                    break;
            case 6 :
                    system("pause");
                    sauv=afficher(6);
                    break;
            case 7 :
                    system("pause");
                    sauv=afficher(7);
                    break;
            case 8 :
                    exit(1);
            default :exit(0);
        }
    }
}

int main()
{
    menu();
    return 0;
}
