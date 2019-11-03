#include <iostream>
#include <GLUT/glut.h>
#include <OpenGL/gl.h>

GLint TopLeftX, TopLeftY, BottomRightX, BottomRightY;
GLboolean RED=false, GREEN=false, BLUE=false;

void MyDisplay(){
    
    // RED
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f(1.0, 1.0, 0.0);
    glVertex3f(0.8, 1.0, 0.0);
    glVertex3f(0.8, 0.8, 0.0);
    glVertex3f(1.0, 0.8, 0.0);
    glEnd();

    //GREEN
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f(1.0, 0.8, 0.0);
    glVertex3f(0.8, 0.8, 0.0);
    glVertex3f(0.8, 0.6, 0.0);
    glVertex3f(1.0, 0.6, 0.0);
    glEnd();
    
    //BLUE
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex3f(0.8, 0.6, 0.0);
    glVertex3f(1.0, 0.6, 0.0);
    glVertex3f(1.0, 0.4, 0.0);
    glVertex3f(0.8, 0.4, 0.0);
    glEnd();
    
    glFlush();
}

void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y){
    
    if(Button==GLUT_LEFT_BUTTON && State==GLUT_DOWN){
        if (X>450 && X<500){
            // RED
            if (Y>0 && Y<50){
                RED = true;
                GREEN = false;
                BLUE = false;
            }
            // GREEN
            else if(Y>50 && Y<100){
                RED = false;
                GREEN = true;
                BLUE = false;
            }
            //BLUE
            else if(Y>100 && Y<150){
                RED = false;
                GREEN = false;
                BLUE = true;
            }
        }
        TopLeftX = X;
        TopLeftY = Y;
    }
}

void MyMouseMove(GLint X, GLint Y){
    // Scaling
    if(X-BottomRightX>70 || X-BottomRightX<-70){
        BottomRightX=X;
    }
    if(Y-BottomRightY>70 || Y-BottomRightY<-70){
        BottomRightY=Y;
    }
    
    
    if(RED){
        glColor3f(1.0, 0.0, 0.0);
    }else if(GREEN){
        glColor3f(0.0, 1.0, 0.0);
    }else if(BLUE){
        glColor3f(0.0, 0.0, 1.0);
    }else{
        glColor3f(0.0, 0.0, 0.0);
    }
    
    // Draw Line
    glBegin(GL_LINES);
    glVertex3f((BottomRightX-250)/250.0, (500-BottomRightY-250)/250.0, 0.0);
    glVertex3f((X-250)/250.0, (500-Y-250)/250.0, 0.0);
    glEnd();
    
    BottomRightX = X;
    BottomRightY = Y;
    
    glutPostRedisplay();
}

int main(int argc,char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("2016015878_SW_INYEONGKIM_Homework_1");
    
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    
    // Callback
    glutDisplayFunc(MyDisplay);
    glutMouseFunc(MyMouseClick);
    glutMotionFunc(MyMouseMove);
    
    glutMainLoop();

    return 0;
}
