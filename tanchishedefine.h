#define SNAKE_SPEED   100//蛇的速度
#define SNAKE_INT_LENGTH 20 //蛇的初始长度,最大30
#define Ini_X1 0 
#define Ini_Y1 0
#define Ini_X2 100
#define Ini_Y2 30
typedef struct snake {//定义蛇
	int x;
	int y;
	int direction;
	int length;
}snake;
snake s1[1];
snake s2[100];
//方法
void Ini_Game();
void ycgb(int k); //隐藏光标 
void gotoxy(int x, int y); //光标的移动 
void Draw_snake();//画蛇
void gotoxy(int x,int y);//坐标
void border();
bool Check_collision();