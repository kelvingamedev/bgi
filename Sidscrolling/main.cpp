#include <iostream>
#include <graphics.h>
#include <conio.h>

// Define que esses nomes representam esses valores
#define LEFT   	75
#define RIGHT  	77
#define UP     	72
#define DOWN   	80
#define ESC    	27

using namespace std;

void getImagemPersonagem(void *imagem);

int main(){
	
	// Coordenadas do personagem
	int personagemX = 0;
	const int PERSONAGEM_Y = 0;
	
	// Velocidade constante do personagem
	const int VELOCIDADE = 10;
	
	// Detecta e inicia o modo gr�fico
	int driver, mode;
	detectgraph(&driver, &mode);
	initgraph(&driver,&mode,"");
	
	// Imagem do perosonagem
	void *imagem;
	getImagemPersonagem(&imagem);
	
	/*
	const int LARGURA_IMAGEM = 400;
	const int ALTURA_IMAGEM = 200;
	
	// Coordenadas do personagem
	int personagemX = 0;
	const int PERSONAGEM_Y = 0;
	
	// Velocidade constante do personagem
	const int VELOCIDADE = 10;

	// L� arquivo de imagem
	readimagefile("desenho.gif",0,0,LARGURA_IMAGEM,ALTURA_IMAGEM);
	
	// Calcula o espa�o necess�rio para armazenar a imagem em bytes
	int tamanho = imagesize(0,0,LARGURA_IMAGEM,ALTURA_IMAGEM);
	
	// Configura o tamanho da vari�vel de controle da imagem
	void *imagem = malloc(tamanho); 
	
	// Copia uma imagem da tela para mem�ria
	getimage(0,0,LARGURA_IMAGEM,ALTURA_IMAGEM,imagem);*/

	// Receber� o input do jogador
	int tecla = 0;
	
	// Coordenadas do circulo e raio (fixo)
	int circuloX = 50;
	int circuloY = 0;
	const int RAIO = 50;
	
	// Coloque uma cor para pintar o c�rculo (dentro do loop)
	setcolor(YELLOW);
	
	
	
	// Enquanto o jogador n�o apertar ESC (Game Loop)
	while (tecla != ESC){
		
		// Velocidade do personagem nos eixos
		int deslocamentoX = 0; 
		
		// Limpe a tela com a cor de fundo e move o CP para (0,0)
		cleardevice();
				
		// Atualize a imagem
		putimage(personagemX,PERSONAGEM_Y,imagem,0);
		
		// Imprima um texto qualquer
		moveto(int(getmaxx() * 0.5), int(getmaxy() * 0.8) ); // Pos da mensagem
		outtext("Ol�");
		
		// Coloque o circulo na tela
		circle(circuloX,circuloY,RAIO);
		
		// Limpe o buffer para usar o getch
		fflush(stdin);
		
		// Receba o input do jogador
		tecla = getch();
		
		// Caso o jogador pressione alguma seta do teclado, incremente a velocidade
		if(tecla == RIGHT){
			deslocamentoX = VELOCIDADE;
		} else if(tecla == LEFT){
			deslocamentoX = - VELOCIDADE;
		}
		
		// Desloque personagem no eixo X
		personagemX += deslocamentoX;
		
		// Aguarde alguns instantes antes de verificar tudo novamente
		delay(10);
		
	}
	
	
	

	
	// Feche os gr�ficos e encerre o programa
	closegraph();
	return 0;
}

void getImagemPersonagem(void *imagem){
	
	// Dimens�es da imagem do personagem
	const int LARGURA_IMAGEM = 400;
	const int ALTURA_IMAGEM = 200;

	// L� arquivo de imagem
	readimagefile("desenho.gif",0,0,LARGURA_IMAGEM,ALTURA_IMAGEM);
	
	// Calcula o espa�o necess�rio para armazenar a imagem em bytes
	int tamanho = imagesize(0,0,LARGURA_IMAGEM,ALTURA_IMAGEM);
	
	// Configura o tamanho da vari�vel de controle da imagem
	imagem = malloc(tamanho); 
	
	// Copia uma imagem da tela para a mem�ria
	getimage(0,0,LARGURA_IMAGEM,ALTURA_IMAGEM,*imagem);
	
}
