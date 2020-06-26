#pragma once

#include <SDL.h>
#include "paddle.h"
#include <SDL_image.h>
#include <random>
#include <ctime>
#include "SDL_mixer.h"

class Ball
{
public:
	Ball() = default;
	~Ball();
	void init(SDL_Renderer *renderer, int x, int y);
	void update(double delta_time);
	void draw(SDL_Renderer *renderer);

public:
	int m_velocity_x;
	int m_velocity_y;
	double m_x;
	double m_y;
	int score1 = 0;
	int score2 = 0;

	SDL_Texture *m_image;
	SDL_Rect m_position;
	Mix_Chunk* wallHitSound;

};