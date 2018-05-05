#include<iostream>
#include<conio.h>
#include"windows.h"
#define RIGHT  0
#define LEFT  1
#define number 10
using namespace std;
bool running;
//int isalive = 0;
int score = 0;
int lives = 5;
int direction = 1;
int currX;//Updated X-Co-ordinates of container
/*This function is used to point the cursor in console at the location of our choice*/
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
class GameObject
{
    public:
    virtual void draw() = 0;
};
class container : public GameObject
{
public:
    int  containerX;
    int containerY;
    char container_symbol;
     void ocontainer(char csymbol, int cx, int cy)
    {
        container_symbol = csymbol;
        containerX = cx;
        containerY = cy;
    }
    /*This function is to draw the container*/
    void draw()
    {
         for (int z = 0; z < 8; z++)
        {
            gotoxy(containerX+z,containerY );
            cout<<container_symbol;
        }
    }
    /*This function takes the input from the keyboard*/
    void movement()
    {
        if (_kbhit())
        {
            char ch = _getch();
            switch (ch)
            {
            case 'a':
                direction = RIGHT;
                break;
            case 'd':
                direction = LEFT;
                break;
            case 'e':
                running=false;
                exit(0);
            break;
            case 'A':
                direction = RIGHT;
                break;
            case 'D':
                direction = LEFT;
                break;
            case 'E':
                running=false;
                exit(0);
            break;
            }
        }

    }
    /*This method takes care of the movemet of the container and  bounces back the container when it hits the boundary*/
    void bounce()
    {
        switch (direction)
        {
        case RIGHT: containerX--;
             currX=containerX;
            break;
        case LEFT: containerX++;
            currX=containerX;
            break;
        }
        if (containerX >= 60)
        {
            direction = RIGHT;
        }

        if (containerX<= 10)
        {
            direction = LEFT;
        }
    }
};

class drop :public GameObject, public container
{
public:
    int isalive=0;//Reset's drop's location, updates it's movement and displays scoreboard
    int dropX;//X- Co-ordinate of drop
    int dropY;//Y- Co-ordinate of drop
    char drop_symbol;
    void odrop(char dsymbol,int dy)
    {
        drop_symbol = dsymbol;
        dropY = dy;
    }
    /*This function takes care of the movement of the drop, increment  and decrement of score and lives respectively, restarting of game when it ends by player's choice*/
    void movement()
    {
        dropY++;
     if((dropY==23)&&(dropX ==currX||dropX == currX+1||dropX == currX+2||dropX == currX+3||dropX == currX+4||dropX == currX+5||dropX == currX+6||dropX == currX+7))
        {
            dropY=0;
            score=score+50;
            isalive=0;
        }
        if (dropY==25)
        {
            --lives;
            dropY=0;
            isalive=0;
            if(lives==0)
            {   char option;
                gotoxy(0,4);
                cout<<"Lives left:"<<"0/5";
                running=false;
                gotoxy(0,5);
                cout<<"Score:"<<score;
                gotoxy(0,6);
                cout<<"!!!GAME OVER!!!";
               gotoxy(0,7);
               cout<<"DO YOU WANT TO PLAY AGAIN??(Y/N)";
               cin>>option;
               if(option=='Y'||option=='y')
               {
                   running=true;
                   lives=5;
                   score=0;
                   int main();
               }
               else
                exit(0);
            }
        }
    }
/*This displays the leaderboard*/
    void draw()
    {

        {
        gotoxy(dropX, dropY);
        cout << drop_symbol;
        gotoxy(0,1);
        cout<<"OIL SPILL GAME";
         gotoxy(0,2);
        cout<<"Controls:";
        gotoxy(0,3);
        cout<<"A-Left,D-Right,E-Quit";
        gotoxy(0,4);
        cout<<"Lives left:"<<lives<<"/5";
        gotoxy(0,5);
        cout<<"Score:"<<score;
       /* //These statements are used to check the co-ordinates of drop and container (For Deveoper's use only)
       gotoxy(0,11);
       cout<<"Current containerX is "<<currX;
        gotoxy(0,12);
        cout<<"Current container Y is"<<containerY;
        gotoxy(0,13);
        cout<<"Current Drop y is:"<<dropY;
        gotoxy(0,14);
        cout<<"Drop X co-ordinate is "<<dropX;*/
        }
    }
};
/*This function is used to clear the console screen*/
void clrscr()
{
	system("cls");
}
int main()
{
    container c;
    drop d;
    drop *drops[number];//pointer object to use it in for loop of main game
    c.ocontainer('X', 38, 23);//sends arguements to ocontainer
        for(int y = 0; y<number; y++)
        {
            drops[y] = &d;//pointer object holds the address of object
            d.odrop('0',0);
        }
        /*This is the main game loop*/
          while (running=true)
        {
            clrscr();
            for (int z = 0; z < number;z++)
            {
                 if (drops[z]->isalive ==0)
                 {
                    drops[z]->dropX = rand() %40+20;// location of the drop, updates after each loop
                    drops[z]->isalive = 1;
                  }
                 if(drops[z]->isalive !=0)
                 {
                    drops[z]->movement();
                    drops[z]->draw();
                    break;
                 }

            }
            c.draw();
            if(kbhit())c.movement();
             c.bounce();
        Sleep(100);//to suspend the execution of a program(makes the game slower i.e playable)
        }
        return 0;
}

