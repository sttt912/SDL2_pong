#pragma once

#include <SDL.h>
#include <SDL_ttf.h>
#include <string>

class UI
{
public:
	UI(int x, int y);

	void draw(SDL_Renderer *renderer);
	void line(SDL_Renderer *renderer);
	void draw_text(SDL_Renderer* renderer, TTF_Font* scoreFont, std::string tp, int y, int x, SDL_Color color);


};