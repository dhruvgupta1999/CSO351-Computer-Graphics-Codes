#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int x1, yy1, r;
void setPixel(GLint x, GLint y){
  glBegin(GL_POINTS);
  glVertex2i(x,y);
  glEnd();
}
void draw(int x1,int yy1,int xi,int yi)
{
    setPixel(x1+xi,yy1+yi);
    setPixel(x1+xi,yy1-yi);
    setPixel(x1-xi,yy1+yi);
    setPixel(x1-xi,yy1-yi);
    setPixel(x1+yi,yy1+xi);
    setPixel(x1+yi,yy1-xi);
    setPixel(x1-yi,yy1+xi);
    setPixel(x1-yi,yy1-xi);
}
void circle(int x1, int yy1, int r){
  int xi=0,yi=r,d=5/4-r;
  while(xi<=yi)
  {
      draw(x1,yy1,xi,yi);
      xi++;
      if(d<0)
        d+=2*xi+1;
      else
      {
          yi--;
          d+=2*(xi-yi)+1;
      }
  }
}

void draw(){
  glClear(GL_COLOR_BUFFER_BIT);
  circle(x1,yy1,r);
  glFlush();
}

void init(){  
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);

  glutInitWindowPosition(0,0);
  glutInitWindowSize(500,500);
  glutCreateWindow("Digital Differential Analyzer");

  glClearColor(0.0,0.0,0.0,0);
  glColor3f(1.0,1.0,1.0);
  gluOrtho2D(0,500,0,500);
}

int main(int argc, char **argv){
  scanf("%d%d%d", &x1, &yy1, &r);

  glutInit(&argc, argv);
  init();
  glutDisplayFunc(draw);
  glutMainLoop();
  return 0;
}

/*
Compile using :
g++ DDA.cpp -lGL -lGLU -lglut
*/