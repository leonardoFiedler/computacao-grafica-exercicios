/// \file exe00.cpp
/// \brief Implementation file for "CG-N2_HelloWorld".
/// \version $Revision: 1.0 $
/// \author Dalton Reis.
/// \date 03/05/11.

/// Obs.: o uso de variaveis globais foram usadas por questoes didaticas mas nao sao recomendas para aplicacoes reais.

#if defined(__APPLE__) || defined(MACOSX)
    #include <OpenGL/gl.h>
    #include <GLUT/glut.h>
#endif
#ifdef WIN32
    #include <windows.h>
    #include <GL/gl.h>
    #include <GL/glut.h>
#endif
#include <math.h>
#include "constantes.h"

GLint gJanelaPrincipal = 0;
GLint janelaLargura  = 400, janelaAltura = 400;
GLfloat ortho2D_minX = -400.0f, ortho2D_maxX =  400.0f, ortho2D_minY = -400.0f, ortho2D_maxY =  400.0f;

void inicializacao (void) {
	glClearColor(0.86f,0.86f,0.86f,1.0);
}

void exibicaoPrincipal(void) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluOrtho2D(ortho2D_minX, ortho2D_maxX, ortho2D_minY, ortho2D_maxY);
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity ();
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
	SRU();
    
    //radiano = grau * PI / 180
    
    //raio = 100
    //72 pontos
    //diametro = 2.r = 200
    //perimetro = 2 * PI * r = 628,3
    //Angulo - 90 graus = 1.57 radianos
    
    glColor3f(0.0, 0.0, 0.0);
    glPointSize(3.0f);
    glBegin(GL_POINTS);

    GLfloat twicePi = 2 * 3.141592;
    
    for(int i = 0; i < 72;i++) {
        
        float x = 100.0f * cos(i *  twicePi / 72);
        float y = 100.0f * sin(i * twicePi / 72);
        
        cout << "x "
        glVertex2f(x,y);
    }
    glEnd();
	
	glutSwapBuffers();
}

int main (int argc, const char * argv[]) {
    glutInit(&argc, (char **)argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition (300, 250);
	glutInitWindowSize (janelaLargura, janelaAltura);
	gJanelaPrincipal = glutCreateWindow("CG-N2_HelloWorld");
    inicializacao();
    glutDisplayFunc (exibicaoPrincipal);
    glutMainLoop();
	
    return 0;
}
