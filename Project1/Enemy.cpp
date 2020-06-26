#include "Enemy.h"
#include <windows.h>
Enemy::Enemy(Type type, int x, int y)
{
	m_position.x = x;
	m_position.y = y;
	m_position.w = 25;
	m_position.h = 75;
	m_y = static_cast<double>(y);
	m_type = type;
}



void Enemy::update(double delta_time, int pos)
{
	fora++;

	if (m_position.y <= pos) {
		if (fora>10) {
			m_position.y++;
			fora = 0;
		}
	}
	
	if (m_position.y >= pos) {
		if (fora > 10) {
			m_position.y--;
			fora = 0;
		}
	}
}

void Enemy::draw(SDL_Renderer *renderer)
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(renderer, &m_position);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
}