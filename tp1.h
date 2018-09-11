#include <SOIL/SOIL.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>


#define VEL_MAX 5//Velocidade máxima dos obstáculos
#define PULO_MAX 60 //Altura máxima do pulo
#define gravidade 9.81 //Tempo em milisegundos em que devemos chamar a funcao para obter um tickrate de 128;
#define FPS 7 //Tempo de chamada do glutTimerFunc para obter aproximadamente 144 fps

//Definição das Structs usadas.
/* 	************************************************** */
typedef struct centro{
  float posX;
  float posY;
}Centro;

typedef struct boneco {
    Centro posicao;   // posição do centro
    float largura, altura;  // dimensões
    int pontuacao;
    int identificadorTextura;
}Boneco;

typedef struct objeto {
  Centro posicao;
  float largura, altura;
  int identificadorTextura;
}Objeto;

/* 	************************************************** */

//Prototypes dos outros arquivos
//Keyboard
void teclado(unsigned char key, int x, int y);
//Desenhos
void desenhaChao();
void desenhaObstaculo(Centro posicao, float largura, float altura);
void desenhaPersonagem(Centro posicao, float largura, float altura);
void jump();
void pontuacao();
void item();
void obstaculo();
void verificaColisao(Objeto obstaculo);
void obstacleMotion();
void aumentoVelocidade();
void gameOver();
void geraObstaculo(float largura, float altura, int voador);

//Variáveis globais
//Main
extern Boneco jogador;
extern Objeto *obstaculos;
extern Objeto *powerup;
extern int contObstaculo;
extern int contPowerup;
//itens
extern int pause_ativo;

//Fisica
extern int ESTADO;
extern int PULO;
extern float VELOCIDADE_OBSTACULOS;
extern int DIFICULDADE;
//-------------------------
