#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<windows.h>
#include<stdlib.h>
#pragma warning(disable:4996)
int width = 800, height = 600, gravity = 1;//ȫ�ֱ������廭�泤������Ϸ��������
struct ball//����С�����Խṹ��
{
	int r;//С��뾶
	int x;//С���������
	int y;//С����������
	int vy;//С���ʼy�ٶ�
}b;
struct rect//���巽�����Խṹ��
{
	int h;//����߶�
	int w;//������
	int x;//������ߺ�������
	int y;//���鶥����������
	int vx;//��������ƶ��ٶ�
}r;
int main()
{
	int flag = 1,score = 0;//������Ϸ������־�����
	initgraph(width, height); //��ʼ��ͼ�ν���
	setbkcolor(GREEN);//���ý��汳����ɫ
	b.r = 20;
	b.x = width / 4;
	b.y = height - b.r;
	b.vy = 0;                                   
  	/*��ʼ��С����������*/
	r.h = 100;
	r.w = 20;
	r.x = width*3/4;
	r.y = height - r.h;
	r.vx = -7;
	/*��ʼ��������������*/
	fillcircle(b.x, b.y, b.r);//����С��
	fillrectangle(r.x, height - r.h, r.x + r.w, height);//���Ʒ����ϰ���
	while (flag)
	{
		if ((r.x <= b.x + b.r) && (r.x + r.w >= b.x - b.r) && (height - r.h <= b.y + b.r))
			flag = 0;
		if (kbhit())//����Ƿ��м�������                                                    
		{
			char input = _getch();//��ȡ����ֵ
			if (input == ' ')//�ж��Ƿ�Ϊ�ո���Ծ��
				b.vy = -15;//С����Ծһ�εĳ��ٶ�
		}
		b.vy += gravity;//��ֱ�����˶�˲ʱ�ٶȵ����ٶȾ���ֵ��ȥ�������ٶ�
		b.y += b.vy;//������������y�����ٶȸı�
		if (b.y >= height - b.r)
		{
			b.vy = 0;//��Ϸ����ΪС���޵�������ٶȼ���Ϊ0
			b.y = height - b.r;//���ñ߽�
		}
		r.x += r.vx;//�������������ٶ�����
		if (r.x <= 0)//��������Ƴ���߽�
		{
			r.x = width-r.w;
			r.h = rand() % (height/4)+height/4;
			r.vx = rand() / RAND_MAX * 4 - 7;
			score++;
		}
		cleardevice();//����
		fillcircle(b.x, b.y, b.r);//���»���С��
		fillrectangle(r.x, height - r.h, r.x + r.w, height);//���Ʒ����ϰ��� 
		TCHAR s[20];//����Tchar�ַ���
		_stprintf(s, _T("%d"), score);//������תΪ�ַ���
		settextstyle(30, 0, _T("����"));//���÷��������ʽ
		outtextxy(50, 30, s);//����÷�����
		Sleep(30);//ˢ����Ļ
	}
	closegraph();
	return 0;
}