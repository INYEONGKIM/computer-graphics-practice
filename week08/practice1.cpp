#include <iostream>
#include <GLUT/glut.h>
#include <OpenGL/gl.h>

int Width, Height;

void MyDisplay() {

    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f(0.0, 10.0, -30.0);
    glVertex3f(0.0, 0.0, -30.0);
    glVertex3f(10.0, 0.0, -30.0);
    glVertex3f(10.0, 10.0, -30.0);
    glEnd();
    
    glLoadIdentity();

    glFlush();
}

int main(int argc,char** argv) {
    glutInit(&argc, argv);
    Width = 500;
    Height = 500;
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(Width, Height);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("20191111");
    
//    glOrtho(0.0, 20.0, 0.0, 20.0, 10.0, 50.0);
    glOrtho(-10.0, 10.0, -10.0, 10.0, 10.0, 50.0);

    glutDisplayFunc(MyDisplay);

    glutMainLoop();

    return 0;
}
