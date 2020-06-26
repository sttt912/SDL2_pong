#pragma once

#include <SDL.h>
#include "paddle.h"
#include "ball.h"
#include "Enemy.h"
#include "UI.h"
#include "SDL_mixer.h"
class Pong
{
public:
	Pong();
	~Pong() = default;

	void game_loop();
	void update(double delta_time);
	void draw();
	bool CheckPaddleCollision(Ball const& ball, Paddle const& paddle);
	bool CheckEnemyCollision(Ball const& ball, Enemy const& paddle);

private:
	SDL_Window * m_game_window;
	SDL_Event     m_game_window_event;
	SDL_Renderer *m_game_window_renderer;
	TTF_Font* scoreFont;
	Mix_Chunk* paddleHitSound;
public:
	Ball          m_ball;
	Paddle        m_left_paddle;
	Enemy         m_right_enemy;
	UI			  m_ui;
};