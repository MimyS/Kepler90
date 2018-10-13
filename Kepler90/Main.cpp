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
	/*Inicia a GLUT para que recursos computacionais sejam disponivilizados para este programa*/
	glutInit(&argc, argv);

	/*Iniciar o buffer de memoria para armazenar a imagem GLUT DOUBLE*/
	glutInitDisplayMode(GLUT_SINGLE);

	/*Tamanho da janela principal*/
	glutInitWindowSize(700, 700);

	/*Coordenadas de tela inicial da janela do OpenGL*/
	glutInitWindowPosition(350, 50);

	/*Apresenta a janela na tela*/
	glutCreateWindow("Emily - Kepler 90");

	/*Funcao que inicia o processo de renderizacao*/
	glutDisplayFunc(drawScene);

	/*Habilitar o teclado usando recursos da GLUT chama o metodo keyboard_special */
	glutSpecialFunc(&keyboard_special);
	glutKeyboardFunc(&keyboard);
	glutMouseFunc(&mouse);

	/*Coloca esse programa OpenGL em loop até fechamento da janela*/
	glutMainLoop();

	return 0;
}
