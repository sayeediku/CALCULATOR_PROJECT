#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>

long double num=0,get,num1=0,result=0;
int button,x,y,x1,y1,x2,y2,s;
long double addnum(int);
char opr;
int a,b,r,i1,count,c,sq,newnum=1,d=0;
union REGS in,out;
void main()
{
  int driver=DETECT,mode;
  int q,p[12];
  char input;
   char *inpu[4][4]={"1","2","3","4",
		  "5","6","7","8",
		  "9","0","+","-" ,
		  "*","/","clr","="};
  char inp[4][4]={'1','2','3','4',
		  '5','6','7','8',
		  '9','0','+','-' ,
		  '*','/','l','='};
		  
  initgraph(&driver,&mode,"C:\\TC\\BGI");
  
  int initmousedetect();
  
  void showpointer();
  void openwindow();
  void closewindow();
  void hidepointer();
  
  void getmouseposition(int *,int*,int*);
  void restrictpointer(int,int,int,int);


  if(initmousedetect()==0)
  {
	printf("not");
	getch();

  }
  openwindow();
  getch();
  cleardevice();

  setfillstyle(1,GREEN);
  bar(236,82,432,300);
  setcolor(GREEN);
  rectangle(238,50,430,80);
  rectangle(237,49,431,81);
  rectangle(236,48,432,82);
  c=240;
  d=100;
  s=0;
   for(a=0;a<4;a++)
  {
	c=240;
	for(b=0;b<4;b++)
	{
	  setfillstyle(1,RED);
	  bar(c,d,c+40,d+40);
	  setcolor(YELLOW);
	  outtextxy(c+10,d+14,inpu[a][b]);
	  c+=50;
	}
	d+=50;
  }
  showpointer();
  num=0;
  gotoxy(36,5);
  printf("%.1Lf",num);
  count=0;
while(!kbhit())
{
  outtextxy(30,20,"Press any key to exit..");
  i1=0;
  c=240;
  d=100;
  rectangle(0,0,638,478);
  getmouseposition(&button,&x,&y);
  for(a=0;a<4;a++)
  {
	c=240;
	for(b=0;b<4;b++)
	{
	  if((x>=c&&x<=c+40)&&(y>=d&&y<=d+40))
	  {
	   if((button&1)==1)
	   {
	 while((button&1)==1)
	 {
	   setcolor(10);
	   rectangle(c,d,c+40,d+40);
	   rectangle(c-1,d-1,c+41,d+41);
	   rectangle(c-2,d-2,c+42,d+42);
	   break;
	 }
	 delay(100);
	 setcolor(GREEN);
	 rectangle(c,d,c+40,d+40);
	 rectangle(c-1,d-1,c+41,d+41);
	 rectangle(c-2,d-2,c+42,d+42);
	 input=inp[a][b];
	 switch(input)
	 {
	 case '1':
		 get=addnum(1);
		 gotoxy(36,5);
		 printf("%.1Lf",get);
		 break;
	 case '2':
		 get=addnum(2);
		 gotoxy(36,5);
		 printf("%.1Lf",get);
		 break;
	  case '3':
		 get=addnum(3);
		 gotoxy(36,5);
		 printf("%.1Lf",get);
		 break;
	   case '4':
		 get=addnum(4);
		 gotoxy(36,5);
		 printf("%.1Lf",get);
		 break;
	 case '5':
		 get=addnum(5);
		 gotoxy(36,5);
		 printf("%.1Lf",get);
		 break;
	 case '6':
		 get=addnum(6);
		 gotoxy(36,5);
		 printf("%.1Lf",get);
		 break;
	 case '7':
		 get=addnum(7);
		 gotoxy(36,5);
		 printf("%.1Lf",get);
		 break;
   case '8':
		 get=addnum(8);
		 gotoxy(36,5);
		 printf("%.1Lf",get);
		 break;
   case '9':
		 get=addnum(9);
		 gotoxy(36,5);
		 printf("%.1Lf",get);
		 break;
   case '0':
		 get=addnum(0);
		 gotoxy(36,5);
		 printf("%.1Lf",get);
		 break;
	case '+':
		 num1=num;
		 num=0;
		 opr='+';
		 gotoxy(36,5);
		 printf("%.1Lf",num);
		 break;
	 case '-':
		 num1=num;
		 num=0;
		 opr='-';
		 gotoxy(36,5);
		 printf("%.1Lf",num);
		break;
	 case '*':
		 num1=num;
		 num=0;
		 opr='*';
		 gotoxy(36,5);
		 printf("%.1Lf",num);
		break;
	 case '/':
		 num1=num;
		 num=0;
		 opr='/';
		 gotoxy(36,5);
		 printf("%.1Lf",num);
		break;
	 case 'l':
		 num=0;
		 num1=0;
		 result=0;
		 count=0;
		 gotoxy(36,5);
		 printf("%.1Lf",num);
		 break;
	 case '=':
		 switch(opr)
		 {
		   case '+':
				 if(count<1)
				 {
				   result=num+num1;
				 }
				 else
				 {
				   result=result+num;
				 }
				 gotoxy(36,5);
				 printf("%.1Lf",result);
				 count+=1;
				 break;
		   case '-':
				 if(count<1)
				 {
				   result=num1-num;
				 }
				 else
				 {
				   result=result-num;
				 }
				 gotoxy(36,5);
				 printf("%.1Lf",result);
				 count+=1;
				 break;
		   case '*':
				 if(count<1)
				 {
				  result=num1*num;
				 }
				 else
				 {
				  result=result*num;
				 }
				 gotoxy(36,5);
				 printf("%.1Lf",result);
				 count+=1;
				 break;
		   case '/':
				 if(count<1)
				 {
				  result=num1/num;
				 }
				 else
				 {
				  result=result/num;
				 }
				 gotoxy(36,5);
				 printf("%.1Lf",result);
				 count+=1;
				 break;
		 }
	 }
	   }
	  }
	  c+=50;
	}
	d+=50;
  }
  setcolor(YELLOW);
  delay(150);
}
  getch();
  closewindow();
  getch();
}
long double addnum(int getnum)
{
	num=num*10+getnum;
	return(num);
}
int initmousedetect()
{
	in.x.ax=0;
	int86(0x33,&in,&out);
	return(out.x.ax);
}
void showpointer()
{
   in.x.ax=1;
   int86(0x33,&in,&out);
}
void hidepointer()
{
   in.x.ax=2;
   int86(0x33,&in,&out);
}
void restrictpointer(int x1,int y1,int x2,int y2)
{
	in.x.ax=7;
	out.x.cx=x1;
	out.x.dx=x2;
	int86(0x33,&in,&out);
	in.x.ax=8;
	out.x.cx=y1;
	out.x.dx=y2;
	int86(0x33,&in,&out);
}
void getmouseposition(int *button,int *x,int *y)
{
  in.x.ax=3;
  int86(0x33,&in,&out);
  *button=out.x.bx;
  *x=out.x.cx;
  *y=out.x.dx;
}
void openwindow()
{
	int a,b,c,d;
	int i=10;

	c=0;
	for(d=250;d<350;d+=20)
	{
	   setfillstyle(1,2);
	   bar(d,400,260+c,410);
	   c+=20;
	}
	a=250;
	b=400;
	c=260;
	while(!kbhit())
	{
	setcolor(i);
	outtextxy(20,20,"WELCOME TO OUR PROJECT");

	outtextxy(20,40,"SUBMITTED TO : DR.KAZI MASUDUL ALAM");
	outtextxy(20,52,"ASSOCIATE PROFESSOR OF CSE DISCIPLINE,KHULNA UNIVERSITY.");
	outtextxy(20,70,"SUBMITTED BY : 180227,180228,180206,180218");
	outtextxy(20,90,"NOW YOU ARE READY TO USE OUR CALCULATOR!!!");

	outtextxy(20,120,"PRESS ANY KEY TO CONTINUE.......");
	if((a==350)&&(c==360))
	{
	  a=250;
	  c=260;
	  continue;
	}
	else
	{
	setcolor(10);
	rectangle(a,b,c,b+10);
	rectangle(a-1,b-1,c+1,b+11);
	}
	delay(300);
	setcolor(BLACK);
	rectangle(a,b,c,b+10);
	rectangle(a-1,b-1,c+1,b+11);
	a+=20;
	c+=20;
	}

}
void closewindow()
{
  int i,j,k;
  cleardevice();


 while(!kbhit())
{
// outtextxy(50,130,"recommend:helping mouse operation:www botskool.com");
  setcolor(GREEN);
  settextstyle(BOLD_FONT,HORIZ_DIR,4);
  outtextxy(180,220,"THANK YOU");
  setcolor(YELLOW);
  settextstyle(SIMPLEX_FONT,HORIZ_DIR,1);
outtextxy(30,300,"recommend:For taking mouse operation help from:www botskool.com");

  }
  }



