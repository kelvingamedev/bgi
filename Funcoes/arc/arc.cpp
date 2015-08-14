

#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>
using namespace std;

int main(){
	/*Requere autodetecção */
	int gdriver = DETECT, gmode, errorcode;
	int midx, midy;
	
	// Ângulo inciial e final
	int stangle = 45, endangle = 135;
	
	// Raio da circunferência
	int radius = 100;
	
	/*Inicializa gráficos e variáveis locais*/
	initgraph(&gdriver, &gmode, "");
	
	/*Lê o resultado da inicialização*/
	errorcode = graphresult();
	
	// Se tiver ocorrido um erro (diferente de grOk)
	if (errorcode != grOk){
		
		cout << "Erro nos gráficos" << grapherrormsg(errorcode);
		
		// Espere o usuário digitar algo para sair do programa 
		cout << "Pressione qualquer tecla para sair:";
		getch();
		exit(1);
	}
	
	/*Busque as coordenadas centrais da tela*/
	midx = getmaxx() / 2;
	midy = getmaxy() / 2;
	
	/*Configura a cor de desenho a apartir da cor máxima para os gráficos atuais*/
	setcolor(getmaxcolor());
	
	// Desenhe o arco
	arc(midx,midy,stangle,endangle, radius);
	
	// Espere um input e então limpe os gráficos e saia
	getch();
	closegraph();
	return 0;
	
}


