/* This file is part of Flappy Bird!

Copyright (C) 2018/2019 Manuel Rodríguez Matesanz
>    This program is free software: you can redistribute it and/or modify
>    it under the terms of the GNU General Public License as published by
>    the Free Software Foundation, either version 3 of the License, or
>    (at your option) any later version.
>
>    This program is distributed in the hope that it will be useful,
>    but WITHOUT ANY WARRANTY; without even the implied warranty of
>    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
>    GNU General Public License for more details.
>
>    You should have received a copy of the GNU General Public License
>    along with this program.  If not, see <http://www.gnu.org/licenses/>.
>    See LICENSE for information.
*/

#include "Bird.hpp"

Bird::Bird(int _x, int _y, SDL_Helper * _helper, char * _sprite, int _sizePerFrameX, int _sizePerFrameY, Settings * _settings) : Sprite(_x, _y, _helper, _sprite, 4, 1, _sizePerFrameX, _sizePerFrameY, 0, 0, true, true, _settings->m_deltaTimeReduction)
{
	this->m_angle = 0.0;
	this->m_center.x = _sizePerFrameX * 0.5;
	this->m_center.y = _sizePerFrameY * 0.5;
	this->m_jumping = false;
	this->m_displacement = _settings->m_birdDisplacement;
}

Bird::~Bird()
{
	
}

void Bird::Draw(SDL_Helper * _helper)
{
	if (this->m_active)
	{
		_helper->SDL_DrawImageRotatedRect(this->m_sprite, this->m_x, this->m_y, this->m_currentFrameX * this->m_sizePerFrameX + this->m_ox, this->m_currentFrameY * this->m_sizePerFrameY + this->m_oy, this->m_sizePerFrameX, this->m_sizePerFrameY, this->m_angle, this->m_center);
	}
}

void Bird::Update()
{
	Sprite::Update();

	if (!this->m_jumping)
	{
		this->m_y += this->m_displacement;
	}
	else
	{
		this->m_y -= this->m_displacement * 2;
	}
}

void Bird::Jump()
{
	this->m_jumping = true;
}

void Bird::Reset()
{
	this->m_angle = 0.0;
}

void Bird::StopJump()
{
	this->m_jumping = false;
}

bool Bird::IsJumping()
{
	return this->m_jumping;
}