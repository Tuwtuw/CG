#include "tp1.h"

int PULO = 0;//Variável que controla o pulo.
float VELOCIDADE_OBSTACULOS = 0.75; //Velocidade inicial dos obstáculos, obtida empiricamente, alterada durante o jogo.
float VELPULO = 2.5;//Velocidade inicial do pulo, obtido empiricamente.

void jump(){
  if(PULO == 1){
    jogador.posicao.posY += VELPULO;
    VELPULO -= gravidade/100;
    if(jogador.posicao.posY < 15){
      jogador.posicao.posY = 15;//Faz uma leve correção, já que a velocidade de queda não resulta em uma parada exata
      VELPULO = 2.5;//Reseta a velocidade do pulo para permitir um novo pulo
      PULO = 0;//Encerra o pulo
    }
    glutPostRedisplay();
  }
}

void aumentoVelocidade(){
  if(VELOCIDADE_OBSTACULOS < VEL_MAX){
    if(DIFICULDADE == 1){
      if(jogador.pontuacao % 50 == 0 && jogador.pontuacao > 0){//A cada multiplo de 50, ou seja a cada 50 pontos, a dificuldade aumenta um pouco.
        VELOCIDADE_OBSTACULOS += 0.2;
      }
    }
    if(DIFICULDADE == 2){
      if(jogador.pontuacao % 50 == 0 && jogador.pontuacao > 0){
        VELOCIDADE_OBSTACULOS += 0.3;
      }
    }
    if(DIFICULDADE == 3){
      if(jogador.pontuacao % 50 == 0 && jogador.pontuacao > 0){
        VELOCIDADE_OBSTACULOS += 0.4;
      }
    }
  }
}

void obstacleMotion(){
  int i;
  for(i = 0; i < contObstaculo; i++){
    if(obstaculos[contObstaculo-1].posicao.posX > -30){//Para de mover em certo ponto para não estourar o int
        obstaculos[i].posicao.posX -= VELOCIDADE_OBSTACULOS;
    }
  }
}

void verificaColisao(Objeto obstaculo){
  int colisao = 0;
  if(jogador.posicao.posX - jogador.largura/2 < obstaculo.posicao.posX + obstaculo.largura/2 && jogador.posicao.posX + jogador.largura/2 > obstaculo.posicao.posX - obstaculo.largura/2
      && jogador.posicao.posY - jogador.altura/2 < obstaculo.posicao.posY + obstaculo.altura/2 && jogador.posicao.posY + jogador.altura/2 > obstaculo.posicao.posY - obstaculo.altura/2){
    colisao = 1;
  }

  if(colisao != 0){
    //gameOver();
  }
}
