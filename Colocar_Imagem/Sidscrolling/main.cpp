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

int main(){
	
	// Detecta e inicia o modo gráfico
	int driver, mode;
	detectgraph(&driver, &mode);
	initgraph(&driver,&mode,"");
	
	const int LARGURA_IMAGEM = 400;
	const int ALTURA_IMAGEM = 200;
	
	// Coordenadas do personagem
	int personagemX = 0;
	const int PERSONAGEM_Y = 0;
	
	// Velocidade constante do personagem
	const int VELOCIDADE = 10;

	// Lê arquivo de imagem
	readimagefile("desenho.gif",0,0,LARGURA_IMAGEM,ALTURA_IMAGEM);
	
	// Calcula o espaço necessário para armazenar a imagem em bytes
	int tamanho = imagesize(0,0,LARGURA_IMAGEM,ALTURA_IMAGEM);
	
	// Configura o tamanho da variável de controle da imagem
	void *imagem = malloc(tamanho); 
	
	// Copia uma imagem da tela para memória
	getimage(0,0,LARGURA_IMAGEM,ALTURA_IMAGEM,imagem);

	// Receberá o input do jogador
	int tecla = 0;
	
	// Aguarda o input do usuário
	getch();
	
	// Enquanto o jogador não apertar ESC (Game Loop)
	while (tecla != ESC){
		
		// Velocidade do personagem nos eixos
		int deslocamentoX = 0; 
		
		// Limpe a tela com a cor de fundo e move o CP para (0,0)
		cleardevice();
				
		// Atualize a imagem
		putimage(personagemX,PERSONAGEM_Y,imagem,0);
		
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
	
	
	

	
	// Feche os gráficos e encerre o programa
	closegraph();
	return 0;
}
