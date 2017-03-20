#ifndef MANDELBROT_H
#define MANDELBROT_H

/*	

		Instituto Tecnológico de Buenos Aires
 		22.08 - Algoritmos y Estructuras de Datos
 
 		Trabajo Práctico n° 2
 		Gráficos, simulación, recursividad
 
 		Grupo 3:	- Mestanza, Nicolás - legajo 57521  
 					- Müller, Malena	- legajo 
 					- Parra, Rocío		- legajo 57669
 		
 		Las funciones contenidas en este archivo permiten realizar una representacion
	grafica del set de Mandelbrot, indicando con distintos tonos de azul cuántas veces
	se puede evaluar para un cierto z (complejo) la funcion:
		
		f(n) = f(n-1)^2 + z, f(0) = 0,

	sin que el modulo de f(n) supere un máximo dado.
 
 */




//	Tipo de datos mapa: coordenadas iniciales y finales de un plano 
//	En este caso, se utilizaran para el plano imaginario
typedef struct
{
	float x0, xf, y0, yf;
} mapCoordinates_t ;


 int drawMandelbrot (unsigned int xMax, unsigned int yMax, mapCoordinates_t * map, unsigned int nMax);
/*  Representa la profundidad en el set de Mandelbrot de los z contenidos en el plano imaginario 'map', 
 * en un display de ancho xMax y altura yMax. Se considerara que z diverge cuando su modulo supera el 
 * mayor de los lados del plano. La maxima profundidad considerada sera 'nMax'. */


#endif //MANDELBROT_H