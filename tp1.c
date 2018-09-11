#include "tp1.h"

Boneco jogador;
int DIFICULDADE = 3;

void desenhaPersonagem(Centro posicao, float largura, float altura){
  glBegin(GL_POLYGON);
  glVertex2f(posicao.posX - largura/2,posicao.posY - altura/2);
  glVertex2f(posicao.posX + largura/2, posicao.posY - altura/2);
  glVertex2f(posicao.posX + largura/2, posicao.posY + altura/2);
  glVertex2f(posicao.posX - largura/2,posicao.posY + altura/2);
  glEnd();
}

void desenhaChao(){
  glBegin(GL_POLYGON);//Desenha o chão.
  glVertex2f(0,0);
  glVertex2f(140,0);
  glVertex2f(140,10);
  glVertex2f(0,10);
  glEnd();
}

void desenhaObstaculo(Centro posicao, float largura, float altura){
  glBegin(GL_POLYGON);
  glVertex2f(posicao.posX - largura/2,posicao.posY - altura/2);
  glVertex2f(posicao.posX + largura/2, posicao.posY - altura/2);
  glVertex2f(posicao.posX + largura/2, posicao.posY + altura/2);
  glVertex2f(posicao.posX - largura/2,posicao.posY + altura/2);
  glEnd();
}

void desenhaPlacar(){
  int i = 0;
  char *string = "Pontuacao:";
  //sprintf (string,"%d", jogador.pontuacao); Tamanho da string deve ser alocado antes.
  glRasterPos3f(20, 20, 0);
  for (i = 0; i < strlen(string); i++) {
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, string[i]);
  }
}


void desenhaCena(void){
  int i;
  glClear(GL_COLOR_BUFFER_BIT);

  glColor3f(0,0,1);
  //desenhaPlacar();
  desenhaChao();
  glColor3f(1,1,1);
  desenhaPersonagem(jogador.posicao, jogador.largura, jogador.altura);
  for(i = 0; i < contObstaculo; i++){
    desenhaObstaculo(obstaculos[i].posicao, obstaculos[i].largura, obstaculos[i].altura);
  }

  glutSwapBuffers();
}


void pause(){

}

void reset(){
  jogador.pontuacao = 0;
  VELOCIDADE_OBSTACULOS = 2;
}


void atualiza(int parametro){
  //verificaColisao(); ARRUMAR ESSE CARAI
  if(Fimdejogo != 0){
    jump();
    obstacleMotion();
    aumentoVelocidade();
    glutPostRedisplay ();
  }else{
    //tela fim de jogo
  }

  glutTimerFunc(7, atualiza, 0);//Atualiza a aproximadamente 144fps

}

//glutTimerFunc(25, atualizaCena, 0);, 25 é milisegundo, atualiza é a função sendo chamada e 0 é o parâmetr passado

void inicializa(void){
  glClearColor(0.196078, 0.6, 0.8, 0);

  glutTimerFunc(5000, item, 0);//Após 5 segundos do início, começa a checar de 5 em 5 segundos se um item vai ser gerado.
  obstaculo();
  pontuacao();
  jogador.posicao.posX = 13;
  jogador.posicao.posY = 15;
  jogador.largura= 14;
  jogador.altura = 10;
  jogador.pontuacao = 0;
}




void redimensiona(int w, int h){
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0, 140, 0, 70, -1, 1);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}


void teclado(unsigned char key, int x, int y){
  switch(key)
  {
    case 27://esc
    exit(0);
    break;
    case 32://espaço
    PULO = 1;
    break;
    case 'p':

    if(pause_ativo == 0) pause_ativo = 1;
    else pause_ativo = 0;

    break;
    case'r':
    reset();
    break;
    default:
    break;
  }
}


int main(int argc, char **argv){

  glutInit(&argc, argv);

  glEnable(GL_TEXTURE_2D);
  glutInitContextVersion(1, 1);
  glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
  glutInitWindowSize(400, 400);
  glutInitWindowPosition(100, 100);

  glutCreateWindow("Dino Run");

  glutDisplayFunc(desenhaCena);
  glutReshapeFunc(redimensiona);
  glutKeyboardFunc(teclado);
  inicializa();
  glutTimerFunc(0, atualiza, 0);

  glutMainLoop();
  return 0;
}
