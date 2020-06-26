#include "UI.h"


UI::UI(int x, int y)
{
	
}


void UI::draw(SDL_Renderer *renderer)
{
	line(renderer);
}

void UI::draw_text(SDL_Renderer* renderer, TTF_Font* scoreFont, std::string tp, int y, int x, SDL_Color color) {
	SDL_Surface* surface{};
	SDL_Texture* texture{};
	SDL_Rect rect{};
	surface = TTF_RenderText_Solid(scoreFont, tp.c_str(), color);
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	int width, height;
	SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);
	rect.x = static_cast<int>(x);
	rect.y = static_cast<int>(y);
	rect.w = width;
	rect.h = height;
	SDL_RenderCopy(renderer, texture, nullptr, &rect);
	SDL_RenderPresent(renderer);

	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);
}

void UI::line(SDL_Renderer *renderer)
{

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	for (int y = 0; y < 400; ++y)
	{
		if (y % 5)
		{
			SDL_RenderDrawPoint(renderer, 400 / 2, y);
		}
	}
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

}