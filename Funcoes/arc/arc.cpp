

#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>
using namespace std;

int main(){
	/*Requere autodetec��o */
	int gdriver = DETECT, gmode, errorcode;
	int midx, midy;
	
	// �ngulo inciial e final
	int stangle = 45, endangle = 135;
	
	// Raio da circunfer�ncia
	int radius = 100;
	
	/*Inicializa gr�ficos e vari�veis locais*/
	initgraph(&gdriver, &gmode, "");
	
	/*L� o resultado da inicializa��o*/
	errorcode = graphresult();
	
	// Se tiver ocorrido um erro (diferente de grOk)
	if (errorcode != grOk){
		
		cout << "Erro nos gr�ficos" << grapherrormsg(errorcode);
		
		// Espere o usu�rio digitar algo para sair do programa 
		cout << "Pressione qualquer tecla para sair:";
		getch();
		exit(1);
	}
	
	/*Busque as coordenadas centrais da tela*/
	midx = getmaxx() / 2;
	midy = getmaxy() / 2;
	
	/*Configura a cor de desenho a apartir da cor m�xima para os gr�ficos atuais*/
	setcolor(getmaxcolor());
	
	// Desenhe o arco
	arc(midx,midy,stangle,endangle, radius);
	
	// Espere um input e ent�o limpe os gr�ficos e saia
	getch();
	closegraph();
	return 0;
	
}


