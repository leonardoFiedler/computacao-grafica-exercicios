#include <afx.h>
#include "..\external_dependency\general_functions.h"

GLint gJanelaPrincipal = 0;
GLint janelaLargura    = 400;
GLint janelaAltura     = 400;
int qtdClicked = 0;
GLenum type = GL_POINTS;


void exercicio6()
{
	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-400.0, 400.0, -400.0, 400.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    SRU();

	//implementation
	glColor3f(0.0, 0.0, 0.0);
	glPointSize(4.0f);
	glLineWidth(4.0f);
	
	//Sua implementacao aqui
	glBegin(GL_POINTS);

	glEnd();

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

	exercicio6();
}

void mouseFunc(int iButton, int iState, int x, int y)
{
	if (iState == GLUT_DOWN && iButton == GLUT_LEFT_BUTTON) 
	{
		

	}
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
    gJanelaPrincipal = glutCreateWindow("Exercicio 6");
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glutDisplayFunc(exercicio6);
    glutKeyboardFunc(keyboardFunc);
	glutMouseFunc(mouseFunc);
	glutMotionFunc(mouseMovement);
	//glutPassiveMotionFunc(void(*func)(int x, int y));
    glutMainLoop();
}