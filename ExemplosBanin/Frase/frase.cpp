#include<iostream>
#include<graphics.h>
using namespace std;
int main() {
	int driver, mode;
	int xmax, ymax;
	detectgraph(&driver, &mode);
	initgraph(&driver, &mode, "");
	xmax = getmaxx(); // getmaxx() fornece a largura da tela
	ymax= getmaxy(); // getmaxy() fornece a altura da tela
	cout << "Tamanho da tela grafica = " ; //exibe na tela do DOS
	cout << xmax << " de largura por ";
	cout << ymax << " de altura \n";
	setcolor(YELLOW); // cor de desenho ou escrita é amarela
	outtextxy(xmax/3, 10, " -----------Aqui é a tela gráfica !!! ---------");
	// exibe em amarelo na tela gráfica
	setcolor(LIGHTBLUE); // cor de desenho ou escrita é azul claro
	circle( 200, 150, 70);
	setcolor(LIGHTGREEN); // cor de desenho ou escrita é verde claro
	circle(400, 150, 70);
	//system("pause");
	getch();
	closegraph(); // fecha modo gráfico
}
