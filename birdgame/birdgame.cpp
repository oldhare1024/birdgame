#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<windows.h>
#include<stdlib.h>
#pragma warning(disable:4996)
int width = 800, height = 600, gravity = 1;//全局变量定义画面长宽与游戏重力属性
struct ball//定义小球属性结构体
{
	int r;//小球半径
	int x;//小球横轴坐标
	int y;//小球纵轴坐标
	int vy;//小球初始y速度
}b;
struct rect//定义方块属性结构体
{
	int h;//方块高度
	int w;//方块宽度
	int x;//方块左边横轴坐标
	int y;//方块顶部纵轴坐标
	int vx;//方块横向移动速度
}r;
int main()
{
	int flag = 1,score = 0;//定义游戏结束标志与分数
	initgraph(width, height); //初始化图形界面
	setbkcolor(GREEN);//设置界面背景颜色
	b.r = 20;
	b.x = width / 4;
	b.y = height - b.r;
	b.vy = 0;                                   
  	/*初始化小球属性数据*/
	r.h = 100;
	r.w = 20;
	r.x = width*3/4;
	r.y = height - r.h;
	r.vx = -7;
	/*初始化方块属性数据*/
	fillcircle(b.x, b.y, b.r);//绘制小球
	fillrectangle(r.x, height - r.h, r.x + r.w, height);//绘制方块障碍物
	while (flag)
	{
		if ((r.x <= b.x + b.r) && (r.x + r.w >= b.x - b.r) && (height - r.h <= b.y + b.r))
			flag = 0;
		if (kbhit())//检测是否有键盘输入                                                    
		{
			char input = _getch();//获取输入值
			if (input == ' ')//判断是否为空格跳跃键
				b.vy = -15;//小球跳跃一次的初速度
		}
		b.vy += gravity;//竖直上抛运动瞬时速度等于速度绝对值减去重力加速度
		b.y += b.vy;//纵轴坐标依据y方向速度改变
		if (b.y >= height - b.r)
		{
			b.vy = 0;//游戏规则为小球无弹性落地速度即变为0
			b.y = height - b.r;//设置边界
		}
		r.x += r.vx;//方块坐标依据速度左移
		if (r.x <= 0)//如果方块移出左边界
		{
			r.x = width-r.w;
			r.h = rand() % (height/4)+height/4;
			r.vx = rand() / RAND_MAX * 4 - 7;
			score++;
		}
		cleardevice();//清屏
		fillcircle(b.x, b.y, b.r);//重新绘制小球
		fillrectangle(r.x, height - r.h, r.x + r.w, height);//绘制方块障碍物 
		TCHAR s[20];//定义Tchar字符串
		_stprintf(s, _T("%d"), score);//将分数转为字符串
		settextstyle(30, 0, _T("宋体"));//设置分数输出样式
		outtextxy(50, 30, s);//输出得分文字
		Sleep(30);//刷新屏幕
	}
	closegraph();
	return 0;
}