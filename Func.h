
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
	glPointSize(3.0f);
	glBegin(GL_POINTS);

	GLfloat twicePi = 2 * 3.141592;

	for (int i = 0; i < 72; i++) {

		float x = 100.0f * cos(i *  twicePi / 72);
		float y = 100.0f * sin(i * twicePi / 72);

		glVertex2f(x, y);
	}
	glEnd();

	glutSwapBuffers();
}