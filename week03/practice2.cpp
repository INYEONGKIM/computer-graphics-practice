#include <iostream>
#include <GLUT/glut.h>
#include <OpenGL/gl.h>

GLfloat Delta = 0.0;
GLfloat vel = 0.01;

void myDisplay(){
    glClear(GL_COLOR_BUFFER_BIT);
    
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.5, 0.8); // 이 색으로 칠할꺼
    
    // 아래 같은 색의 4개의 점이 만드는 면을 채울꺼 (서로 다르면 그라데이션으로 찍힐꺼)
    // 이 순서대로 점을 찍는게 아니라 오른손 좌표계(시계 반대 방향)로 프로세서가 알아서 순서를 지정함
    // 정면일 경우는 시계 반대방향으로 돌아간다는걸 생각;;
    glVertex3f(-1.0 + Delta, -0.5, 0.0); //x값만 계속 변화하고 있음 (좌우로 왔다갔다)
    glVertex3f(0.0 + Delta, -0.5, 0.0);
    glVertex3f(0.0 + Delta, 0.5, 0.0);
    glVertex3f(-1.0 + Delta, 0.5, 0.0);
    
    glEnd();
    glutSwapBuffers();
}

void myTimer(int value){
    Delta += vel;
    
    // 오른쪽으로 가고 있고 Delta가 1을 넘어서면 반대방향으로 움직이기
    if((Delta > 1 && vel>0) || (Delta<0 && vel<0)){
        vel *= -1; //방향을 변경
    }
    glutPostRedisplay();
    glutTimerFunc(40, myTimer, 1); // 2번 타이머 : 단 한 번만 타이머 이벤트를 발생시키는 것을 방지하기 위함
    
}

void MyIdle(){
    Delta += 0.001; // 값이 커질수록 느려짐 (값을 1000으로 나눠야하기 때문에 상대적으로 느려짐)
    glutPostRedisplay();
}

int main(int argc,char** argv) {
    glutInit(&argc, argv);
    
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE); // 얘 추가됨
    
    glutInitWindowSize(300, 300);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("OpenGL Examlple Drawing"); // title
    
    
    glClearColor(1.0, 1.0, 1.0, 1.0);
    
    // 이 아래 3개가 한 쌍
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    glutDisplayFunc(myDisplay); // 실행을 하고나면 항상 다른 콜백함수보다는 얘가 먼저 호출됨 ㅇㅇ
    
    
    // 둘 중에 하나만 주석 풀기
    glutTimerFunc(1, myTimer, 1); // 얼마만큼 시간을 지연시킬 것인가, callback, val
    //    glutIdleFunc(MyIdle); //idle func 추가
    
    glutMainLoop();
    
    return 0;
}

// 시험문제 : 특정 함수의 역할, display 함수 정도는 직접 손으로 짜야함 ㅇㅇ
//          특정 output이 되도록 코드의 빈칸 뚫어놓고 채워야 함
