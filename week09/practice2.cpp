#include <iostream>
#include <GLUT/glut.h>
#include <OpenGL/gl.h>

void MyLightInit(){
    GLfloat light_ambient[] = { 0.5, 0.4, 0.3, 1.0 };
    GLfloat light_diffuse[] = { 0.5, 0.4, 0.3, 1.0};
    GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0};
    
    GLfloat mat_ambient[] = { 0.3, 0.3, 0.3, 1.0 };
    GLfloat mat_specular[] = { 0.3, 0.3, 0.3, 1.0 };
    GLfloat mat_diffuse[] = { 0.0, 1.0, 0.0, 1.0};
    GLfloat mat_shininess[] = { 20.0};
    
    glShadeModel(GL_SMOOTH);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
}

void MyDisplay(){
//    GLfloat LightPosition[] = {0.0, 0.0, 2.0, 1.0};
    GLfloat LightPosition[] = {2.0, 2.0, 2.0, 1.0};
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    glLightfv(GL_LIGHT0, GL_POSITION, LightPosition);
    gluLookAt(0.5, 0.5, 0.5,
              0.0, 0.0, -1.0,
              0.0, 1.0, 0.0);
    glColor3f(1.0, 0.0, 0.0);
    
    glTranslatef(0.3, 0.3, 0.0);
    glutSolidTorus(0.3, 0.6, 800, 800);
    
    glFlush();
}

void MyReshape(int w, int h){
    glViewport(0, 0, (GLint) w, (GLint) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0);
}


int main(int argc,char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("20191118");
    
    MyLightInit();
    glutDisplayFunc(MyDisplay);
//    glutReshapeFunc(MyReshape);
    glutMainLoop();

    return 0;
}


