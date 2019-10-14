// OpenGL Pipeline Vertex Array P21

#include <iostream>
#include <GLUT/glut.h>
#include <OpenGL/gl.h>

GLfloat MyVertices[8][3] = {
    {-0.25, -0.25, 0.25}, {-0.25, 0.25, 0.25}, {0.25, 0.25, 0.25}, {0.25, -0.25, 0.25},
    {-0.25, -0.25, -0.25}, {-0.25, 0.25, -0.25}, {0.25, 0.25, -0.25}, {0.25, -0.25, -0.25}
};

GLfloat MyColors[8][3] = {
    {1.0, 1.0, 1.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 1.0}, {1.0, 0.0, 0.0},
    {0.0, 0.0, 1.0}, {1.0, 0.0, 1.0}, {1.0, 1.0, 1.0}, {0.0, 1.0, 0.0},
};

GLubyte MyVertexList[24] = {0, 1, 5, 4, 0, 3, 2, 1, 2, 3, 7, 6, 0, 4, 7, 3, 1, 2, 6, 5, 4, 5, 6, 7};

void myDisplay(){
    glFrontFace(GL_CCW); // 정면일때 반시계 방향으로 하겠다(cw의 경우 반대)
    glEnable(GL_CULL_FACE); // 내부를 안보이게 하는 속성
    glEnableClientState(GL_COLOR_ARRAY);
    glEnableClientState(GL_VERTEX_ARRAY);
    glColorPointer(3, GL_FLOAT, 0, MyColors);
    glVertexPointer(3, GL_FLOAT, 0, MyVertices);
    glMatrixMode(GL_MODELVIEW); // 정점의 위치 기준으로 통일 시키는 목적(상대거리좌표)
    glLoadIdentity(); // 단위행렬을 불러오는 역할 -> 모델을 변환하기 위해 필요(회전, 위치이동, 모양이동 등)
    glRotatef(270.0, 1.0, 1.0, 1.0); // x,y,z축 모두로 270씩 회전하라, 0을 넣으면 그 축으로는 회전하지 않음
    for(GLint i=0; i<6; i++){
        glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, &MyVertexList[4*i]);
    }
    glFlush();
}

int main(int argc,char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(300, 300);
    glutInitWindowPosition(0, 0);
    
    glutCreateWindow("week04");
    
    glutDisplayFunc(myDisplay);
    glutMainLoop();

    return 0;
}

