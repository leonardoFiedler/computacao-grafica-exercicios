#include <afx.h>
#include "..\external_dependency\general_functions.h"

using namespace VART;

GLint gJanelaPrincipal = 0;
GLint janelaLargura    = 400;
GLint janelaAltura     = 400;
GLint initialX = 200;
GLint initialY = 200;
GLint posX = 200;
GLint posY = 200;

GLint posXReal = 200;
GLint posYReal = 200;


bool mover = false;
bool estaDentrobBox = true;
bool naoDesenha = false;

Point4D pto1(0, 0, 0);
Point4D pto2(0, 0, 0);
Point4D pto3(0, 0, 0);
Point4D pto4(0, 0, 0);
Point4D ptoCentral(0 ,0 ,0);
BoundingBox bBox(0, 0, 0, 0, 0, 0);

int iTeste = 0;


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
    if (naoDesenha)
    {
        glColor3f(0.0, 1.0, 1.0);
    }
    else
    {
        if (estaDentrobBox)
            glColor3f(0.8, 0.5, 0.7);
        else
            glColor3f(1.0, 0.5, 0.15);
    }
    

	glLineWidth(2.0f);
	double pi = 3.14159265358979;
	glBegin(GL_LINE_LOOP);		
		double theta = pi * (45) / 200;

		double x = 200 * cos(theta);
		double y = 200 * sin(theta);

		glVertex2d(x + posX, y + posY);	
		pto1.SetXY(x + posX, y + posY);
			
		theta = pi * (-45) / 200;

		x = -200 * cos(theta);
		y = -200 * sin(theta);

		glVertex2d(x + posX, y + posY);
		pto2.SetXY(x + posX, y + posY);

		theta = pi * (45) / 200;

		x = -200 * cos(theta);
		y = -200 * sin(theta);

		glVertex2d(x + posX, y + posY);	
		pto3.SetXY(x + posX, y + posY);

		theta = pi * (-45) / 200;

		x = 200 * cos(theta);
		y = 200 * sin(theta);

		glVertex2d(x + posX, y + posY);
		pto4.SetXY(x + posX, y + posY);
		
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

    desenha_circulo(200, 200, 200, 100);

    desenha_circulo(posXReal, posYReal, 50, 30);
    desenha_ponto(posXReal, posYReal);

    ptoCentral.SetXY(posXReal, posYReal);
	bBox.SetBoundingBox(pto3.GetX(), pto3.GetY(), pto3.GetZ(), pto1.GetX(), pto1.GetY(), pto1.GetZ());
	bBox.DrawInstanceOGL();
	glColor3f(0.0, 1.0, 1.0);
    glPointSize(3.0);
	desenha_quadrado(200, 200);

	glutSwapBuffers();
}

void mouseFunc(int iButton, int iState, int x, int y)
{
	initialX = x;
	initialY = y;

	if (iState == GLUT_UP && iButton == GLUT_LEFT_BUTTON) 
	{
		//para voltar ao centro depois de soltar o botao do mouse
		posXReal = posX = 200;
		posYReal = posY = 200;

		initialX = 200;
		initialY = 200;

        estaDentrobBox = true;
        naoDesenha = false;
	}	

	glutPostRedisplay();
}

void mouseMovement(int x, int y)
{
	//Calcular a diferença
	GLint diffX = x - initialX;
	GLint diffY = y - initialY;

	//Jogar isso pro cara que desenha o circulo
	posX += diffX;
	posY -= diffY;

    if (naoDesenha == false)
    {
        posXReal = posX;
        posYReal = posY;
    }

	//atualizar os valores do anterior
	initialX = x;
	initialY = y;

    ptoCentral.SetXY(posX, posY);

    if (bBox.testPoint(ptoCentral))
    {
        estaDentrobBox = true;
    }
    else
    {
        estaDentrobBox = false;
        double result = pow((posX - 200), 2) + pow((posY - 200), 2);
        if (result > pow(200, 2)) {
            naoDesenha = true;
        }
        else {
            naoDesenha = false;
        }
    }

    if (iTeste >= 100)
    {
        iTeste = 0;
    }

	glutPostRedisplay();
}

int main(int argc, TCHAR* argv[], TCHAR* envp[])
{
	glutInit(&argc, (char **)argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(300, 250);
    glutInitWindowSize(janelaLargura, janelaAltura);
    gJanelaPrincipal = glutCreateWindow("Exercicio 7");
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    bBox.ConditionalUpdate(ptoCentral);
    bBox.ProcessCenter();
    glutDisplayFunc(exercicio7);
	glutMouseFunc(mouseFunc);
	glutMotionFunc(mouseMovement);
    glutMainLoop();
}