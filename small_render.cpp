#include <SDL2/SDL.h>
#include <stdio.h>
#include <iostream>
const int SCREEN_WIDTH = 480;//1366;//480;
const int SCREEN_HEIGHT = 270;//768;//270;

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

		
		
		window = SDL_CreateWindow("SDL Test",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
		if (window==NULL) {
			printf("Cannot create window. SDL_Error: %s\n",SDL_GetError());
		} else {
			
			
			
			SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			SDL_SetRenderDrawColor(renderer, 100, 149, 237, 255);
			
			SDL_RenderClear(renderer);
			
			SDL_RenderPresent(renderer);
			
		//	SDL_Delay(3000);
		
		
		
			Uint32 holdTime = SDL_GetTicks();
		
			while (SDL_GetTicks() - holdTime < 5000)
			{
					SDL_RenderClear(renderer);
			
			SDL_RenderPresent(renderer);
			
				frames++;
			 
			}
		
		
			
			SDL_Rect arect;
			
			/*screenSurface=SDL_GetWindowSurface(window);
			SDL_FillRect(screenSurface,NULL,SDL_MapRGB(screenSurface->format,0x00,0x00,0x44));
			arect.x=64; arect.y=64; arect.w=SCREEN_WIDTH-128; arect.h=SCREEN_HEIGHT-128;*/
			
			/*
			Uint32 holdTime = SDL_GetTicks();
		
			while (SDL_GetTicks() - holdTime < 5000)
			{
			   SDL_FillRect(screenSurface,&arect,SDL_MapRGB(screenSurface->format,0x00,0x77,0x77));
				frames++;
			 SDL_UpdateWindowSurface(window);
			}*/
			//SDL_Delay(3000);
		}
	}
	SDL_DestroyWindow(window);
	SDL_Quit();

	std::cout << "frames:" << frames*2;


	return 0;
}
