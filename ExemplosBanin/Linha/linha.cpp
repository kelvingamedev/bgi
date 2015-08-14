#include <iostream>
#include <graphics.h>
using namespace std;

int main()
{
	initwindow(400, 300); //abre uma janela gráfica de 400X300 pixels
	moveto(10,10); //posiciona cursor na posição (10,10)
	lineto( 200, 50); //desenha uma linha de (10,10) até (200,50)
	while(!kbhit()); // espera até alguma tecla se pressiona
	closegraph(); // fecha janela gráfica
return 0;
}	
