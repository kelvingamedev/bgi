#include <stdio.h>
#include <graphics.h>

int main(){
	int i, j, left, top, bottom, right;
	
	// Inicializa a janela gr�fica com o tamanho inserido
	initwindow(700,500);
	
	// Coordenadas de destino (esquerda e em cima)
	// e coordenadas de destino (direita e em baixo)
	left = 10; right = 600; top = 10; bottom = 200;
	for (i = top; i <= bottom; i++)
	for (j = left; j <= right; j++)
	
		// Colque um pixel da cor magneta
		putpixel (j, i, MAGENTA);
		
	// Espere o usu�rio apertar uma tecla
	getch ( );
	
	// Feche a janela gr�fica
	closegraph ( );
}
