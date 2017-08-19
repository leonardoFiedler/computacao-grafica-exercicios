#include "..\external_dependency\general_functions.h"

GLint gJanelaPrincipal = 0;
GLint janelaLargura = 400;
GLint janelaAltura = 400;

GLdouble left   = -400.0;
GLdouble right  =  400.0;
GLdouble bottom = -400.0;
GLdouble top    =  400.0;

void exercicio2()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(left, right, bottom, top);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	SRU();
	glColor3f(0.0, 0.0, 0.0);
	glPointSize(2.0f);
	glBegin(GL_POINTS);

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

void keyboardFuncExe2(UCHAR key, int x, int y)
{
	switch (key)
	{
		case 'I':
		case 'i':
		{
			if (right >= 100 && top >= 100)
			{
				left += 3;
				right -= 3;
				bottom += 3;
				top -= 3;
			}
			break;
		}

		case 'O':
		case 'o':
		{
			if (right <= 1000 && top <= 1000)
			{
			    left -= 3;
			    right += 3;
			    bottom -= 3;
			    top += 3;
            }
			break;
		}

		case 'E':
		case 'e':
		{
			left += 3;
			right += 3;
			break;
		}

		case 'D':
		case 'd':
		{
			left -= 3;
			right -= 3;
			break;
		}
		
		case 'C':
		case 'c':
		{
			bottom -= 3;
			top -= 3;
			break;
		}
		
		case 'B':
		case 'b':
		{
			bottom += 3;
			top += 3;
			break;
		}
	}

	exercicio2();
}


int main(int argc, TCHAR* argv[], TCHAR* envp[])
{
	glutInit(&argc, (char **)argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(300, 250);
	glutInitWindowSize(janelaLargura, janelaAltura);
	gJanelaPrincipal = glutCreateWindow("Exercicio 2");
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glutDisplayFunc(exercicio2);
	glutKeyboardFunc(keyboardFuncExe2);
	glutMainLoop();
}
