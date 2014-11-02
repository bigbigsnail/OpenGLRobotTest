//
//  main.cpp
//  OpenGLRobotTest
//
//  Created by bigbigsnail on 14/11/1.
//  Copyright (c) 2014年 bigbigsnail. All rights reserved.
//

#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

GLfloat noMat[] = {0.0, 0.0, 0.0, 1.0};
GLfloat matAmbient[] = {0.8, 0.8, 0.8, 1.0};
GLfloat matAmbientColor[] = {0.8, 0.8, 0.2, 1.0};
GLfloat matDiffuse[] = {0.5, 0.8, 0.0, 1.0};
GLfloat matSpecular[] = {1.0, 0.0, 0.5, 1.0};
GLfloat matEmission[] = {0.3, 0.2, 0.2, 0.0};
GLfloat noShininess[] = {0.5};
GLfloat lowShininess[] = {5.0};
GLfloat highShininess[] = {100.0};

//angle
static int angle = 0;
static int neck = 0;
static int leftShoulder = 0, rightShoulder = 0;
static int leftElbow = 0, rightElbow = 0;
static int leftHips = 0, rightHips = 0;
static int leftFoot = 0, rightFoot = 0;
static int flagNeck = 0;
static int flagLeftShoulder = 0, flagRightShoulder = 0;
static int flagLeftElbow = 0, flagRightElbow = 0;
static int flagLeftHips = 0, flagRightHips = 0;
static int flagLeftFoot = 0, flagRightFoot = 0;

//Initialize
void init()
{
    GLfloat ambient[] = {0.0, 0.0, 0.0, 1.0};
    GLfloat diffuse[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat position[] = {0.0, 5.0, 10.0, 0.0};
    GLfloat lmodelAmbient[] = {0.4, 0.4, 0.4, 1.0};
    GLfloat localView[] = {0.0};
    
    glClearColor(0, 0, 0, 0);
    
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodelAmbient);
    glLightModelfv(GL_LIGHT_MODEL_LOCAL_VIEWER, localView);
    
    
    //glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
}


//Draw Body Of the Robot
void drawBody()
{
    glPushMatrix();
    
    glTranslatef(0, 1.5, 0);
    glScalef(0.5, 1, 0.4);
    
    glMaterialfv(GL_FRONT, GL_AMBIENT, matAmbientColor);
    //glMaterialfv(GL_FRONT, GL_DIFFUSE, matDiffuse);
    //glMaterialfv(GL_FRONT, GL_SPECULAR, matSpecular);
    //glMaterialfv(GL_FRONT, GL_SHININESS, highShininess);
    //glMaterialfv(GL_FRONT, GL_EMISSION, noMat);
    
    glutSolidCube(4);
    
    glPopMatrix();
    
}

//Draw left & right shoulder of the robot
void drawLeftShoulder()
{
    glPushMatrix();
    
    glMaterialfv(GL_FRONT, GL_AMBIENT, noMat);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, matDiffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, noMat);
    glMaterialfv(GL_FRONT, GL_SHININESS, noShininess);
    glMaterialfv(GL_FRONT, GL_EMISSION, noMat);
    glTranslatef(1.5, 3, 0);
    glRotatef(leftShoulder, 1, 0, 0);
    
    glTranslatef(0, -0.5, 0);
    glScalef(0.4, 1, 0.5);
    glutSolidCube(2);
    
    glScalef(1 / 0.4, 1 / 1, 1 / 0.5);
    glTranslatef(0, -1.4, 0);
    glRotatef(leftElbow, 1, 0, 0);
    glutWireSphere(0.4, 200, 500);
    //glutSolidSphere(0.4, 200, 500);
    
    glScalef(0.4, 1, 0.5);
    glTranslatef(0, -1.4, 0);
    glutSolidCube(2);
    
    glPopMatrix();
}

void drawRightShoulder()
{
    glPushMatrix();
    
    glMaterialfv(GL_FRONT, GL_AMBIENT, noMat);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, matDiffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, noMat);
    glMaterialfv(GL_FRONT, GL_SHININESS, noShininess);
    glMaterialfv(GL_FRONT, GL_EMISSION, noMat);
    glTranslatef(-1.5, 3, 0);
    glRotatef(rightShoulder, 1, 0, 0);
    
    glTranslatef(0, -0.5, 0);
    glScalef(0.4, 1, 0.5);
    glutSolidCube(2);
    
    glScalef(1 / 0.4, 1 / 1, 1 / 0.5);
    glTranslatef(0, -1.4, 0);
    glRotatef(rightElbow, 1, 0, 0);
    glutWireSphere(0.4, 200, 500);
    
    glScalef(0.4, 1, 0.5);
    glTranslatef(0, -1.4, 0);
    glutSolidCube(2);
    
    glPopMatrix();
}


//Draw head of the robot
void drawHead()
{
    glPushMatrix();
    
    glMaterialfv(GL_FRONT, GL_AMBIENT, noMat);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, matDiffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, matSpecular);
    glMaterialfv(GL_FRONT, GL_SHININESS, lowShininess);
    glMaterialfv(GL_FRONT, GL_EMISSION, noMat);
    
    glTranslatef(0.0, 3.5, 0.0);
    glRotatef(neck, 0.0, 0.0, 1.0);
    glTranslatef(0.0, 1.0, 0.0);
    glutWireSphere(1, 200, 500);
    
    glPopMatrix();
}

//Draw feet of the robot
void drawLeftFoot()
{
    glPushMatrix();
    
    glMaterialfv(GL_FRONT, GL_AMBIENT, noMat);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, matDiffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, noMat);
    glMaterialfv(GL_FRONT, GL_SHININESS, noShininess);
    glMaterialfv(GL_FRONT, GL_EMISSION, noMat);
    
    glTranslatef(-0.6, -0.6, 0.0);
    glRotatef(leftFoot, 1.0, 0.0, 0.0);
    glTranslatef(0.0, -1.0, 0.0);
    glScalef(0.4, 1.0, 0.5);
    glutSolidCube(2.0);
    
    glScalef(1 / 0.4, 1.0 / 1.0, 1 / 0.5);
    glTranslatef(0.0, -1.4, 0.0);
    glRotatef(leftHips, 1.0, 0.0, 0.0);
    glutWireSphere(0.4, 200, 500);
    
    glScalef(0.4, 1.0, 0.5);
    glTranslatef(0.0, -1.4, 0.0);
    glutSolidCube(2.0);
    
    glPopMatrix();
}

void drawRightFoot()
{
    glPushMatrix();
    
    glMaterialfv(GL_FRONT, GL_AMBIENT, noMat);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, matDiffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, noMat);
    glMaterialfv(GL_FRONT, GL_SHININESS, noShininess);
    glMaterialfv(GL_FRONT, GL_EMISSION, noMat);
    
    glTranslatef(0.6, -0.6, 0.0);
    glRotatef(rightFoot, 1.0, 0.0, 0.0);
    glTranslatef(0.0, -1.0, 0.0);
    glScalef(0.4, 1.0, 0.5);
    glutSolidCube(2.0);
    
    glScalef(1 / 0.4, 1.0 / 1.0, 1 / 0.5);
    glTranslatef(0.0, -1.4, 0.0);
    glRotatef(rightHips, 1.0, 0.0, 0.0);
    glutWireSphere(0.4, 200, 500);
    
    glScalef(0.4, 1.0, 0.5);
    glTranslatef(0.0, -1.4, 0.0);
    glutSolidCube(2.0);
    
    glPopMatrix();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    
    
    glPushMatrix();
    
    glRotatef(angle, 0.0, 1.0, 0.0);
    
    glTranslatef(0.0, 4.0, 0.0);
    drawBody();
    
    drawHead();
    
    drawLeftShoulder();
    drawRightShoulder();
    
    drawLeftFoot();
    drawRightFoot();
    
    glPopMatrix();
    glutSwapBuffers();
}

void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-8.0, 8.0, -8.0, 8.0, 1.0, 20.0);
    //gluPerspective(80.0f, (GLfloat)w/(GLfloat)h, 1.0f, 20.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 4.0, 10, 0.0, 4, 0.0, 0.0, 1.0, 0.0);
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key) {
        case '1':
            angle = (angle + 5) % 360;
            glutPostRedisplay();
            break;
        case '2':
            angle = (angle - 5 ) % 360;
            glutPostRedisplay();
            break;
        case '3':
            if(flagNeck)
            {
                neck = neck + 5;
                if(neck >= 30)
                {
                    flagNeck = 0;
                }
            }
            else
            {
                neck = neck - 5;
                if (neck <= -30)
                {
                    flagNeck = 1;
                }
            }
            glutPostRedisplay();
            break;
        case '4':
            if (flagLeftShoulder)
            {
                leftShoulder = leftShoulder + 5;
                if(leftShoulder >= 60)
                {
                    flagLeftShoulder = 0;
                }
            }
            else
            {
                leftShoulder = leftShoulder - 5;
                if(leftShoulder <= -60)
                {
                    flagLeftShoulder = 1;
                }
            }
            glutPostRedisplay();
            break;
        case '5':
            if (flagRightShoulder) {
                rightShoulder = rightShoulder + 5;
                if (rightShoulder >= 60) {
                    flagRightShoulder = 0;
                }
            }
            else
            {
                rightShoulder = rightShoulder - 5;
                if (rightShoulder <= -60) {
                    flagRightShoulder = 1;
                }
            }
            glutPostRedisplay();
            break;
        case '6':
            if (flagLeftElbow) {
                leftElbow = leftElbow + 5;
                if (leftElbow >= 60) {
                    flagLeftElbow = 0;
                }
            }
            else
            {
                leftElbow = leftElbow - 5;
                if (leftElbow <= -60) {
                    flagLeftElbow = 1;
                }
            }
            glutPostRedisplay();
            break;
        case '7':
            if (flagRightElbow) {
                rightElbow = rightElbow + 5;
                if (rightElbow >= 60) {
                    flagRightElbow = 0;
                }
            }
            else
            {
                rightElbow = rightElbow - 5;
                if (rightElbow <= -60) {
                    flagRightElbow = 1;
                }
            }
            
            glutPostRedisplay();
            break;
        case '8':
            if (flagLeftHips) {
                leftHips = leftHips + 5;
                if (leftHips >= 60) {
                    flagLeftHips = 0;
                }
            }
            else
            {
                leftHips = leftHips - 5;
                if (leftHips <= -60) {
                    flagLeftHips = 1;
                }
            }
            glutPostRedisplay();
            break;
        case '9':
            if (flagRightHips) {
                rightHips = rightHips + 5;
                if (rightHips >= 60) {
                    flagRightHips = 0;
                }
            }
            else
            {
                rightHips = rightHips + 5;
                if (rightHips <= -60) {
                    flagRightHips = 1;
                }
            }
            glutPostRedisplay();
            break;
        case 'a':
            if (flagLeftFoot) {
                leftFoot = leftFoot + 5;
                if (leftFoot >= 60) {
                    flagLeftFoot = 0;
                }
            }
            else
            {
                leftFoot = leftFoot - 5;
                if (leftFoot <= -60) {
                    flagLeftFoot = 1;
                }
            }
            glutPostRedisplay();
            break;
        case 'b':
            if (flagRightFoot) {
                rightFoot = rightFoot + 5;
                if (rightFoot >= 60) {
                    flagRightFoot = 0;
                }
            }
            else
            {
                rightFoot = rightFoot - 5;
                if (rightFoot <= -60) {
                    flagRightFoot = 0;
                }
            }
            glutPostRedisplay();
            break;
        default:
            break;
    }
}




int main(int argc, char * argv[]) {
    // insert code here...
    cout<<"按键「1」，「2」为整体旋转\n";
    cout<<"按键「3」为头部旋转\n";
    cout<<"按键「4」，「5」，「6」，「7」为手臂旋转\n";
    cout<<"按键「8」，「9」「a」，「b」为腿部旋转\n";
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RED);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    
    
    
    return 0;
}
