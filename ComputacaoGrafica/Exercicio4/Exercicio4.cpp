#include "..\external_dependency\general_functions.h"

GLint gJanelaPrincipal = 0;
GLint janelaLargura    = 400;
GLint janelaAltura     = 400;

GLdouble posX = 0;
GLdouble raio = 0;
GLdouble angulo = 0;

GLdouble left = -400.0;
GLdouble right = 400.0;
GLdouble bottom = -400.0;
GLdouble top = 400.0;

void exercicio4()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
	gluOrtho2D(left, right, bottom, top);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    SRU();

    //implementation
	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(2.0f);
	float pi = 3.14159265358979f;
	glBegin(GL_LINES);

		float theta = pi * (45.0f + angulo) / 180.0f;
		float x = (100.0f + raio) * cos(theta);
		float y = (100.0f + raio) * sin(theta);
		glVertex2f(posX + 0.0f, 0.0f);
		glVertex2f(posX + x + raio, y + raio);
		
	glEnd();

	

    glutSwapBuffers();
}

void keyboardFunc(UCHAR key, int x, int y)
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
		case 'Q':
		case 'q':
		{
			posX--;			
			break;
		}
		case 'W':
		case 'w':
		{
			posX++;			
			break;
		}
		case 'A':
		case 'a':
		{
			raio--;
			break;
		}
		case 'S':
		case 's':
		{
			raio++;
			break;
		}
		case 'Z':
		case 'z':
		{
			angulo--;
			break;
		}
		case 'X':
		case 'x':
		{
			angulo++;
			break;
		}
	}

	exercicio4();
}

int main(int argc, TCHAR* argv[], TCHAR* envp[])
{
    glutInit(&argc, (char **)argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(300, 250);
    glutInitWindowSize(janelaLargura, janelaAltura);
    gJanelaPrincipal = glutCreateWindow("Exercicio 4");
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glutDisplayFunc(exercicio4);
	glutKeyboardFunc(keyboardFunc);
    glutMainLoop();
}