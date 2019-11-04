#include <iostream>
#include <GLUT/glut.h>
#include <OpenGL/gl.h>

int Width, Height;

void MyDisplay(){

    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-5.0, 5.0, -5.0, 5.0, 0.0, 10.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
//    gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
//    gluLookAt(0.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    
    
// Teapot
#if 0
    // 시점 변환 후 scale, transport 등 추가하기
    gluLookAt(1.0, 2.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glColor3f(0.0, 0.0, 1.0);
    glScalef(2.0, 2.0, 2.0);
    glutWireTeapot(1.0);
#endif
    
#if 0
    gluLookAt(0.0, 5.0, 3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f(2.0, 0.0, 2.0);
    glVertex3f(2.0, 0.0, -2.0);
    glVertex3f(-2.0, 0.0, -2.0);
    glVertex3f(-2.0, 0.0, 2.0);
    glEnd();
#endif
    
// X-Z plain
#if 1
    gluLookAt(1.0, 2.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glColor3f(0.0, 1.0, 1.0);
    glScalef(2.0, 2.0, 2.0);
    glBegin(GL_POLYGON);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, 1.0);
    glVertex3f(1.0, 0.0, 1.0);
    glVertex3f(1.0, 0.0, 0.0);
    glEnd();
#endif
    

// Cube
#if 0
    glColor3f(1.0, 0.0, 0.0);
    glutSolidCube(1.5);
#endif

    glFlush();
}

void MyReshape(int w, int h){
    Width = w;
    Height = h;
}

int main(int argc,char** argv) {
    glutInit(&argc, argv);
    Width = 500;
    Height = 500;
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(Width, Height);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("20191104");


    glutDisplayFunc(MyDisplay);
    glutReshapeFunc(MyReshape);

    glutMainLoop();

    return 0;
}
