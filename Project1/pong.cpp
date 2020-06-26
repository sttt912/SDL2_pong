#include "pong.h"

Pong::Pong() : 
	m_left_paddle(Paddle::Type::LEFT, 20, 150), 
	m_right_enemy(Enemy::Type::RIGHT, 360, 150),
	m_ui(150,20)
{
	SDL_CreateWindowAndRenderer(680, 480, SDL_WINDOW_RESIZABLE, &m_game_window, &m_game_window_renderer);

	SDL_RenderSetLogicalSize(m_game_window_renderer, 400, 400);

	m_ball.init(m_game_window_renderer, (400 / 2) - 12, (400 / 2) - 12);
	scoreFont = TTF_OpenFont("DejaVuSansMono.ttf", 40);

	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

	paddleHitSound = Mix_LoadWAV("PaddleHit.wav");

}

void Pong::game_loop()
{
	bool keep_running = true;
	while (keep_running)
	{
		while (SDL_PollEvent(&m_game_window_event) > 0)
		{
			switch (m_game_window_event.type)
			{
			case SDL_QUIT:
				keep_running = false;
			}

			m_left_paddle.handle_input(m_game_window_event);
		}

		update(1.0 / 30.0);
		draw();
	}
}

void Pong::update(double delta_time)
{
	m_left_paddle.update(delta_time);
	m_right_enemy.update(delta_time, m_ball.m_position.y);
	m_ball.update(delta_time);


	//COLLLISION
	if (CheckPaddleCollision(m_ball, m_left_paddle))
	{
		m_ball.m_velocity_x = -m_ball.m_velocity_x;
		m_ball.m_velocity_y = -m_ball.m_velocity_y + (rand() % 5);
		Mix_PlayChannel(-1, paddleHitSound, 0);
	}

	if (CheckEnemyCollision(m_ball, m_right_enemy))
	{
		m_ball.m_velocity_x = -m_ball.m_velocity_x;
		m_ball.m_velocity_y = -m_ball.m_velocity_y + (rand() % 5);
		Mix_PlayChannel(-1, paddleHitSound, 0);
	}


}

void Pong::draw()
{
	SDL_RenderClear(m_game_window_renderer);

	m_left_paddle.draw(m_game_window_renderer);
	m_right_enemy.draw(m_game_window_renderer);
	m_ball.draw(m_game_window_renderer);

	m_ui.draw(m_game_window_renderer);
	m_ui.draw_text(m_game_window_renderer, scoreFont, std::to_string(m_ball.score2), 20, 300, { 128,145,75 });
	m_ui.draw_text(m_game_window_renderer, scoreFont, std::to_string(m_ball.score1), 20, 100, { 128,145,75 });
	//SDL_Delay(10);
	SDL_RenderPresent(m_game_window_renderer);
}


bool Pong::CheckPaddleCollision(Ball const& ball, Paddle const& paddle)
{
	float ballLeft = ball.m_x;
	float ballRight = ball.m_x + 25;
	float ballTop = ball.m_y;
	float ballBottom = ball.m_y + 25;

	float paddleLeft = paddle.m_position.x;
	float paddleRight = paddle.m_position.x + paddle.m_position.w;
	float paddleTop = paddle.m_position.y;
	float paddleBottom = paddle.m_position.y + paddle.m_position.h;

	if (ballLeft >= paddleRight)
	{
		return false;
	}

	if (ballRight <= paddleLeft)
	{
		return false;
	}

	if (ballTop >= paddleBottom)
	{
		return false;
	}

	if (ballBottom <= paddleTop)
	{
		return false;
	}

	return true;
}

bool Pong::CheckEnemyCollision(Ball const& ball, Enemy const& enemy)
{
	float ballLeft = ball.m_x;
	float ballRight = ball.m_x + 25;
	float ballTop = ball.m_y;
	float ballBottom = ball.m_y + 25;

	float paddleLeft = enemy.m_position.x;
	float paddleRight = enemy.m_position.x + enemy.m_position.w;
	float paddleTop = enemy.m_position.y;
	float paddleBottom = enemy.m_position.y + enemy.m_position.h;

	
	if (ballLeft >= paddleRight)
	{
		return false;
	}

	if (ballRight <= paddleLeft)
	{
		return false;
	}
	
	if (ballTop >= paddleBottom)
	{
		return false;
	}

	if (ballBottom <= paddleTop)
	{
		return false;
	}
	
	return true;

}