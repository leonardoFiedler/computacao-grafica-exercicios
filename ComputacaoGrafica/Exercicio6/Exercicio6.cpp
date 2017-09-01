#include <afxtempl.h>
#include "..\external_dependency\general_functions.h"

GLint gJanelaPrincipal = 0;
GLint janelaLargura    = 400;
GLint janelaAltura     = 400;
GLenum type = GL_POINTS;
CArray<CPoint> ListaPontos;

int xAnterior = 0;
int yAnterior = 0;
bool bMoveu = false;

CArray<double>& SPLINE_Inter(CPoint A, CPoint B, GLint t, GLboolean desenha, GLint qtdPontos)
{
    CArray<double> aPontos;
    aPontos.SetSize(2);
    aPontos[0] = A.x + (B.x - A.x) * t / qtdPontos;
    aPontos[1] = A.y + (B.y - A.y) * t / qtdPontos;

    if (desenha)
    {
        glColor3f(0.0f, 0.0f, 1.0f);
        glRectd(aPontos[0] - 2, aPontos[1] -2, 4, 4);
    }

    return aPontos;
}

void SPLINE_DESENHA(GLint qtdPontos)
{
    if (bMoveu)
    {
        
    }
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

	glColor3f(0.0, 0.0, 0.0);
	glPointSize(4.0f);
	//glLineWidth(4.0f);
	
	glBegin(GL_POINTS);

    for (INT_PTR iIndex = 0; iIndex < ListaPontos.GetSize(); iIndex++)
    {
        glVertex2f(ListaPontos[iIndex].x, ListaPontos[iIndex].y);
    }
    
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

    p1.x = -150;
    p1.y =  150;

    p2.x = -150;
    p2.y = -150;

    p3.x =  150;
    p3.y = -150;

    p4.x = 125;
    p4.y = 125;

    ListaPontos[0] = p1;
    ListaPontos[1] = p2;
    ListaPontos[2] = p3;
    ListaPontos[3] = p4;

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