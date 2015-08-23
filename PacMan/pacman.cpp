

#include <iostream>
#include <graphics.h>
#include <conio.h>

/*Correspond�ncia entre o retorno n�merico do getch e as teclas*/
#define LEFT   	75
#define RIGHT  	77
#define UP     	72
#define DOWN   	80
#define ESC    	27

enum Orientacao{CIMA,BAIXO,DIREITA,ESQUERDA};

using namespace std;

void PacMan(int posX, int posY, Orientacao orienta ){

		
		// Comprimento da linha da diagonal do PACMAN
		const int LIN_TAM = 35;
		
		// Raio da circunfer�ncia Pacman
		const int RAIO = 50;
		
		// Angulo inicial e final da circunfer�ncia Pacman
		
		int angInicial = 0;
		int angFinal = 0;
		
		// Orienta��o das linhas diagonais
		int linhaDiag1[2]; 
		int linhaDiag2[2]; /// linhaDiag[0] � o x | linhaDiag[1] � o y
		
		
		
		// Verifica a orienta��o e define o angulo do PacMan a partir dela
		if (orienta == DIREITA){
			
			 angInicial = 45;
			 angFinal = 315;
			 linhaDiag1[0] = LIN_TAM;
			 linhaDiag1[1] = LIN_TAM;
			 linhaDiag2[0] = LIN_TAM;
			 linhaDiag2[1] = -LIN_TAM;
			
		} else if(orienta == ESQUERDA){
			 angInicial = 225;
			 angFinal = 135;
			 linhaDiag1[0] =  -LIN_TAM;
			 linhaDiag1[1] = -LIN_TAM;
			 linhaDiag2[0] = -LIN_TAM;
			 linhaDiag2[1] = LIN_TAM;

		} else if(orienta == CIMA){
			angInicial = 135;
			angFinal = 45;
			linhaDiag1[0] = LIN_TAM;
			linhaDiag1[1] = -LIN_TAM;
			linhaDiag2[0] = -LIN_TAM;
			linhaDiag2[1] = -LIN_TAM;	
			
		}
		else if(orienta == BAIXO){
			angInicial = 315;
			angFinal = 225;
			linhaDiag1[0] = -LIN_TAM;
			linhaDiag1[1] = LIN_TAM;
			linhaDiag2[0] = LIN_TAM;
			linhaDiag2[1] = LIN_TAM;
		}
		
		
		
	
		// Desenha um arco com seguinte config. :
		arc(posX, posY, angInicial, angFinal, RAIO);
		
		//Moivmenta as coordenadas para o centro da circunfer�ncia
		moveto(posX, posY);
		
		// Desenha a linha diagonal do pacman
		linerel(linhaDiag1[0],linhaDiag1[1]);
		
		//Moivmenta as coordenadas para o centro da circunfer�ncia
		moveto(posX, posY);
		
		// Desenha a outra diagonal do pacman
		linerel(linhaDiag2[0],linhaDiag2[1]);
	
}

int main(){
		
	// Recebe dados de configura��o da tela
	int driver, mode;
	
	// Define valores para a orienta��o do PacMan
	Orientacao meOrienta = DIREITA;
	
	// Recebe o input do teclado
	int tecla;
	
	// Velocidade do PacMan
	const int SPEED = 10;
	
	// Detecta o adapatador de gr�ficos do sistema e escolhe o modo que provem
	// a maior resolu��o para o adaptador
	detectgraph(&driver,&mode);
	
	// Inicaliza os gr�ficos do sistema atrav�s do carregamento
	// do driver gr�fico do disco e colcando o sistema no modo gr�fico
	initgraph(&driver,&mode,"");
	
	// Calcula o centro da tela
	const int MID_X = getmaxx() / 2;
	const int MID_Y = getmaxy() / 2;
	
	// Posi��o do pacman
	int posX = MID_X;
	int posY = MID_Y;

	
	// Recebe o input do usu�rio
	do{
		
		// Indica se houve acr�scimo ou n�o na posi��o do PacMan
		int updateX = 0, updateY = 0;
		
		// Configura o cor para apagar os gr�ficos (� igual ao fundo da tela)
		setcolor(BLACK);
		
		// Limpa a �ltima posi��o onde o PacMan esteve
		PacMan(posX,posY, meOrienta);
		
		// Limpa a tela
		setfillstyle(1, BLACK);
			
		// Limpa o buffer para usar o getch
		fflush(stdin);	
		
	
		
		// Altere a posi��o de desenho conforme o input do usu�rio
		
		if(tecla == RIGHT){
			meOrienta = DIREITA;
			updateX += SPEED;
		}
		else if(tecla == LEFT){
			meOrienta = ESQUERDA;
			updateX -= SPEED;
		}
		else if(tecla == UP){
			meOrienta = CIMA;
			updateY -= SPEED;
		}
		else if(tecla == DOWN){
			meOrienta = BAIXO;
			updateY += SPEED;
		}
			
		
		posX += updateX;
		posY += updateY;
		
		// Configura a pintura interna da circunfer�ncia
		setcolor(YELLOW);
		
		// Mostra o PacMan
		PacMan(posX, posY, meOrienta);
			
		// Verifica o pressionamento de teclas
		tecla = getch();
		
		// Espera um tempo at� a pr�xima atualiza��o
		delay(10);
		
		
	}while(tecla != ESC);
	
	// Fecha o sistema de gr�ficos
	closegraph();	
	

	return 0;
}


