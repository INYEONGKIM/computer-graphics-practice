#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <iostream>
#include <math.h>

GLboolean RED = false;
GLboolean GREEN = false;
GLboolean BLUE = false;

GLfloat tx, ty, tz = 0;
GLfloat rx, ry, rz =0;
GLfloat lx, ly, lz =0;
GLfloat a, ax, ay, az = 0;
GLfloat s, sx, sy, sz = 0;
GLfloat p, px, py, pz = 0;

#define GL_PI 3.1415f

void drawSnowmanBody(){
    glPushMatrix();
    glPushAttrib(GL_LIGHTING_BIT);
    glLoadIdentity();
    
    GLfloat mat_diffuse[] = { 0.9, 0.9, 0.9, 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_ambient[] = { 0.1, 0.1, 0.1, 1.0 };
    GLfloat mat_shininess[] = { 15.0 };
    
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shininess);
    
    GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0};
    GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0};
    GLfloat light_ambient[] = { 1.0, 1.0, 1.0, 1.0};
    GLfloat light_position[] = { -10, 20, -25.0, 0.0};
    
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    
    // Draw Body
    glTranslatef(0.7f ,0.0f, 0.0f);
    glScalef(0.7, 0.7, 0.7);
    glutSolidSphere(0.2f,20,20);
    
    // Draw Head
    glTranslatef(0.0f, 0.25f, 0.0f);
    glutSolidSphere(0.1f,20,20);
    
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
    
    glPopAttrib();
    glPopMatrix();
}

void drawSnowmanEyes() {
    glPushMatrix();
    glPushAttrib(GL_LIGHTING_BIT);
    glLoadIdentity();
    
    GLfloat mat_diffuse[] = { 0.9, 0.9, 0.9, 1.0 };
    GLfloat mat_specular[] = { 0.1, 0.1, 0.1, 1.0 };
    GLfloat mat_ambient[] = { 0.0, 0.1, 0.1, 1.0 };
    GLfloat mat_shininess[] = { 15.0 };

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shininess);
    
    GLfloat light_specular[] = { 0.0, 0.0, 0.0, 1.0};
    GLfloat light_diffuse[] = { 0.0, 0.0, 0.0, 1.0};
    GLfloat light_ambient[] = { 0.0, 0.0, 0.0, 1.0};
    GLfloat light_position[] = { -10, 20, -25.0, 0.0};
    
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    
    glColor3f(0.0f,0.0f,0.0f);
    
    glTranslatef(0.71f, 0.2f, -0.7);
    glutSolidSphere(0.01f,10,10);
    glTranslatef(-0.06f, 0.0f, 0.0f);
    glutSolidSphere(0.01f,10,10);
    
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
    
    glPopAttrib();
    glPopMatrix();
    
}

void drawSnowmanNose() {
    glPushMatrix();
    glPushAttrib(GL_LIGHTING_BIT);
    glLoadIdentity();
    
    GLfloat mat_diffuse[] = { 1.0, 0.5, 0.0, 1.0 };
    GLfloat mat_specular[] = { 0.5, 0.5, 0.0, 1.0 };
    GLfloat mat_ambient[] = { 1.0, 0.5, 0.0, 1.0 };
    GLfloat mat_shininess[] = { 30.0 };
    
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shininess);
    
    GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0};
    GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0};
    GLfloat light_ambient[] = { 0.1, 0.1, 0.1, 1.0};
    GLfloat light_position[] = { -10, 20, -25.0, 0.0};
    
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    
    // Draw Nose
    glColor3f(1.0f, 0.5f , 0.5f);
    glTranslatef(0.67f, 0.17f, -1);
    glRotatef(-10.0f,0.0f, 1.0f, 0.0f);
    glutSolidCone(0.02f,0.5f,10,2);
    
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
    
    glPopAttrib();
    glPopMatrix();
}

void drawSnowmanEars() {
    glPushMatrix();
    glPushAttrib(GL_LIGHTING_BIT);
    glLoadIdentity();
    
    GLfloat mat_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_specular[] = { 0.5, 0.5, 0.5, 1.0 };
    GLfloat mat_ambient[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = { 15.0 };
    
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shininess);
    
    GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0};
    GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0};
    GLfloat light_ambient[] = { 1.0, 1.0, 1.0, 1.0};
    GLfloat light_position[] = { -10, 20, -25.0, 0.0};
    
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    
    glColor3f(0.0f,0.0f,0.0f);
    
    glTranslatef(0.75f, 0.25f, 0.2f);
    glutSolidSphere(0.03f,10,10);
    glTranslatef(-0.08f, 0.0f, 0.0f);
    glutSolidSphere(0.03f,10,10);
    
    glPopAttrib();
    glPopMatrix();
}

void drawSnowmanButtons() {
    glPushMatrix();
    glPushAttrib(GL_LIGHTING_BIT);
    glLoadIdentity();
    
    glScalef(0.7, 0.7, 0.7);
    GLfloat mat_diffuse[] = { 0.0, 0.0, 1.0, 1.0 };
    GLfloat mat_specular[] = { 0.0, 0.0, 1.0, 1.0 };
    GLfloat mat_ambient[] = { 0.0, 0.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = { 15.0 };
    
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shininess);
    
    GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0};
    GLfloat light_diffuse[] = { 0.8, 0.8, 0.8, 1.0};
    GLfloat light_ambient[] = { 0.2, 0.2, 0.2, 1.0};
    GLfloat light_position[] = { -10, 20, -25.0, 0.0};
    
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    
    // Draw Buttons
    glTranslatef(0.94, 0.13f, -0.9);
    glutSolidSphere(0.02f,10,10);
    glTranslatef(0.0f, -0.08f, 0.0f);
    glutSolidSphere(0.02f,10,10);
    glTranslatef(0.0f, -0.08f, 0.0f);
    glutSolidSphere(0.02f,10,10);
    
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
    
    glPopAttrib();
    glPopMatrix();
}

void drawSnowmanRArms() {
    glPushMatrix();
    glPushAttrib(GL_LIGHTING_BIT);
    glLoadIdentity();
    
    glRotatef(s, sx, sy, sz);
    glTranslatef(rx, ry, rz);
    
    GLfloat mat_diffuse[] = { 0.29, 0.16, 0.043, 1.0 };
    GLfloat mat_specular[] = { 0.29, 0.16, 0.043, 1.0 };
    GLfloat mat_ambient[] = { 0.29, 0.16, 0.043, 1.0 };
    GLfloat mat_shininess[] = { 15.0 };
    
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shininess);
    
    GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0};
    GLfloat light_diffuse[] = { 0.29, 0.16, 0.043, 1.0};
    GLfloat light_ambient[] = { 0.29, 0.16, 0.043, 1.0};
    GLfloat light_position[] = { -10, 20, -25.0, 0.0};
    
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    
    //Draw Right-Arms
    glTranslatef(0.85f, 0.063f, 0.0);
    glRotatef(-30.0f ,0.0f, 0.0f, 1.0f);
    glScalef (0.7, 0.07, 0.3);
    glutSolidCube (0.25);
    
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
    
    glPopAttrib();
    glPopMatrix();
}

void drawSnowmanLArms() {
    glPushMatrix();
    glPushAttrib(GL_LIGHTING_BIT);
    glLoadIdentity();
    
    glRotatef(p, px, py, pz);
    glTranslatef(lx, ly, lz);
    //glRotatef(-50, 0, 0, 1);
    GLfloat mat_diffuse[] = { 0.29, 0.16, 0.043, 1.0 };
    GLfloat mat_specular[] = { 0.29, 0.16, 0.043, 1.0 };
    GLfloat mat_ambient[] = { 0.29, 0.16, 0.043, 1.0 };
    GLfloat mat_shininess[] = { 15.0 };
    
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shininess);
    
    GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0};
    GLfloat light_diffuse[] = { 0.29, 0.16, 0.043, 1.0};
    GLfloat light_ambient[] = { 0.29, 0.16, 0.043, 1.0};
    GLfloat light_position[] = { -10, 20, -25.0, 0.0};
    
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    
    //Draw Left-Arms
    glTranslatef(0.56f, 0.07f, 0.2);
    glRotatef(30.0f ,0.0f, 0.0f, 1.0f);
    glScalef (0.7, 0.07, 0.3);
    glutSolidCube (0.25);
    
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
    
    glPopAttrib();
    glPopMatrix();
}


void makeSnowman() {
    drawSnowmanBody();
    drawSnowmanEyes();
    drawSnowmanNose();
    drawSnowmanEars();
    drawSnowmanButtons();
    drawSnowmanRArms();
    drawSnowmanLArms();
}

void drawRudolphFace() {
    glPushMatrix();
    glPushAttrib(GL_LIGHTING_BIT);
    glLoadIdentity();
    
    glTranslatef(tx, ty, tz);
    glRotatef(a, ax, ay, az);
    
    glScalef(0.7, 0.7, 0.7);
    GLfloat mat_diffuse[] = { 0.29, 0.16, 0.043, 1.0 };
    GLfloat mat_specular[] = { 0.29, 0.16, 0.043, 1.0 };
    GLfloat mat_ambient[] = { 0.29, 0.16, 0.043, 1.0 };
    GLfloat mat_shininess[] = { 15.0 };
    
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shininess);
    //glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, mat_emi);
    
    GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0};
    GLfloat light_diffuse[] = { 0.5, 0.5, 0.5, 1.0};//낮아야 밝음
    GLfloat light_ambient[] = { 0.29, 0.16, 0.043, 1.0};//높아야 밝고
    GLfloat light_position[] = { 0, 6, -9.0, 1.0};
    //GLfloat light_position[] = { -5, 6, 3.0, 0.0};
    
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    
    //Draw Rudolph Face
    glPushMatrix();
    glColor3f (0.545098, 0.270588, 0.07451);//saddle-brown color
    glTranslatef(-0.7 ,-0.7, 0.0);//0.3,0.3
    glRotatef(-10, 1, 0, 0);
    glRotatef(-20, 0, 1, 0);
    glScalef (0.5, 0.3, 0.4);
    glutSolidCube (0.5);
    glPopMatrix();
    
    //Draw Rudolph Neck
    glPushMatrix();
    glColor3f (0.545098, 0.270588, 0.07451);//saddle-brown color
    glTranslatef(-0.77 ,-0.85, 0.03);
    glRotatef(-10, 1, 0, 0);
    glRotatef(-20, 0, 1, 0);
    glScalef (0.2, 0.3, 0.4);
    glutSolidCube (0.5);
    glPopMatrix();
    
    //Draw Rudolph Body
    glPushMatrix();
    glColor3f (0.545098, 0.270588, 0.07451);//saddle-brown color
    glTranslatef(-0.95 ,-1, 0.03);
    glRotatef(-10, 1, 0, 0);
    glRotatef(-20, 0, 1, 0);
    glScalef (1.0, 0.4, 0.6);
    glutSolidCube (0.5);
    glPopMatrix();
    
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
    
    glPopAttrib();
    glPopMatrix();
}
void drawRudolphLegs(){
    glPushMatrix();
    glPushAttrib(GL_LIGHTING_BIT);
    glLoadIdentity();
    
    glTranslatef(tx, ty, tz);
    glRotatef(a, ax, ay, az);
    
    glScalef(0.7, 0.7, 0.7);
    
    GLfloat mat_diffuse[] = { 0.29, 0.16, 0.043, 1.0 };
    GLfloat mat_specular[] = { 0.29, 0.16, 0.043, 1.0 };
    GLfloat mat_ambient[] = { 0.29, 0.16, 0.043, 1.0 };
    GLfloat mat_shininess[] = { 15.0 };
    
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shininess);
    //glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, mat_emi);
    
    GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0};
    GLfloat light_diffuse[] = { 0.5, 0.5, 0.5, 1.0};//낮아야 밝음
    GLfloat light_ambient[] = { 0.1, 0.1, 0.1, 1.0};//높아야 밝고
    GLfloat light_position[] = { 3, 6, -9.0, 1.0};
    //GLfloat light_position[] = { -5, 6, 3.0, 0.0};
    
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    //Draw Rudolph Legs
    glPushMatrix();
    //back-right leg
    glTranslatef(-1.2 ,-1.2, 0.1);
    glRotatef(-10, 1, 0, 0);
    glRotatef(-20, 0, 1, 0);
    glScalef (0.1, 0.7, 0.1);
    glutSolidCube (0.5);
    //back-left leg
    glTranslatef(0.0 ,0.0, -2);
    glutSolidCube (0.5);
    //front-left leg
    glTranslatef(4.1 ,0.0, 0.0);
    glutSolidCube (0.5);
    //front-right leg
    glTranslatef(0 ,0.0, 2);
    glutSolidCube (0.5);
    
    glPopMatrix();
    
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
    
    glPopAttrib();
    glPopMatrix();
}

void drawRudolphRedNose() {
    glPushMatrix();
    glPushAttrib(GL_LIGHTING_BIT);
    glLoadIdentity();
    
    glTranslatef(tx, ty, tz);
    glRotatef(a, ax, ay, az);
    
    GLfloat mat_diffuse[] = { 1.0, 0.0, 0.0, 1.0 };
    GLfloat mat_specular[] = { 0.1, 0.1, 0.1, 1.0 };
    GLfloat mat_ambient[] = { 1.0, 0, 0, 1.0 };
    GLfloat mat_shininess[] = { 55.0 };
    
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shininess);
    
    GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0};
    GLfloat light_diffuse[] = { 1.0, 0.0, 0.0, 1.0};
    GLfloat light_ambient[] = { 1.0, 0.0, 0.0, 1.0};
    GLfloat light_position[] = { 6, 6, -9.0, 1.0};
    
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    
    glColor3f (1, 0, 0);
    glTranslatef(-0.38 ,-0.49, 0.05);
    glutSolidSphere(0.04, 10, 10);
    
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
    
    glPopAttrib();
    glPopMatrix();
}

void drawRudolphEyes() {
    glPushMatrix();
    glPushAttrib(GL_LIGHTING_BIT);
    glLoadIdentity();
    
    glTranslatef(tx, ty, tz);
    glRotatef(a, ax, ay, az);
    
    GLfloat mat_diffuse[] = { 0.9, 0.9, 0.9, 1.0 };
    GLfloat mat_specular[] = { 0.1, 0.1, 0.1, 1.0 };
    GLfloat mat_ambient[] = { 0.0, 0.1, 0.1, 1.0 };
    GLfloat mat_shininess[] = { 15.0 };
    
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shininess);
    
    GLfloat light_specular[] = { 0.0, 0.0, 0.0, 1.0};
    GLfloat light_diffuse[] = { 0.0, 0.0, 0.0, 1.0};
    GLfloat light_ambient[] = { 0.0, 0.0, 0.0, 1.0};
    GLfloat light_position[] = { 6, 6, -9.0, 1.0};
    
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    //Draw Right Eye
    glTranslatef(-0.43 ,-0.5, -0.08);
    glRotatef(-10, 1, 0, 0);
    glRotatef(-20, 0, 1, 0);
    glutSolidSphere(0.02f,10,10);
    glTranslatef(0, 0.0f, 0.2);
    glutSolidSphere(0.02f,10,10);
    
    glPopMatrix();
    
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
    
    glPopAttrib();
    glPopMatrix();
}

void drawRudolphAntlersTail() {
    glPushMatrix();
    glPushAttrib(GL_LIGHTING_BIT);
    glLoadIdentity();
    
    glTranslatef(tx, ty, tz);
    glRotatef(a, ax, ay, az);
    
    GLfloat mat_diffuse[] = { 0.29, 0.16, 0.043, 1.0 };
    GLfloat mat_specular[] = { 0.29, 0.16, 0.043, 1.0 };
    GLfloat mat_ambient[] = { 0.29, 0.16, 0.043, 1.0 };
    GLfloat mat_shininess[] = { 15.0 };
    
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shininess);
    
    GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0};
    GLfloat light_diffuse[] = { 0.29, 0.16, 0.043, 1.0};
    GLfloat light_ambient[] = { 0.29, 0.16, 0.043, 1.0};
    GLfloat light_position[] = { 5, -6, -9.0, 1.0};
    
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    
    //Draw RudolphAntlers
    glPushMatrix();
    //right-antlers
    glTranslatef(-0.52 ,-0.37, -0.05);
    glRotatef(40.0f ,0.0f, 0.0f, 1.0f);
    glScalef (0.1, 0.5, 0.1);
    glutSolidCube (0.3);
    //left-antlers
    glTranslatef(-0.5, 0, -0.2);
    glutSolidCube (0.3);
    
    glPopMatrix();
    
    //Draw RudolphTail
    glPushMatrix();
    glTranslatef(-0.87, -0.65, -0.05);
    glutSolidSphere(0.05f,10,10);
    glPopMatrix();
    
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
    
    glPopAttrib();
    glPopMatrix();
}
void makeRudolph() {
    drawRudolphFace();
    drawRudolphLegs();
    drawRudolphEyes();
    drawRudolphRedNose();
    drawRudolphAntlersTail();
}

void drawTreeStar(GLfloat x, GLfloat z){
    glPushMatrix();
    glPushAttrib(GL_LIGHTING_BIT);
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
    
    glPopAttrib();
    glPopMatrix();
}

void drawTreeTrunk(GLfloat centerx, GLfloat centery, GLfloat centerz, GLfloat radius, GLfloat h){
    glPushMatrix();
    glPushAttrib(GL_LIGHTING_BIT);
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
    
    glPopAttrib();
    glPopMatrix();
}

void drawLeaf(){
    glPushMatrix();
    glPushAttrib(GL_LIGHTING_BIT);
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
    
    glPopAttrib();
    glPopMatrix();
}

void makeRedDecoration(){
    glPushMatrix();
    glPushAttrib(GL_LIGHTING_BIT);
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
    
    glPopAttrib();
    glPopMatrix();
}

void makeGreenDecoration(){
    glPushMatrix();
    glPushAttrib(GL_LIGHTING_BIT);
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
    
    glPopAttrib();
    glPopMatrix();
}

void makeBlueDecoration(){
    glPushMatrix();
    glPushAttrib(GL_LIGHTING_BIT);
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
    
    glPopAttrib();
    glPopMatrix();
}

void makePurpleBulbDecoration(){
    glPushMatrix();
    glPushAttrib(GL_LIGHTING_BIT);
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
    glPopAttrib();
    glPopMatrix();
}

void makePinkBulbDecoration(){
    glPushMatrix();
    glPushAttrib(GL_LIGHTING_BIT);
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
    glPopAttrib();
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
    glPushAttrib(GL_LIGHTING_BIT);
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
    
    glPopAttrib();
    glPopMatrix();
}

void makeOrangeOnBlueBox(){
    glPushMatrix();
    glPushAttrib(GL_LIGHTING_BIT);
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
    
    glPopAttrib();
    glPopMatrix();
}

void makeBlueBox(){
    glPushMatrix();
    glPushAttrib(GL_LIGHTING_BIT);
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
    
    glPopAttrib();
    glPopMatrix();
    
    if (BLUE){
        makeOrangeOnBlueBox();
        drawBlueOrangeLeaf();
    }
}

// GREEN BOX
void drawGreenOrangeLeaf(){
    glPushMatrix();
    glPushAttrib(GL_LIGHTING_BIT);
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
    
    glPopAttrib();
    glPopMatrix();
}

void makeOrangeOnGreenBox(){
    glPushMatrix();
    glPushAttrib(GL_LIGHTING_BIT);
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
    
    glPopAttrib();
    glPopMatrix();
}

void makeGreenBox(){
    glPushMatrix();
    glPushAttrib(GL_LIGHTING_BIT);
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
    
    glPopAttrib();
    glPopMatrix();
    
    if (GREEN) {
        makeOrangeOnGreenBox();
        drawGreenOrangeLeaf();
    }
}

// RED BOX
void drawRedOrangeLeaf(){
    glPushMatrix();
    glPushAttrib(GL_LIGHTING_BIT);
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
    
    glPopAttrib();
    glPopMatrix();
}

void makeOragneOnRedBox(){
    glPushMatrix();
    glPushAttrib(GL_LIGHTING_BIT);
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
    
    glPopAttrib();
    glPopMatrix();
}

void makeRedBox(){
    glPushMatrix();
    glPushAttrib(GL_LIGHTING_BIT);
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
    
    glPopAttrib();
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
    
    //makeSnowman
    makeSnowman();
    
    //makeRudolph
    makeRudolph();
    
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
            
        case 'Q':
        case 'q':
            tx = -0.17;
            ty = 1.0;
            tz =0;
            a = 40;
            ax =0;
            ay =1;
            az = 0;
            s = 0;
            sx =0;
            sy =0;
            sz = 0;
            p =-0;
            px =0;
            py =0;
            pz =0;
            lx = 0;
            ly = 0;
            lz =0;
            rx = 0;
            ry = 0;
            rz = 0;
            lx = 0;
            ly = 0.;
            lz =0;
            break;
            
        case 'W':
        case 'w':
            tx = 0.9;
            ty = 1.1;
            tz =0;
            a = 70;
            ax =0;
            ay =1;
            az = -0.2;
            s = 60;
            sx =0;
            sy =0;
            sz = 1;
            p =-60;
            px =0;
            py =0;
            pz =1;
            lx = -0.4;
            ly = 0.45;
            lz =0;
            rx = -0.3;
            ry = -0.75;
            rz = 0;
            lx = -0.4;
            ly = 0.45;
            lz =0;
            break;
        case 'S':
        case 's':
            tx = 1.2;
            ty =0;
            tz =0;
            a = 50;
            ax =0;
            ay =1;
            az = -0.2;
            s = 0;
            sx =0;
            sy =0;
            sz = 0;
            p =-0;
            px =0;
            py =0;
            pz =0;
            lx = 0;
            ly = 0;
            lz =0;
            rx = 0;
            ry = 0;
            rz = 0;
            lx = 0;
            ly = 0.;
            lz =0;
            break;
        case 'A' :
        case 'a' :
            tx =0;
            ty =0;
            tz =0;
            a = 0;
            ax =0;
            ay =0;
            az = 0;
            s = 0;
            sx =0;
            sy =0;
            sz =0;
            p =-0;
            px =0;
            py =0;
            pz =0;
            lx = 0;
            ly = 0;
            lz =0;
            rx = 0;
            ry = 0;
            rz = 0;
            lx = 0;
            ly = 0;
            lz =0;
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
