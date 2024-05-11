#include"snakefun.h"
#include"Snake_setting.h"
using namespace std;
int food_x;//食物坐标
int food_y;//食物坐标
int tem =1;
int main(){	
	Ini_Game();
	Creat_snake();
	cout<<"按J开始游戏"<<endl;
	getchar();
	border();
	ycgb(0);
	tem=1;
	
	while(1){
				if(s1[0].direction==0)
		{
			s1[0].x++;//D
			
		}
		if(s1[0].direction==1)
		{
			s1[0].x--;//A
		}
		if(s1[0].direction==2)
		{
			s1[0].y++;//S
		}
		if(s1[0].direction==3)
		{
			s1[0].y--;//W
		}
		

	
		if(_kbhit())
		{
		char ch = _getch();
		if(ch == 'j' )
		{
			system("cls");
			tem = 1;
			border();	
		}
		if(ch=='d' && s1[0].direction!=1){
			s1[0].direction=0;
			Draw_snake();
			Sleep(SNAKE_SPEED);
			if(Check_collision())
			{
				break;
			}
				continue;
		} 
		if(ch=='a'&& s1[0].direction!=0){
		 	s1[0].direction=1;
			Draw_snake();
			Sleep(SNAKE_SPEED);
			if(Check_collision())
			{
				break;
			}
				continue;
		} 
		if(ch=='s'&& s1[0].direction!=3){
			s1[0].direction=2;
			Draw_snake();
			Sleep(SNAKE_SPEED);
			if(Check_collision())
			{
				break;
			}
				continue;
			
		} 
		if(ch=='w'&& s1[0].direction!=2){
			s1[0].direction=3;
			Draw_snake();	
			Sleep(SNAKE_SPEED);
			if(Check_collision())
			{
				break;
			}
			continue;
		}	
	}Draw_snake();
		if(Check_collision())
			{
				break;
			}
		if(tem)
		{	
			 int tems=1;
			 while(tems){
			 	food_x = rand()%Ini_X2+1;
			 food_y = rand()%Ini_Y2+1;
			 tems=0;
			 for(int i=0;i<s1[0].length;i++)
			 {
				if(s2[i].x==food_x && s2[i].y == food_y)
				{
					tems =1;
				}
			 }
			 
			 }
			gotoxy(food_x,food_y);
			cout<<"*";
			tem = 0;
		}
		
		if((s1[0].x==food_x && s1[0].y==food_y))
		{
			tem = 1;
			s1[0].length++;
		}
	
	Sleep(SNAKE_SPEED);
	
}
system("cls");
gotoxy(0,Ini_Y2+1);
cout<<"GAME OVER"<<endl;
return 0;
}



