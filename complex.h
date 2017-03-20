#ifndef COMPLEX_H
#define COMPLEX_H

/*	

		Instituto Tecnológico de Buenos Aires
 		22.08 - Algoritmos y Estructuras de Datos
 
 		Trabajo Práctico n° 2
 		Gráficos, simulación, recursividad
 
 		Grupo 3:	- Mestanza, Nicolás - legajo 57521  
 					- Müller, Malena	- legajo 
 					- Parra, Rocío		- legajo 57669
 		
 		Este archivo contiene funciones para trabajar con numeros complejos,
 	asi como el tipo de dato complex_t que las mismas utilizan.
 
 */



//Tipo de dato numero complejo (numeros de forma 're + im*i', donde re e im son reales)
typedef struct
{
	float re;	//parte real 
	float im;	//parte compleja 
}complex_t;


complex_t complexSum (complex_t, complex_t);
/* Suma de dos numeros complejos
 * Recibe los numeros que se quieren sumar, devuelve el resultado */

complex_t complexSquare(complex_t);
/* Cuadrado de complejos
 * Devuelve el cuadrado del numero recibido */

float complexMod(complex_t);
//Calcula el modulo de un numero complejo


#endif //COMPLEX_H 