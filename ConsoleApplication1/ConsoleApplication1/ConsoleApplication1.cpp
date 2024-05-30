#include <GL/glut.h>
#include <stdio.h>
#include <stdio.h>
#include <cmath>
#define BASE_WIDTH 20.0f
#define BASE_HEIGHT 0.5f
#define BASE_DEPTH 60.0f
#define PI 3.1415926535897932384626433832795
float cameraX = 5.0f;
float cameraY = 5.0f;
float cameraZ = 5.0f;
GLfloat angle = 60.0f;
GLfloat angle1 = 90.0f;
GLfloat angle2 = 70.0f;
int rotX = 30;
int rotY = 0;
int obsZ = 180;
// Função de inicialização

void init() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Define a cor de fundo como preto
	glEnable(GL_DEPTH_TEST); // Habilita teste de profundidade para ocultação de superfícies
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);


}
void DrawHalfSphereBottom(float radius, int slices, int stacks) {

	for (int i = 0; i < stacks / 2; ++i) {
		float lat0 = PI * (-0.5f + static_cast<float>(i) / stacks);
		float lat1 = PI * (-0.5f + static_cast<float>(i + 1) / stacks);
		float y0 = sin(lat0);
		float y1 = sin(lat1);
		float r0 = cos(lat0);
		float r1 = cos(lat1);

		glBegin(GL_TRIANGLE_STRIP);
		for (int j = 0; j <= slices; ++j) {
			float lng = 2 * PI * static_cast<float>(j) / slices;
			float x = cos(lng);
			float z = sin(lng);

			glNormal3f(x * r0, y0, z * r0);
			glVertex3f(x * r0 * radius, y0 * radius, z * r0 * radius);

			glNormal3f(x * r1, y1, z * r1);
			glVertex3f(x * r1 * radius, y1 * radius, z * r1 * radius);
		}
		glEnd();
	}
}
void DefineIluminacao(void)
{
	GLfloat luzAmbiente[4] = { 0.3,0.3,0.3,1.0 };
	GLfloat luzDifusa[4] = { 0.3,0.3,0.3,1.0 };
	GLfloat luzEspecular[4] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat posicaoLuz[4] = { 0.0, 50.0, 50.0, 1.0 };
	GLfloat especularidade[4] = { 1.0,1.0,1.0,1.0 };
	GLint especMaterial = 60;
	glMaterialfv(GL_FRONT, GL_SPECULAR, especularidade);
	glMateriali(GL_FRONT, GL_SHININESS, especMaterial);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);
	glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa);
	glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular);
	glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz);
}

// Função de renderização
void render() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Limpa o buffer de cores e de profundidade
	DefineIluminacao();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Configura a câmera
	gluLookAt(cameraX, cameraY, cameraZ,  // Posição da câmera
		0.0f, 0.0f, 0.0f,          // Ponto de visualização
		0.0f, 1.0f, 0.0f);         // Vetor de orientação da câmera

								   //Torre direita
	glPushMatrix();
	glTranslatef(-1.0f, 14.0f, -20.0f);
	glScalef(5.0f, 32.0f, 10.0f);
	glColor3f(0.9f, 0.9f, 0.9f);
	glutSolidCube(1.0f);
	glPopMatrix();

	//Torre esquerda
	glPushMatrix();
	glTranslatef(-8.0f, 14.0f, -20.0f);
	glScalef(5.0f, 32.0f, 10.0f);
	glColor3f(0.9f, 0.9f, 0.9f);
	glutSolidCube(1.0f);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-5.0f, 15.0f, -20.0f);
	glScalef(3.0f, 3.0f, 3.0f);
	glColor3f(0.9f, 0.9f, 0.9f);
	glutSolidCube(1.0f);
	glPopMatrix();

	//Base de baixo
	glPushMatrix();
	glTranslatef(0.0f, -2.0f, 0.0f);
	glColor3f(0.9f, 0.9f, 0.9f);
	glScalef(BASE_DEPTH, BASE_HEIGHT, BASE_WIDTH);
	glutSolidCube(1.0f);
	glPopMatrix();

	// Base de cima
	glPushMatrix();
	glTranslatef(0.0f, 2.0f, 0.0f);
	glColor3f(0.9f, 0.9f, 0.9f);
	glScalef(BASE_DEPTH, BASE_HEIGHT, BASE_WIDTH);
	glutSolidCube(1.0f);
	glPopMatrix();

	glColor3f(0.4f, 0.4f, 0.4f);
	glScalef(57.0f, 4.0f, 17.0f);
	glutSolidCube(1.0f);

	// Senado 
	glPushMatrix();
	glTranslatef(-0.32f, 0.5, -0.0f);
	glColor3f(0.9f, 0.9f, 0.9f);
	glScalef(0.4f, 3.4f, 1.1f);
	glutSolidSphere(1 / PI, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.0429f, -0.5f, 0.8f);
	glColor3f(0.9f, 0.9f, 0.9f);
	glScalef(0.1342, 0.3, 2.6);
	glutSolidCube(0.3f);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.083f, 0.01f, 0.87f);
	glColor3f(0.9f, 0.9f, 0.9f);
	glRotatef(angle, 1.0f, 0.0f, 0.0f);
	glScalef(0.1342, 0.2, 4.1);
	glutSolidCube(0.3f);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.078f, -0.2f, -0.7f);
	glColor3f(0.9f, 0.9f, 0.9f);
	glRotatef(angle, 1.0f, 0.0f, 0.0f);
	glScalef(0.12, 0.2, 2.4);
	glutSolidCube(0.3f);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.078f, -0.2f, -0.7f);
	glColor3f(0.9f, 0.9f, 0.9f);
	glRotatef(angle, 1.0f, 0.0f, 0.0f);
	glScalef(0.12, 0.2, 2.4);
	glutSolidCube(0.3f);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.078f, 0.09f, -1.0f);
	glColor3f(0.9f, 0.9f, 0.9f);
	glScalef(0.12, 0.2, 0.9);
	glutSolidCube(0.3f);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.1f, -0.1f, -0.5f);
	glColor3f(0.9f, 0.9f, 0.9f);
	glScalef(0.05, 6.7, 8.0);
	glutSolidCube(0.1f);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.06f, -0.1f, -0.5f);
	glColor3f(0.9f, 0.9f, 0.9f);
	glScalef(0.05, 6.7, 8.0);
	glutSolidCube(0.1f);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.19f, 0.0f, -1.1f);
	glColor3f(0.9f, 0.9f, 0.9f);
	glRotatef(angle1, 0, 1, 0);
	glRotatef(angle2, 1.0f, 0.0f, 0.0f);
	glScalef(0.7, 0.3, 3.0);
	glutSolidCube(0.3f);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.234f, -0.2f, -1.1f);
	glColor3f(0.9f, 0.9f, 0.9f);
	glRotatef(angle1, 0, 1, 0);
	glRotatef(-angle2, 1.0f, 0.0f, 0.0f);
	glScalef(0.7, 0.3, 1.4);
	glutSolidCube(0.3f);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0f, -2.0f, 0.0f);
	glColor3f(0.0f, 0.9f, 0.0f);
	glScalef(80.0f, BASE_HEIGHT, 90.0f);
	glutSolidCube(1.0f);
	glPopMatrix();

	glTranslatef(0.32f, 1.5f, 0.0f);
	glColor3f(0.9f, 0.9f, 0.9f);
	glScalef(0.5f, 3.4f, 1.1f);
	DrawHalfSphereBottom(1 / PI, 50, 50);
	glFlush();

	glutSwapBuffers();
	glEnd();



}

// Função de redimensionamento da janela
void reshape(int width, int height) {
	glViewport(0, 0, width, height); // Define a janela de visualização
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, (float)width / (float)height, 0.1f, 100.0f); // Configura a perspectiva
	glMatrixMode(GL_MODELVIEW);
}

// Função para capturar e processar eventos do teclado
void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 'q': // Movimento para cima
		cameraY += 1.0f;
		break;
	case 'Q': // Movimento para cima
		cameraY += 1.0f;
		break;
	case 'e': // Movimento para baixo
		cameraY -= 1.0f;
		break;
	case 'E': // Movimento para baixo
		cameraY -= 1.0f;
		break;
	case 'a': // Movimento para a esquerda
		cameraX -= 1.0f;
		break;
	case 'A': // Movimento para a esquerda
		cameraX -= 1.0f;
		break;
	case 'd': // Movimento para a direita
		cameraX += 1.0f;
		break;
	case 'D': // Movimento para a direita
		cameraX += 1.0f;
		break;
	case 'w': // Movimento para frente
		cameraZ -= 1.0f;
		break;
	case 'W': // Movimento para frente
		cameraZ -= 1.0f;
		break;
	case 's': // Movimento para trás
		cameraZ += 1.0f;
		break;
	case 'S': // Movimento para trás
		cameraZ += 1.0f;
		break;
	}
	glutPostRedisplay(); // Marca a janela como necessitando de redesenho
}

int main(int argc, char** argv) {
	int Window, i = 0;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 600); // Tamanho da janela
	glutCreateWindow("Congresso Nacional");
	glutDisplayFunc(render); // Função de renderização
	glutReshapeFunc(reshape); // Função de redimensionamento
	glutKeyboardFunc(keyboard); // Função do teclado
	init(); // Inicialização
	glEnable(GL_DEPTH_TEST);
	glutMainLoop(); // Loop principal do GLUT
	return 0;
	if (!Window) {
		printf("Failed to create window\n");
		return -1;
	}

	glClearColor(0.0, 0.0, 0.0, 1.0);
	gluOrtho2D(-1, 1, -1, 1);
	glEnable(GL_DEPTH_TEST);
	glutDisplayFunc(render);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}