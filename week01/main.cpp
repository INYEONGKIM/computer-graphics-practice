#include <iostream>
#include <GLUT/glut.h>

void Draw(){
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

int main(int argc,char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("OpenGL");
    glutDisplayFunc(Draw);
    glutMainLoop();
    return 0;
}

