#include "tp1.h"

int Fimdejogo = 0;



typedef struct placar{
	char* nome;
	int pontuacao;
}Placar;

void gravaHighScore(char* nome, int pontuacao){
	FILE *highscore;
	Placar placar[10];
	int i, j, auxPont, menor, imenor;
	char auxNome[31];

	for(i = 0; i < 10; i++){//Sempre escreve os 10 melhores, se não haviam 10, preenche com "" e 0.
		strcpy(placar[i].nome, "");
		placar [i].pontuacao = 0;
	}

	i = 0;
	highscore = fopen("highscore.txt", "r");//Abre o arquivo para recuperar o highscore anterior e atualiza-lo.
	if(highscore != NULL){
		while(!feof(highscore)){
			fscanf(highscore, "%s", placar[i].nome);
			fscanf(highscore, "%d", &(placar[i].pontuacao));
			i++;
		}
		fclose(highscore);
	}


	menor = placar[0].pontuacao;
	imenor = 0;
	for(i = 0; i < 10; i++){//Percorre o highscore atual para ver se a nova pontuação é maior que a menor pontuacao para substitui-la
		if(menor > placar[i].pontuacao){
			menor = placar[i].pontuacao;
			imenor = i;
		}
	}

	if(pontuacao > placar[imenor].pontuacao){
		strcpy(placar[imenor].nome, nome);
		placar[imenor].pontuacao = pontuacao;
	}


	for(i = 0; i < 10; i++){//Ordena o placar da maior pra menor pontuacao.
		for(j = i+1; j < 10; j++){
			if(placar[j].pontuacao > placar[i].pontuacao){
				strcpy(auxNome, placar[j].nome);
				auxPont = placar[j].pontuacao;

				strcpy(placar[j].nome, placar[i].nome);
				placar[j].pontuacao = placar[i].pontuacao;

				strcpy(placar[i].nome, auxNome);
				placar[i].pontuacao = auxPont;
			}
		}
	}



	fopen("highscore.txt", "w");//Abre para reescrever o highscore atualizado.

	for(i = 0; i < 10; i++){
		fprintf(highscore, "%s %d\n", placar[i].nome, placar[i].pontuacao);
	}

	fclose(highscore);
}

void quadrado_central(){
	glColor3f(1,0.3,0.9);

	glBegin(GL_POLYGON);//Desenha o chão.
			glVertex2f(20,50);
			glVertex2f(50,50);
			glVertex2f(20,90);
			glVertex2f(50,90);
		glEnd();

		glutSwapBuffers();

}


void gameOver(){
	quadrado_central();
	Fimdejogo = 0;
	gravaHighScore("", 0);
}


void telaPausa(){

	quadrado_central();

}

void menuPrincipal(){

}
