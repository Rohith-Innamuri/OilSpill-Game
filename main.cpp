#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<stdio.h>
#include"windows.h"
#define RIGHT  0
#define LEFT  1
#define number 10
using namespace std;
bool running;
int isalive = 0;
int score = 0;
int lives = 5;
int direction = 1;
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
    void draw()
    {
        for (int z = 0; z < 5; z++)
        {
            gotoxy(containerX +z,containerY );
            cout<<container_symbol;
        }
    }
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
    void bounce()
    {
        switch (direction)
        {
        case RIGHT: containerX--;
            break;
        case LEFT: containerX++;
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

class drop : public GameObject,public container
{
public:
    int isalive=0;
    int dropX;
    int dropY;
    char drop_symbol;
    void odrop(char dsymbol,int dy)
    {
        drop_symbol = dsymbol;
        dropY = dy;
    }
    ~drop(){}
    void movement()
    {
        dropY++;
        //container*container;
        if(dropY==containerX||dropY==containerX+1||dropY==containerX+2||dropY==containerX+3||dropY==containerX+4)
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
            {
                gotoxy(0,4);
                cout<<"Lives left:"<<"0/5";
                running=false;
                gotoxy(0,6);
                cout<<"!!!GAME OVER!!!";
                exit(0);
            }

        }

    }

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
        cout<<"A- Left, D- Right,E-Quit";
        gotoxy(0,4);
        cout<<"Lives left:"<<lives<<"/5";
        gotoxy(0,5);
        cout<<"Score:"<<score;

        }
    }
   /* void checkcollison(container *container)
    {
        if (x == container->x && y == container->y)
        {
            y = 0;
            score += 50;
            isalive = 0;

        }
        else
        {
            lives=lives-1;
        }
          if(lives==0)
         running=false;
       }*/
};
void clrscr()
{
	system("cls");
}
int main()
{
    container c;
    container *f[4];
    //f[4]=&c;
    //container *c=new container('X',38,23);
    drop d;
    drop *drops[number];
    //drops[number]=&d;
    //drop d('0',0);
    //container c('X',38,23);
    //container *co=&c;
        for (int z = 0; z < 4; z++)
        {
        f[z]= &c;
        c.ocontainer('X', 38, 23);
        }
        for(int y = 0; y<number; y++)
        {
            drops[y] = &d;
            d.odrop('0',0);
        }

            while (running=true)
        {

            clrscr();
          // d.checkcollison(co);
            for (int z = 0; z < number;z++)
            {
                 if (drops[z]->isalive ==0)
                 {
                    drops[z]->dropX = rand() %40+20;// location of drops
                    drops[z]->isalive = 1;
                    //d.checkcollison(co);
                  }
                 if(drops[z]->isalive !=0)
                 {
                    drops[z]->draw();
                    drops[z]->movement();
                    //d.checkcollison(co);
                    break;
                 }

            }
//            checkcollision();
        //including here to update the score after each loop.
        /*gotoxy(0,4);
        cout<<"Lives left:"<<lives<<"/5";
        gotoxy(0,5);
        cout<<"Score:"<<score;*/

            for (int z = 0; z != 4; z++)
            {
                f[z]-> draw();
                if(kbhit())f[z]->movement();
                f[z]->bounce();
            }

        Sleep(100);
        }
        return 0;
}

