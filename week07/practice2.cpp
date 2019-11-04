#include <iostream>
#include <GLUT/glut.h>
#include <OpenGL/gl.h>

int Width, Height;

void MyDisplay() {

    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
// 투상방식 선택
//    glOrtho(-5.0, 5.0, -5.0, 5.0, 0.0, 10.0);
//    gluPerspective(50, Width/Height, 3.0, 50.0);
    glFrustum(-2.0, 2.0, -2.0, 2.0, 0.5, 10.0);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
#if 0
// Teapot
    gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glColor3f(0.0, 0.0, 1.0);
    glScaled(3.0, 3.0, 3.0);
    glutWireTeapot(1.0);
#endif

#if 1
    gluLookAt(0.0, 3.0, 3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f(2.0, 0.0, 2.0);
    glVertex3f(2.0, 0.0, -2.0);
    glVertex3f(-2.0, 0.0, -2.0);
    glVertex3f(-2.0, 0.0, 2.0);
    glEnd();
#endif
    
    
    glFlush();
}

void MyReshape(int w, int h) {
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
