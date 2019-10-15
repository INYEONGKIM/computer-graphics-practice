// Matrix Stack

#include <iostream>
#include <GLUT/glut.h>
#include <OpenGL/gl.h>

void myDisplay(){
    glClear(GL_COLOR_BUFFER_BIT);
    glViewport(0, 0, 300, 300);
    glColor3f(1.0, 0.0, 0.0);
    glMatrixMode(GL_MODELVIEW);
    
    glLoadIdentity();
    glRotatef(45.0, 1.0, 1.0, 1.0);
    glutSolidCube(0.5); //애를 그릴꺼
    
    glPushMatrix();
    
    glTranslatef(0.6, 1.0, 1.0);
    glutSolidCube(0.3); //애도 그릴꺼
    
//    glPopMatrix();
//    glutSolidCube(0.3);
    
    glFlush();
}

int main(int argc,char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA);
    glutInitWindowSize(300, 300);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("week05");

    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    
    glutDisplayFunc(myDisplay);
    glutMainLoop();

    return 0;
}
