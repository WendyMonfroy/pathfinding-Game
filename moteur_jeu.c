#include "moteur.h"

data_t init_data(SDL_Window * window,char * font,char * text,char * img)
{
    data_t        data;
    SDL_Surface * s;
    TTF_Font    * f;
    SDL_Color     noir = {0,0,0,0};

    data.img=NULL;
    data.txt=NULL;

    if(font && text && img)
    {
        /* initialisation du renderer */
        data.renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
        if(!data.renderer)
        {
            return data;
        }

        /* initialisation du texte */
        f = TTF_OpenFont(font,20);
        s = TTF_RenderText_Blended(f,text,noir);
        if(s)
        {
            data.txt = SDL_CreateTextureFromSurface(data.renderer,s);
            if(!data.txt)
            {
                close_data(data);
                return data;
            }
            SDL_FreeSurface(s);
        }
        else
        {
            close_data(data);
            return data;
        }

        /* initialisation de l'image */
        data.pos_img.x = 120;
        data.pos_img.y = 400;
        data.pos_img.w = 50;
        data.pos_img.h = 50;
        s=IMG_Load(img);
        if(s)
        {
            data.img = SDL_CreateTextureFromSurface(data.renderer,s);
            SDL_FreeSurface(s);
            if(!data.img)
                close_data(data);
        }
    }

    return data;
}

void close_data(data_t data)
{
    /* liberation de l'espace associe au renderer */
    if(data.renderer)
        SDL_DestroyRenderer(data.renderer);

    /* liberation de l'espace associe a l'image */
    if(data.img)
        SDL_DestroyTexture(data.img);

    /* liberation de l'espace associe au texte */
    if(data.txt)
        SDL_DestroyTexture(data.txt);
}
