#include <iostream>
#include <gl\glut.h>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <D:/Learning/glaux/Glaux.h>
#pragma comment(lib, "D:/Learning/glaux/Glaux.lib")
#pragma comment(lib, "legacy_stdio_definitions.lib")


GLfloat myAmbient[] = { 0.10588, 0.058824, 0.113725, 1 };
GLfloat myDiffuse[] = { 0.427451, 0.470588, 0.541176, 1 };
GLfloat mySpecular[] = { 0.3333, 0.3333, 0.521569, 1 };
GLfloat myShininess[] = { 9.84615 };

GLfloat ratio = 4.0 / 3.0;
GLfloat angle = 0.0, plusangle = 0.0;
AUX_RGBImageRec* image;
int ch1 = 0, ch2 = 0;
void init()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, 1, 1, 10);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(2.0, 2.0, 2.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);


}
void reshape(int width, int height)
{
	if (ratio > width / height) glViewport(0, 0, width, width / ratio);
	else glViewport(0, 0, height * ratio, height);
}


void display()
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	glRotatef(angle, 0.0, 1.0, 0.0);

	image = auxDIBImageLoadA("renault.bmp");

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image->sizeX, image->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, image->data);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);

	GLfloat myLightPosition[] = { 1.0, 2.0, 2.0, 1.0 }; // Источник света в CKw
	glLightfv(GL_LIGHT0, GL_POSITION, myLightPosition); /*Позиция источника света будет преобразована в CKe*/
	glLightfv(GL_LIGHT0, GL_AMBIENT, myAmbient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, myDiffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, mySpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, myShininess);

	glEnable(GL_LIGHTING); // Включение расчета освещенности
	glEnable(GL_LIGHT0); // включаем этот конкретный источник

	glPushMatrix();

	glLightfv(GL_LIGHT0, GL_POSITION, myLightPosition);
	glPopMatrix(); // Восстанавливаем VM=Fwe
	// грань dawn
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image->sizeX, image->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, image->data);
	glBegin(GL_POLYGON);
	glNormal3f(0, -1, 0);
	glTexCoord2f(0, 0); glVertex3f(-0.25, 0, -0.25);
	glTexCoord2f(0, 1); glVertex3f(0.25, 0, -0.25);
	glTexCoord2f(1, 0); glVertex3f(0.25, 0, 0.25);
	glTexCoord2f(1, 1); glVertex3f(-0.25, 0, 0.25);
	glEnd();
	//грань лево низ
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image->sizeX, image->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, image->data);
	glBegin(GL_POLYGON);
	glNormal3f(0, 0.707, -0.707);
	glTexCoord2f(0, 0); glVertex3f(-0.25, 0, -0.25);
	glTexCoord2f(1, 0); glVertex3f(-0.5, 1, -0.25);
	glTexCoord2f(1, 1); glVertex3f(-0.5, 1, 0.25);
	glTexCoord2f(0, 1); glVertex3f(-0.25, 0, 0.25);
	
	glEnd();
	//грань право низ
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image->sizeX, image->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, image->data);
	glBegin(GL_POLYGON);
	glNormal3f(0, 0.707, -0.707);
	glTexCoord2f(0, 0); glVertex3f(0.25, 0, -0.25);
	glTexCoord2f(1, 0); glVertex3f(0.5, 1, -0.25);
	glTexCoord2f(1, 1); glVertex3f(0.5, 1, 0.25);
	glTexCoord2f(0, 1); glVertex3f(0.25, 0, 0.25);
	glEnd();
	//// грань лево верх
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image->sizeX, image->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, image->data);
	glBegin(GL_POLYGON);
	glNormal3f(0, 0.707, -0.707);
	glTexCoord2f(0, 0); glVertex3f(-0.5, 0, -0.25);
	glTexCoord2f(1, 0); glVertex3f(-0.25, 2, -0.25);
	glTexCoord2f(1, 1); glVertex3f(-0.25, 2, 0.25);
	glTexCoord2f(0, 1); glVertex3f(-0.5, 0, 0.25);
	glEnd();
	//// грань f4
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image->sizeX, image->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, image->data);
	glBegin(GL_POLYGON);
	glNormal3f(0, 0.707, 0.707);
	glTexCoord2f(0, 0); glVertex3f(1, 0, 1);
	glTexCoord2f(0, 1); glVertex3f(0, 0, 1);
	glTexCoord2f(1, 0); glVertex3f(0.5, 0.5, 0.5);
	glEnd();

	glPopMatrix(); // Восстанавливаем VM=Fwe
	glDisable(GL_LIGHTING); //Выключаем освещение

	glBegin(GL_LINES); //Рисуем координатные оси разного цвета в CKe
	glColor3f(1, 0, 0); glVertex3f(0, 0, 0); glVertex3f(2, 0, 0);
	glColor3f(0, 1, 0); glVertex3f(0, 0, 0); glVertex3f(0, 2, 0);
	glColor3f(0, 0, 1); glVertex3f(0, 0, 0); glVertex3f(0, 0, 2);
	glEnd();

	glPopMatrix();
	glFlush();
	glutSwapBuffers();
}

void myIdle()
{
	angle += plusangle; if (angle > 360.0) angle = 0;
	glutPostRedisplay();
}

void keys(unsigned char key, int x, int y)
{
	if (key == '0') {
		if (ch1 % 2 == 0) plusangle = 2;
		else plusangle = 0;
		ch1++;
	}
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(900, 900);
	glutCreateWindow("Пример текстурирования");
	glutDisplayFunc(display);
	glutKeyboardFunc(keys);
	glutReshapeFunc(reshape);
	glutIdleFunc(myIdle);
	init();
	glutMainLoop();

}
