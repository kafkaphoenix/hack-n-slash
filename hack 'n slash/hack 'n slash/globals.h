#ifndef GLOBALS
#define GLOBALS

#include <string>
#include <iostream>
#include <SDL.h>
#include "randomNumber.h"
#include <math.h>


namespace globals {

	extern const float PI;
	extern bool debugging;
	extern int screenWidth, screenHeight, screenScale;
	extern SDL_Renderer *renderer;
};


#endif // !GLOBALS

