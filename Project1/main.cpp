#include "pong.h"

int main(int argc, char *argv[])
{
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	TTF_Init();
	Pong pong;
	pong.game_loop();
	return 0;
}