#include "..\external_dependency\general_functions.h"

GLint gJanelaPrincipal = 0;
GLint janelaLargura = 400;
GLint janelaAltura = 400;

void exercicio1()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-400.0, 400.0, -400.0, 400.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	SRU();
	glColor3f(0.0, 0.0, 0.0);
	glPointSize(2.0f);
	glBegin(GL_POINTS);

	glColor3f(0.0, 0.0, 1.0);

	for (int i = 0; i < 72; i++)
	{
		float theta = 2.0f * 3.1415926f * float(i) / float(72);

		float x = 100.0f * cos(theta);
		float y = 100.0f * sin(theta);

		glVertex2f(x, y);
	}
	glEnd();

	glutSwapBuffers();
}

int main(int argc, TCHAR* argv[], TCHAR* envp[])
{
	glutInit(&argc, (char **)argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(300, 250);
	glutInitWindowSize(janelaLargura, janelaAltura);
	gJanelaPrincipal = glutCreateWindow("Exercicio 1");
	glClearColor(0.86f, 0.86f, 0.86f, 1.0f);
	glutDisplayFunc(exercicio1);
	glutMainLoop();
}