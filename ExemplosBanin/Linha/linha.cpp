#include <iostream>
#include <graphics.h>
using namespace std;

int main()
{
	initwindow(400, 300); //abre uma janela gr�fica de 400X300 pixels
	moveto(10,10); //posiciona cursor na posi��o (10,10)
	lineto( 200, 50); //desenha uma linha de (10,10) at� (200,50)
	while(!kbhit()); // espera at� alguma tecla se pressiona
	closegraph(); // fecha janela gr�fica
return 0;
}	
