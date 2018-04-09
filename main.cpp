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
    int x, y;
    char symbol;
    virtual void draw() = 0;
};
class container : public GameObject
{
public:
    container(char symbol, int x, int y)
    {
        this->symbol = symbol;
        this->x = x;
        this->y = y;
    }
    void draw()
    {
        for (int z = 0; z < 5; z++)
        {
            gotoxy(x + z, y);
            cout<<symbol;
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
        case RIGHT: x--;
            break;
        case LEFT: x++;
            break;
        }
        if (x >= 60)
        {
            direction = RIGHT;
        }
        if (x <= 10)
        {
            direction = LEFT;
        }
    }
};

class drop : public GameObject,public container
{
//private:

public:
    int isalive;
    drop(char symbol,int y)
    {
        this->symbol = symbol;
        this->y = y;
    }
    ~drop(){}
    void movement()
    {
        y++;
        container*container;
        if(x==container->x&&container->y)
        {
            y=0;
            score+=50;
            isalive=0;
        }
        if (y>23)
        {
            lives=lives-1;
            if(lives==0)
            {
                running=false;
                gotoxy(0,6);
                cout<<"!!!GAME OVER!!!";
                exit(0);
            }
            y=0;
            isalive=0;
        }

    }

    void draw()
    {

        {
        gotoxy(x, y);
        cout << symbol;
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
    void checkcollison(container *container)
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
       }
};
void clrscr()
{
	system("cls");
}
int main()
{

    container *f[4];
    //container *c=new container('X',38,23);
    drop *drops[number];
    drop d('0',0);
    container c('X',38,23);
    container *co=&c;
        for (int z = 0; z < 4; z++)
        {
        f[z]= new container('X', 38, 23);
        }
        for(int y = 0; y<number; y++)
        {
            drops[y] = new drop('0',0);
        }

            while (running=true)
        {

            clrscr();
          // d.checkcollison(co);
            for (int z = 0; z < number;z++)
            {
                 if (drops[z]->isalive ==0)
                 {
                    drops[z]->x = rand() %40+20;// location of drops
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

