#include "Functions.h"
#include "Projectile.h"

int main(int argc, char* args[])
{

	Projectile bullet;
    SDL_Surface *screen, *temp, *sprite, *enemy, *grass, *hello, *bulletBMP;
    SDL_Rect rcSprite, rcGrass, rcEnemy, rcBullet;
    SDL_Event event;
    Uint8 *keystate;
    int colorkey, gameover;

    //Start SDL
    SDL_Init( SDL_INIT_EVERYTHING );

    //Set up screen
    screen = SDL_SetVideoMode( 640, 480, 32, SDL_SWSURFACE );

    //Load image
    temp = SDL_LoadBMP("sprite.bmp");
    sprite = SDL_DisplayFormat(temp);
    SDL_FreeSurface(temp);
    temp = SDL_LoadBMP("enemy.bmp");
    enemy = SDL_DisplayFormat(temp);
    SDL_FreeSurface(temp);
    temp = SDL_LoadBMP("bullet.bmp");
    bulletBMP = SDL_DisplayFormat(temp);
    SDL_FreeSurface(temp);

    //Apply image to screen

    //Update Screen
    SDL_Flip( screen );


    //Welcome Screen Start
    SDL_Delay( 1000 );
    SDL_FillRect( screen, 0, 0 );


    //Game Loop Start
   	 
    /* setup sprite colorkey and turn on RLE */
    colorkey = SDL_MapRGB(screen->format, 255, 0, 255);
    SDL_SetColorKey(sprite, SDL_SRCCOLORKEY | SDL_RLEACCEL, colorkey);
    SDL_SetColorKey(enemy, SDL_SRCCOLORKEY | SDL_RLEACCEL, colorkey);

    //initialize sprite position
    rcSprite.x = 200;
    rcSprite.y = 200;

    rcEnemy.x = 300;
    rcEnemy.y = 300;

	bullet.img = bulletBMP;
	bullet.position.x = rcSprite.x;
	bullet.position.y = rcSprite.x;	
	bullet.velY = 10;


    bool gameRunning = true;
	int bullExists = 0;

    while (gameRunning)
    {
   	 if (SDL_PollEvent(&event))
   	 {
   		 if (event.type == SDL_QUIT)
   		 {
   			 gameRunning = false;
   		 }

   		 if (event.type == SDL_KEYDOWN)
   		 {
   			 SDLKey keyPressed = event.key.keysym.sym;

   			 keystate = SDL_GetKeyState(NULL);
   			 if (keystate[SDLK_LEFT] ) {
   				 rcSprite.x -= 2;
   			 }
   			 if (keystate[SDLK_RIGHT] ) {
   				 rcSprite.x += 2;
   			 }
   			 if (keystate[SDLK_UP] ) {
   				 rcSprite.y -= 2;
   			 }
   			 if (keystate[SDLK_DOWN] ) {
   				 rcSprite.y += 2;
   			 }
			 if (keystate[SDLK_SPACE] ) {		
				 bullExists = 1;
				 bullet.update(5);
   			 }


   			 if(keyPressed == SDLK_ESCAPE)
   			 {
   				 gameRunning = false;
   			 }
   		 }
   		 SDL_FillRect( screen, 0, 0 );
   	 }
   	 /* draw the sprite */
	 
	 if(bullExists == 1){
		apply_surface(bullet.position.x, bullet.position.y, bullet.img, screen);
		bullExists = 0;
	 }
   	 SDL_BlitSurface(sprite, NULL, screen, &rcSprite);
   	 SDL_BlitSurface(enemy, NULL, screen, &rcEnemy);	

   	 /* update the screen */
   	 SDL_UpdateRect(screen, 0, 0, 0, 0);

    }
    //Game Loop End

    //Quit SDL
    SDL_Quit();

    return 0;
}