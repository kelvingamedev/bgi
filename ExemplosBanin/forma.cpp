#include<graphics.h>

int main()
{
	int driver, mode; // variaveis usadas para modo gráfico
	int xmax, ymax; // variáveis a serem usadas ao longo do programa
	detectgraph(&driver, &mode); // Obtém o driver gráfico
	initgraph(&driver, &mode, ""); // inicializa modo gráfico
	rectangle(50, 50, 150, 150); //desenha retângulo cujo canto superior esquerdo está em (50, 50) e canto inferior direito em (150, 150)
	circle(300, 100, 50); // desenha circulo de raio 50 e centro em	(300, 100)
	line(450, 50, 600, 150); //desenha uma linha de (450,50) até (600,150)
	//system("pause")
	getch();
}
