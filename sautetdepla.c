#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <stdlib.h>
#include <stdio.h>
#include "SDL/SDL_mixer.h"
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "header.h"
#include <SDL/SDL_ttf.h>
#include <string.h>
#include <time.h>
/** * @file sautetdepla.c*/
void sautetdepla(personnage *p,SDL_Event *event,int *continuer)
{   float x,y;
    x=p->position.x;
    y=p->position.y;
while (SDL_PollEvent(event))
{ 
             switch(event->type)
{
                case SDL_KEYDOWN:
                switch(event->key.keysym.sym)
                {
                    case SDLK_b: 
                    y-=p->vitesse*5;
                    x+=p->vitesse*3;
                    break;
                    case SDLK_v: 
                    y-=p->vitesse*5;
                    x-=p->vitesse*3;
                    break;
                    case SDLK_UP:
                    y-=p->vitesse*5;                   
                    break;
                }
                break;
                case SDL_KEYUP:
                switch(event->key.keysym.sym)
                {
                    case SDLK_b:
                    y+=p->vitesse*5;
                    x+=p->vitesse*3;
                    break;
                    case SDLK_v:
                    y+=p->vitesse*5;
                    x-=p->vitesse*3;
                    break;
                    case SDLK_UP:
                    y+=p->vitesse*5;
                    break;

                }
                break;
}
}

    
            switch(event->type)
            {
                case SDL_QUIT:
                (*continuer) = 0;
                break;
                case SDL_KEYDOWN:
                switch(event->key.keysym.sym)
                {
                    case SDLK_LEFT:
                    x-=p->vitesse+p->acceleration*0.2;
                    break;
                    case SDLK_RIGHT:
                    x +=p->vitesse+p->acceleration*0.2;
                    break;
                }
                break;
            }
        
    

        p->position.x = x;
        p->position.y = y;
   
}
