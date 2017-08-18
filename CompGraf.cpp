
#include "stdafx.h"
#include "CompGraf.h"
#include "Func.h"
#include <conio.h>


int main(int argc, TCHAR* argv[], TCHAR* envp[])
{
	void(*funcao)(void);
	CString sNomeTela;
	int iOpcao = 0;

	GLfloat fColor1, fColor2, fColor3, fColor4;

	printf("==========Exercicios de Computacao Grafica==========\n");
	printf("\n");
	printf("1) Execicio 1\n");
	printf("2) Execicio 2\n");
	printf("3) Execicio 3\n");
	printf("4) Execicio 4\n");
	printf("5) Execicio 5\n");
	printf("6) Execicio 6\n");
	printf("\n");

	printf("===================================\n");
	printf("=====        Alunos           =====\n");
	printf("===================================\n");
	printf("=====  Flavio Omar Losada     =====\n");
	printf("=====  Jader Antonio Tomelin  =====\n");
	printf("=====  Leonardo Fiedler       =====\n");
	printf("===================================\n");

	iOpcao = _getch();
	
	switch (iOpcao)
	{
		case '1':
		{
			funcao = &exercicio1; 
			sNomeTela = "Exercicio 1";
			fColor1 = 0.86f; fColor2 = 0.86f; fColor3 = 0.86f; fColor4 = 1.0f;
			break;
		}
		case '2':
		{
			funcao = &exercicio2;
			sNomeTela = "Exercicio 2";
			fColor1 = 1.0f; fColor2 = 1.0f; fColor3 = 1.0f; fColor4 = 1.0f;
			break;
		}

		case '3':
		{
			//funcao = &exercicio3;
			sNomeTela = "Exercicio 3";
			fColor1 = 1.0f; fColor2 = 1.0f; fColor3 = 1.0f; fColor4 = 1.0f;
			break;
		}

		case '4':
		{
			//funcao = &exercicio4;
			sNomeTela = "Exercicio 4";
			fColor1 = 1.0f; fColor2 = 1.0f; fColor3 = 1.0f; fColor4 = 1.0f;
			break;
		}

		case '5':
		{
			//funcao = &exercicio5;
			sNomeTela = "Exercicio 5";
			fColor1 = 1.0f; fColor2 = 1.0f; fColor3 = 1.0f; fColor4 = 1.0f;
			break;
		}

		case '6':
		{
			//funcao = &exercicio6;
			sNomeTela = "Exercicio 6";
			fColor1 = 1.0f; fColor2 = 1.0f; fColor3 = 1.0f; fColor4 = 1.0f;
			break;
		}
	}

	glutInit(&argc, (char **)argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(300, 250);
	glutInitWindowSize(janelaLargura, janelaAltura);
	gJanelaPrincipal = glutCreateWindow(sNomeTela);
	inicializacao(fColor1, fColor2, fColor3, fColor4);
	glutDisplayFunc(funcao);
	glutKeyboardFunc(keyboardFuncExe2);
	glutMainLoop();

}
