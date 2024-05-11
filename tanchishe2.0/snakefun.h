#include"tanchishedefine.h"
#include<iostream>
#include<Windows.h>
#include<conio.h>
using namespace std;
void Ini_Game(){
	 HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // 设置控制台窗口信息
    SMALL_RECT windowSize = {0, 0, 1000, 1000}; // 左上角 (0, 0)
    SetConsoleWindowInfo(hConsole, TRUE, &windowSize);

    // 获取并输出设置后的控制台窗口大小
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
}
void Creat_snake(){//初始化蛇
	s1[0].x=31,s1[0].y=20,s1[0].length=SNAKE_INT_LENGTH;
	for(int i=0;i<s1[0].length;i++)
	 {
	 	s2[i].x=31-i,s2[i].y=20,s2[i].length=4;
	 }
		
}
void cls(){//清屏
	for(int i=0;i<100;i++)
	{
		for(int j=0;j<100;j++)
		{
			gotoxy(i,j);
			cout<<" ";
		}
	}
}
extern void gotoxy(int x,int y) //移动光标  
{  
   
 COORD coord = {x, y}; 
 //COORD是Windows API中定义的一种结构体类型，表示控制台屏幕上的坐标。
 //上面语句是定义了COORD类型的变量coord，并以形参x和y进行初始化。
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
 //GetStdHandle(STD_OUTPUT_HANDLE); 获取控制台输出句柄
 //然后用SetConsoleCursorPosition设置控制台(cmd)光标位置

}  
void ycgb(int k)//隐藏光标  
{  
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);  
    CONSOLE_CURSOR_INFO cci;  
    GetConsoleCursorInfo(hOut,&cci);  
    cci.bVisible=k;//赋1为显示，赋0为隐藏  
    SetConsoleCursorInfo(hOut,&cci);  
}

void Draw_snake(){//画蛇
	
	
		for(int j=s1[0].length;j>0;j--)
	{
		s2[j].x=s2[j-1].x;
		s2[j].y=s2[j-1].y;
	}
	s2[0].x=s1[0].x,s2[0].y=s1[0].y;
	for(int i=0;i<s1[0].length-1;i++)
	{	if(i==0)
	{
		gotoxy(s2[i].x,s2[i].y);
		cout<<SNAKE_HEND;
		continue;
	}
		gotoxy(s2[i].x,s2[i].y);
		cout<<SNAKE_BODY;
	}

	gotoxy(s2[s1[0].length].x,s2[s1[0].length].y);
	cout<<" ";
}
void border()
{

	for(int i=Ini_X1;i<Ini_X2;i++)
	{
		gotoxy(i,Ini_Y1);
		cout<<BORDER;
		gotoxy(i,Ini_Y2);
		cout<<BORDER;
	}
	for(int j=Ini_Y1;j<Ini_Y2;j++)
	{
		gotoxy(Ini_X1,j);
		cout<<BORDER;
		gotoxy(Ini_X2,j);
		cout<<BORDER;
	}
}
bool Check_collision(){
	for(int i=1;i<s1[0].length;i++)
	{
		if(s1[0].x==s2[i].x && s1[0].y == s2[i].y)
		{
			return true;
		}
	}
		if(s1[0].x >=Ini_X2 || s1[0].x<=Ini_X1 || s1[0].y>=Ini_Y2-1 || s1[0].y <=Ini_Y1)//边界检测
		{
			return true;
		}
	return false;
}
