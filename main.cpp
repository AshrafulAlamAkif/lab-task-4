#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>
#include <math.h>

void init(void)
{
  glClearColor(0.0,0.0,0.0,0.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0.0, 500.0, 0.0, 500.0, -1.0, 500.0);
}


void Draw()
{
       int aa=380, bb=190, cc=570, dd=342;

       glClear(GL_COLOR_BUFFER_BIT);
       glColor3f(0.2,0.2,0.5);

       int dy=dd-bb;
       int dx=cc-aa;
       int diff1=2*dy-2*dx;
       int p0=2*dy-dx;
       int p=p0;
       int x=aa, y=bb;

       glBegin(GL_POINTS);
       glVertex2d(x,y);
       while(1){
        if(p>=0){
            x++;
            y++;
            p=p+diff1;
        }
        else{
            x++;
            p=p+2*dy;
        }
        glVertex2d(x,y);
        if(x==cc && y==dd)
            break;
       }
       glEnd();
       glFlush();
       glutSwapBuffers();
}

int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode ( GLUT_RGB | GLUT_DOUBLE );
    glutInitWindowPosition(0,0);
    glutInitWindowSize(600,600);
    glutCreateWindow("Lab Task(182-15-2225)");
    init();
    glutDisplayFunc(Draw);
    glutMainLoop();
    return 0;
}
