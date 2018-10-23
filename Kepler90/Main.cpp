/*
Departamento de Ciência da Computação
Princípio da Computação Gráfica - 2/2018
Emily Souza Rodrigues - 15/0009101

Modelo Kepler 90 em OpenGL

Fonte: https://exoplanets.nasa.gov/newworldsatlas/
Page 134 - 25 per page
*/

#include "Kepler90.h"

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

	/*Window setting*/
	glutInitWindowSize(750, 750);
	glutInitWindowPosition(350, 20);
	glutCreateWindow("Emily - Kepler 90");

	glutIdleFunc(animate);

	/*Start rendering*/
	glutDisplayFunc(drawScene);

	/*Window Reshape*/
	glutReshapeFunc(windowReshapeFunc);

	/*Enable keyboard and mouse*/
	glutSpecialFunc(&keyboard_special);
	glutKeyboardFunc(&keyboard);
	glutMouseFunc(&mouse);

	/*Set window background color*/
	glClearColor(0.0f, 0.05f, 0.1f, 1.0f);
	/*Keep the OpenGL program running until the window is closed*/
	glutMainLoop();

	return 0;
}
