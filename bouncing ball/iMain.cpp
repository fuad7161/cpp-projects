/*
Author: Fuadul Hasan(fuadul202@gmail.com)
BSMRSTU,Gopalganj
*/
#include <iostream>
# include "iGraphics.h"
using namespace std;

#define screenwidth 1000
#define screenhight 600

int score = 0;
int time1 = 0;
int level = 1;

int mposx, mposy;
bool tt = 1;
int x = 0;
int y = 0;
int xline = 0;
int yline = 0;
int linedx = 150;
int linedy = 5;

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
	if (game_over) {
		iText(screenwidth/2 - 10, screenhight/2, "Game over", GLUT_BITMAP_TIMES_ROMAN_24);
		iText2(screenwidth / 2 - 10, (screenhight / 2) - 45, "Score : "+to_string(score), GLUT_BITMAP_TIMES_ROMAN_24);
		iText2(screenwidth / 2 - 10, (screenhight / 2) - 65, "Time : "+to_string(time1), GLUT_BITMAP_TIMES_ROMAN_24);
		iText2(screenwidth / 2 - 10, (screenhight / 2) - 85, "Level : " + to_string(level), GLUT_BITMAP_TIMES_ROMAN_24);
		//iText(300, 260, "If you want to play this game again press Inter", GLUT_BITMAP_TIMES_ROMAN_24);
		return;
	}

	//ractangles row....
	iRectangle(xline, yline, linedx, linedy);
	iRectangle(0, 0 + screenhight, screenwidth, 0);
	iFilledRectangle(xline, yline, linedx, linedy);
	//iFilledRectangle(0, 0 + screenhight - 10, 200, 10);
	string str = to_string(score);
	string str2 = to_string(time1);
	string str3 = to_string(level);
	iFilledCircle(x, y, 5, 1000);
	iText2(10, screenhight - 15, "Score : "+str, GLUT_BITMAP_9_BY_15);
	iText2(10, screenhight - 30, "Timer : "+str2, GLUT_BITMAP_9_BY_15);
	iText2(10, screenhight - 45, "level : " + str3, GLUT_BITMAP_9_BY_15);
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
	if (game_over) {
		return;
	}
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
	if (game_over) {
		return;
	}
	if (key == GLUT_KEY_LEFT){
		if (xline - 20 >= 0) xline -= 20;
	}
	else if (key == GLUT_KEY_RIGHT){
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
	if (game_over) {
		return;
	}
	x += dx;
	y += dy;
	score++;
	if (x >= screenwidth || x <= 0){
		dx *= (-1);
	}
	if (y >= screenhight){
		dy *= (-1);
	}
	if (y == 0){
		if (x >= xline && x <= xline + linedx){
			dy *= (-1);
			dx+= tt^1;
			dy+= tt^1;
			tt ^= 1;
			if (tt)level++;
			colorChange();
		}
		else{
			game_over = true;
		}
	}
}

void change1(){
	if (game_over) {
		return;
	}
	time1++;
}

//
int main()
{
	//place your own initialization codes here.
	iSetTimer(1, change);
	//iSetTimer(1000, colorChange);
	iSetTimer(1000, change1);
	iInitialize(screenwidth, screenhight,"Ball Ball Ball");
	if (game_over) {
		return 0;
	}
	return 0;
}
