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
#include <time.h>

int main(int argc, char *argv[])
{ 
int start_game=0;
if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
           {
           printf("%s",Mix_GetError());
           }
           musique=Mix_LoadMUS("music.ogg");
           Mix_PlayMusic(musique, -1); 
start_game=menu1();

unsigned int start_time;
do{
if(start_game==1)
 {int dead=0,fin=0,continuer = 1,i=1,coll=0;
unsigned int frameLimit = SDL_GetTicks() + 16;
start_time=SDL_GetTicks();
unsigned int time;
SDL_Event event;
SDL_Rect position_enemy;
SDL_Surface  *texte = NULL;
objet c1,c2,quiz;
float vie_col;
char lien[20];
TTF_Font *police = NULL;
SDL_Color couleur = {255,255, 255};
SDL_Rect textposition;
SDL_Init(SDL_INIT_VIDEO);
TTF_Init();
//atexit(SDL_QUIT);
s.ecran = SDL_SetVideoMode(558,417, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);
SDL_WM_SetCaption("Torn Asunder", NULL); 
        //s.mask=IMG_Load("Coll.png");
sprintf(lien,"1r%d.png",i);
p.sprite = IMG_Load(lien);
s.background=IMG_Load("final_map.png");
SDL_SetColorKey(p.sprite, SDL_SRCCOLORKEY, SDL_MapRGB(p.sprite->format, 255, 255, 255));    
        initialiser_personnage(&p);
        s.background=initialiser_stage(&s,"final_map.png");
        afficher_background(s.background,&s.pos,s.ecran);
        s.pos.x=0;
        s.pos.y=0;
        c1=init(c1,740,70,40,32);
        c2=init(c2,740,70,40,32);
        quiz=init(quiz,120,220,40,32);
 afficher_objet(c1,"c1.png",s.background);
 afficher_objet(quiz,"quiz1.png",s.background);
initializeEnnemy();
position_enemy.x=monstre.x;
position_enemy.y=monstre.y;
position_enemy.h=10;
position_enemy.w=5;
int coll_quiz;
int test=1;
        while (continuer)
  {sautetdepla(&p,&event,&continuer); 
coll=Collision(p.position,position_enemy);  //BBOX_COLLISON FULLY 
/*coll_quiz=Collission(quiz.positionObjet,p.position);
if((coll_quiz==1)&&(test==1)){
generatequiz();
test=0; 
}*/
if(coll==1) 
{
 if(p.id==2){vie_col=12.5;}else{
 vie_col=25;}
 p.position.x-=30;
 p.v.val-=vie_col;
 monstre.x+=50; 
 coll=0;
}
               if(i>4){i=1;}                
               anim_perso(&i,&event,&p);
                scrolling(&p,&s);
                afficher_background(s.background,&s.pos,s.ecran);
                afficher_vie(p.v,s.ecran);
                time=crono(&s,start_time);                
                SDL_BlitSurface(p.sprite, NULL,s.ecran,&p.position);
                  drawanimatedEnnemy();
                   SDL_Flip(s.ecran);
                  delay(frameLimit);
                  frameLimit = SDL_GetTicks() + 16;
 /*              
if(Collision(c1.positionObjet,p.position)==1){
char pause;
getchar();
afficher_objet(c2,"c2.png",s.background);
printf("YOU SHALL NOT PASS !");
}*/

position_enemy.x=monstre.x;
position_enemy.y=monstre.y;
position_enemy.h=10;
position_enemy.w=5;
SDL_Flip(s.ecran);
if(p.v.val<=0){continuer=0;
fin=1;
}} 
if(fin==1){
start_game=fin_jeu(time);
}  
        }}while(start_game==1||start_game==2);
    SDL_FreeSurface(s.background);
    SDL_FreeSurface(p.sprite);
    SDL_Quit();

    return EXIT_SUCCESS;

}
