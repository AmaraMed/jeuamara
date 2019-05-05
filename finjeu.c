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
/** * @file finjeu.c*/
int fin_jeu(unsigned int time){
int cn=1;
SDL_Event event;
SDL_Surface *texte=NULL,*sprite1=NULL,*sprite2=NULL;
TTF_Font *police = NULL;
SDL_Color couleur = {255,255, 255};
SDL_Rect textposition,positionsprite2,positionsprite1;
//position sprite& texte 
textposition.x=230;
textposition.y=210;
positionsprite1.x=230;
positionsprite1.y=290;
positionsprite1.w =128;
positionsprite1.h =26;
positionsprite2.x=230;
positionsprite2.y=340;
positionsprite2.w =128;
positionsprite2.h =26;
objet game_over;
char score[20];
char timech[20];
game_over=init(game_over,0,0,0,0);
afficher_objet(game_over,"gameover1.png",s.ecran);
police = TTF_OpenFont("GODOFWAR.TTF",20);
sprintf(score, "score : %d",p.score);
sprintf(timech,"time: %d Sec",time);
texte = TTF_RenderText_Blended(police,score, couleur);
SDL_BlitSurface(texte, NULL,s.ecran, &textposition); /* Blit du texte */
SDL_Flip(s.ecran);
texte = TTF_RenderText_Blended(police,timech, couleur);
textposition.x=230;
textposition.y=250;
SDL_BlitSurface(texte, NULL,s.ecran, &textposition); /* Blit du texte */
charger_image("play.png",s.ecran,sprite1,&positionsprite1);
charger_image("quit.png",s.ecran,sprite2,&positionsprite2);
int mouse=0,keyboard=0;
while(cn){
SDL_WaitEvent(&event);
switch(event.type)
        { 
   case SDL_QUIT: cn=0; break ;
   case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
             {case SDLK_UP:
              keyboard--;
              break;
              case SDLK_DOWN:  
              keyboard++;
              break;
              case SDLK_RETURN: 
              if(keyboard==2){
TTF_Quit();
SDL_FreeSurface(texte); 
SDL_FreeSurface(sprite1);
SDL_FreeSurface(sprite2);
cn = 0;return -1;} 
              if(keyboard==1){
TTF_Quit();
SDL_FreeSurface(texte); 
SDL_FreeSurface(sprite1);
SDL_FreeSurface(sprite2);
return 1;}
              break;
              }}
if(keyboard==1){charger_image("play2.png",s.ecran,sprite1,&positionsprite1);
}else {charger_image("play.png",s.ecran,sprite1,&positionsprite1);}
if(keyboard==2){charger_image("quit2.png",s.ecran,sprite2,&positionsprite2);}else {charger_image("quit.png",s.ecran,sprite2,&positionsprite2);}
if(keyboard<1){keyboard=2;}
if(keyboard>2){keyboard=1;
}
} 

}
