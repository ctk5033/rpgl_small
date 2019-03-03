#include <SDL2/SDL.h>
#include <stdio.h>
#include <iostream>
const int SCREEN_WIDTH = 1366;//480;
const int SCREEN_HEIGHT = 768;//270;

int main(int argc,char* args[]) {
int frames = 0;
	SDL_Window* window = NULL;
	SDL_Surface* screenSurface = NULL;
	if (SDL_Init(SDL_INIT_VIDEO)<0) {
		printf("Could not initialize SDL. SDL_Error: %s\n",SDL_GetError());
	} else {
		
	/*	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_ES);*/

		
		
		window = SDL_CreateWindow("SDL Test",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN | SDL_SWSURFACE);//SDL_WINDOW_OPENGL);
		if (window==NULL) {
			printf("Cannot create window. SDL_Error: %s\n",SDL_GetError());
		} else {
			SDL_Rect arect;
			screenSurface=SDL_GetWindowSurface(window);
			SDL_FillRect(screenSurface,NULL,SDL_MapRGB(screenSurface->format,0x00,0x00,0x44));
			arect.x=64; arect.y=64; arect.w=SCREEN_WIDTH-128; arect.h=SCREEN_HEIGHT-128;
			
			
			Uint32 holdTime = SDL_GetTicks();
		
			while (SDL_GetTicks() - holdTime < 5000)
			{
			   SDL_FillRect(screenSurface,&arect,SDL_MapRGB(screenSurface->format,0x00,0x77,0x77));
				frames++;
			 SDL_UpdateWindowSurface(window);
			}
			//SDL_Delay(3000);
		}
	}
	SDL_DestroyWindow(window);
	SDL_Quit();

	std::cout << "frames:" << frames << std::endl;
	std::cout << "fps:" << frames/5;


	return 0;
}
