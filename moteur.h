#ifndef _MOTEUR_TESTSDL2_PIXEL_
#define _MOTEUR_TESTSDL2_PIXEL_

/*include des headers standards en C*/
#include <stdlib.h>

/*include des headers de la SDL2*/
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

typedef struct{
    SDL_Texture  * img;
    SDL_Rect       pos_img;
    SDL_Texture  * txt;
    SDL_Renderer * renderer;
}data_t;

data_t init_data(SDL_Window * window,char * font,char * text,char * img);

void close_data(data_t data);

#endif
