#include <iostream>
#include <GLUT/glut.h>
#include <OpenGL/gl.h>

void MyDisplay(){

    glShadeModel(GL_SMOOTH); // GL_SMOOTH : 구로셰이딩(기본) , GL_FLAT : 플랫셰이딩
    
    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(-0.5, -0.5, 0.0);
    
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(0.5, -0.5, 0.0);
    
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(0.0, 0.5, 0.0);
    glEnd();
    
    glFlush();
}

int main(int argc,char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("20191118");
    glutDisplayFunc(MyDisplay);

    glutMainLoop();

    return 0;
}


