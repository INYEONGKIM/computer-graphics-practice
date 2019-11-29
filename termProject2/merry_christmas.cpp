#include <iostream>
#include <GLUT/glut.h>
#include <OpenGL/gl.h>

GLboolean RED = false;
GLboolean GREEN = false;
GLboolean BLUE = false;

void makeTree(){
    // TODO :)
}

void makeSignOnBlueBox(){
    glPushMatrix();
    glLoadIdentity();
    
    // set self Light
    GLfloat mat_diffuse[] = { 1.0, 0.0, 0.0, 1.0};
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0};
    GLfloat mat_ambient[] = { 1.0, 0.0, 0.0, 1.0};
    GLfloat mat_shininess[] = { 15.0 };
    
    GLfloat light_specular[] = { 1.0, 1.0, 0.0, 1.0};
    GLfloat light_diffuse[] = { 1.0, 1.0, 0.0, 1.0};
    GLfloat light_ambient[] = { 1.0, 1.0, 0.0, 1.0};
    GLfloat light_position[] = { -3, 6, -10.0, 0.0}; // x, y, z, w
    
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    
    glRotatef(45, -1.0, 0.0, 0.0);
    glRotatef(28, 0.0, 1.0, 0.0);
    glTranslatef(0.5, 0.15, -0.35);
    
    glutSolidSphere(0.05, 10, 8);
    
    // postcondition, Turn off the ligth
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
    
    glPopMatrix();
}

void makeBlueBox(){
    glPushMatrix();
    glLoadIdentity();
    
    GLfloat mat_diffuse[] = { 1.0, 0.0, 0.0, 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_ambient[] = { 1.0, 0.0, 0.0, 1.0 };
    GLfloat mat_shininess[] = { 15.0 };
    
    GLfloat light_specular[] = { 0.02, 0.47, 0.75, 1.0 };
    GLfloat light_diffuse[] = { 0.02, 0.47, 0.75, 1.0 };
    GLfloat light_ambient[] = { 0.02, 0.47, 0.75, 1.0 };
    GLfloat light_position[] = { -3, 6, -10.0, 0.0 }; // x, y, z, w
    
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    
    glRotatef(45, -1.0, 0.0, 0.0);
    glRotatef(28, 0.0, 1.0, 0.0);
    glTranslatef(0.5, 0.0, -0.35);
    
    glutSolidCube(0.20);
    
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
    
    glPopMatrix();
    
    if (BLUE) makeSignOnBlueBox();
}

void makeSignOnGreenBox(){
    glPushMatrix();
    glLoadIdentity();
    
    // set self Light
    GLfloat mat_diffuse[] = { 1.0, 0.0, 0.0, 1.0};
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0};
    GLfloat mat_ambient[] = { 1.0, 0.0, 0.0, 1.0};
    GLfloat mat_shininess[] = { 15.0 };
    
    GLfloat light_specular[] = { 1.0, 1.0, 0.0, 1.0};
    GLfloat light_diffuse[] = { 1.0, 1.0, 0.0, 1.0};
    GLfloat light_ambient[] = { 1.0, 1.0, 0.0, 1.0};
    GLfloat light_position[] = { -3, 6, -10.0, 0.0}; // x, y, z, w
    
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    
    glRotatef(45, -1.0, 0.0, 0.0);
    glRotatef(28, 0.0, 1.0, 0.0);
    glTranslatef(0.5, 0.15, -0.65);
    
    glutSolidSphere(0.05, 10, 8);
    
    // postcondition, Turn off the ligth
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
    
    glPopMatrix();
}

void makeGreenBox(){
    glPushMatrix();
    glLoadIdentity();

    GLfloat mat_diffuse[] = { 1.0, 0.0, 0.0, 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_ambient[] = { 1.0, 0.0, 0.0, 1.0 };
    GLfloat mat_shininess[] = { 15.0 };
    
    GLfloat light_specular[] = { 0.0, 1.0, 0.0, 1.0 };
    GLfloat light_diffuse[] = { 0.0, 1.0, 0.0, 1.0 };
    GLfloat light_ambient[] = { 0.0, 1.0, 0.0, 1.0 };
    GLfloat light_position[] = { -3, 6, -10.0, 0.0 }; // x, y, z, w
    
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    
    glRotatef(45, -1.0, 0.0, 0.0);
    glRotatef(28, 0.0, 1.0, 0.0);
    glTranslatef(0.5, 0.0, -0.65);
    
    glutSolidCube(0.20);
    
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
    
    glPopMatrix();
    
    if (GREEN) makeSignOnGreenBox();
}

void makeSignOnRedBox(){
    glPushMatrix();
    glLoadIdentity();
    
    // set self Light
    GLfloat mat_diffuse[] = { 1.0, 0.0, 0.0, 1.0};
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0};
    GLfloat mat_ambient[] = { 1.0, 0.0, 0.0, 1.0};
    GLfloat mat_shininess[] = { 15.0 };
    
    GLfloat light_specular[] = { 1.0, 1.0, 0.0, 1.0};
    GLfloat light_diffuse[] = { 1.0, 1.0, 0.0, 1.0};
    GLfloat light_ambient[] = { 1.0, 1.0, 0.0, 1.0};
    GLfloat light_position[] = { -3, 6, -10.0, 0.0}; // x, y, z, w
    
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    
    glRotatef(45, -1.0, 0.0, 0.0);
    glRotatef(28, 0.0, 1.0, 0.0);
    glTranslatef(0.2, 0.15, -0.65);
    
    glutSolidSphere(0.05, 10, 8);
    
    // postcondition, Turn off the ligth
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);

    glPopMatrix();
}

void makeRedBox(){
    glPushMatrix();
    glLoadIdentity();

    // set self Light
    GLfloat mat_diffuse[] = { 1.0, 0.0, 0.0, 1.0};
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0};
    GLfloat mat_ambient[] = { 1.0, 0.0, 0.0, 1.0};
    GLfloat mat_shininess[] = { 15.0 };
    
    GLfloat light_specular[] = { 1.0, 0.0, 0.0, 1.0};
    GLfloat light_diffuse[] = { 1.0, 0.0, 0.0, 1.0};
    GLfloat light_ambient[] = { 1.0, 0.0, 0.0, 1.0};
    GLfloat light_position[] = { -3, 6, -10.0, 0.0}; // x, y, z, w
    
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    
    glRotatef(45, -1.0, 0.0, 0.0);
    glRotatef(28, 0.0, 1.0, 0.0);
    glTranslatef(0.2, 0.0, -0.65);
    
    glutSolidCube(0.20);
    
    // postcondition, Turn off the ligth
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);

    glPopMatrix();
    
    if(RED) makeSignOnRedBox();
}

void myDisplay(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    // make Boxes
    makeRedBox();
    makeGreenBox();
    makeBlueBox();

    // make Tree
    makeTree();


    glFlush();
}

void MyKeyboard(unsigned char key, int x, int y){
    switch (key) {
        case 'R':
        case 'r':
        RED = !RED;
        break;
        
        case 'G':
        case 'g':
        GREEN = !GREEN;
        break;
        
        case 'B':
        case 'b':
        BLUE = !BLUE;
        break;
    
        default:
        break;
    }
    glutPostRedisplay();
}

int main(int argc,char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Merry Christmas :)");
    glClearColor(0.4, 0.4, 0.4, 0.0);

    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

    glutDisplayFunc(myDisplay);
    glutKeyboardFunc(MyKeyboard);

    glutMainLoop();

    return 0;
}
