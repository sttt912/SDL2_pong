#pragma once

#include <SDL.h>

class Enemy
{
public:
	enum class Type { LEFT, RIGHT };
	Enemy(Type type,int x, int y);
	~Enemy() = default;

	void update(double delta_time, int pos);
	void draw(SDL_Renderer *renderer);
private:
	double m_y;
	int fora = 0;
	Type      m_type;
public:
	SDL_Rect  m_position;
}; 