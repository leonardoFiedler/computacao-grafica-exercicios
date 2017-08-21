#include "..\external_dependency\general_functions.h"

GLint gJanelaPrincipal = 0;
GLint janelaLargura    = 400;
GLint janelaAltura     = 400;
int qtdClicked = 0;
GLenum type = GL_POINTS;


void drawLinhaSupEsq()
{
	//Azul
	glColor3f(0.0f, 0.0f, 0.8f);
	glVertex2f(-200.0f, 200.0f);
}

void drawLinhaInfEsq()
{
	//Rosa
	glColor3f(0.8f, 0.0f, 0.8f);
	glVertex2f(-200.0f, -200.0f);
}

void drawLinhaSupDir()
{
	//Amarelo
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(200.0f, 200.0f);
}

void drawLinhaInfDir()
{
	//Vermelho
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(200.0f, -200.0f);
}

void drawPontoInicial()
{
	drawLinhaSupDir();
	drawLinhaSupEsq();
	drawLinhaInfEsq();
	drawLinhaInfDir();
}

void drawLinhasParalelasVerticais()
{
	//Linha da esquerda
	drawLinhaSupEsq();
	drawLinhaInfEsq();

	//Linha da direita
	drawLinhaSupDir();
	drawLinhaInfDir();
}

void drawLinhaParalelaHorizontalCima()
{
	//Linha de cima
	drawLinhaSupEsq();
	drawLinhaSupDir();
}

void drawLinhaParalelaHorizontalBaixo()
{
	//Linha de baixo
	drawLinhaInfEsq();
	drawLinhaInfDir();
}

void drawLineLoop()
{
	//Linha da esquerda
	drawLinhaSupEsq();
	drawLinhaInfEsq();

	//Linha de baixo
	drawLinhaInfEsq();
	drawLinhaInfDir();

	//Linha da direita
	drawLinhaInfDir();
	drawLinhaSupDir();

	//Linha de cima
	drawLinhaSupDir();
	drawLinhaSupEsq();
}

void drawLineStrip()
{
	//Linha da direita
	drawLinhaInfDir();
	drawLinhaSupDir();

	//Linha de cima
	drawLinhaSupDir();
	drawLinhaSupEsq();
	
	//Linha da esquerda
	drawLinhaSupEsq();
	drawLinhaInfEsq();
}

void drawTriangles() 
{
	drawLinhaInfDir();
	drawLinhaSupEsq();
	drawLinhaSupDir();
}

void drawTriangulesFan() 
{
	drawTriangles();

	drawLinhaInfDir();
	drawLinhaSupEsq();
	drawLinhaInfEsq();
}

void drawTriangulesSemParteBaixo()
{
	drawLinhaSupEsq();
	drawLinhaSupDir();
	drawLinhaInfDir();

	drawLinhaInfEsq();
	drawLinhaSupEsq();
	drawLinhaSupDir();
}

void drawTriangulesStrip()
{
	drawLinhaSupEsq();
	drawLinhaSupDir();
	drawLinhaInfDir();

	drawLinhaSupDir();
	drawLinhaInfEsq();
	drawLinhaSupEsq();
}

void drawTriangulesSemParteCima()
{
	drawLinhaSupDir();
	drawLinhaInfDir();
	drawLinhaInfEsq();
	
	drawLinhaSupEsq();
	drawLinhaInfDir();
	drawLinhaInfEsq();
}

void drawQuads()
{
	drawLinhaSupDir();
	drawLinhaInfDir();
	drawLinhaInfEsq();
	drawLinhaSupEsq();
}

void exercicio5()
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
	
	glBegin(type);

	switch (qtdClicked)
	{
		case 0:
		{
			drawPontoInicial();
			break;
		}

		case 1:
		{
			drawLinhasParalelasVerticais();
			break;
		}

		case 2:
		{
			drawLineLoop();
			break;
		}

		case 3:
		{
			drawLineStrip();
			break;
		}

		case 4:
		{
			drawTriangles();
			break;
		}

		case 5:
		{
			drawTriangulesFan();
			break;
		}

		case 6:
		{
			drawTriangulesSemParteBaixo();
			break;
		}

		case 7:
		{
			drawTriangulesStrip();
			break;
		}

		case 8:
		{
			drawTriangulesSemParteCima();
			break;
		}

		case 9:
		case 10:
		case 11:
		{
			drawQuads();
			break;
		}

		

	}
	
	glEnd();


    glutSwapBuffers();
}

void keyboardFunc(UCHAR key, int x, int y)
{
	switch (key)
	{
		case 'D':
		case 'd':
		{
			qtdClicked++;
			break;
		}
	}

	if (qtdClicked <= 0)
	{
		type = GL_POINTS;
	}
	else if (qtdClicked == 1)
	{
		type = GL_LINES;
	}
	else if (qtdClicked == 2)
	{
		type = GL_LINE_LOOP;
	}
	else if (qtdClicked == 3)
	{
		type = GL_LINE_STRIP;
	}
	else if (qtdClicked == 4) 
	{
		type = GL_TRIANGLES;
	}
	else if (qtdClicked == 5)
	{
		type = GL_TRIANGLE_FAN;
	}
	else if (qtdClicked == 6)
	{
		type = GL_TRIANGLES;
	}
	else if (qtdClicked == 7)
	{
		type = GL_TRIANGLE_STRIP;
	}
	else if (qtdClicked == 8)
	{
		type = GL_TRIANGLES;
	}
	else if (qtdClicked == 9)
	{
		type = GL_QUADS;
	}
	else if (qtdClicked == 10)
	{
		type = GL_QUAD_STRIP;
	}
	else if (qtdClicked == 11)
	{
		type = GL_POLYGON;
	}
	else {
		qtdClicked = 0;
		type = GL_POINTS;
	}

	exercicio5();
}

int main(int argc, TCHAR* argv[], TCHAR* envp[])
{
    glutInit(&argc, (char **)argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(300, 250);
    glutInitWindowSize(janelaLargura, janelaAltura);
    gJanelaPrincipal = glutCreateWindow("Exercicio 5");
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glutDisplayFunc(exercicio5);
	glutKeyboardFunc(keyboardFunc);
    glutMainLoop();
}