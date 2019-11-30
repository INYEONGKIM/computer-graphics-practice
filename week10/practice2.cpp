#include <iostream>
#include <GLUT/glut.h>
#include <OpenGL/gl.h>

#define Width 4
#define Height 4

GLubyte MyTexture[Width][Height][3];

void FillMyTexture(){
    int s, t;
    for(s=0; s<Width; s++){
        for(t=0; t<Height; t++){
            GLubyte Intensity = ((s+t)%2)*255;
            MyTexture[s][t][0] = Intensity; // R
            MyTexture[s][t][1] = Intensity; // G
            MyTexture[s][t][2] = Intensity; // B
        }
    }
}

void MyInit(){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    FillMyTexture();
    glTexImage2D(GL_TEXTURE_2D, 0, 3, Width, Height, 0, GL_RGB, GL_UNSIGNED_BYTE, &MyTexture[0][0][0]);
    
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); // 점 샘플링
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); // 양선형 보간 샘플링
    
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    
    glEnable(GL_TEXTURE_2D); // enable texutring
}

void MyDisplay(){
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);
    glLoadIdentity();
    
    glTexCoord2f(0.0, 0.0); glVertex3f(-1.0, -1.0, 0.0); // Texture image 명시, 수동 텍스쳐 맵핑
    glTexCoord2f(0.0, 3.0); glVertex3f(-1.0, 1.0, 0.0);
    glTexCoord2f(3.0, 3.0); glVertex3f(1.0, 1.0, 0.0);
    glTexCoord2f(3.0, 0.0); glVertex3f(1.0, -1.0, 0.0);
    
    glEnd();
    
    glutSwapBuffers();
}

int main(int argc,char** argv) {
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutCreateWindow("20191125");
    MyInit();
    
    glutDisplayFunc(MyDisplay);
    glutMainLoop();
    
    return 0;
}
