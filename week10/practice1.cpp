#include <iostream>
#include <GLUT/glut.h>
#include <OpenGL/gl.h>

void MyLightInit(){
    GLfloat global_ambient[] = { 0.1, 0.1, 0.1, 1.0 };
    
    GLfloat light0_ambient[] = { 0.5, 0.4, 0.3, 1.0 };
    GLfloat light0_diffuse[] = { 0.5, 0.4, 0.3, 1.0};
    GLfloat light0_specular[] = { 1.0, 1.0, 1.0, 1.0};
    
    GLfloat light1_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat light1_diffuse[] = { 0.5, 0.2, 0.3, 1.0};
    GLfloat light1_specular[] = { 0.0, 0.0, 0.0, 1.0};
    
    GLfloat mat_ambient[] = { 0.3, 0.3, 0.3, 1.0 };
    GLfloat mat_specular[] = { 0.8, 0.8, 0.8, 1.0 };
    GLfloat mat_diffuse[] = { 0.0, 0.0, 1.0, 1.0};
    GLfloat mat_shininess[] = { 25.0};
    
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light0_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light0_specular);
    
    glEnable(GL_LIGHT1);
    glLightfv(GL_LIGHT1, GL_AMBIENT, light1_ambient);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse);
    glLightfv(GL_LIGHT1, GL_SPECULAR, light1_specular);
    
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);
    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
}

void MyDisplay(){
    GLfloat LightPosition0[] = {0.0, 0.0, 2.0, 1.0};
    
    GLfloat LightPosition1[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat LightDirection1[] = {-0.5, -1.0, -1.0};
    GLfloat SpotAngel1[] = {20.0};
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    gluLookAt(0.5, 0.5, 0.5,
              0.0, 0.0, -1.0,
              0.0, 1.0, 0.0);
    glTranslatef(0.3, 0.3, 0.0);
    
    glLightfv(GL_LIGHT1, GL_POSITION, LightPosition1);
    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, LightDirection1);
    glLightfv(GL_LIGHT1, GL_SPOT_CUTOFF, SpotAngel1);
    glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 1.0);
    
    glutSolidTorus(0.3, 0.6, 800, 800);
    
    glFlush();
}

void MyReshape(int w, int h){
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
}

int main(int argc,char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(0, 0);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
    glutCreateWindow("20191125");
    
    MyLightInit();
    glutDisplayFunc(MyDisplay);
    glutReshapeFunc(MyReshape);
    glutMainLoop();
    
    return 0;
}

