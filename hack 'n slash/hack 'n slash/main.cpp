#include "cleanup.h"
#include "res_path.h"
#include "drawing_functions.h"
#include "SDL_mixer.h"
#include "globals.h"
using globals::renderer;

int main(int argc, char **argv) {

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		cout << "Error Initialising SDL" << endl;
		return 1;
	}

	SDL_Window *window = SDL_CreateWindow("Hack 'n Slash", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, globals::screenWidth * globals::screenScale, globals::screenHeight * globals::screenScale, SDL_WINDOW_SHOWN);
	
	if (window == nullptr) {
		SDL_Quit();
		cout << "Window Error" << endl;
		return 1;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (renderer == nullptr) {
		cleanup(window);
		SDL_Quit();
		cout << "Renderer Error" << endl;
		return 1;
	}

	// Size to draw things before scaling it to the screen size dimensions 
	SDL_RenderSetLogicalSize(renderer, globals::screenWidth, globals::screenHeight);

	if (IMG_Init(IMG_INIT_PNG) != 2) {
		cleanup(renderer);
		cleanup(window);
		SDL_Quit();
		cout << "Error Initialising SDL_image" << endl;
		return 1;
	}

	if (TTF_Init() != 0) {
		cleanup(renderer);
		cleanup(window);
		SDL_Quit();
		cout << "Error Initialising SDL_ttf" << endl;
		return 1;
	}

	if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) != 0) {
		cleanup(renderer);
		cleanup(window);
		SDL_Quit();
		cout << "Error Initialising SDL_ttf" << endl;
		return 1;
	}

	string resPath = getResourcePath();

	SDL_Texture *texture = loadTexture(resPath + "map.png", renderer);

	while (SDL_GetTicks() < 5000) {
		SDL_RenderClear(renderer);
		renderTexture(texture, renderer, 0, 0);
		SDL_RenderPresent(renderer);
	}

	cleanup(renderer);
	cleanup(window);
	cleanup(texture);

	SDL_Quit();

	return 0;

}