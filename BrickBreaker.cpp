/* The project contains two-dimensional graphics realized by each of the following sections 
	1. Graphic text
	2. Sketching different shapes
	3. Filling shapes
	4. Moving
	5. Screen borders
	6. Rounds
	7. Animation
	8. Work with a keyboard
	9. Working with a mouse
	10. Text throughout the game (counter)
*/

#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>


int initmouse();
void showmouseptr();
void getmousepos(int *button, int *x, int *y);

union REGS i, o;
int button,x,y;
void print_briks();
int briks[20]={0},bally=200,BallMaxYFlag=0,ballx=50;
// getmaxx(),getmaxy() : getting the screen size
int cx = getmaxx()/2,r = 10,maxx=getmaxx(),StartGame = 0,InstructionF = 0,endGameF = 0,GameOverFlag = 0;
int  main()
{
int gdriver = DETECT, gmode, errorcode;
initgraph(&gdriver, &gmode, ""); //initgraph() - entering entering graphic mode
errorcode = graphresult(); /*graphresult () checks whether we have successfully switched to graphical mode. If not, we print an error message
			    and finish the program.*/ 
int status, gd = DETECT, gm;
	 initgraph(&gd,&gm,"C:\\TC\\BGI");
	 getmousepos(&button,&x,&y);
if (errorcode != grOk)
{
printf("Graphics error: %s\n", grapherrormsg(errorcode));
printf("Press any key to halt:");
getch();
exit(1);
}
char ch,str[20];
int left = 200 , top = getmaxy()-60,right = 400, bottom = getmaxy()-50;
int j=0,score = 0,Winner = 0;
int ballx=50,BallStartflag=0,bally=200, life = 2;
int midx,midy,k;

	 midx=getmaxx()/2;
	 midy=getmaxy()/2;
	 settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
	 setcolor(3);
	 int c=150;
	for(int e=0;e<15;e++)
	 {
		  for(int k=50;k<100;k++)
		  {
		   settextstyle(SCRIPT_FONT, HORIZ_DIR, 5);
		   outtextxy(midx,midy,"Loading...");
		   settextstyle(SCRIPT_FONT, HORIZ_DIR, 5);
		   //outtextxy receiving the text to display on the screen in a specific place
		   outtextxy(midx+5,midy+30,"Please Wait.. ");
		   setcolor(3);
		   circle(midx,midy,k);
		   circle(midx,midy,c);
		   c--;
		   cleardevice();
		  }
	  }
	  setfillstyle(USER_FILL,WHITE);
	  floodfill(0,0,WHITE);
	  setcolor(3);
	  settextstyle(SMALL_FONT, HORIZ_DIR,5);
	  outtextxy(0,0,"< We Are PRESENTING To YOUOOOOOOOOOOOOOOOOOOOOO The Brick Breaker >");
	  
	  //rectangle(left, top, right, bottom ) An order that receives rectangle borders, and draws an empty rectangle
	  rectangle(100,30,170,70);
	  outtextxy(120,40,"START");
	  
	  rectangle(160,80,230,120);
	  outtextxy(170,90,"BLA BLA");
	  
	  rectangle(220,130,420,170);
	  outtextxy(230,140,"GET ME OUT OF HERE YLAA");
	  
	  settextstyle(SMALL_FONT, HORIZ_DIR, 40);
	  settextjustify(midx,midy);
	  outtextxy(midx-100,midy-60,"WELCOME");
	  delay(150);
	  
	  outtextxy(midx-100,midy-30,"TO");
	  delay(150);
	  
	  outtextxy(midx-100,midy-2,"THE");
	  delay(150);
	  
	  settextstyle(  GOTHIC_FONT, HORIZ_DIR, 4);
	  outtextxy(midx-100,midy+50,"TA TRAAA RAAM");
	  
	  outtextxy(midx-100,midy+100,"GAME HEHEHEHEHE");
	  while(!kbhit() && StartGame == 0 && endGameF == 0)
{
	  showmouseptr();
	  getmousepos(&button,&x,&y);
			if(button == 1 && x >=100 && x <= 170 && y >= 30 && y <= 70  )
				StartGame = 1;
			if(button == 1&&x >=160 && x <= 230 && y >=80 && y <= 120  )
			{
				settextstyle(  SMALL_FONT, HORIZ_DIR, 4);
		        outtextxy(240,90,"Move The Stick By: (Left-A , Right-D) ");
			}
			if(button == 1&&x >=220 && x <= 420 && y >=130 && y <= 170  )
				endGameF = 1;
			button=-1;
}
	if(endGameF==1)
		exit(1);
	if(StartGame==1)
	{	
		settextstyle(SMALL_FONT, HORIZ_DIR,5);
		do{
			while(!kbhit())
			{
				sprintf(str,"LIFE : %d",life);
                outtextxy(midx,midy+15,str);
				sprintf(str,"SCORE : %d",score);
                outtextxy(midx,midy,str);
				cleardevice();
				sprintf(str,"LIFE : %d",life);
                outtextxy(midx,midy+15,str);
				sprintf(str,"SCORE : %d",score);
                outtextxy(midx,midy,str);
				print_briks();

				//when the ball hit the bars to deleted it //
				int x=0,y=0;
				for(int k=0;k<20;k++)
            	{
	            	if(ballx>=x && ballx <= x+124 && bally-10==y+5 && briks[k]==0)
	            	{
		            	briks[k] = 1;
						sound(1200);                       
						delay(10);
						nosound();
						score += 10;
		            	BallMaxYFlag=0;
						Winner++;
		            }
		            x=x+128;
		            if (k%5==4)
		            {
		            	x=0;
		            	y+=10;
			
		            }
	            }
				
				setfillstyle(SOLID_FILL,WHITE);
				bar(left+j,top,right+j,bottom);
				
				// start of the circle code //
				if(ballx==getmaxx()-10 )
				{
					sound(600);
					delay(10);
					nosound();
					BallStartflag=1;
				}	
				if(bally==getmaxy()-10 )
				{
					sound(600);
					delay(10);
					nosound();
					BallMaxYFlag =1;
				}
				if(ballx-r == 0)
				{
					sound(600);
					delay(10);
					nosound();
					BallStartflag = 0;
				}
				if(bally-r == 0)
				{
					sound(600);
					delay(10);
					nosound();
					BallMaxYFlag = 0;
				}
				if(BallMaxYFlag == 1 && BallStartflag == 0)
				{
					bally--;
					ballx++;
					
				}

				if(BallMaxYFlag == 0 && BallStartflag == 1)
				{
					bally++;
					ballx--;
				}

				if(BallMaxYFlag == 1 && BallStartflag == 1)
				{
					bally--;
					ballx--;
				}

				if(BallMaxYFlag == 0 && BallStartflag ==0)
				{
					bally++;
					ballx++;
				}
				// THE BALL TOUCH'S THE Main BARS'S TOP
				if(ballx-r >= left+j && ballx+r <= right+j && bally+r == top)
				{	
					sound(1200);                       
					delay(10);
					nosound();
					BallMaxYFlag=1;
				}
				//lose
				if(bally + 10 == getmaxy())
				{
					life--;
					if(!life)
						GameOverFlag = 1;
				}
				//whene the hit getmaxy (game over)
				
				while(!kbhit() && GameOverFlag == 1)
				{
					printf("Game Is Over \n");
                    sprintf(str,"SCORE : %d",score);
                    outtextxy(midx,midy,str);
					cleardevice();
					
				}
				setfillstyle(SOLID_FILL,BLUE);
				fillellipse(ballx,bally,r,r);
				if(Winner == 5)
				{
					cleardevice();
					int num1= getmaxx()/2,num2= getmaxy()/2;
						//settextstyle(TRIPLEX_FONT,HORIZ_DIR,rand());
						//setcolor(4); for other text
						while(!kbhit())
						{
							setcolor(rand());
							for(int color = 0 ; color < 52 ; color++)
								circle(num1,num2,color);
							setcolor(rand());
							for(int g = 70; g < 120 ; g++ )
								circle(num1,num2,g);
							setcolor(rand());
							for(int l = 140; l < 190; l++ )
								circle(num1,num2,l);
							setcolor(rand());
							for(int h = 210 ; h < 230; h++)
								circle(num1,num2,h);
							delay(200);
							outtextxy(0,0,"You Won Amigooo Yeahhhhhhh Good job");
						}
						
				}
				delay(2);
		}
				ch=getch();
				if(ch == 'a' && left+j >= 0)
				{
					j-=15;
				}
				if(ch == 'd' && right+j <= getmaxx())
				{
					j+=15;
				}
				if(score == 200)
					exit(1);
			}while(ch!='q');
	}
	
	
getch();
/*At the end of the work in graphical mode we need to call the closegraph () function to return to text mode.*/
closegraph(); 
return 0;
}

void print_briks()
{
	int j,x=0,y=0,h=5,maxx=getmaxx();
	double d=0.2;
	for(j=0;j<20;j++)
	{
		if(briks[j]==0)
		{	setfillstyle(SOLID_FILL,GREEN);
			bar (x,y,x+124,y+5);
		}
		x=x+128;
		if (j%5==4)
		{
			x=0;
			y+=10;
			
		}
	}
}
int initmouse()
{
	 i.x.ax = 0;
	 int86(0X33,&i,&o);
	 return ( o.x.ax );
}
void showmouseptr()
{
	 i.x.ax = 1;
	 int86(0X33,&i,&o);
}
void getmousepos(int *button, int *x, int *y)
{
	 i.x.ax = 3;
	 int86(0X33,&i,&o);

	 *button = o.x.bx;
	 *x = o.x.cx;
	 *y = o.x.dx;
}
