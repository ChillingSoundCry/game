#define SHOW_CONSOLE
#include <windows.h>
#include <graphics.h>
#include<iostream>
#include<vector>
using namespace std;
int hp=100;
int magic=100;
int px=100,py=300,v=2,wqtype=1,bx=400,by=300,gj_sj_x=0;
bool close=false,end=true;
mouse_msg msg;
HANDLE hMutex = NULL;//������

/*
void pet()
{
	int x=-16;
int y=0,x1=-16,x2=-16;
//����һ��imgͼƬ����, ָ������. point image. 
PIMAGE img; 
initgraph(640, 480);
setbkcolor(EGERGB(255,128,192)); //���ñ�����ɫ 
img = newimage();
getimage(img,"MARIO.BMP",0,0); 
//�õ�һ��ͼƬ������ִ��exe�ļ�ͬһ��λ��. Ҳ����ָ����(c://MARIO.BMP) 
while(1)
{
putimage(x1 += 5,240,16*2,16*2,img,x += 17,1,16,16);
//putimage(dst x, dst y, dst with, dst high, img, 
// src x, src y, src with, src high);
//dst = destination(Ŀ��) ��Ӧ�ڴ�������
//src=source(Ŀ��Դ) ��Ӧ��ͼƬ����,��(MARIO.BMP) 
//getch(); //���Բ������� 
delay_ms(100);
y++; //��¼ͼƬ֡�ĸ��� 
if(5 == y)
{
x=-16; //�ص�ͼƬ��ʼλ�� 
y=0; 
} 
if(x1 > 640 )x1=-16; //�ص���Ļ��ʼλ�� 
// getch();
cleardevice(); //�򵥵�����ʵ�ֲ��� 
}
getch();
delimage(img); //�ͷ��ڴ�ָ�� 
}*/
void backpicture()
{
	PIMAGE img1 = newimage();
    getimage(img1, "1.jpg",0,0);
	putimage(0,0, img1); 
	delimage(img1);
}
void playpicture()
{
	PIMAGE img2 = newimage();
    getimage(img2, "2.jpg",0,0);
	putimage(60,385, img2); 
	delimage(img2);
	PIMAGE img3 = newimage();
    getimage(img3, "3.jpg",0,0);
	putimage(280,385, img3); 
	delimage(img3);
	PIMAGE img4 = newimage();
    getimage(img4, "4.jpg",0,0);
	putimage(500,385, img4); 
	delimage(img4);
}
void getwqpicture(PIMAGE wq)
{
setfont(20,0,"��Բ");
setbkmode(TRANSPARENT);
if(wqtype==1)
{
    getimage(wq, "wq1.jpg",0,0);
	outtextxy(10,40,"����:����");
}
else if(wqtype==2)
{
    getimage(wq, "wq2.jpg",0,0);
	outtextxy(10,40,"����:˪֮����");
}
else if(wqtype==3)
{
    getimage(wq, "wq3.jpg",0,0);
	outtextxy(10,40,"����:�����");
}
else if(wqtype==4)
{
    getimage(wq, "wq4.jpg",0,0);
	outtextxy(10,40,"����:�ɽ�");
}
else if(wqtype==5)
{
    getimage(wq, "wq5.jpg",0,0);
	outtextxy(10,40,"����:ʥ��.ʤ����Լ");
}
else if(wqtype==6)
{
    getimage(wq, "wq6.jpg",0,0);
	outtextxy(10,40,"����:���ӻ��и���");
}
else if(wqtype==7)
{
    getimage(wq, "wq7.jpg",0,0);
	outtextxy(10,40,"����:������");
}
else if(wqtype==8)
{
    getimage(wq, "wq8.jpg",0,0);
	outtextxy(10,40,"����:AK47��");
}
}
void player()
{
	PIMAGE player_ = newimage();
    getimage(player_, "player.jpg",0,0);
	//putimage(px,py, player_); 
	putimage_withalpha(NULL,player_,px,py);
	delimage(player_);
	PIMAGE wq = newimage();
	getwqpicture(wq); 
	putimage_withalpha(NULL,wq,px+40,py);
	delimage(wq);

}
void boss()
{
	PIMAGE Boss = newimage();
    getimage(Boss, "b.jpg",0,0);
	putimage_withalpha(NULL,Boss,bx,by); 
	delimage(Boss);
}
void bgj(int bgx,int bgy)
{
	PIMAGE bg = newimage();
    getimage(bg, "bg.jpg",0,0);
	putimage_withalpha(NULL,bg,bgx,bgy); 
	delimage(bg);
}
void drew()
{
	delay_fps(60);
	//delay_ms(60);
	cleardevice(); //�򵥵�����ʵ�ֲ���
	player();
	boss();
	bgj(gj_sj_x,by);
	/////////////////////////////////
	char hp_char[100];
	char magic_char[100];
	//setfont(20,0,"��Բ");
	//setbkmode(TRANSPARENT);
	outtextxy(10, 10, "HP:");
	outtextxy(75, 10,"ħ��ֵ:");
	itoa(hp,hp_char,10);
	itoa(magic,magic_char,10);
	outtextxy(38, 10, hp_char);
	outtextxy(143, 10,magic_char);
	

}
void hurt()
{
	if(gj_sj_x>=px && gj_sj_x<=px+55 && by>=py && by <= py+55)
	{
		hp-=5;
	}
	else if(hp<=0)
	{
		cleardevice(); //�򵥵�����ʵ�ֲ���
		setcolor(BLACK);
		setfont(100,0,"����");
		outtextxy(100,150,"DEAD");
		outtextxy(100,300,"END");
		//end=true;//���ƶ��̹߳ر�
		//end=false;
		hp=100;
	}
}
void keyb()
{
	if(kbhit())
	{
	int c=getch();
	switch(c)
	{
	case 119://w
		py-=v;
		keyb();
		break;
	case 115://s
		if(py<=410){
		py+=v;
		keyb();}
		break;
	case 97://a
		if(px>=-4){
		px-=v;
		keyb();}
		break;
	case 100://d
		if(px<=660){
		px+=v;
		keyb();}
		break;
	case 107://k
		if(wqtype<8){
			wqtype++;}else
		{wqtype=1;}
			keyb();
		break;
	case 32://' '
		keyb();
		break;
	}
	}
}
//�̺߳���
DWORD WINAPI Bg(LPVOID lpParamter)
{
	//����һ����������
        WaitForSingleObject(hMutex, INFINITE);
		while(1)
		{
        for(int j=bx;j>0;j--)
		{
			api_sleep(0.001);
			gj_sj_x=j;
			//
		}
		//�ͷŻ�������
        ReleaseMutex(hMutex);
		}
    return 0L;//��ʾ���ص���long�͵�0

}
void getposition();
void begin();
void play();
int main()
{
    //initgraph(800,500);
	initgraph(720,470);
	SetWindowTextA(getHWnd(), "�Ҷ�"); 	
	setbkcolor(WHITE);

	backpicture();
	playpicture();
    while(is_run())
    {
	getposition();
	begin();
	if(close)
	{break;}
    }
    closegraph();
    return 0;
}	


void getposition()
{
	msg = getmouse();
	cout<<"x: "<<msg.x<<"y: "<<msg.y<<endl;
}
void begin()
{
	if(msg.flags == mouse_flag_left && msg.is_up()){
	if(msg.x<=188 && msg.x>=60 && msg.y>=385 && msg.y<=435)
	{
		cout<<"Begin"<<endl;
		play();
	}
	else if(msg.x<=628 && msg.x>=280 && msg.y>=385 && msg.y<=435)
	{
		close=true;
	}}
}
void play()
{
	//����һ�����߳�
    HANDLE hThread = CreateThread(NULL, 0, Bg, NULL, 0, NULL);
    hMutex = CreateMutex(NULL, FALSE,"screen");
    //�ر��߳�
    CloseHandle(hThread);
	while(is_run())
	{
		//������һ����������
        WaitForSingleObject(hMutex,INFINITE);
		drew();
		hurt();
        keyb();
        //Sleep(100);
        //�ͷŻ�������
        ReleaseMutex(hMutex);
	}
}																																																										

/* ���ҿ������������ʴȵ���Ī���������޷�������˼����ȫ���ᴩ����ϵ��������

������������һ����Ϊ��֪��ƽ��С���ϣ��������޾��ĺڰ������Χ�������Ǳ��Ͳ����﷫Զ������

���г�һ�գ����������ܰ�������Щ�໥�ָ��֪ʶƴ�յ�һ��ʱ��չ����������ǰ����ʵ���磬�Լ����������еĴ��������������ǲ��������񣬾��Ǵӿ��µĹ�â�ж㵽�ڰ��¼�Ԫ����ð����� ��

  ���г��Կ���³������������ħ����

����������֮�顷�����䣺

That is not dead which can eternal lie
���߲�������Զ��Ϣ

And with strange aeons even death may die
�ڹ��ص�����м�������Ҳ������

����仰��Ӣ��������ľ�������



�Լ��Ǿ䱻��ͽ�ǹ�Ϊ���������ò�Ϣ����䣺

�������լۡ����Ү�У����ߵĿ���³�������� Ph'nglui mglw'nafh Cthulhu R'lyeh wgah'nagl fhtagn!
*/
