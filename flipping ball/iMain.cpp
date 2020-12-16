/*
Author: Fuadul Hasan(fuadul202@gmail.com)
BSMRSTU,Gopalganj
*/
#include <iostream>
# include "iGraphics.h"
using namespace std;

#define screenwidth 1000
#define screenhight 600

int mposx, mposy;

int x = 0;
int y = 0;
int xline = 0;
int yline = 0;
int linedx = 200;
int linedy = 10;
int dx = 3;
int dy = 3;

int r = 255;
int g = 255;
int b = 255;

//ractangle colum variable..
int colx = 0;
int coly = 0;
int colxline = 10;
int colyline = 200;
int moveBer = 20;

//is game over or not..
bool game_over = false;

void iDraw()
{
	iClear();

	//ractangles row....
	iRectangle(xline, yline, linedx, linedy);
	iRectangle(xline, yline + screenhight - 10, linedx, linedy);
	iFilledRectangle(xline, yline, linedx, linedy);
	iFilledRectangle(xline, yline + screenhight - 10, linedx, linedy);

	//ractangle col....
	iRectangle(colx, coly, colxline, colyline);
	iRectangle(colx+screenwidth-10, coly, colxline, colyline);
	iFilledRectangle(colx, coly, colxline, colyline);
	iFilledRectangle(colx + screenwidth - 10, coly, colxline, colyline);

	//circle.....
	iSetColor(r, g, b);
	iFilledCircle(x, y, 10, 1000);

	//iText...
	//score..
	//iText(870, 20, "score: ", GLUT_BITMAP_TIMES_ROMAN_24);

	//game over 
	if (game_over) {
		iText(450, 300, "Game over", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(428, 280, "You are a loser", GLUT_BITMAP_TIMES_ROMAN_24);
		//iText(300, 260, "If you want to play this game again press Inter", GLUT_BITMAP_TIMES_ROMAN_24);
		return;
	}

}

void iMouseMove(int mx, int my)
{
	//place your codes here
}
int t = 0;
void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
}

void iPassiveMouseMove(int mx, int my)
{
	//place your code here

	mposx = mx;
	mposy = my;
	if (mx == 2){}        /*Something to do with mx*/
	else if (my == 2){}   /*Something to do with my*/

}

void iKeyboard(unsigned char key)
{
	if (key == 'a'){
		//linedx -= 5;
		if(xline-20>=0) xline -= 20;
	}
	else if (key == 'd'){
		//linedx += 5;
		if(xline+20<=screenwidth - linedx) xline += 20;
	}
	else if (key == 'w'){
		if(coly + moveBer<= screenhight- colyline)coly += moveBer;
	}
	else if (key == 's'){
		if(coly -moveBer >= 0)coly -= moveBer;
	}
}

void iSpecialKeyboard(unsigned char key)
{
	if (key == GLUT_KEY_LEFT){
		//linedx -= 5;
		if (xline - 20 >= 0) xline -= 20;
	}
	else if (key == GLUT_KEY_RIGHT){
		//linedx += 5;
		if (xline + 20 <= screenwidth - linedx) xline += 20;
	}
	else if (key == GLUT_KEY_UP){
		if (coly + moveBer <= screenhight - colyline)coly += moveBer;
	}
	else if (key == GLUT_KEY_DOWN){
		if (coly - moveBer >= 0)coly -= moveBer;
	}
}

void colorChange(){
	r = rand() % 255;
	g = rand() % 255;
	b = rand() % 255;
}

void change()
{
	x += dx;
	y += dy;

	if (x >= screenwidth || x <= 0){
		if (y >= coly && y <= coly + colyline){
			dx *= (-1);
			colorChange();
		}
		else{
			game_over = true;
		}
	}
	if (y >= screenhight || y <= 0){
		if (x >= xline && x <= xline + linedx){
			dy *= (-1);
			colorChange();
		}
		else{
			game_over = true;
		}
	}
}

//
int main()
{
	//place your own initialization codes here.
	iSetTimer(1, change);
	//iSetTimer(1000, colorChange);
	iInitialize(screenwidth, screenhight, "youtube project");
	return 0;
}
