//*MEDICAL STORE by AYUSH JAIN*//
//*FINAL C PROJECT OF 1st SEMESTER*//
//*HEADER FILES*//
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#define PATH"c:\\tc\\bgi"
#include<string.h>
//*screen 1*//
void screen1()
 {
 int gd=DETECT,gm;
 initgraph(&gd,&gm,PATH);
 setfillstyle(SOLID_FILL,RED);
 bar(0,0,640,480);
 setfillstyle(SOLID_FILL,WHITE);
 bar(15,15,625,465);
 setfillstyle(SOLID_FILL,RED);
 //*for filling color*//
 bar(30,30,610,450);
 //*for constructing 2D bar*//
 settextstyle(1,0,8);
 setcolor(WHITE);
 outtextxy(190,35,"JIIT");
 setfillstyle(SOLID_FILL,LIGHTGRAY);
 bar3d(180,140,385,130,20,20);
 //* for costruct a 3D bar*//
 outtextxy(160,150,"MEDICAL");
 bar3d(140,255,440,245,20,20);
 outtextxy(165,270,"STORE");
 bar3d(145,375,440,365,20,20);
 getch();
 closegraph();
 restorecrtmode();
 //*restore the original video mode detected by initgraph*//
 }     //*here screen 1 coplete*//
 //*for end screen *//
void endscr()
 {
 int gd=DETECT,gm;
 initgraph(&gd,&gm,PATH);
 setfillstyle(SOLID_FILL,RED);
 bar(0,0,640,480);
 setfillstyle(SOLID_FILL,WHITE);
 bar(15,15,625,465);
 setfillstyle(SOLID_FILL,RED);
 bar(30,30,610,450);
 settextstyle(1,0,8);
 setcolor(WHITE);
 outtextxy(190,35,"GET");
 setfillstyle(SOLID_FILL,LIGHTGRAY);
 bar3d(180,140,385,130,20,20);
 outtextxy(160,150,"WELL");
 bar3d(140,255,440,245,20,20);
 outtextxy(165,270,"SOON");
 bar3d(145,375,440,365,20,20);
 getch();
 closegraph();
 restorecrtmode();
 }
      //*here screen end complete*//
      //*the main menu or page2*//

char file()
{
	int gd=DETECT, gm;
	int i;
	initgraph(&gd,&gm,"c:\\tc\\bgi");
	setcolor(RED);
	rectangle(170,85,430,385);
	rectangle(175,90, 425,380);
	setcolor(GREEN);
	settextstyle(7,0,4);
	outtextxy(130,45,"THE MEDICAL SHOP.");
	settextstyle(7,0,3);
	frame();
	setcolor(YELLOW);
	outtextxy(260,95,"MENU");
	settextstyle(0,0,0);
	setcolor(MAGENTA);
	outtextxy(200,145,"1>>ADD A NEW MEDICINE.");
	outtextxy(200,170,"2>>SEARCH A MEDICINE.");
	outtextxy(200,195,"3>>EXIT.");

	setcolor(GREEN+BLINK);
	outtextxy(200,360,"ENTER YOUR CHOICE:1/2/3.");
	setcolor(RED);
	outtextxy(480,350,"made by:");
	setcolor(BLUE);
	outtextxy(480,370,"AYUSH JAIN (9103553)");

	i=getch();
	restorecrtmode();
	return (i);
}
//*here page2 ends*//
//*welcome scrren*//
frame()
{
int gdriver=DETECT,gmod;
initgraph(&gdriver,&gmod,"c:\\tc\\bgi");
setcolor(RED);
rectangle(170,85,430,385);
setcolor(RED+BLINK);
settextstyle(7,0,4);
outtextxy(250,0,"WELCOME");
setfillstyle(1,4);
bar(0,220,100,240);
bar(40,170,60,300);
bar(540,220,640,240);
bar(580,170,600,300);
}
//*for option 1 this is the page*//
void medicinei()
{
	int i;
	char nam[10],company[10],men[20],exp[20],number[20],ch;

	FILE *fp;
      //*using of file in C*//
	fp=fopen("medicine.txt","a");


	gotoxy(32,4);
	textcolor(RED+BLINK);
	cprintf("ADD A NEW MEDICINE");
	gotoxy(25,6);
	textcolor(GREEN);
	cprintf("1.ENTER NAME OF MEDICINE: ");
	gotoxy(27,7);
	gets(nam);

	gotoxy(25,8);
	cprintf("2.ENTER NAME OF MANIFACTURING CONPANY: ");
	gotoxy(27,9);
	gets(company);

	gotoxy(25,10);
	cprintf("3.ENTER DATE OF MANIFACTURING AS DD/MM/YYYY:");
	gotoxy(27,11);
	gets(men);

	gotoxy(25,12);
	cprintf("4.ENTER EXP. DATE AS DD/MM/YYYY:");
	gotoxy(27,13);
	gets(exp);

	gotoxy(25,14);
	cprintf("5.QANTITY OF MEDICINE YOU HAVE:");
	gotoxy(27,15);
	gets(number);

	 gotoxy(29,21);
	textcolor(MAGENTA + BLINK);
	cprintf("SAVE CHANGES (y/n)?");
	ch=getch();
	if(ch=='y'||ch=='Y')
	{
		fprintf(fp,"%s %s %s %s %s ",nam,company,men,exp,number);
		fflush(stdin);
	}
	fclose(fp);
}
//*ends page 3*//
/**********************OUTPUT FOR MEDICINE'S DATAS**************************/
void medicine()
{
	int i;
	//*USE OF STRUCTURE*//
	struct medicine
	{
		char nam[10],company[10],men[20],exp[20],number[20];
	}t;
	FILE *fp;
	fp=fopen("medicine.txt","r");

	textcolor(GREEN);
	gotoxy(1,2);
	cprintf("NAME");
	gotoxy(15,2);
	cprintf("COMPANY");
	gotoxy(29,2);
	cprintf("MANIFACTURING DATE");
	gotoxy(50,2);
	cprintf("EXPIRY DATE");
	gotoxy(70,2);
	cprintf("QUANTITY");
	i=4;
	while(fscanf(fp,"%s %s %s %s %s ",t.nam,t.company,t.men,t.exp,t.number)!=EOF)
	{
	gotoxy(1,i);
	printf("%s",t.nam);
	gotoxy(15,i);
	printf("%s",t.company);
	gotoxy(29,i);
	printf("%s",t.men);
	gotoxy(50,i);
	printf("%s",t.exp);
	gotoxy(70,i);
	printf("%s",t.number);
	i++;
	}
       //* OPTION 2 ENDS HERE  *//

}
	//*main function*//
void main()
{
char ch ='a';
clrscr();
screen1();
while(ch!='0')
{
ch=file();
textcolor(WHITE);
switch(ch)
{
case'1':
medicinei();
break;

case '2':
medicine();
getch();
break;


case'3':
endscr();
exit();
   }
  }
}
//*************************PROGGRAM ENDS************************************//