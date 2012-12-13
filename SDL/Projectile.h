#include "SDL.h"

class Projectile{

	public:
		SDL_Rect position;
		SDL_Surface *img;
		int velX;
		int velY;
		int alive;
		int dead;
		void update(int time_delta);
		bool isDead();
		bool checkCollision(int y);
		void draw(SDL_Surface *source, SDL_Surface *dest);
};


	void Projectile::update(int time_delta){
		 if(!isDead()) {
				position.x += velX*time_delta;
				position.y += velY*time_delta;
			}
		 if (checkCollision(position.y))
			 SDL_FreeSurface(img);
	}

	bool Projectile::isDead(){
		return alive<=dead;
	}

	bool Projectile::checkCollision(int y){
		return y<=0;
	}

	void Projectile::draw(SDL_Surface *source, SDL_Surface *dest){		
		 apply_surface(position.x, position.y, source, dest);
	}