#include "mandelbrot.h"
#include "complex.h"
#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\bitmap.h>

#define MAX(x,y)	( (x) >= (y) ? (x) : (y) )	//macro: devuelve el mayor de los parametros

unsigned int mandelbrotDepth(complex_t z, unsigned int n, float maxMod);	//predeclaracion


int drawMandelbrot (unsigned int xMax, unsigned int yMax, mapCoordinates_t * map, unsigned int nMax)
{
	float gReal, gImag;			//granuralidad en ambos ejes
	unsigned int depth, i, j;	//profundidad en el set de mandelbrot // indices
	complex_t z;				//cada numero que se analizara
	mapCoordinates_t auxMap;	//si no se recibe un mapa, se utilizara este
	float maxMod;				//modulo maximo que se puede alcanzar sin que se considere que diverge un z

	if (map == NULL)					//si no recibio un mapa, carga valores default
	{
		map = &auxMap;
		auxMap.x0=-1; auxMap.xf=1;
		auxMap.y0=-1; auxMap.yf=1;
	}
	else if (map->x0 > map->xf || map->y0 > map-> yf)
	//verifica que los valores recibidoe en el mapa sean validos
	{
		return false;
	}

	gReal = (map->xf - map->x0) / xMax;	//calcular la granuralidad para ambos ejes
	gImag = (map->yf - map->y0) / yMax;
	maxMod = MAX(map->xf-map->x0, map->yf-map->y0);
	//si en alguna iteracion de mandelbrot se supera maxMod, se considera que diverge

	for ( i = 0; i < xMax; i++)			//barrer el eje x
	{
		z.re = map->x0 + i*gReal;		

		for ( j = 0; j < yMax; j++ )	//barrer el eje y
		{
			
			z.im = map->y0 + j*gImag;	
			depth = mandelbrotDepth(z, nMax, maxMod);  //obtener profundidad
			al_put_pixel(i, j, al_map_rgb(0,0,depth)); //pintar el pixel en tonos de azul/negro segun la prof.
		}
	}
	
	al_flip_display();			//mostrar el resultado
	return true;				//devolver que no hubo error
}




unsigned int mandelbrotDepth(complex_t z, unsigned int n, float maxMod)
/* Se devuelve el n recibido menos el maximo numero de veces que se puede evaluar la funcion:
			f(n) = f(n-1)^2 + z, f(0) = 0
	de forma tal que el modulo de f(n) sea menor que el recibido (maxMod), donde se considera que z diverge 
	P. ej, si se recibe n=10 y la funcion diverge en la tercera iteracion, se devolvera 10-3 = 7 */
{
	complex_t sum = {0,0};		//f(0) = 0
	float modulus = 0;			//mod(0 + 0*i)= 0

	while (n>0 && modulus< maxMod)	//repetir hasta que se obtenga que z diverge o se 
	{
		sum = complexSquare(sum);   //f(n-1) = f(n)^2 ...
		sum = complexSum(sum,z);	//... + z
		modulus = complexMod(sum);	//obtener el nuevo modulo
		n--;						//indicar que se pudo hacer una iteracion mas
	}

	return n;
}