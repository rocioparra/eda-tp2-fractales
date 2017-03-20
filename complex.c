#include "complex.h"
#include <math.h>


complex_t complexSum (complex_t x1, complex_t x2)
{
	complex_t result = { x1.re + x2.re, x1.im + x2.im };
	// suma de numeros complejos: (a + bi) + (c + di) = (a + b) + (c + d)i

	return result;
}


complex_t complexSquare (complex_t x)
{
	complex_t result = { x.re * x.re - x.im * x.im, 2 * x.re * x.im };
	/* cuadrado de un numero complejo de forma 're + im*i':
	 * - parte real: re^2 - im^2
	 * - parte imaginaria: 2 * re * im  */

	return result;
}


float complexMod(complex_t x)
/*	Modulo de un numero complejo de forma re + im*i:
 *	mod(re + im*i) = (re^2 + im^2) ^ (1/2) <=>
 *	mod(re + im*i) = (re*re + im*im) ^ (1/2)			*/
{
	return sqrt(x.re*x.re + x.im*x.im);
}