#include <stdlib.h>
#include <graphics.h>
#include <math.h>
#define COLOR(r,g,b) (r|(g<<8)|(b<<16)|15<<24)
#define X(x)(600*(x-xmin)/(xmax-xmin)+25)
#define Y(y)(310-310*(y-ymin)/(ymax-ymin)+25)
#define F(x)(sin(x))
#define F2(x)(0)

//перебрать X для функций, Y дан в задании


int main() {
	float x = 0, ymin = -1, ymax = 1, y = 0;
	float xmax = 3.14, xmin = 0;
	
	// рисуем координатную плоскость
	initwindow(640,360); // открыть графическое окно 640 на 360 пикселей 
	setcolor(GREEN); //цвет линий зелёный
	moveto(320, 0); // курсор в точку (320,0)
	lineto(320, 360); // ось Y
	moveto(0, 180); // курсор в точку (0, 180)
	lineto(640,180); // ось X
 	
 	// находим и рисуем график
 	setcolor(MAGENTA); // цвет линий фиолетовый
 	x = xmin;
 	y = F(x);
 	moveto(X(x),Y(y));
 	

	for(x = xmin; x <= xmax; x += 0.001){
		y = F(x);
		lineto(X(x),Y(y));
	}
	

	for(x = xmin; x <= xmax; x += 0.001){
		y = F2(x);
		lineto(X(x),Y(y));
	}
	
	setfillstyle(7,5);
	floodfill(310,170,5);
	setcolor(GREEN); //цвет линий зелёный
	moveto(320, 0); // курсор в точку (320,0)
	lineto(320, 360); // ось Y
	
	outtextxy ( 15, 30, "FUNCTION  f(x)=sin(x)" );
	outtextxy ( 15, 200, "FUNCTION  f(x)=sin(x)" );
	setcolor(LIGHTCYAN);
	outtextxy ( 250, 320, "curved trapezoid" );
	
	getch();            
	closegraph(); // закрываем графическое окно
 
 return 0;
}
