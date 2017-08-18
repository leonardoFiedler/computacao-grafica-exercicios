
void inicializacao(float f1, float f2, float f3, float f4)
{
	glClearColor(f1, f2, f3, f4);
}

void exercicio1(void) 
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-400.0, 400.0, -400.0, 400.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	CCGUtils::SRU();
	glColor3f(0.0, 0.0, 0.0);
	glPointSize(2.0f);
	glBegin(GL_POINTS);

	GLfloat twicePi = 2 * 3.141592;
	glColor3f(0.0, 0.0, 1.0);

	for (int i = 0; i < 72; i++) {

		float x = 100.0f * cos(i *  twicePi / 72);
		float y = 100.0f * sin(i * twicePi / 72);

		glVertex2f(x, y);
	}
	glEnd();

	glutSwapBuffers();
}


//VARIAVEIS DO EXERCICIO 2

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

	CCGUtils::SRU();
	glColor3f(0.0, 0.0, 0.0);
	glPointSize(2.0f);
	glBegin(GL_POINTS);

	GLfloat twicePi = 2 * 3.141592;

	for (int i = 0; i < 72; i++) 
	{
		float x = 100.0f * cos(i *  twicePi / 72);
		float y = 100.0f * sin(i * twicePi / 72);

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
		left   += 3; 
		right  -= 3; 
		bottom += 3; 
		top    -= 3;
		break;
	case 'O':
	case 'o':
		left   -= 3; 
		right  += 3; 
		bottom -= 3; 
		top    += 3;
		break;
	case 'E':
	case 'e':
		left  += 3; 
		right += 3;
		break;
	case 'D':
	case 'd':
		left  -= 3; 
		right -= 3;
		break;
	case 'C':
	case 'c':
		bottom -= 3; 
		top    -= 3;
		break;
	case 'B':
	case 'b':
		bottom += 3; 
		top    += 3;
		break;
	}

	exercicio2();
}