#if defined(__APPLE__) || defined(MACOSX)
#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#endif

#include <windows.h>
#include <GL/gl.h>
#include "glut.h"
#include <math.h>

#include "vart\boundingbox.h"
#include "vart\camera.h"
#include "vart\color.h"
#include "vart\mathdef.h"
#include "vart\point4d.h"
#include "vart\time.h"
#include "vart\transform.h"


void SRU()
{
	glDisable(GL_TEXTURE_2D);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisable(GL_LIGHTING);

	// eixo x
	glColor3f(1.0f, 0.0f, 0.0f);
	glLineWidth(1.0f);
	glBegin(GL_LINES);
	glVertex2f(-200.0f, 0.0f);
	glVertex2f(200.0f, 0.0f);
	glEnd();

	// eixo y
	glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_LINES);
	glVertex2f(0.0f, -200.0f);
	glVertex2f(0.0f, 200.0f);
	glEnd();
}