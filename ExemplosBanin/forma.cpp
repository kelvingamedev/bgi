#include<graphics.h>

int main()
{
	int driver, mode; // variaveis usadas para modo gr�fico
	int xmax, ymax; // vari�veis a serem usadas ao longo do programa
	detectgraph(&driver, &mode); // Obt�m o driver gr�fico
	initgraph(&driver, &mode, ""); // inicializa modo gr�fico
	rectangle(50, 50, 150, 150); //desenha ret�ngulo cujo canto superior esquerdo est� em (50, 50) e canto inferior direito em (150, 150)
	circle(300, 100, 50); // desenha circulo de raio 50 e centro em	(300, 100)
	line(450, 50, 600, 150); //desenha uma linha de (450,50) at� (600,150)
	//system("pause")
	getch();
}
