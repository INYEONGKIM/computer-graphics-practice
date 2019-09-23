#include <iostream>
#include <GLUT/glut.h>
#include <OpenGL/gl.h>

GLint TopLeftX, TopLeftY, BottomRightX, BottomRightY;

void myDisplay(){
    glClear(GL_COLOR_BUFFER_BIT);
    
    glColor3f(1.0, 1.0, 1.0); // 면의 색(#ffffff, 흰색)
    glBegin(GL_POLYGON); // 입력 기본요소 정의(사각형)
    
    // 가시부피 (내 모니터 상에 보이는 부피), max=1.0
    glVertex3f(TopLeftX/300.0, (300-TopLeftY)/300.0, 0.0);
    glVertex3f(TopLeftX/300.0, (300-BottomRightY)/300.0, 0.0);
    glVertex3f(BottomRightX/300.0, (300-BottomRightY)/300.0, 0.0);
    glVertex3f(BottomRightX/300.0, (300-TopLeftY)/300.0, 0.0);
    
    glEnd();
    glFlush();
}

void myKeyboard(unsigned char keyPressed, int x, int y){
    switch (keyPressed) {
        case 'Q':
            exit(0);
        case 'q':
            exit(0);
        case 27:
            exit(0);
        default:
            break;
    }
}

void mySpecialKeyBoard(int key, int x, int y){
    switch (key) {
        case 1:
            printf("pressed F1\n");
            break;
        case 2:
            printf("pressed F2\n");
            break;
        case 3:
            printf("pressed F3\n");
            break;
        default:
            break;
    }
}

void myMouseClick(GLint button, GLint state, GLint x, GLint y){
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        TopLeftX = x;
        TopLeftY = y;
    }
}

void myMouseMove(GLint x, GLint y){
    BottomRightX = x;
    BottomRightY = y;
    glutPostRedisplay();
}

int main(int argc,char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(300, 300);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("OpenGL Sample Drawing"); // title
    
    // callback Function
    glutDisplayFunc(myDisplay); // Register GLUT callback func (display event)
    glutKeyboardFunc(myKeyboard); // exit by keyboard
    glutSpecialFunc(mySpecialKeyBoard);
    glutMouseFunc(myMouseClick);
    glutMotionFunc(myMouseMove);
    
    glutMainLoop();
    
    return 0;
}
