#include <iostream>
#include <GLUT/glut.h>
#include <OpenGL/gl.h>

void myDisplay(){
    glClear(GL_COLOR_BUFFER_BIT);
    
    glColor3f(1.0, 1.0, 0.0);
    glLineWidth(2.5);

#if 1
    // pack man
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0.5, 0.2, 0.0);
    glVertex3f(0.2, 0.5, 0.0);
    glVertex3f(-0.2, 0.5, 0.0);
    glVertex3f(-0.5, 0.2, 0.0);
    glVertex3f(-0.5, -0.2, 0.0);
    glEnd();
    
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0.2, 0.5, 0.0);
    glVertex3f(-0.2, -0.5, 0.0);
    glVertex3f(0.2, -0.5, 0.0);
    glVertex3f(0.5, -0.2, 0.0);
    glVertex3f(0.5, 0.2, 0.0);
    glEnd();
#endif
    
    
#if 0
    // arrow
    glBegin(GL_TRIANGLES);
    glVertex3f(0.5, 0.2, 0.0);
    glVertex3f(-0.7, 0.7, 0.0);
    glVertex3f(-0.5, 0.2, 0.0);
    
    glVertex3f(-0.5, -0.2, 0.0);
    glVertex3f(-0.7, -0.7, 0.0);
    glVertex3f(0.5, -0.2, 0.0);
    glEnd();
#endif
    
#if 0
    glBegin(GL_QUADS);
    glVertex3f(0.7, 0.7, 0.0);
    glVertex3f(-0.7, 0.7, 0.0);
    glVertex3f(-0.5, 0.2, 0.0);
    glVertex3f(0.5, 0.2, 0.0);
    
    glVertex3f(-0.5, -0.2, 0.0);
    glVertex3f(-0.7, -0.7, 0.0);
    glVertex3f(0.7, -0.7, 0.0);
    glVertex3f(0.5, -0.2, 0.0);
    glEnd();
#endif

    glFlush();
}

int main(int argc,char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("week04");
    
    glutDisplayFunc(myDisplay);
    glutMainLoop();

    return 0;
}
