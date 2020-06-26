#include "ball.h"


Ball::~Ball()
{
	SDL_DestroyTexture(m_image);
}

void Ball::init(SDL_Renderer *renderer, int x, int y)
{
	IMG_Init(IMG_INIT_PNG);
	SDL_Surface *image = IMG_Load("ball.png");
	

	srand(time(0));
	m_image = SDL_CreateTextureFromSurface(renderer, image);
	SDL_FreeSurface(image);

	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

	wallHitSound = Mix_LoadWAV("WallHit.wav");


	IMG_Quit();

	m_position.x = x;
	m_position.y = y;

	m_x = m_position.x;
	m_y = m_position.y;

	SDL_QueryTexture(m_image, nullptr, nullptr, &m_position.w, &m_position.h);

	if (rand()%2 == 0)
	{
		m_velocity_x = -3;
	}
	else {
		m_velocity_x = 3;
	}

	//if (rand()%4 == 0)
	//{
		m_velocity_y = m_velocity_y+rand()%5;
	//}
}

void Ball::update(double delta_time)
{
	m_x = m_x + (m_velocity_x * delta_time);
	m_y = m_y + (m_velocity_y * delta_time);
	m_position.x = m_x;
	m_position.y = m_y;
	
	if (m_position.x > 350) {

		m_velocity_x = 3;
		m_velocity_y = -(rand() % 5);
		score1++;
		m_x = 200;
		m_y = 200;
		Mix_PlayChannel(-1, wallHitSound, 0);
		SDL_Delay(500);
	}

	if (m_position.x < 35) {

		m_velocity_x = -3;
		m_velocity_y = abs(rand() % 5);
		score2++;
		m_x = 200;
		m_y = 200;
		Mix_PlayChannel(-1, wallHitSound, 0);
		SDL_Delay(500);
	}

	if (m_position.y > 370 || m_position.y < 20) {

		if (m_position.y >370) {
			m_velocity_y = -m_velocity_y;
			Mix_PlayChannel(-1, wallHitSound, 0);
		}
		if (m_position.y < 20) {
			Mix_PlayChannel(-1, wallHitSound, 0);
			m_velocity_y = -m_velocity_y;
		}
	}
}

void Ball::draw(SDL_Renderer *renderer)
{
	SDL_RenderCopy(renderer, m_image, nullptr, &m_position);
}