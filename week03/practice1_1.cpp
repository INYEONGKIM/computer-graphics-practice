#include <iostream>
#include <GLUT/glut.h>
#include <OpenGL/gl.h>

GLboolean isSphere = true;

void myDisplay(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.5, 0.0, 0.5); // 약간 보라색으로 칠할꺼 ㅇㅇ, 앞으로 변경하지 않는한 이 색으로 고정 갈꺼(위의 코드)
    
    
    /*
     gl : 더 디테일 하게 사용자가 입력해주어야함(선의 개수, 간격, 원의 개수 등등)
     glut : gl보다는 적은 수 만큼의 인수를 받아 그림(비교적 단순, 그러나 디테일하게는 변경 불가)
     */
    if (isSphere){
        //        glutWireSphere(<#GLdouble radius#>, <#GLint slices#>, <#GLint stacks#>)
        glutWireSphere(0.2, 15, 15);
    }
    else{
        //        glutWireTorus(<#GLdouble innerRadius#>, <#GLdouble outerRadius#>, <#GLint sides#>, <#GLint rings#>)
        glutWireTorus(0.1, 0.3, 40, 20);
    }
    
    glFlush();
}

void MyMainMenu(int entryId){
    if(entryId==1){
        isSphere = true;
    }
    else if (entryId == 2){
        isSphere = false;
    }
    else{
        exit(0);
    }
    glutPostRedisplay();
}


int main(int argc,char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(300, 300);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("OpenGL Examlple Drawing"); // title
    
    
    glClearColor(1.0, 1.0, 1.0, 1.0);
    
    // 이 아래 3개가 한 쌍
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    
    
    
    glutCreateMenu(MyMainMenu);
    glutAttachMenu(GLUT_RIGHT_BUTTON); //우클릭 했을 때 메뉴를 작동시키기 위함
    glutAddMenuEntry("Draw Sphere", 1);
    glutAddMenuEntry("Draw Torus", 2);
    glutAddMenuEntry("Exit", 3);
    glutDisplayFunc(myDisplay); // 실행을 하고나면 항상 다른 콜백함수보다는 얘가 먼저 호출됨 ㅇㅇ
    
    
    glutMainLoop();
    
    return 0;
}
