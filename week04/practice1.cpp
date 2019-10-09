#include <iostream>
#include <GLUT/glut.h>
#include <OpenGL/gl.h>

void myDisplay(){
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    
    glBegin(GL_POLYGON);
    
    //    glColor3f(<#GLfloat red#>, <#GLfloat green#>, <#GLfloat blue#>) : 특정 점의 색을 바꾸는 함수
    // 얘가 아래에서 또 다시 호출을 하지 않는 이상 점의 색은 고정 박힘
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(-0.5, -0.5, 0.0);
    
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(0.5, 0.5, 0.0);
    
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(-0.5, 0.5, 0.0);
    
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(0.5, -0.5, 0.0);
    
    glEnd();
    glFlush();
}

int main(int argc,char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("week04");
    
    glutDisplayFunc(myDisplay);
    glutMainLoop();

    return 0;
}
