#include <iostream>
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <math.h>

GLboolean RED = false;
GLboolean GREEN = false;
GLboolean BLUE = false;

#define GL_PI 3.1415f

void drawTreeStar(GLfloat x, GLfloat z){
    glPushMatrix();
    glLoadIdentity();
    
    GLfloat mat_diffuse[] = { 0.0, 1.0, 0.0, 1.0 };
    GLfloat mat_specular[] = { 0.0, 1.0, 0.0, 1.0 };
    GLfloat mat_ambient[] = { 0.0, 1.0, 0.0, 1.0 };
    GLfloat mat_shininess[] = { 10.0 };
    
    GLfloat light_specular[] = { 1.0, 1.0, 0.0, 1.0 };
    GLfloat light_diffuse[] = { 1.0, 1.0, 0.0, 1.0 };
    GLfloat light_ambient[] = { 1.0, 1.0, 0.0, 1.0 };
    GLfloat light_position[] = { 10.0, 0.0, 5.0, 0.0};
    
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    
    glTranslatef(0.0, 0.0, -0.9);
    glRotatef(35, 0.0, 1.0, 0.0);
    glTranslatef(-0.168, 0.75, 0.0);
    
    GLfloat toAngle = GL_PI/180;
    GLfloat y = x*cos(36*toAngle)/2.909;
    int zSign[] = { 1, -1 };
    
    for(int i=0; i<2; i++){
        glBegin(GL_POLYGON);
        glNormal3f(0.0f, 0.0f, 1.0f);
        glVertex3f(x/2, -(y*tan(54*toAngle))/(2*cos(54*toAngle)), z*zSign[i]); // 1, 5, 8, 11, 15, 16, 21, 22, 27, 28
        glVertex3f(x/2, x*(sin(72*toAngle)-sin(36*toAngle)), 0.0); // 2, 30
        glVertex3f((x-y)/2, 0.0, 0.0); // 3, 6
        glEnd();
        
        glBegin(GL_POLYGON);
        glNormal3f(0.0f, 0.0f, 1.0f);
        glVertex3f(0.0, 0.0, 0.0); // 4, 7
        glVertex3f(x/2, -(y*tan(54*toAngle))/(2*cos(54*toAngle)), z*zSign[i]); // 5
        glVertex3f((x-y)/2, 0.0, 0.0); // 6
        glEnd();
        
        glBegin(GL_POLYGON);
        glNormal3f(0.0f, 0.0f, 1.0f);
        glVertex3f(0.0, 0.0, 0.0); // 7
        glVertex3f(x/2, -(y*tan(54*toAngle))/(2*cos(54*toAngle)), z*zSign[i]); // 8
        glVertex3f((x-y)*sin(36*toAngle)/2, -cos(36*toAngle)*(x-y)/2, 0.0); // 9, 10
        glEnd();
        
        glBegin(GL_POLYGON);
        glNormal3f(0.0f, 0.0f, 1.0f);
        glVertex3f((x-y)*sin(36*toAngle)/2, -cos(36*toAngle)*(x-y)/2, 0.0); // 10
        glVertex3f(x/2, -(y*tan(54*toAngle))/(2*cos(54*toAngle)), z*zSign[i]); // 11
        glVertex3f(x*(1-cos(36*toAngle)), -x*sin(36*toAngle), 0.0); // 12
        glEnd();
        
        glBegin(GL_POLYGON);
        glNormal3f(0.0f, 0.0f, 1.0f);
        glVertex3f(x*(1-cos(36*toAngle)), -x*sin(36*toAngle), 0.0); // 13
        glVertex3f(x/2, ((x-y)*cos(36*toAngle)/2)-x*sin(36*toAngle), 0.0); // 14, 17
        glVertex3f(x/2, -(y*tan(54*toAngle))/(2*cos(54*toAngle)), z*zSign[i]); // 15
        glEnd();
        
        glBegin(GL_POLYGON);
        glNormal3f(0.0f, 0.0f, 1.0f);
        glVertex3f(x/2, -(y*tan(54*toAngle))/(2*cos(54*toAngle)), z*zSign[i]); // 16
        glVertex3f(x/2, ((x-y)*cos(36*toAngle)/2)-x*sin(36*toAngle), 0.0); // 17
        glVertex3f(x*cos(36*toAngle), -x*sin(36*toAngle), 0.0); // 18, 19
        glEnd();
        
        glBegin(GL_POLYGON);
        glNormal3f(0.0f, 0.0f, 1.0f);
        glVertex3f(x*cos(36*toAngle), -x*sin(36*toAngle), 0.0); // 19
        glVertex3f(x-((x-y)*sin(36*toAngle)/2), -cos(36*toAngle)*(x-y)/2, 0.0); // 20, 23
        glVertex3f(x/2, -(y*tan(54*toAngle))/(2*cos(54*toAngle)), z*zSign[i]); // 21
        glEnd();
        
        glBegin(GL_POLYGON);
        glNormal3f(0.0f, 0.0f, 1.0f);
        glVertex3f(x/2, -(y*tan(54*toAngle))/(2*cos(54*toAngle)), z*zSign[i]); // 22
        glVertex3f(x-((x-y)*sin(36*toAngle)/2), -cos(36*toAngle)*(x-y)/2, 0.0); // 23
        glVertex3f(x, 0.0, 0.0); // 24, 25
        glEnd();
        
        glBegin(GL_POLYGON);
        glNormal3f(0.0f, 0.0f, 1.0f);
        glVertex3f(x, 0.0, 0.0); // 25
        glVertex3f((x+y)/2, 0.0, 0.0); // 26, 29
        glVertex3f(x/2, -(y*tan(54*toAngle))/(2*cos(54*toAngle)), z*zSign[i]); // 27
        glEnd();
        
        glBegin(GL_POLYGON);
        glNormal3f(0.0f, 0.0f, 1.0f);
        glVertex3f(x/2, -(y*tan(54*toAngle))/(2*cos(54*toAngle)), z*zSign[i]); // 28
        glVertex3f((x+y)/2, 0.0, 0.0); // 29
        glVertex3f(x/2, x*(sin(72*toAngle)-sin(36*toAngle)), 0.0); // 30
        glEnd();
    }
    
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
    
    glPopMatrix();
}

void drawTreeTrunk(GLfloat centerx, GLfloat centery, GLfloat centerz, GLfloat radius, GLfloat h){
    glPushMatrix();
    glLoadIdentity();

    GLfloat mat_diffuse[] = { 0.0, 1.0, 0.0, 1.0 };
    GLfloat mat_specular[] = { 0.0, 1.0, 0.0, 1.0 };
    GLfloat mat_ambient[] = { 0.0, 1.0, 0.0, 1.0 };
    GLfloat mat_shininess[] = { 15.0 };
    
    GLfloat light_specular[] = { 0.238, 0.168, 0.121, 1.0 };
    GLfloat light_diffuse[] = { 0.238, 0.168, 0.121, 1.0 };
    GLfloat light_ambient[] = { 0.238, 0.168, 0.121, 1.0 };
    GLfloat light_position[] = { -10, 20, -25.0, 0.0};
    
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    
    GLfloat x, y, angle;
    
    glRotatef(25, -1.0, 0.0, 0.0);
    glRotatef(45, 1.0, 0.0, 0.0);
    glRotatef(80, -2.5, 0.0, 1.0);
    glRotatef(90, 1.0, 0.0, 1.0);
    glRotatef(90, 0.0, 1.0, 0.0);
    
    glBegin(GL_TRIANGLE_FAN);
    glNormal3f(0.0f, 0.0f, -1.0f);
    glVertex3f(centerx, centery, centerz);
    
    for(angle = 0.0f; angle < (2.0f*GL_PI); angle += (GL_PI/8.0f)){
        x = centerx + radius*sin(angle);
        y = centery + radius*cos(angle);
        glNormal3f(0.0f, 0.0f, -1.0f);
        glVertex3f(x, y, centerz);
    }
    glEnd();
    
    glBegin(GL_QUAD_STRIP);
    for(angle = 0.0f; angle < (2.0f*GL_PI); angle += (GL_PI/8.0f)){
        x = centerx + radius*sin(angle);
        y = centery + radius*cos(angle);
        glNormal3f(sin(angle), cos(angle), 0.0f);
        glVertex3f(x, y, centerz);
        glVertex3f(x, y, centerz + h);
    }
    glEnd();
    
    glBegin(GL_TRIANGLE_FAN);
    glNormal3f(0.0f, 0.0f, 1.0f);
    glVertex3f(centerx, centery, centerz + h);
    for(angle = (2.0f*GL_PI); angle > 0.0f; angle -= (GL_PI/8.0f)){
        x = centerx + radius*sin(angle);
        y = centery + radius*cos(angle);
        glNormal3f(0.0f, 0.0f, 1.0f);
        glVertex3f(x, y, centerz + h);
    }
    glEnd();
    
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
    glPopMatrix();
}

void drawLeaf(){
    glPushMatrix();
    glLoadIdentity();
    
    GLfloat mat_diffuse[] = { 0.0, 1.0, 0.0, 1.0 };
    GLfloat mat_specular[] = { 0.0, 1.0, 0.0, 1.0 };
    GLfloat mat_ambient[] = { 0.0, 1.0, 0.0, 1.0 };
    GLfloat mat_shininess[] = { 15.0 };
    
    GLfloat light_specular[] = { 0.156, 0.293, 0.113, 1.0 };
    GLfloat light_diffuse[] = { 0.156, 0.293, 0.113, 1.0 };
    GLfloat light_ambient[] = { 0.156, 0.293, 0.113, 1.0 };
    GLfloat light_position[] = { -10, 20, -25.0, 0.0};
    
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);

    // 2nd Leaf
    glTranslated(0.0, 0.05, 0.2);
    glRotatef(10, 0.0, 1.0, 0.0);
    glRotatef(90, -1.0, 0.0, 0.0);
    glRotatef(30, 1.0, -1.0, 1.0);
    glRotatef(45, -1.0, 0.0, 0.0);
    glRotatef(28, 0.0, 1.0, 0.0);
    glutSolidCone(0.35, 0.5, 20, 8);
    glPushMatrix();
    
    // Top Level
    glTranslated(0.0, 0.0, 0.2);
    glutSolidCone(0.32, 0.5, 20, 8);
    
    // Bottom
    glPopMatrix();
    glTranslated(0.0, 0.0, -0.2);
    glutSolidCone(0.37, 0.5, 20, 8);
    
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
    
    glPopMatrix();
}

void makeRedDecoration(){
    glPushMatrix();
    glLoadIdentity();
    
    GLfloat mat_diffuse[] = { 1.0, 0.0, 0.0, 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_ambient[] = { 1.0, 0.0, 0.0, 1.0 };
    GLfloat mat_shininess[] = { 15.0 };
    
    GLfloat light_specular[] = { 1.0, 0.0, 0.0, 1.0 };
    GLfloat light_diffuse[] = { 1.0, 0.0, 0.0, 1.0 };
    GLfloat light_ambient[] = { 1.0, 0.0, 0.0, 1.0 };
    GLfloat light_position[] = { -10, 20, -25.0, 0.0};
    
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    
    glPushMatrix();
    
    // draw Left ball
    glTranslatef(0.0, 0.0, -0.3);
    glRotatef(45, 0.0, -1.0, 0.0);
    glTranslatef(0.0, 0.0, 0.45);
    glutSolidSphere(0.04, 20, 8);
    
    glPopMatrix();
    // draw Hightest ball
    glTranslatef(0.08, 0.5, -0.6);
    glRotatef(45, 0.0, -1.0, 0.0);
    glutSolidSphere(0.045, 20, 8);

    // draw right ball
    glTranslatef(0.4, -0.65, 0.2);
    glutSolidSphere(0.04, 20, 8);
    
    glEnd();
    
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
    glPopMatrix();
}

void makeGreenDecoration(){
    glPushMatrix();
    glLoadIdentity();
    
    GLfloat mat_diffuse[] = { 1.0, 0.0, 0.0, 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_ambient[] = { 1.0, 0.0, 0.0, 1.0 };
    GLfloat mat_shininess[] = { 15.0 };
    
    GLfloat light_specular[] = { 0.586, 0.293, 0.0, 1.0 };
    GLfloat light_diffuse[] = { 0.586, 0.293, 0.0, 1.0 };
    GLfloat light_ambient[] = { 0.586, 0.293, 0.0, 1.0 };
    GLfloat light_position[] = { -10, 20, -25.0, 0.0};
    
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);

    glPushMatrix();
    glTranslatef(0.6, 0.3, -0.3);
    glRotatef(60, 0.0, -1.0, 0.0);
    glTranslatef(0.0, 0.0, 0.45);
    glRotatef(90, 0.0, 1.0, 0.0);
    glutWireSphere(0.05, 8, 10);
    glPopMatrix();
    
    glTranslatef(0.24, 0.05, -0.6);
    glRotatef(30, 0.0, -1.0, 0.0);
    glutWireSphere(0.045, 8, 10);
    
    glTranslatef(-0.42, -0.16, 0.2);
    glutWireSphere(0.045, 8, 10);

    glEnd();
    
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
    glPopMatrix();
}

void makeBlueDecoration(){
    glPushMatrix();
    glLoadIdentity();
    
    GLfloat mat_diffuse[] = { 1.0, 0.0, 0.0, 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_ambient[] = { 1.0, 0.0, 0.0, 1.0 };
    GLfloat mat_shininess[] = { 15.0 };
    
    GLfloat light_specular[] = { 0.93, 0.898, 0.766, 1.0 };
    GLfloat light_diffuse[] = { 0.93, 0.898, 0.766, 1.0 };
    GLfloat light_ambient[] = { 0.93, 0.898, 0.766, 1.0 };
    GLfloat light_position[] = { -10, 20, -25.0, 0.0};
    
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    
    glPushMatrix();
    
    // draw Left Torus
    glTranslatef(0.24, 0.2, -0.75);
    glRotatef(60, 0.0, -1.0, 0.0);
    glTranslatef(0.0, 0.0, 0.45);
    glRotatef(90, 0.0, 1.0, 0.0);
    glutSolidTorus(0.026, 0.08, 20, 8);
    glPopMatrix();
    
    // draw 2nd
    glTranslatef(0.24, 0.05, -0.6);
    glRotatef(30, 0.0, -1.0, 0.0);
    glutSolidTorus(0.02, 0.07, 20, 8);
    
    // draw Lowest
    glTranslatef(-0.25, -0.2, 0.2);
    glRotatef(55, 0.0, 1.0, 0.0);
    glutSolidTorus(0.025, 0.08, 20, 8);
    
    glEnd();
    
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
    glPopMatrix();
}

void makePurpleBulbDecoration(){
    glPushMatrix();
    glLoadIdentity();
    
    GLfloat mat_diffuse[] = { 1.0, 0.0, 0.0, 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_ambient[] = { 1.0, 0.0, 0.0, 1.0 };
    GLfloat mat_shininess[] = { 15.0 };
    
    GLfloat light_specular[] = { 0.867, 0.867, 0.934, 1.0 };
    GLfloat light_diffuse[] = { 0.867, 0.867, 0.934, 1.0 };
    GLfloat light_ambient[] = { 0.867, 0.867, 0.934, 1.0 };
    GLfloat light_position[] = { 0, 10, -25.0, 0.0};
    
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    
    glPushMatrix();
    glTranslatef(0.35, 0.2, -0.8);
    glRotatef(45, 0.0, -1.0, 0.0);
    glTranslatef(0.0, 0.0, 0.45);
    glutSolidSphere(0.052, 20, 8);
    glPopMatrix();
    
    glTranslatef(-0.15, 0.03, -0.5);
    glutSolidSphere(0.04, 20, 8);
    
    glEnd();
    
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
    glPopMatrix();
}

void makePinkBulbDecoration(){
    glPushMatrix();
    glLoadIdentity();
    
    GLfloat mat_diffuse[] = { 1.0, 0.0, 0.0, 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_ambient[] = { 1.0, 0.0, 0.0, 1.0 };
    GLfloat mat_shininess[] = { 15.0 };
    
    GLfloat light_specular[] = { 1.0, 0.816, 0.859, 1.0 };
    GLfloat light_diffuse[] = { 1.0, 0.816, 0.859, 1.0 };
    GLfloat light_ambient[] = { 1.0, 0.816, 0.859, 1.0 };
    GLfloat light_position[] = { 0, 10, -25.0, 0.0 };
    
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    
    glPushMatrix();
    glTranslatef(0.4, 0.0, -0.8);
    glRotatef(45, 0.0, -1.0, 0.0);
    glTranslatef(0.0, 0.0, 0.45);
    glutSolidSphere(0.052, 20, 8);
    glPopMatrix();
    
    glTranslatef(-0.05, 0.4, -0.6);
    glutSolidSphere(0.052, 20, 8);
    
    glEnd();
    
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
    glPopMatrix();
}

void makeTree(){
    drawTreeTrunk(-0.07, 0.03, -0.45, 0.12, 0.26);
    drawLeaf();
    
    if (RED && GREEN && BLUE){
        drawTreeStar(0.3, 0.05);
        makePinkBulbDecoration();
        makePurpleBulbDecoration();
    }
    if (RED) makeRedDecoration();
    if (GREEN) makeGreenDecoration();
    if (BLUE) makeBlueDecoration();
}

// BLUE BOX
void drawBlueOrangeLeaf(){
    glPushMatrix();
    glLoadIdentity();
    
    GLfloat mat_diffuse[] = { 1.0, 0.0, 0.0, 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_ambient[] = { 1.0, 0.0, 0.0, 1.0 };
    GLfloat mat_shininess[] = { 15.0 };
    
    GLfloat light_specular[] = { 0.0, 1.0, 0.0, 1.0 };
    GLfloat light_diffuse[] = { 0.0, 1.0, 0.0, 1.0 };
    GLfloat light_ambient[] = { 0.0, 1.0, 0.0, 1.0 };
    GLfloat light_position[] = { 0, 2, -10.0, 0.0 };
    
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    
    glRotatef(45, -1.0, 0.0, 0.0);
    glRotatef(28, 0.0, 1.0, 0.0);
    glTranslatef(0.5, 0.2, -0.35);
    
    glBegin(GL_POLYGON);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, 0.05);
    glVertex3f(0.05, 0.0, 0.05);
    glVertex3f(0.05, 0.0, 0.0);
    glEnd();
    
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
    glPopMatrix();
}

void makeOrangeOnBlueBox(){
    glPushMatrix();
    glLoadIdentity();
    
    // set self Light
    GLfloat mat_diffuse[] = { 1.0, 0.0, 0.0, 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_ambient[] = { 1.0, 0.0, 0.0, 1.0 };
    GLfloat mat_shininess[] = { 15.0 };
    
    GLfloat light_specular[] = { 1.0, 0.496, 0.0, 1.0 };
    GLfloat light_diffuse[] = { 1.0, 0.496, 0.0, 1.0 };
    GLfloat light_ambient[] = { 1.0, 0.496, 0.0, 1.0 };
    GLfloat light_position[] = { 0, 2, -10.0, 0.0 };
    
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
    GLfloat light_position[] = { 0, 2, -10.0, 0.0 };
    
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
    
    if (BLUE){
        makeOrangeOnBlueBox();
        drawBlueOrangeLeaf();
    }
}

// GREEN BOX
void drawGreenOrangeLeaf(){
    glPushMatrix();
    glLoadIdentity();

    GLfloat mat_diffuse[] = { 1.0, 0.0, 0.0, 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_ambient[] = { 1.0, 0.0, 0.0, 1.0 };
    GLfloat mat_shininess[] = { 15.0 };
    
    GLfloat light_specular[] = { 0.0, 1.0, 0.0, 1.0 };
    GLfloat light_diffuse[] = { 0.0, 1.0, 0.0, 1.0 };
    GLfloat light_ambient[] = { 0.0, 1.0, 0.0, 1.0 };
    GLfloat light_position[] = { 0, 2, -10.0, 0.0 };
    
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    
    glRotatef(45, -1.0, 0.0, 0.0);
    glRotatef(28, 0.0, 1.0, 0.0);
    glTranslatef(0.5, 0.2, -0.65);
    
    glBegin(GL_POLYGON);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, 0.05);
    glVertex3f(0.05, 0.0, 0.05);
    glVertex3f(0.05, 0.0, 0.0);
    glEnd();
    
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
    glPopMatrix();
}

void makeOrangeOnGreenBox(){
    glPushMatrix();
    glLoadIdentity();
    
    GLfloat mat_diffuse[] = { 1.0, 0.0, 0.0, 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_ambient[] = { 1.0, 0.0, 0.0, 1.0 };
    GLfloat mat_shininess[] = { 15.0 };
    
    GLfloat light_specular[] = { 1.0, 0.496, 0.0, 1.0 };
    GLfloat light_diffuse[] = { 1.0, 0.496, 0.0, 1.0 };
    GLfloat light_ambient[] = { 1.0, 0.496, 0.0, 1.0 };
    GLfloat light_position[] = { 0, 2, -10.0, 0.0 };
    
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
    GLfloat light_position[] = { 0, 2, -10.0, 0.0 };
    
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
    
    if (GREEN) {
        makeOrangeOnGreenBox();
        drawGreenOrangeLeaf();
    }
}

// RED BOX
void drawRedOrangeLeaf(){
    glPushMatrix();
    glLoadIdentity();

    GLfloat mat_diffuse[] = { 1.0, 0.0, 0.0, 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_ambient[] = { 1.0, 0.0, 0.0, 1.0 };
    GLfloat mat_shininess[] = { 15.0 };
    
    GLfloat light_specular[] = { 0.0, 1.0, 0.0, 1.0 };
    GLfloat light_diffuse[] = { 0.0, 1.0, 0.0, 1.0 };
    GLfloat light_ambient[] = { 0.0, 1.0, 0.0, 1.0 };
    GLfloat light_position[] = { 0, 2, -10.0, 0.0 };
    
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    
    glRotatef(45, -1.0, 0.0, 0.0);
    glRotatef(28, 0.0, 1.0, 0.0);
    glTranslatef(0.2, 0.2, -0.65);
    
    glBegin(GL_POLYGON);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, 0.05);
    glVertex3f(0.05, 0.0, 0.05);
    glVertex3f(0.05, 0.0, 0.0);
    glEnd();
    
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
    glPopMatrix();
}

void makeOragneOnRedBox(){
    glPushMatrix();
    glLoadIdentity();
    
    GLfloat mat_diffuse[] = { 1.0, 0.0, 0.0, 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_ambient[] = { 1.0, 0.0, 0.0, 1.0 };
    GLfloat mat_shininess[] = { 15.0 };
    
    GLfloat light_specular[] = { 1.0, 0.496, 0.0, 1.0 };
    GLfloat light_diffuse[] = { 1.0, 0.496, 0.0, 1.0 };
    GLfloat light_ambient[] = { 1.0, 0.496, 0.0, 1.0 };
    GLfloat light_position[] = { 0, 2, -10.0, 0.0 };
    
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
    
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
    
    glPopMatrix();
}

void makeRedBox(){
    glPushMatrix();
    glLoadIdentity();
    
    GLfloat mat_diffuse[] = { 1.0, 0.0, 0.0, 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_ambient[] = { 1.0, 0.0, 0.0, 1.0 };
    GLfloat mat_shininess[] = { 15.0 };
    
    GLfloat light_specular[] = { 1.0, 0.0, 0.0, 1.0 };
    GLfloat light_diffuse[] = { 1.0, 0.0, 0.0, 1.0 };
    GLfloat light_ambient[] = { 1.0, 0.0, 0.0, 1.0 };
    GLfloat light_position[] = { 0, 2, -10.0, 0.0 };
    
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
    
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);

    glPopMatrix();
    
    if (RED){
        makeOragneOnRedBox();
        drawRedOrangeLeaf();
    }
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