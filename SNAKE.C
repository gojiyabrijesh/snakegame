#include<stdio.h>
#include<conio.h>
#include<dos.h>
void main()
{
	 char ch='d',c,game;
	int i,j,d=0,a[100],h=20,w=29,x=1,r=315,stor=0,n=1,z=1,o[100];
	int b=0,m=0,p=0,speed=200;
	clrscr();
	for(z=0; z<=100; z++);
	{
	      a[z]=0;
	}
	textbackground(LIGHTBLUE);
	textcolor(YELLOW);

	printf("\n\n\n\n\t\t\t\tINFORMATION\n\n");
	printf("\t\t\t\t1.w press -> up \n\n");
	printf("\t\t\t\t2.s press -> down\n\n");
	printf("\t\t\t\t3.d press -> right\n\n");
	printf("\t\t\t\t4.a press -> left\n\n");
	printf("\t\t\t\t5.b press -> pause\n\n");
	printf("\t\t\t\t6.x press -> break\n\n");
	printf("\n\t\t\t.....press any key to forward.....");
	getch();
	acc:
	clrscr();
	printf("\n\n\n\t\t\t        SNAKE SPEED\n");
	printf("\t\t------------------------------------------\n");
	printf("\t\t|     Easy    |    Medium   |     Hard   |\n");
	printf("\t\t|-------------|-------------|------------|\n");
	printf("\tRange-->| 500 b/w 300 | 300 b/w 200 | 200 b/w 50 |\n");
	printf("\t\t------------------------------------------\n");
	printf("\n\n\t\tEnter your speed = ");
	scanf("%d",&speed);

	if(speed<=49 || speed>=501)
	{        gotoxy(16,14);

		printf("Enter a valid speed");
		getch();
		goto acc;
	}
	clrscr();
	gotoxy(24,12);


	cprintf("....press any key to continue....");
	getch();
	a[0]=w+1;
	clrscr();
		textbackground(BLACK);
	while(1)
	{


		 if(a[0]==r)
		{        abc:
			r=rand()%570;
			if(r<w+1 || r>570 || r%w==0 || r%w==1 )
			{   goto abc;
			}
			else
			{
				n++;
				speed-=5;
			}
		}

		d=1;
		clrscr();
		for(i=1; i<=h; i++)
		{
			printf("\t\t\t");
			for(j=1; j<=w; j++)
			{        textcolor(YELLOW);
				if(i==1 || i==h || j==1)
				{
				   cprintf("#");
				}
				else
				{      p=0;
					b=n;
				       abcc:
				       if(p<=n && b>=0)
					{
							 if(d==a[p] || d==a[b])
							{

								if(d==a[0])
								{
								       textcolor(BROWN);

									cprintf("");

								 }
								 else if(d==a[n])
								 {
									textcolor(GREEN);
									cprintf("*");
								 }
								 else
								 {
									textcolor(WHITE);
									cprintf("\4");
								 }

								j++;
								 d++;
							}
						       b--;
							p++;
							goto abcc;
					}
					 if(r==d)
					{

						textcolor(RED);
						cprintf("\3");
					}
					else
					{
						printf(" ");
					}
				}
				d++;
		}
			textcolor(YELLOW);
			cprintf("#");
			printf("\n");
	}
		 textcolor(LIGHTRED);
		cprintf("                         score = %d\npress x -> exit\n",n+1);
		 textcolor(YELLOW);
			delay(speed);
		while(ch=='w' || ch=='a' || ch=='s' || ch=='d' || ch=='W' || ch=='A' || ch=='S' || ch=='D')
		{
			c=ch;
			break;
		}
		if(ch=='W' || ch=='S' || ch=='w' || ch=='s')
		{
			if(kbhit())
			{
				ch=getch();
				switch(ch)
				{
					case 'a':
						x=-1;
						break;
					case 'd':
						x=1;
						break;
					case 'A':
						x=-1;
						break;
					case 'D':
						x=1;
						break;
				}
				if(ch=='x' || ch=='X')
				{
					break;
				}
				else if(ch=='b' || ch=='B')
				{
					textbackground(BLACK);
					textcolor(YELLOW);
					cprintf("PAUSE");
					getch();
				}
				else if(ch=='j' ||ch=='J' )
				{
				   speed-=20;
				}
				else if(ch=='i' || ch=='I')
				{
					speed+=20;
				}
				else if(ch=='l' || ch=='L')
				{
					n++;
				}
			}
		}
		else if(ch=='D' || ch=='A'||ch=='d' || ch=='a')
		{
			if(kbhit())
			{
				ch=getch();
				switch(ch)
				{
					case 'w':
						x=(-1)*w;

						break;
					case 's':
						x=w;
						break;
					case 'W':
						x=(-1)*w;

						break;
					case 'S':
						x=w;
						break;
				}
				if(ch=='x' || ch=='X')
				{
				break;
				}
				else if(ch=='b' || ch=='B')
				{
					textbackground(BLACK);
					textcolor(YELLOW);
					cprintf("\nPAUSE");
					getch();
				}
				else if(ch=='j' || ch=='J')
				{
				   speed-=20;
				}
				else if(ch=='i' || ch=='i')
				{
					speed+=20;
				}
				else if(ch=='l' || ch=='L')
				{
					n++;
				}
			}
		}
		else
		{
		    ch=c;
		}
		for(z=0; z<n; z++)
		{
			m=a[z];
			o[z]=m;

		}

		for(z=0; z<n; z++)
		{
		   m=o[z];
		   a[z+1]=m;

		}
		  a[0]=a[0]+x;

	for(z=1; z<=n; z++)
	{
		if(a[0]==a[z])
		{
			delay(speed*2);
		    clrscr();

		      textcolor(YELLOW);
			gotoxy(35, 12);
		      cprintf("GAME IS OVER");
		 delay(speed*3);
		      break;
		}
	}
		if(a[0]<w+1 || a[0]>w*h-w || a[0]%w==0 || a[0]%w==1)
		{
			clrscr();
			gotoxy(35, 12);
		      textcolor(YELLOW);
		   cprintf("GAME IS OVER");
		 delay(speed*3);
		    break;
		}
	}

}