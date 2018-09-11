#include "tp1.h"

//VARIAVEIS GLOBAIS
int contObstaculo = 0, contPowerup = 0;
int pause_ativo = 1;
Objeto *obstaculos;
Objeto *powerup;


//FUNCOES
void obstaculo(){
  int chance = (rand()%125) + 1;//Gera um número de 1 a 100, pra checar qual tipo de obstáculo vai gerar.
  if(DIFICULDADE == 1){//Dependendo da dificuldade, inimigos voadores vem mais cedo e itens de suporte são mais raros.
    if(jogador.pontuacao > 1000){//Valor arbitrário para começar a aparecer obstáculos voadores.
      if(chance >= 110){
        geraObstaculo(14,7,1);//Alterar para voador.
      }
    }
    else{
      if(chance <= 50){
        geraObstaculo(10,5,0);
      }
      else if(chance >= 51 && chance <= 84){
        geraObstaculo(14,7,0);
      }
      else if(chance >= 85 && chance < 110){
        geraObstaculo(20, 10, 0);
      }
    }
  }


  if(DIFICULDADE == 2){
    if(jogador.pontuacao > 700){//Valor arbitrário para começar a aparecer obstáculos voadores.
      if(chance >= 100){
        geraObstaculo(14,7,1);
      }
    }
    else{
      if(chance <= 35){
        geraObstaculo(10,5,0);
      }
      else if(chance >= 36 && chance <= 70){
        geraObstaculo(14,7,0);
      }
      else if(chance >= 71 && chance < 100){
        geraObstaculo(20, 10,0);
      }
    }
  }


  if(DIFICULDADE == 3){
    if(jogador.pontuacao > 450){//Valor arbitrário para começar a aparecer obstáculos voadores.
      if(chance >= 90){
        geraObstaculo(14,7,1);
      }
    }
      if(chance <= 20){
        geraObstaculo(10,5,0);
      }
      else if(chance >= 21 && chance <= 59){
        geraObstaculo(14,7,0);
      }
      else if(chance >= 60 && chance < 90){
        geraObstaculo(20, 10,0);
      }
  }
  int tempoRandomico = 0;
  while(tempoRandomico < 900){//Gera obstaculos em um tempo randomico maior que 0.9 segundos.
    tempoRandomico = rand()%2000;
  }
  glutTimerFunc(tempoRandomico, obstaculo, 0);
}

void item(){
  int chance = (rand() % 100) + 1;//Chance de gerar um item de suporte ao jogador.
  if(DIFICULDADE == 1){
    if(chance >= 60){

    }
  }
  if(DIFICULDADE == 2){
    if(chance >= 75){

    }
  }
  if(DIFICULDADE == 1){
    if(chance >= 85){

    }
  }
  glutTimerFunc(3000, item, 0);
}

void geraObstaculo(float largura, float altura, int voador){//O parametro voador recebe 1 ou 0 para definir se o obstáculo é voador ou não
  contObstaculo++;
  obstaculos = realloc(obstaculos, contObstaculo*sizeof(Objeto));
  if(voador == 0){
    obstaculos[contObstaculo-1].posicao.posY = (altura/2)+10;
    obstaculos[contObstaculo-1].posicao.posX = 200;//Objeto vai ser gerado fora da tela.
    obstaculos[contObstaculo-1].largura = largura;
    obstaculos[contObstaculo-1].altura = altura;
  }
  else{
    obstaculos[contObstaculo-1].posicao.posY = (altura/2)+25;
    obstaculos[contObstaculo-1].posicao.posX = 200;//Objeto vai ser gerado fora da tela.
    obstaculos[contObstaculo-1].largura = largura;
    obstaculos[contObstaculo-1].altura = altura;
  }

}

void pontuacao(){
  if(pause_ativo != 0){
    jogador.pontuacao++;
    glutTimerFunc(100, pontuacao, 0);
  }
}
