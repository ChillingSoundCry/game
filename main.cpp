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
HANDLE hMutex = NULL;//互斥量

/*
void pet()
{
	int x=-16;
int y=0,x1=-16,x2=-16;
//声明一个img图片对象, 指针类型. point image. 
PIMAGE img; 
initgraph(640, 480);
setbkcolor(EGERGB(255,128,192)); //设置背景颜色 
img = newimage();
getimage(img,"MARIO.BMP",0,0); 
//得到一个图片，放在执行exe文件同一个位置. 也可以指定如(c://MARIO.BMP) 
while(1)
{
putimage(x1 += 5,240,16*2,16*2,img,x += 17,1,16,16);
//putimage(dst x, dst y, dst with, dst high, img, 
// src x, src y, src with, src high);
//dst = destination(目标) 对应于窗口坐标
//src=source(目标源) 对应于图片坐标,如(MARIO.BMP) 
//getch(); //可以步进调试 
delay_ms(100);
y++; //记录图片帧的个数 
if(5 == y)
{
x=-16; //回到图片起始位置 
y=0; 
} 
if(x1 > 640 )x1=-16; //回到屏幕起始位置 
// getch();
cleardevice(); //简单的清屏实现擦除 
}
getch();
delimage(img); //释放内存指针 
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
setfont(20,0,"幼圆");
setbkmode(TRANSPARENT);
if(wqtype==1)
{
    getimage(wq, "wq1.jpg",0,0);
	outtextxy(10,40,"武器:村雨");
}
else if(wqtype==2)
{
    getimage(wq, "wq2.jpg",0,0);
	outtextxy(10,40,"武器:霜之哀伤");
}
else if(wqtype==3)
{
    getimage(wq, "wq3.jpg",0,0);
	outtextxy(10,40,"武器:赤焰大剑");
}
else if(wqtype==4)
{
    getimage(wq, "wq4.jpg",0,0);
	outtextxy(10,40,"武器:干将");
}
else if(wqtype==5)
{
    getimage(wq, "wq5.jpg",0,0);
	outtextxy(10,40,"武器:圣剑.胜利誓约");
}
else if(wqtype==6)
{
    getimage(wq, "wq6.jpg",0,0);
	outtextxy(10,40,"武器:量子化切割镰");
}
else if(wqtype==7)
{
    getimage(wq, "wq7.jpg",0,0);
	outtextxy(10,40,"武器:毁灭者");
}
else if(wqtype==8)
{
    getimage(wq, "wq8.jpg",0,0);
	outtextxy(10,40,"武器:AK47改");
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
	cleardevice(); //简单的清屏实现擦除
	player();
	boss();
	bgj(gj_sj_x,by);
	/////////////////////////////////
	char hp_char[100];
	char magic_char[100];
	//setfont(20,0,"幼圆");
	//setbkmode(TRANSPARENT);
	outtextxy(10, 10, "HP:");
	outtextxy(75, 10,"魔力值:");
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
		cleardevice(); //简单的清屏实现擦除
		setcolor(BLACK);
		setfont(100,0,"宋体");
		outtextxy(100,150,"DEAD");
		outtextxy(100,300,"END");
		//end=true;//控制多线程关闭
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
//线程函数
DWORD WINAPI Bg(LPVOID lpParamter)
{
	//请求一个互斥量锁
        WaitForSingleObject(hMutex, INFINITE);
		while(1)
		{
        for(int j=bx;j>0;j--)
		{
			api_sleep(0.001);
			gj_sj_x=j;
			//
		}
		//释放互斥量锁
        ReleaseMutex(hMutex);
		}
    return 0L;//表示返回的是long型的0

}
void getposition();
void begin();
void play();
int main()
{
    //initgraph(800,500);
	initgraph(720,470);
	SetWindowTextA(getHWnd(), "乱斗"); 	
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
	//创建一个子线程
    HANDLE hThread = CreateThread(NULL, 0, Bg, NULL, 0, NULL);
    hMutex = CreateMutex(NULL, FALSE,"screen");
    //关闭线程
    CloseHandle(hThread);
	while(is_run())
	{
		//请求获得一个互斥量锁
        WaitForSingleObject(hMutex,INFINITE);
		drew();
		hurt();
        keyb();
        //Sleep(100);
        //释放互斥量锁
        ReleaseMutex(hMutex);
	}
}																																																										

/* 在我看来，世上最仁慈的事莫过于人类无法将其所思所想全部贯穿、联系起来。”

“我们生活在一个名为无知的平静小岛上，被无穷无尽的黑暗海洋包围，而我们本就不该扬帆远航。”

“有朝一日，当我们真能把所有那些相互分割的知识拼凑到一起时，展现在我们面前的真实世界，以及人类在其中的处境，将会令我们不是陷入疯狂，就是从可怕的光芒中躲到黑暗新纪元以求得安宁。 ”

  还有出自克苏鲁神话中最著名的魔导书

——《死灵之书》的名句：

That is not dead which can eternal lie
死者并不会永远安息

And with strange aeons even death may die
在诡秘的万古中即便死亡也会消逝

（这句话用英文念出来颇具魄力）



以及那句被信徒们广为传唱，经久不息的神句：

在永恒的宅邸拉莱耶中，长眠的克苏鲁候汝入梦 Ph'nglui mglw'nafh Cthulhu R'lyeh wgah'nagl fhtagn!
*/
