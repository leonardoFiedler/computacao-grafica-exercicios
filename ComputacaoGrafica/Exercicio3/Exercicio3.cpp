#include "..\external_dependency\general_functions.h"

GLint gJanelaPrincipal = 0;
GLint janelaLargura = 400;
GLint janelaAltura = 400;

void desenha_circulo(GLfloat posX, GLfloat posY, GLfloat raio, int iQtd)
{
	glColor3f(0.0, 0.0, 0.0);

	glLineWidth(2.0f);
	glBegin(GL_LINE_LOOP);
	for (int ii = 0; ii < iQtd; ii++)
	{
		float theta = 2.0f * 3.1415926f * float(ii) / float(iQtd);

		float x = 100 * cosf(theta);
		float y = 100 * sinf(theta);

		glVertex2f(x + posX, y + posY);

	}
	glEnd();
}


void exercicio3()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-400.0, 400.0, -400.0, 400.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	SRU();

	desenha_circulo(101, 101, 100, 100);
	desenha_circulo(-101, 101, 100, 100);
	desenha_circulo(0, -100, 100, 100);

	glColor3f(0.0, 1.0, 1.0);
	glLineWidth(1.0f);

	glBegin(GL_LINES);
	glVertex2f(-100, 100);
	glVertex2f(100, 100);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(-100, 100);
	glVertex2f(0, -100);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(100, 100);
	glVertex2f(0, -100);
	glEnd();

	glutSwapBuffers();
}

int main(int argc, TCHAR* argv[], TCHAR* envp[])
{
	glutInit(&argc, (char **)argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(300, 250);
	glutInitWindowSize(janelaLargura, janelaAltura);
	gJanelaPrincipal = glutCreateWindow("Exercicio 3");
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glutDisplayFunc(exercicio3);
	glutMainLoop();
}