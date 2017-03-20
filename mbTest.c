#include <stdio.h>
#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include "mandelbrot.h"

#define WIDTH	640		//tamano del display y del bitmap
#define	HEIGHT	480 



int main (void);

int main (void)
{
	ALLEGRO_DISPLAY * display = NULL;
	ALLEGRO_BITMAP * bitmap = NULL;
	int i; 
	
	if(!al_init())
	{
		fprintf(stderr, "failed to initialize allegro!\n");
		return -1;
   }
	else if (!al_init_primitives_addon())
	{
		fprintf(stderr, "failed to initialize primitives addon!\n");
		return -1;
	}
	else if (!(display = al_create_display(WIDTH, HEIGHT)))
	{
		fprintf(stderr, "failed to create display!\n");
		al_shutdown_primitives_addon();
		return -1;
	}

	bitmap = al_get_backbuffer(display);

	al_clear_to_color(al_map_rgb(0,0,0));
	al_flip_display();

	al_lock_bitmap(bitmap, al_get_bitmap_format(bitmap), ALLEGRO_LOCK_READWRITE);

	drawMandelbrot(WIDTH, HEIGHT, NULL, 255);

	al_unlock_bitmap(bitmap);

	al_flip_display();

	do 
	{
		i = getchar();				//esperar a que el usuario apriete enter
	}while (i != '\n');



	al_destroy_bitmap(bitmap);
	al_destroy_display(display);
	al_shutdown_primitives_addon();
			
	return 0;
}