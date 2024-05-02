# include "iGraphics.h"
# include "struct.h"

//All variables
int x = 3, y = 400;
int a=20;
int random=0;

//All variables
//Looping variables
int i, j, l;

//For Tom, Jerry and Spike
int Tomfrontx=0, Tombackx=0;
int Spikexmove=0, Spikeymove=0;
int Spikefrontx=0, Jerrybackx=0;
//Count for Pause and Resume
int cnt=0;
int start=0;
//For obstacles
int loxstart=421, obstaclexmove=0, uoxstart=631;
//loxstart=lower obstacle x axis start, uoxstart=upper obstacle x axis start

//For randomness of objects
//int rl[10]={4, 1, -1, -2, 1, -1, -2, 1, -2, 1};
//int ru[10]={0, 7, -2, -2, 2, -2, -2, 7, 1, 7};//Works more selectively to make the game harder
int rl[10]={rand()%2, rand()%2, rand()%2, rand()%1, rand()%2, rand()%3, rand()%1, rand()%2, rand()%2, rand()%1};
int ru[10]={rand()%7, rand()%7, rand()%5, rand()%4, rand()%3, rand()%5, rand()%7, rand()%3, rand()%1, rand()%6};
//For obstacles
int lofirstx, losecondx;
int uofirstx, uosecondx;
int lobsrand, uobsrand;//For randomness of obstacles
//Third obstacle
int toxstart=400, tobsrand;
int tobsrandmultiply;
int tofirstx, tosecondx;
//int r3[10]={0, 7, -2, -2, 2, -2, -2, 7, 1, 7};
int r3[10]={rand()%8, rand()%8, rand()%8, rand()%8, rand()%8, rand()%8, rand()%8, rand()%8, rand()%8, rand()%8};
//For Tom Tripping
int trip=0;
int spikein=0, spikeout=0;
int tripcount=0;
//Variable difference
int vardiff=0;
//Not going up or down while in pause
int notpause=0;
//Timer variables
//Rawtime..
int H, M, S, c;
//Counttime
int h=0, m=0, s=0;
//For booster
int bfirstx, bsecondx;
int rb[10]={-20, 17, 10, 18, 10, 15, 27, 12, 15,17};
int brand;
int bstore[50];
char coin[8][15]={"Coins_1.bmp", "Coins_2.bmp", "Coins_3.bmp", "Coins_4.bmp", "Coins_5.bmp", "Coins_6.bmp", "Coins_7.bmp", "Coins_8.bmp"};
int coinindex=0;
//For galleons
int silfirstx, silsecondx;
int silverstore[50];
int silrand;
int silcoinindex=0;
//Coin collection->//Spike.speed
int coinage=0;
//Game navigation
int countofs=0;
//Menu navigation
int menu=1;
int menulimit=4;
//Settings navigation
int settingspage=0;
int settings=2;
//Instruction navigation
int inst=1;
//Tom jumping
int jump=0;
//For mid placing
int previous=0, mid;
//For sound and level settings
int sound=0;
int level=1;
//For resume page
int resume=1;
int resumepage=0;
//For 3 lifes of Tom
int life=3;
int lifestate=0;
//Variables for Levels
float Spikespeed=1;
int obstaclespeed=3;
//Jerry waving
int jerrywave=0;
char jwave[2][15]={"wave1.bmp", "wave2.bmp"};
int jwaveindex=0;
//Spike can or cannot catch Tom
int spikecancatch=1;
int spikejumprange=5;
//High Score Variables
int score;
int Highscore;
//Display variables
char timestr[80], coinstr[80], scorestr[80];
char finalscorestr[80], highscorestr[80];
//For new game after spike catches Tom
int newgame=0;
//For more page
int moremenu=1;

//Structured objects*********
whisker Tom, Jerry;
obj wall, b, sil;//wall, coin and galleons


//Function Prototypes
void scorestore(int score);
int GetHighScore();
void reset(void);

//For Levels
//Start values
/*
1.Intro page->start=0
2.Home page->start=1->Instruction(2), Quit game(->0), Settings(3)->Sound on/off, Level(Optional)
3.Game page->start=2;
4.Settings->start=4;
5.Game over->win->start=5;
              lose->start=6;
5.Instruction page->start=7;
6.Resume page->start=8;
7.More page->start=9;
8.Best figures->start=10;
9.Credits->start=11;
10.Features->start=12;
*/

/*
Features of whiskers
/Game start
1. Press s to proceed to game
2. Press space to resume/pause
3. Try to catch jerry
/Obstacles
4. Obstacles positions are random
5. Right click to avoid lower obstacles
   Left  click to avoid upper obstacles
6. Right/Left click gets Tom 5 pix back
/Tripping
7. No tripping within 100 on either side
8. No spike comes in within 250 for tripping
   but jerry advances by 10
9. Spike comes in for tripping after 250
   and moves by itself
10. Every tripping gets tom 50 pix back
/Spike
11.Avoid Spike catching Tom
12.Spike chases Tom up to 600 and then retreats
13.Avoids obstacles by itself
/Jerry
14.Goes at constant speed
/Looping
15.Tom comes back to zero after 1180
   idea is to shift the camera
16.Jerry after looping
   a.Restarts at 100 if final difference<300
   b.Restarts at 200 if final difference>300
17.Spike restarts from Neg x and continues to
   chase Tom
/Booster
18.Tom gets booster once in a while
19.Booster positions are random
20.Booster vanishes after use
*/


//iDraw Function start
void iDraw()
{
    //Initiating Drawing code
    iClear();

    //*****************************
    //First intro page
    if(start == 0)
    {
        iShowBMP(450,100,"Intro.bmp");
        iPauseTimer(0);
    }

    //******************************
    //Menu page
    //Selecting Start game/ New game
    if(start==1 && menu==1)
    {
        iShowBMP(0, 0, "bg1.bmp");
        if(resumepage==0)
        {
            iShowBMP(30, 400, "Start_game_2.bmp");
        }
        if(resumepage==1)
        {
            iShowBMP(30, 400, "New_game_2.bmp");
        }
        iShowBMP(30, 340, "Settings_1.bmp");
        iShowBMP(30, 290, "Instructions_1.bmp");
        iShowBMP(30, 230, "Quit_game_1.bmp");
        if(resumepage==1 && menulimit==5)
        {
            iShowBMP(30, 170, "Resume_1.bmp");
        }
        iShowBMP(1100, 520, "morebutton2.bmp");
    }
    //Selecting Settings
    if(start==1 && menu==2)
    {
        iShowBMP(0, 0, "bg1.bmp");
        if(resumepage==0)
        {
            iShowBMP(30, 400, "Start_game_1.bmp");
        }
        if(resumepage==1)
        {
            iShowBMP(30, 400, "New_game_1.bmp");
        }
        iShowBMP(30, 340, "Settings_2.bmp");
        iShowBMP(30, 290, "Instructions_1.bmp");
        iShowBMP(30, 230, "Quit_game_1.bmp");
        if(resumepage==1 && menulimit==5)
        {
            iShowBMP(30, 170, "Resume_1.bmp");
        }
        iShowBMP(1100, 520, "morebutton2.bmp");
    }
    //Selecting Instructions
    if(start==1 && menu==3)
    {
        iShowBMP(0, 0, "bg1.bmp");
        if(resumepage==0)
        {
            iShowBMP(30, 400, "Start_game_1.bmp");
        }
        if(resumepage==1)
        {
            iShowBMP(30, 400, "New_game_1.bmp");
        }
        iShowBMP(30, 340, "Settings_1.bmp");
        iShowBMP(30, 290, "Instructions_2.bmp");
        iShowBMP(30, 230, "Quit_game_1.bmp");
        if(resumepage==1 && menulimit==5)
        {
            iShowBMP(30, 170, "Resume_1.bmp");
        }
        iShowBMP(1100, 520, "morebutton2.bmp");
    }
    //Selecting Exit
    if(start==1 && menu==4)
    {
        iShowBMP(0, 0, "bg1.bmp");
        if(resumepage==0)
        {
            iShowBMP(30, 400, "Start_game_1.bmp");
        }
        if(resumepage==1)
        {
            iShowBMP(30, 400, "New_game_1.bmp");
        }
        iShowBMP(30, 340, "Settings_1.bmp");
        iShowBMP(30, 290, "Instructions_1.bmp");
        iShowBMP(30, 230, "Quit_game_2.bmp");
        if(resumepage==1 && menulimit==5)
        {
            iShowBMP(30, 170, "Resume_1.bmp");
        }
        iShowBMP(1100, 520, "morebutton2.bmp");
    }
    //Selecing Resume
    if(start==1 && menulimit==5 && menu==5)
    {
        iShowBMP(0, 0, "bg1.bmp");
        if(resumepage==0)
        {
            iShowBMP(30, 400, "Start_game_1.bmp");
        }
        if(resumepage==1)
        {
            iShowBMP(30, 400, "New_game_1.bmp");
        }
        iShowBMP(30, 340, "Settings_1.bmp");
        iShowBMP(30, 290, "Instructions_1.bmp");
        iShowBMP(30, 230, "Quit_game_1.bmp");
        iShowBMP(30, 170, "Resume_2.bmp");
        iShowBMP(1100, 520, "morebutton2.bmp");
    }
    //Selecting Soundon
    if(start==4 && menu==2 && settingspage==1 && settings==1)
    {
        iShowBMP(0, 0, "Cool_intro.bmp");
        iShowBMP(30, 470, "Sound_1.bmp");
        iShowBMP(30, 420, "On_2.bmp");
        iShowBMP(30, 370, "Off_1.bmp");
        iShowBMP(30, 290, "Level_1.bmp");
        iShowBMP(30, 240, "Easy_1.bmp");
        iShowBMP(30, 190, "Medium_1.bmp");
        iShowBMP(30, 140, "Hard_1.bmp");
        iShowBMP(30, 70, "Back_1.bmp");
        if(sound==1)
        {
            iShowBMP(90, 425, "Tick.bmp");
        }
        else if(sound==0)
        {
            iShowBMP(90, 370, "Tick.bmp");
        }

        if(level==1)
        {
            iShowBMP(110, 240, "Tick.bmp");
        }
        if(level==2)
        {
            iShowBMP(140, 190, "Tick.bmp");
        }
        if(level==3)
        {
            iShowBMP(120, 140, "Tick.bmp");
        }
    }
    //Selecting Sounoff
    if(start==4 && menu==2 && settingspage==1 && settings==2)
    {
        iShowBMP(0, 0, "Cool_intro.bmp");
        iShowBMP(30, 470, "Sound_1.bmp");
        iShowBMP(30, 420, "On_1.bmp");
        iShowBMP(30, 370, "Off_2.bmp");
        iShowBMP(30, 290, "Level_1.bmp");
        iShowBMP(30, 240, "Easy_1.bmp");
        iShowBMP(30, 190, "Medium_1.bmp");
        iShowBMP(30, 140, "Hard_1.bmp");
        iShowBMP(30, 70, "Back_1.bmp");
        if(sound==1)
        {
            iShowBMP(90, 425, "Tick.bmp");
        }
        else if(sound==0)
        {
            iShowBMP(90, 370, "Tick.bmp");
        }

        if(level==1)
        {
            iShowBMP(110, 240, "Tick.bmp");
        }
        if(level==2)
        {
            iShowBMP(140, 190, "Tick.bmp");
        }
        if(level==3)
        {
            iShowBMP(120, 140, "Tick.bmp");
        }
    }
    //Selecting Level-1: Easy
    if(start==4 && menu==2 && settingspage==1 && settings==3)
    {
        iShowBMP(0, 0, "Cool_intro.bmp");
        iShowBMP(30, 470, "Sound_1.bmp");
        iShowBMP(30, 420, "On_1.bmp");
        iShowBMP(30, 370, "Off_1.bmp");
        iShowBMP(30, 290, "Level_1.bmp");
        iShowBMP(30, 240, "Easy_2.bmp");
        iShowBMP(30, 190, "Medium_1.bmp");
        iShowBMP(30, 140, "Hard_1.bmp");
        iShowBMP(30, 70, "Back_1.bmp");
        if(sound==1)
        {
            iShowBMP(90, 425, "Tick.bmp");
        }
        else if(sound==0)
        {
            iShowBMP(90, 370, "Tick.bmp");
        }

        if(level==1)
        {
            iShowBMP(110, 240, "Tick.bmp");
        }
        if(level==2)
        {
            iShowBMP(140, 190, "Tick.bmp");
        }
        if(level==3)
        {
            iShowBMP(120, 140, "Tick.bmp");
        }
    }
    //Selecting Level-2: Medium
    if(start==4 && menu==2 && settingspage==1 && settings==4)
    {
        iShowBMP(0, 0, "Cool_intro.bmp");
        iShowBMP(30, 470, "Sound_1.bmp");
        iShowBMP(30, 420, "On_1.bmp");
        iShowBMP(30, 370, "Off_1.bmp");
        iShowBMP(30, 290, "Level_1.bmp");
        iShowBMP(30, 240, "Easy_1.bmp");
        iShowBMP(30, 190, "Medium_2.bmp");
        iShowBMP(30, 140, "Hard_1.bmp");
        iShowBMP(30, 70, "Back_1.bmp");
        if(sound==1)
        {
            iShowBMP(90, 425, "Tick.bmp");
        }
        else if(sound==0)
        {
            iShowBMP(90, 370, "Tick.bmp");
        }

        if(level==1)
        {
            iShowBMP(110, 240, "Tick.bmp");
        }
        if(level==2)
        {
            iShowBMP(180, 195, "Tick.bmp");
        }
        if(level==3)
        {
            iShowBMP(120, 140, "Tick.bmp");
        }
    }
    //Selecting Level-3: Hard
    if(start==4 && menu==2 && settingspage==1 && settings==5)
    {
        iShowBMP(0, 0, "Cool_intro.bmp");
        iShowBMP(30, 470, "Sound_1.bmp");
        iShowBMP(30, 420, "On_1.bmp");
        iShowBMP(30, 370, "Off_1.bmp");
        iShowBMP(30, 290, "Level_1.bmp");
        iShowBMP(30, 240, "Easy_1.bmp");
        iShowBMP(30, 190, "Medium_1.bmp");
        iShowBMP(30, 140, "Hard_2.bmp");
        iShowBMP(30, 70, "Back_1.bmp");
        if(sound==1)
        {
            iShowBMP(90, 425, "Tick.bmp");
        }
        else if(sound==0)
        {
            iShowBMP(90, 370, "Tick.bmp");
        }

        if(level==1)
        {
            iShowBMP(110, 240, "Tick.bmp");
        }
        if(level==2)
        {
            iShowBMP(140, 190, "Tick.bmp");
        }
        if(level==3)
        {
            iShowBMP(140, 145, "Tick.bmp");
        }
    }
    //Selecting Back
    if(start==4 && menu==2 && settingspage==1 && settings==6)
    {
        iShowBMP(0, 0, "Cool_intro.bmp");
        iShowBMP(30, 470, "Sound_1.bmp");
        iShowBMP(30, 420, "On_1.bmp");
        iShowBMP(30, 370, "Off_1.bmp");
        iShowBMP(30, 290, "Level_1.bmp");
        iShowBMP(30, 240, "Easy_1.bmp");
        iShowBMP(30, 190, "Medium_1.bmp");
        iShowBMP(30, 140, "Hard_1.bmp");
        iShowBMP(30, 70, "Back_2.bmp");
        if(sound==1)
        {
            iShowBMP(90, 425, "Tick.bmp");
        }
        else if(sound==0)
        {
            iShowBMP(90, 370, "Tick.bmp");
        }

        if(level==1)
        {
            iShowBMP(110, 240, "Tick.bmp");
        }
        if(level==2)
        {
            iShowBMP(140, 190, "Tick.bmp");
        }
        if(level==3)
        {
            iShowBMP(120, 140, "Tick.bmp");
        }
    }

    //**********************************
    //Instruction pages
    if(start==7 && menu==3 && inst==1)
    {
            iShowBMP(0, 0, "instr1.bmp");
    }
    if(start==7 && menu==3 && inst==2)
    {
            iShowBMP(0, 0, "instr2.bmp");
    }
    if(start==7 && menu==3 && inst==3)
    {
            iShowBMP(0, 0, "instr3.bmp");
    }
    if(start==7 && menu==3 && inst==4)
    {
            iShowBMP(0, 0, "instr4.bmp");
    }
    if(start==7 && menu==3 && inst==5)
    {
            iShowBMP(0, 0, "instr5.bmp");
    }
    if(start==7 && menu==3 && inst==6)
    {
            iShowBMP(0, 0, "instr6.bmp");
    }
    if(start==7 && menu==3 && inst==7)
    {
            iShowBMP(0, 0, "instr7.bmp");
    }
    if(start==7 && menu==3 && inst==8)
    {
            iShowBMP(0, 0, "instr8.bmp");
    }
    if(start==7 && menu==3 && inst==9)
    {
            iShowBMP(0, 0, "instr9.bmp");
    }
    if(start==7 && menu==3 && inst==10)
    {
            iShowBMP(0, 0, "instr10.bmp");
    }


    //************************************
    //Game page
    if(start == 2)
    {
    //Starting Game//

    iShowBMP(0, 0, "menubg3.bmp");

    //For the timer
    if((cnt%2)==1)
    {
    time_t rawtime;
	tm * ptm;
    time( & rawtime );
	ptm=gmtime(&rawtime);

    H=(ptm->tm_hour+6)%12;
	M=ptm->tm_min;
	S=ptm->tm_sec;

    //Printing time
    if(S!=c)
    {
        s++;
        if(s==60)
        {
            s=0;
            m++;
        }
        if(m==60)
        {
            m=0;
            h++;
        }

        //Display
        system("cls");
        printf("H:  %d  M: %d  S: %d\n", h, m, s);
        score=h*3600+m*60+s;
    }
    //For one second interval
    c=S;
    }

    //Display on game terminal
    iSetColor(245, 96, 66);
    if(notpause==0 || notpause==1)
    {
        iText(900,480,timestr);
        iText(900,450,coinstr);
    }

    sprintf(timestr, "H:  %d  M: %d  S: %d", h, m, s);
    sprintf(coinstr, "Coins: %d", coinage);


    //Constructing Wall Below
    for(j=1; j<5; j++)
    {
    for(i=0; i<50000; i++)
    {
        wall.xstart=1;
        if((j%2)==1)
        {
            wall.xstart=8;
        }
        iSetColor(175,52,25);
        iFilledRectangle((wall.xstart+(21*(i)))+wall.xmove,(1+(11*(j))),20,10);
    }
    }

    //Constructing Wall Above
    for(j=1; j<5; j++)
    {
    for(i=0; i<50000; i++)
    {
        wall.xstart=1;
        if((j%2)==1)
        {
            wall.xstart=8;
        }
        iSetColor(175,52,25);
        iFilledRectangle((wall.xstart+(21*(i))+wall.xmove),(589-(11*(j))),20,10);
    }
    }


    //Characters
    //Tom's
    iShowBMP(30+Tom.xmove,62+Tom.ymove,"Chase1.bmp");
    //Jerry's
    iShowBMP(150+Jerry.xmove,78+Jerry.ymove,"Jerry.bmp");
    //Spike's
    iShowBMP(-60+Spikexmove,62+Spikeymove,"Spike2.bmp");


    //Obstacle on the lower wall
    for(l=0; l<50; l++)
    {
    for(j=0; j<2; j++)
    {
        for(i=0; i<2; i++)
        {
        //Creating obstacles
        lobsrand=rl[l%10];//For lower obstacle
        uobsrand=ru[l%10];//For higher obstacle
        //Creating lower obstacle
        iSetColor(175,52,25);
        iFilledRectangle(loxstart+(21*(i))-obstaclexmove+((l*370)-lobsrand*15),(56+(11*(j))),20,10);
        //Lower obstacle coordinates
        lofirstx=loxstart+(21*(i))-obstaclexmove+((l*370)-lobsrand*15);
        if(previous!=0)
        {
            mid=(loxstart+lofirstx+previous)/2;
        }
        losecondx=lofirstx+41;
        previous=losecondx;


        //Tomfrontx and Tombackx
        Tomfrontx=30+Tom.xmove+60;
        Tombackx=Tomfrontx-38;
        //Spikefrontx and Jerrybackx
        Spikefrontx=Spikexmove-60+50;
        Jerrybackx=150+Jerry.xmove;


        //Tom tripping condition
        if((lofirstx<=Tomfrontx) && (Tomfrontx<=losecondx) && (Tomfrontx>100) && (Tomfrontx<1150) && ((Tom.ymove+62)<77))
        {
            iText(600, 400, "Tripped", GLUT_BITMAP_TIMES_ROMAN_24);
            trip=1;
        }
        if((lofirstx<=Tombackx) && (Tombackx<=losecondx) && (Tombackx>100) && (Tombackx<1150) && ((Tom.ymove+62)<77))
        {
            iText(600, 400, "Tripped", GLUT_BITMAP_TIMES_ROMAN_24);
            trip=1;
        }


        //Spike Avoiding Lower obstacles
        if(((Spikexmove)>(lofirstx-spikejumprange)) && ((Spikexmove)<(lofirstx)))//Spikexmove=Spikexmove-55+55
        {
            Spikeymove=18;
        }
        if(((Spikexmove-55)>(losecondx)) && ((Spikexmove-55)<(losecondx+spikejumprange)))
        {
            Spikeymove=0;
        }


        //Spike goes back after 600
		if(Spikexmove>600)
		{
			spikeout=1;
		}


        //Upper obstacle
        //Creating upper obstacle
        iSetColor(175,52,25);
        iFilledRectangle((uoxstart+(21*(i))-obstaclexmove+((l)*370)-uobsrand*15),(105+(11*(j))),20,10);
        //Upper obstacle coordinates
        uofirstx=(uoxstart+(21*(i))-obstaclexmove+((l)*370)-uobsrand*15);
        uosecondx=uofirstx+41;
        Tomfrontx=30+Tom.xmove+60;
        //Tom tripping condition
        if((uofirstx<=Tomfrontx) && (Tomfrontx<=uosecondx) && (Tomfrontx>100) && (Tomfrontx<1150) && ((Tom.ymove+62+44)>105) &&((Tom.ymove+62+44)<160))
        {
            iText(600, 400, "Tripped", GLUT_BITMAP_TIMES_ROMAN_24);
            trip=1;
        }
        if((uofirstx<=Tombackx) && (Tombackx<=uosecondx) && (Tomfrontx>100) && (Tomfrontx<1150) && ((Tom.ymove+62+44)>105) &&((Tom.ymove+62+44)<160))
        {
            iText(600, 400, "Tripped", GLUT_BITMAP_TIMES_ROMAN_24);
            trip=1;
        }

        //Third Obstacle
        iSetColor(175,52,25);
        iFilledRectangle((toxstart+(21*(i))-obstaclexmove+((l)*370)-tobsrand*40),(157+(11*(j))),20,10);
        //Third obstacle coordinates
        tofirstx=(toxstart+(21*(i))-obstaclexmove+((l)*370)-tobsrand*40);
        tosecondx=tofirstx+41;

        //Tom tripping with third obstacle
        if((tofirstx<=Tomfrontx) && (Tomfrontx<=tosecondx) && (Tomfrontx>100) && (Tomfrontx<1150) && ((Tom.ymove+62+44)>150) &&((Tom.ymove+62+44)<205))
        {
            iText(800, 400, "Tripped", GLUT_BITMAP_TIMES_ROMAN_24);
            trip=1;
        }
        if((tofirstx<=Tombackx) && (Tombackx<=tosecondx) && (Tomfrontx>100) && (Tomfrontx<1150) && ((Tom.ymove+62+44)>150) &&((Tom.ymove+62+44)<205))
        {
            iText(800, 400, "Tripped", GLUT_BITMAP_TIMES_ROMAN_24);
            trip=1;
        }

        lobsrand=0;
        uobsrand=0;
        tobsrand=0;


        //Booster Positioning Algorithm
        brand=rb[l%10];
        if(bstore[l]==0)
        {
        iShowBMP((b.xstart-b.xmove+((l*600)-brand*.2)), 82, coin[coinindex]);
        coinindex++;
        if(coinindex==7)
        {
            coinindex=0;
        }

        //Booster coordinates
        bfirstx=(b.xstart-b.xmove+((l*600)-brand*.2));
        bsecondx=bfirstx+30;


        //Tom gets a boost
        if((Tomfrontx>bfirstx) && (Tomfrontx<bsecondx) && (Tom.ymove+50)<105)
        {
            iSetColor(255,99,9);
            iFilledCircle(550,400,20);
            coinage++;
            bstore[l]=-1;
        }
        //End of boost
        }


        //Galleon positioning algorithm
        silrand=rb[l%10];
        if(silverstore[l]==0 && ((l+1)%2)==0)
        {
        iShowBMP((sil.xstart-sil.xmove+((l*600)-silrand*.2)), 127, "Large_token_1.bmp");
        //silvercoin[silcoinindex]
        silcoinindex++;
        if(silcoinindex==7)
        {
            silcoinindex=0;
        }

        //Galleon coordinates
        silfirstx=(sil.xstart-sil.xmove+((l*600)-silrand*.2));
        silsecondx=silfirstx+30;

        //Tom gets a Galleon
        if((Tomfrontx>silfirstx) && (Tomfrontx<silsecondx) && (Tom.ymove+62)>100 && (Tom.ymove+62)<140)
        {
            iSetColor(255,99,9);
            iFilledCircle(600,500,20);
            silverstore[l]=-1;
            coinage+=5;
        }
        if((Tomfrontx>silsecondx) && (Tombackx<silfirstx) && (Tom.ymove+62)>100 && (Tom.ymove+62)<140)
        {
            iSetColor(255,99,9);
            iFilledCircle(600,500,20);
            silverstore[l]=-1;
            coinage+=5;
        }
        if((Tombackx>silfirstx) && (Tombackx<silsecondx) && (Tom.ymove+62)>80 && (Tom.ymove+62)<140)
        {
            iSetColor(255,99,9);
            iFilledCircle(600,500,20);
            silverstore[l]=-1;
            coinage+=5;
        }
        //End of coin & Galleon loop
        }
        //End of i loop
        }
    //End of j loop
    }
    //End of l loop
    }

    //Jumping Conditions
    //Stays on board
    if(jump==0)
    {
        Tom.ymove=0;
    }

    //Limited jump with 'w'
    if(jump==1)
    {
        Tom.ymove+=9;
        if(Tom.ymove>=72)
        {
            Tom.ymove=72;
            jump=2;
        }
    }

    //Comes back down with 's'
    if(jump==2)
    {
        Tom.ymove-=9;
        if(Tom.ymove<=9)
        {
            Tom.ymove=0;
            jump=0;
        }
    }

    //High jump with 'a'
    if(jump==4)
    {
        Tom.ymove+=5;
        if(Tom.ymove>=350)
        {
            jump=2;
        }
    }

    //Tom Catches Jerry
    if((Jerrybackx-Tomfrontx)>0 && (Jerrybackx-Tomfrontx)<3 && (Tom.ymove+40)<120)//Tomymove
    {
        iDelay(2);
        iPauseTimer(0);
        start=5;

        //Algorithm of winning game
        scorestore(score);
        Highscore=GetHighScore();
        int p=Highscore/3600;
        int q=Highscore/60;
        int r=Highscore%60;

        //score display
        sprintf(highscorestr, "Best Timing-> H: %d M: %d S: %d", p, q, r);
        sprintf(finalscorestr, "Your Timing-> H: %d M: %d S: %d", h, m, s);
    }

    //Spike catches Tom
    if((Tombackx-Spikefrontx)>-50  && (Tombackx-Spikefrontx)<20 && (Tombackx>100) && (Tom.ymove+40)<105 && spikecancatch==1)
    {
        Spikexmove=-10;
        spikecancatch=0;//So, can't catch Tom twice at one go
        iDelay(3);
        life--;
        spikeout=1;//Goes back
    }

    //Jerry waves
    if(jerrywave==1)
    {
        iSetColor(175,52,25);
        iFilledRectangle(1130, 190, 50, 5);//For jerry to stand
        iShowBMP(1145, 195, jwave[jwaveindex]);
        jwaveindex++;
        if(jwaveindex==2)
        {
            jwaveindex=0;
        }
    }
    //Display of lives

    /*display with heads
    if(start==2 && life==3)
    {
        iShowBMP(30, 500, "life4.bmp");
        iShowBMP(80, 500, "life4.bmp");
        iShowBMP(130, 500, "life4.bmp");
    }

    if(start==2 && life==2)
    {
        iShowBMP(80, 500, "life4.bmp");
        iShowBMP(130, 500, "life4.bmp");
    }

    if(start==2 && life==1)
    {
        iShowBMP(30, 500, "life4.bmp");
    }
    */

    //Displaying lives on game terminal(with life bars)
    if(start==2)
    {
        iShowBMP(40, 465, "Life.bmp");
    }

    if(start==2 && life==3)
    {
        iSetColor(214, 28, 11);
        iFilledRectangle(30, 500, 20, 3);
        iFilledRectangle(53, 500, 20, 3);
        iFilledRectangle(76, 500, 20, 3);
    }

    if(start==2 && life==2)
    {
        iSetColor(214, 28, 11);
        iFilledRectangle(30, 500, 20, 3);
        iFilledRectangle(53, 500, 20, 3);
        iSetColor(117, 92, 87);
        iFilledRectangle(76, 500, 20, 3);
    }

    if(start==2 && life==1)
    {
        iSetColor(214, 28, 11);
        iFilledRectangle(30, 500, 20, 3);
        iSetColor(117, 92, 87);
        iFilledRectangle(53, 500, 20, 3);
        iFilledRectangle(76, 500, 20, 3);
    }

    //End bracket of start=2*************************
    }

    //Game over display->Win*************************
    if(start==5)
    {
        iShowBMP(350, 100, "Tomwin1.bmp");

        //score display
        iSetColor(186, 11, 40);
        iText(450, 550, finalscorestr, GLUT_BITMAP_TIMES_ROMAN_24);
        iText(450, 500, highscorestr, GLUT_BITMAP_TIMES_ROMAN_24);

        iShowBMP(540, 50, "New_game_1.bmp");
        newgame=1;
    }

    //Game over display->Lose*************************
    if(start==6)
    {
        iDelay(3);
        iShowBMP(180, 0, "Gameover.bmp");
        iShowBMP(480, 350, "Gameovertom3.bmp");
        iText(450, 150, finalscorestr);
        iShowBMP(510, 80, "New_game_2.bmp");
        newgame=1;
    }


    //Resume page after pausing*********************
    if(start==8)
    {
        iShowBMP(0, 0, "Cool_intro.bmp");
        if(resume==1)
        {
            iShowBMP(200, 500, "Resume_2.bmp");
            iShowBMP(200, 450, "Main menu_1.bmp");
        }

        if(resume==2)
        {
            iShowBMP(200, 500, "Resume_1.bmp");
            iShowBMP(200, 450, "Main menu_2.bmp");
        }
    }


    //More page display
    if(start==9)
    {
        iShowBMP(0, 0, "bg1.bmp");
        //Best Figures
        if(moremenu==1)
        {
            iShowBMP(30, 340, "Best_figures_2.bmp");
            iShowBMP(30, 290, "Credits_1.bmp");
            iShowBMP(30, 220, "Back_1.bmp");
        }
        //Credits
        if(moremenu==2)
        {
            iShowBMP(30, 340, "Best_figures_1.bmp");
            iShowBMP(30, 290, "Credits_2.bmp");
            iShowBMP(30, 220, "Back_1.bmp");
        }
        //Back
        if(moremenu==3)
        {
            iShowBMP(30, 340, "Best_figures_1.bmp");
            iShowBMP(30, 290, "Credits_1.bmp");
            iShowBMP(30, 220, "Back_2.bmp");
        }
    }

    //For Best Figures
    if(start==10)
    {
        iShowBMP(0, 0, "menubg3.bmp");
        iShowBMP(1050, 50, "Back_2.bmp");

        Highscore=GetHighScore();
        int p=Highscore/3600;
        int q=Highscore/60;
        int r=Highscore%60;

        //score display
        sprintf(highscorestr, "Best Timing-> H: %d  M: %d  S: %d", p, q, r);
        iSetColor(21, 183, 189);
        iText(440, 350, highscorestr, GLUT_BITMAP_TIMES_ROMAN_24);
    }
    //For Credits
    if(start==11)
    {
        iShowBMP(50, 0, "Credits5.bmp");
        iShowBMP(1050, 50, "Back_2.bmp");
    }

//End of iDraw()**********************************
}


void iMouseMove(int mx, int my)
{
    //No codes here//
}


void iMouse(int button, int state, int mx, int my)
{
    //To get over lower obstacle
    if(start==2 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        //Tom will not go up or down while in pause
        if(notpause==0)
        {
        jump=3;
        Tom.ymove+=18;
        Tom.xmove-=10;
        }
    }
    if(start==2 && button == GLUT_LEFT_BUTTON && state == GLUT_UP)
    {
        if(notpause==0)
        {
        jump=0;
        Tom.ymove-=18;
        }
    }

    //To get down upper obstacle
    if(start==2 && button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        if(notpause==0)
        {
        jump=3;
        Tom.ymove-=5;
        Tom.xmove-=10;
        }
    }
    if(start==2 && button == GLUT_RIGHT_BUTTON && state == GLUT_UP)
    {
        if(notpause==0)
        {
        jump=0;
        Tom.ymove+=5;
        }
    }

    //Mouse navigation for main menu without resume
    //Start game
    if(start==1 && resumepage==0 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && (mx>=30 && mx<=190) && (my>=405 && my<=445))
    {
        menu=1;
        start=2;
    }
    //Settings
    if(start==1 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && (mx>=30 && mx<=130) && (my>=340 && my<=380))
    {
        menu=2;
        start=4;
        settingspage=1;
    }
    //Instructions
    if(start==1 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && (mx>=30 && mx<=220) && (my>=290 && my<=325))
    {
        menu=3;
        start=7;
    }
    //Quit game
    if(start==1 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && (mx>=30 && mx<=150) && (my>=230 && my<=260))
    {
        menu=4;
        exit(0);
    }

    //Mouse navigation for settings page
    //Sound on
    if(menu==2 && start==4 && settingspage==1 && sound==0 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && (mx>=30 && mx<=80) && (my>=422 && my<=455))
    {
        settings=1;
        sound=1;
        PlaySound("Tales.wav", NULL, SND_ASYNC | SND_LOOP);
    }
    //Sound off
    if(menu==2 && start==4 && settingspage==1 && sound==1 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && (mx>=30 && mx<=85) && (my>=375 && my<=415))
    {
        settings=2;
        sound=0;
        PlaySound(0, 0, 0);
    }
    //Level->Easy
    if(menu==2 && start==4 && settingspage==1 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && (mx>=30 && mx<=100) && (my>=240 && my<=275))
    {
        settings=3;
        level=1;
        Tom.speed=1.5; Jerry.speed=1.3; Spikespeed=1;
        wall.speed=3; obstaclespeed=3;
        b.speed=3; sil.speed=3;
        spikejumprange=5;
    }
    //Level->Medium
    if(menu==2 && start==4 && settingspage==1 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && (mx>=30 && mx<=140) && (my>=195 && my<=225))
    {
        settings=4;
        level=2;
        Tom.speed=3; Jerry.speed=2.5; Spikespeed=2;
        wall.speed=4; obstaclespeed=4;
        b.speed=4; sil.speed=4;
        spikejumprange=8;
    }
    //Level->Hard
    if(menu==2 && start==4 && settingspage==1 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && (mx>=30 && mx<=110) && (my>=150 && my<=182))
    {
        settings=5;
        level=3;
        Tom.speed=5; Jerry.speed=4.4; Spikespeed=2;
        wall.speed=6; obstaclespeed=6;
        b.speed=6; sil.speed=6;
        spikejumprange=12;
    }
    //Back from Settings
    if(menu==2 && start==4 && settingspage==1 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && (mx>=30 && mx<=90) && (my>=80 && my<=115))
    {
        start=1;
        menu=2;
        settingspage=0;
        if(sound==1)
        {
            settings=1;
        }
        else if(sound==0)
        {
            settings=2;
        }
    }

    //Mouse navigation for main menu with resume
    //New game
    if(start==1 && resumepage==1 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && (mx>=30 && mx<=190) && (my>=405 && my<=445))
    {
        reset();

        start=1;
    }
    //Resume
    if(start==1 && resumepage==1 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && (mx>=30 && mx<=140) && (my>=150 && my<=205))
    {
        menu=1;
        start=2;
    }

    //resume after pausing
    //Mouse navigation for resume and main menu
    if(start==8 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && (mx>=200 && mx<=330) && (my>=500 && my<=540))
    {
        start=2;
    }
    if(start==8 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && (mx>=200 && mx<=365) && (my>=450 && my<=490))
    {
        start=1;
        resume=1;
        resumepage=1;
        menulimit=5;
    }

    //New game after Tom loses
    if(start==6 && newgame==1 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && (mx>=510 && mx<=670) && (my>=80 && my<=120))
    {
        newgame=0;
        reset();
        start=1;
    }

    //New game after Tom wins
    if(start==5 && newgame==1 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && (mx>=540 && mx<=670) && (my>=50 && my<=85))
    {
        newgame=0;
        reset();
        start=1;
    }

    //Accessing the more button
    if(start==1 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && (mx>=1100 && mx<=1150) && (my>=520 && my<=570))
    {
        start=9;
    }

    //Accessing more page buttons
    //Best Figures
    if(start==9 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && (mx>=30 && mx<=160) && (my>=340 && my<=375))
    {
        start=10;
        moremenu=1;
    }
    //Credits
    if(start==9 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && (mx>=30 && mx<=130) && (my>=290 && my<=325))
    {
        start=11;
        moremenu=2;
    }
    //Back
    if(start==9 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && (mx>=30 && mx<=95) && (my>=220 && my<=255))
    {
        start=1;
        moremenu=1;
    }

    //Getting back from any more
    if((start== 10 || start==11) && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && (mx>=1050 && mx<=1140) && (my>=50 && my<=90))
    {
        start=9;
    }
    //End**************************
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{

    if(key == 'q')
    {
        exit(0);
    }

    //Pause and Resume with space key
    if(start==2 && key == 32)
    {
        cnt++;
        if((cnt%2) == 0)
        {
            iPauseTimer(0);
            notpause=1;
            resumepage=1;
            start=8;
        }
        if((cnt%2) == 1)
        {
            iResumeTimer(0);
            notpause=0;
        }
    }

    //Introducing game page
    if(start==0 && key == 's')
    {
        start=1;
    }

    //Menu selections
    //Start game
    if(start==1 && resumepage==0 && menu==1 && key=='\r')
    {
        start=2;
    }
    //New game
    if(start==1 && resumepage==1 && menu==1 && key=='\r')
    {
        reset();
        start=1;
    }
    //Settings
    if(start==1 && menu==2 && key=='\r')
    {
        start=4;
        settingspage=1;
    }
    //Quit game
    if(start==1 && menu==4 && key=='\r')
    {
        exit(0);
    }

    //Resume
    if(start==1 && menulimit==5 && menu==5 && key=='\r')
    {
        start=2;
    }

    //Within Settings*******************
    //Sound on
    if(menu==2 && start==4 && settingspage==1 && settings==1 && sound==0 && key=='\r')
    {
        sound=1;
        PlaySound("Tales.wav", NULL, SND_ASYNC | SND_LOOP);
    }
    //Sound off
    if(menu==2 && start==4 && settingspage==1 && settings==2 && sound==1 && key=='\r')
    {
        sound=0;
        PlaySound(0, 0, 0);
    }
    //Level->Easy
    if(menu==2 && start==4 && settingspage==1 && settings==3 && key=='\r')
    {
        level=1;
        Tom.speed=1.5; Jerry.speed=1.3; Spikespeed=1;
        wall.speed=3; obstaclespeed=3;
        b.speed=3; sil.speed=3;
        spikejumprange=5;
    }
    //Level->Medium
    if(menu==2 && start==4 && settingspage==1 && settings==4 && key=='\r')
    {
        level=2;
        Tom.speed=3; Jerry.speed=2.5; Spikespeed=2;
        wall.speed=4; obstaclespeed=4;
        b.speed=4; sil.speed=4;
        spikejumprange=8;
    }
    //Level->Hard
    if(menu==2 && start==4 && settingspage==1 && settings==5 && key=='\r')
    {
        level=3;
        Tom.speed=5; Jerry.speed=4.4; Spikespeed=2;
        wall.speed=6; obstaclespeed=6;
        b.speed=6; sil.speed=6;
        spikejumprange=12;
    }
    //Back from settings
    if(menu==2 && start==4 && settingspage==1 && settings==6 && key=='\r')
    {
        start=1;
        settingspage=0;
        if(sound==1)
        {
            settings=1;
        }
        else if(sound==0)
        {
            settings=2;
        }
    }

    //For instruction navigation
    if(start==1 && menu==3 && key=='\r')
    {
        start=7;
    }

    //Tom jump state
    if(start==2 && jump==0 && key=='w')
    {
        jump=1;
    }
    if(start==2 && ((jump==1) || (jump==4)) && key=='s')
    {
        jump=2;
    }

    //Using the coins
    if(start ==2  && coinage>5 && key=='d')
    {
        coinage-=5;
        Tom.xmove+=25;
    }
    if(start==2 && jump==0 && key=='a'  && coinage>=15)
    {
        jump=4;
        coinage-=15;
    }

    //For resume
    if(start==8 && resume==1 && key=='\r')
    {
        start=2;
    }

    if(start==8 && resume==2 && key=='\r')
    {
        start=1;
        resume=1;
        resumepage=1;
        menulimit=5;
    }

    //For new game after Tom loses
    if(start==6 && newgame==1 && key=='\r')
    {
        newgame=0;
        reset();
        start=1;
    }

    //For new game after Tom wins
    if(start==5 && newgame==1 && key=='\r')
    {
        newgame=0;
        reset();
        start=1;
    }

    //For more page navigation
    //Best Figures
    if(start==9 && moremenu==1 && key=='\r')
    {
        start=10;
    }
    //Credits
    if(start==9 && moremenu==2 && key=='\r')
    {
        start=11;
    }
    //Exit
    if(start==9 && moremenu==3 && key=='\r')
    {
        start=1;
        moremenu=1;
    }

    //Getting back from any more****************************
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/

void iSpecialKeyboard(unsigned char key)
{

    if(key == GLUT_KEY_END)
    {
        exit(0);
    }

    //Menu Navigation
    if(start==1 && key == GLUT_KEY_UP)
    {
        menu--;
        if(menu==0)
        {
            menu=menulimit;
        }
    }
    if(start==1 && key == GLUT_KEY_DOWN)
    {
        menu++;
        if(menu==(menulimit+1))
        {
            menu=1;
        }
    }

    //For settings navigation
    if(start==4 && key == GLUT_KEY_UP && menu==2 && settingspage==1)
    {
        settings--;
        if(settings==0)
        {
            settings=6;
        }
    }
    if(start==4 && key == GLUT_KEY_DOWN && menu==2 && settingspage==1)
    {
        settings++;
        if(settings==7)
        {
            settings=1;
        }
    }

    //For instruction navigation
    if(start==7 && key == GLUT_KEY_LEFT && menu==3)
    {
        inst--;
        if(inst==0)
        {
            inst=10;
        }
    }
    if(start==7 && key == GLUT_KEY_RIGHT && menu==3)
    {
        inst++;
        if(inst==11)
        {
            inst=1;
        }
    }
    if(start==7 && menu==3 && key==GLUT_KEY_HOME)
    {
        start=1;
        inst=1;
    }

    //For resume
    if(start==8 && key==GLUT_KEY_DOWN)
    {
        resume++;
        if(resume==3)
        {
            resume=1;
        }
    }

    if(start==8 && key==GLUT_KEY_UP)
    {
        resume--;
        if(resume==0)
        {
            resume=2;
        }
    }

    if(start==8 && key==GLUT_KEY_HOME)
    {
        start=1;
        resume=1;
    }

    //For more page navigation
    if(start==9 && key == GLUT_KEY_UP)
    {
        moremenu--;
        if(moremenu==0)
        {
            moremenu=3;
        }
    }
    if(start==9 && key == GLUT_KEY_DOWN)
    {
        moremenu++;
        if(moremenu==4)
        {
            moremenu=1;
        }
    }

}

//Resetting Function
void reset(void)
{
        loxstart=421;
        uoxstart=631;
        toxstart=rand()%800;
        b.xstart=800;
        sil.xstart=1000;

        srand(time(0));
        int n=rand()%4;
        loxstart+=n*100;
        uoxstart+=n*100;
        toxstart+=n*100;
        b.xstart+=n*100;
        sil.xstart+=n*100;
        tobsrandmultiply=n*100;

        Tom.xmove=0; Tom.ymove=0;
        Jerry.xmove=0; Jerry.ymove=0;
        Spikexmove=0; Spikeymove=0;
        wall.xmove=0; obstaclexmove=0;
        b.xmove=0; sil.xmove=0;

        cnt=0;
        trip=0; tripcount=0;
        spikein=0; spikeout=0;

        vardiff=0; notpause=0; jerrywave=0;

        h=0; m=0; s=0;

        coinindex=0; silcoinindex=0; coinage=0;
        jwaveindex=0;
        for(a=0; a<50; a++)
        {
            bstore[a]=0;
        }
        for(a=0; a<50; a++)
        {
            silverstore[a]=0;
        }

        menu=1; menulimit=4; settingspage=0; settings=2;
        inst=1; jump=0;
        level=1;
        resume=1; resumepage=0;

        if(sound==1)
        {
            sound=0;
            PlaySound(0, 0, 0);
        }

        for(a=0; a<10; a++)
        {
            r3[a]=rand()%8;
        }

        life=3; score=0;
        spikecancatch=1; spikejumprange=5;

        moremenu=1;

        return;
}

//High Score Function
int GetHighScore()
{
    int n;
    FILE * fp;
    fp=fopen("archive.txt", "r");
    if(fp==NULL)
    {
        printf("Memory Allocation Error.\n");
        return 0;
    }

    fscanf(fp, "%d", &n);
    fclose(fp);

    return n;
}

//Function for storing score in file
void scorestore(int score)
{
    FILE * fp;
    fp=fopen("archive.txt", "r");
    if(fp==NULL)
    {
        printf("Memory Allocation Error\n");
        return;
    }

    int n;
    fscanf(fp, "%d", &n);
    fclose(fp);

    if(score<n)
    {
        fp=fopen("archive.txt", "wb");
        if(fp==NULL)
        {
            printf("Memory Allocation Error\n");
            return;
        }

        fprintf(fp, "%d", score);
        fclose(fp);
    }

    return;
}

//Function for the animations
void movewall(void)
{
    /*Usual x moving for Wall, obstacles
    Tom and jerry and booster*/

    wall.xmove-=wall.speed;
    b.xmove+=b.speed;
    sil.xmove+=sil.speed;
    Tom.xmove+=Tom.speed;
    Jerry.xmove+=Jerry.speed;
    obstaclexmove+=obstaclespeed;
    x-=3;

    //Return loop for Tom
    if(Tom.xmove>1180)
    {
        vardiff=Jerrybackx-Tomfrontx;
        Tom.xmove=0;
        Spikexmove=-5;
        Spikeymove=0;
        if(vardiff<300)
        {
            Jerry.xmove=100;
        }
        if(vardiff>=300)
        {
            Jerry.xmove=200;
        }
    }

    //Jerry waving
    if(Jerrybackx>1250 && Tomfrontx<1050)
    {
        jerrywave=1;
    }
    if(Tomfrontx>1050)
    {
        jerrywave=0;
    }

    //When Tom trips
    if(trip==1)
    {
        /*Spike won't come in
        if trips within 250*/
        if(Tombackx>300)
        {
        tripcount++;
        }
        if(Tombackx<250)
        {
            //But jerry will get advantage
            Jerry.xmove+=10;
        }

    //Spike comes in
    if(tripcount==1)
    {
        Spikexmove+=60;
        spikein=1;
    }
    trip=0;
    Tom.xmove-=25;
    }

    if(spikein==1)
    {
        //Usual x movement for Spike
        Spikexmove+=Spikespeed;
    }

    //Spike goes out after 600
    if(spikeout==1)
    {
        Spikexmove-=4;
        //Spike sits back in initial postion
        if(Spikexmove<=-30)
        {
            Spikexmove=-60;
            spikecancatch=1;
            spikein=0;
            spikeout=0;
            tripcount=0;
        }
    }
    //Spikein but won't come in in proximity
    if((spikein==1) && (Tombackx<150) && (Spikefrontx>0))
    {
        Spikexmove-=5;
    }

    if(life==0)
    {
        iPauseTimer(0);
        sprintf(finalscorestr, "You played for-> H: %d M: %d S: %d", h, m, s);
        start=6;
    }

    return;
}

int main()
{

    //place your own initialization codes here.

    //Helps to destroy the boosters after using
    for(a=0; a<50; a++)
    {
        bstore[a]=0;
    }
    for(a=0; a<50; a++)
    {
        silverstore[a]=0;
    }

    //Structured materials******
    Tom.xmove=0;
    Tom.ymove=0;
    Tom.speed=1.5;
    Jerry.xmove=0;
    Jerry.ymove=0;
    Jerry.speed=1.3;

    wall.xstart=0;
    wall.xmove=0;
    b.xstart=800;
    b.xmove=0;
    sil.xstart=1000;
    sil.xmove=0;
    wall.speed=3;
    b.speed=3;
    sil.speed=3;

    //For randomness of objects at initialization
    int n;
    srand(time(0));
    n=rand()%4;
    loxstart+=n*100;
    uoxstart+=n*100;
    toxstart=rand()%800;
    toxstart+=n*100;
    b.xstart+=n*100;
    sil.xstart+=n*100;
    tobsrandmultiply=n*100;

    //Initialize
    movewall();
    iSetTimer(1, movewall);
    iInitialize(1200, 600, "Whiskers!");


    return 0;
}
