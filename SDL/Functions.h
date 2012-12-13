#include "SDL.h"

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination )
{
	//clear screen
	SDL_FreeSurface( source ); 

    //Make a temporary rectangle to hold the offsets
    SDL_Rect offset;
    
    //Give the offsets to the rectangle
    offset.x = x;
    offset.y = y;
	//Blit the surface
    SDL_BlitSurface( source, NULL, destination, &offset );
}

//void shoot(int x, int y, SDL_Surface *screen){	
//	SDL_Surface *temp, *bullet;
//	SDL_Rect rcBullet;
//    temp = SDL_LoadBMP("bullet.bmp");
//    bullet = SDL_DisplayFormat(temp);
//    SDL_FreeSurface(temp);
//
//	rcBullet.x = x;
//	rcBullet.y = y;
//
//	for(int i = y; i > 0; i--){
//		apply_surface(rcBullet.x, rcBullet.y+i, bullet, screen);
//	}
