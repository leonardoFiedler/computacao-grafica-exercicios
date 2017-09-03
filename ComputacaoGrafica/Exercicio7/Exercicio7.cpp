#include <afx.h>
#include "..\external_dependency\general_functions.h"

GLint gJanelaPrincipal = 0;
GLint janelaLargura    = 400;
GLint janelaAltura     = 400;

void desenha_circulo(GLfloat posX, GLfloat posY, GLfloat raio, int iQtd)
{
	glColor3f(0.0, 0.0, 0.0);

	glLineWidth(2.0f);
	glBegin(GL_LINE_LOOP);
	for (int ii = 0; ii < iQtd; ii++)
	{
		float theta = 2.0f * 3.1415926f * float(ii) / float(iQtd);

		float x = raio * cosf(theta);
		float y = raio * sinf(theta);

		glVertex2f(x + posX, y + posY);

	}
	glEnd();
}

void desenha_ponto(GLfloat posX, GLfloat posY)
{
	glColor3f(0.0, 0.0, 0.0);

	glPointSize(2.0f);
	glBegin(GL_POINTS);
		glVertex2d(posX, posY);
	glEnd();
}

void desenha_quadrado(GLfloat posX, GLfloat posY)
{
	glColor3f(0.8, 0.5, 0.7);

	glLineWidth(2.0f);
	double pi = 3.14159265358979;
	glBegin(GL_LINE_LOOP);		
		double theta = pi * (45) / 200;

		double x = 200 * cos(theta);
		double y = 200 * sin(theta);

		glVertex2d(x + posX, y + posY);	
			
		theta = pi * (-45) / 200;

		x = -200 * cos(theta);
		y = -200 * sin(theta);

		glVertex2d(x + posX, y + posY);

		theta = pi * (45) / 200;

		x = -200 * cos(theta);
		y = -200 * sin(theta);

		glVertex2d(x + posX, y + posY);	

		theta = pi * (-45) / 200;

		x = 200 * cos(theta);
		y = 200 * sin(theta);

		glVertex2d(x + posX, y + posY);
		
	glEnd();
}

void exercicio7()
{
	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-400.0, 400.0, -400.0, 400.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    SRU();

	desenha_circulo(0, 0, 200, 100);
	desenha_circulo(0, 0, 50, 30);
	desenha_ponto(0, 0);
	desenha_quadrado(0, 0);

	glutSwapBuffers();
}



void keyboardFunc(UCHAR key, int x, int y)
{
	switch (key)
	{
	case '1':

		break;

	case '2':

		break;

	case '3':

		break;

	case '4':

		break;
	default:
		break;
	}

	exercicio7();
}

void mouseFunc(int iButton, int iState, int x, int y)
{
	/*if (iState == GLUT_DOWN && iButton == GLUT_LEFT_BUTTON) 
	{
		

	}*/
	glutPostRedisplay();
}

void mouseMovement(int x, int y)
{

}

int main(int argc, TCHAR* argv[], TCHAR* envp[])
{
	glutInit(&argc, (char **)argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(300, 250);
    glutInitWindowSize(janelaLargura, janelaAltura);
    gJanelaPrincipal = glutCreateWindow("Exercicio 7");
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glutDisplayFunc(exercicio7);
    glutKeyboardFunc(keyboardFunc);
	glutMouseFunc(mouseFunc);
	glutMotionFunc(mouseMovement);
	//glutPassiveMotionFunc(void(*func)(int x, int y));
    glutMainLoop();
}