#include <afxtempl.h>
#include "..\external_dependency\general_functions.h"

GLint gJanelaPrincipal = 0;
GLint janelaLargura    = 400;
GLint janelaAltura     = 400;
GLenum type = GL_POINTS;
CArray<CPoint> ListaPontos;
CPoint pontoSelecionado;

int xAnterior = 0;
int yAnterior = 0;
bool bMoveu = false;

void calculaSpline(GLdouble t, GLdouble& x, GLdouble& y)
{
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

	//Desenhar o ponto selecionado
	glColor3f(1.0f, 0.0f, 0.0f);
	glPointSize(8.0f);
	
	glBegin(GL_POINTS);
	glVertex2f(pontoSelecionado.x, pontoSelecionado.y);
	glEnd();

	//desenhar a Spline
	glColor3f(1.0f, 1.0f, 0.0f);
	glLineWidth(2.0f);
	glBegin(GL_LINE_STRIP);
	
	for (int t = 0; t <= 40; t++){
		GLdouble xRet = 0;
		GLdouble yRet = 0;

		calculaSpline(t * 0.025, xRet, yRet);
		glVertex2f(xRet, yRet);
	}
	
	glEnd();

	glutSwapBuffers();
}

void keyboardFunc(UCHAR key, int x, int y)
{
	switch (key)
	{
	case '1':
		pontoSelecionado = ListaPontos[3];
		break;

	case '2':
		pontoSelecionado = ListaPontos[2];
		break;

	case '3':
		pontoSelecionado = ListaPontos[1];
		break;

	case '4':
		pontoSelecionado = ListaPontos[0];
		break;
	default:
		break;
	}

	glutPostRedisplay();
}

void mouseFunc(int iButton, int iState, int x, int y)
{
	if (iState == GLUT_DOWN && iButton == GLUT_LEFT_BUTTON) 
	{
        if (x != xAnterior || y != yAnterior)
            bMoveu = true;

        for (INT_PTR iIndex = 0; iIndex < ListaPontos.GetCount(); iIndex++)
        {
            CPoint ponto = ListaPontos[iIndex];

            CRect rectPonto;
            rectPonto.SetRect(CPoint(ponto.x - 3, ponto.y - 3), CPoint(ponto.x + 3, ponto.y + 3));
            
            bool bEstaDentro = rectPonto.PtInRect(CPoint(x, y));
            Sleep(0);
        }
	}
    else if (iState == GLUT_UP && iButton == GLUT_LEFT_BUTTON)
    {
        bMoveu = false;
    }

    CString s;
    s = bMoveu ? "Sim\n" : "Não\n";
    TRACE(s);

	glutPostRedisplay();
}

void mouseMovement(int x, int y)
{
    xAnterior = x;
    yAnterior = y;

    CString s;
    s.Format("xAnterior: %d | yAnterior: %d\n", xAnterior, yAnterior);
    TRACE(s);

}

int main(int argc, TCHAR* argv[], TCHAR* envp[])
{
    ListaPontos.SetSize(4);

    CPoint p1, p2, p3, p4;

    p1.x =  100;
    p1.y = -100;

    p2.x =  100;
    p2.y =  100;

    p3.x = -100;
    p3.y =  100;

    p4.x = -100;
    p4.y = -100;

    ListaPontos[0] = p1;
    ListaPontos[1] = p2;
    ListaPontos[2] = p3;
    ListaPontos[3] = p4;

	//definindo como ponto inicial o p4
	pontoSelecionado = p4;

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