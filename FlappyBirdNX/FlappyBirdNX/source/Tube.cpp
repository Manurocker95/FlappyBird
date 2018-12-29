#include "Tube.hpp"

Tube::Tube(int _x, int _y, SDL_Helper * _helper, char * _sprite, int _sizePerFrameX, int _sizePerFrameY, Settings * _settings, bool _up) : Sprite(_x, _y, _helper, _sprite, 1, 1, _sizePerFrameX, _sizePerFrameY, 0, 0, false, false, _settings->m_deltaTimeReduction)
{
	this->m_angle = 0.0;
	this->m_center.x = _sizePerFrameX * 0.5;
	this->m_center.y = _sizePerFrameY * 0.5;
	this->m_displacement = _settings->m_birdDisplacement;
	this->m_flip = _up ? SDL_FLIP_VERTICAL : SDL_FLIP_NONE;
}

void Tube::Draw(SDL_Helper * _helper)
{
	_helper->SDL_DrawImageRotated(this->m_sprite, this->m_x, this->m_y, this->m_angle, this->m_center, this->m_flip);
}

void Tube::Update()
{
	this->m_x -= this->m_displacement;
	if (this->m_x < -this->m_sizePerFrameX)
		this->m_x = SWITCH_SCREEN_WIDTH;
}