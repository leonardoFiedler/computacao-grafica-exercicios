#include <afxtempl.h>
#include "..\external_dependency\general_functions.h"

GLint gJanelaPrincipal = 0;
GLint janelaLargura    = 400;
GLint janelaAltura     = 400;
CArray<CPoint> ListaPontos;
CPoint* pontoSelecionado = nullptr;

int xAnterior = 0;
int yAnterior = 0;

void splinePosition(GLdouble t, GLdouble& x, GLdouble& y)
{
	//Calculo da Spline com base na teoria de Bezier
	double diff = 1.0 - t;

	x = pow(diff, 3) * ListaPontos[3].x + 3 * t * pow(diff, 2) * ListaPontos[2].x + 3 * pow(t, 2) * diff * ListaPontos[1].x + pow(t, 3) * ListaPontos[0].x;
	y = pow(diff, 3) * ListaPontos[3].y + 3 * t * pow(diff, 2) * ListaPontos[2].y + 3 * pow(t, 2) * diff * ListaPontos[1].y + pow(t, 3) * ListaPontos[0].y;
}

void exercicio6()
{
	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-400.0, 400.0, -400.0, 400.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    SRU();

	glColor3f(0.0f, 1.0f, 1.0f);
	glLineWidth(3.0f);

	//desenhar o poliedro
	glBegin(GL_LINE_STRIP);
	for (INT_PTR iIndex = 0; iIndex < ListaPontos.GetSize(); iIndex++)
        glVertex2f(ListaPontos[iIndex].x, ListaPontos[iIndex].y);
	glEnd();
	//desenhar o poliedro

	//Desenhar o ponto selecionado
	glColor3f(1.0f, 0.0f, 0.0f);
	glPointSize(8.0f);
	glBegin(GL_POINTS);
	glVertex2f(pontoSelecionado->x, pontoSelecionado->y);
	glEnd();
	//Desenhar o ponto selecionado

	//desenhar a Spline
	glColor3f(1.0f, 1.0f, 0.0f);
	glLineWidth(2.0f);
	glBegin(GL_LINE_STRIP);
	
	for (int t = 0; t <= 40; t++){
		GLdouble xRet = 0;
		GLdouble yRet = 0;

		splinePosition(t * 0.025, xRet, yRet); //multiplicar o valor de t por 1/40 para poder ter um intervalo de t entre 0...1
		glVertex2f(xRet, yRet);
	}
	glEnd();
	//desenhar a Spline

	glutSwapBuffers();
}

void keyboardFunc(UCHAR key, int x, int y)
{
	switch (key)
	{
		case '1': pontoSelecionado = &ListaPontos[3]; break;

		case '2': pontoSelecionado = &ListaPontos[2]; break;

		case '3': pontoSelecionado = &ListaPontos[1]; break;

		case '4': pontoSelecionado = &ListaPontos[0]; break;
		
		default: break; //nada a fazer
	}

	glutPostRedisplay();
}

void mouseFunc(int iButton, int iState, int x, int y)
{
	//Caso der um clique simples...
	xAnterior = x;
	yAnterior = y;

	glutPostRedisplay();
}

void mouseMovement(int x, int y)
{
	//Calculando a diferença atual da posição atual do mouse pra posição anterior
	GLdouble mouseDiffX = x - xAnterior;
	GLdouble mouseDiffY = y - yAnterior;

	//Com base nisso, trocar os valores do ponto selecionado
	pontoSelecionado->SetPoint(pontoSelecionado->x + mouseDiffX, pontoSelecionado->y - mouseDiffY);

	//e atualizando os valores de X e Y anteriores
    xAnterior = x;
    yAnterior = y;

	glutPostRedisplay();
}

int main(int argc, TCHAR* argv[], TCHAR* envp[])
{
    ListaPontos.SetSize(4);

    CPoint p1, p2, p3, p4;

	//Definindo os pontos iniciais
    p1.x =  100; p1.y = -100;
    p2.x =  100; p2.y =  100;
    p3.x = -100; p3.y =  100;
    p4.x = -100; p4.y = -100;

	//Por praticidade, guardar todos numa lista
    ListaPontos[0] = p1;
    ListaPontos[1] = p2;
    ListaPontos[2] = p3;
    ListaPontos[3] = p4;

	//definindo como ponto inicial o p4
	pontoSelecionado = &ListaPontos[3];

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
    glutMainLoop();
}