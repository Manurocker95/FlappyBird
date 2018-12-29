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
#pragma once
#ifndef _BIRD_HPP_
#define _BIRD_HPP_

#include "Sprite.hpp"
#include "Settings.hpp"

class Bird : public Sprite
{
private:
	SDL_Point m_center;
	double m_angle;

	int m_displacement;

	bool m_jumping;
public:

	Bird(int _x, int _y, SDL_Helper * _helper, char * _sprite, int _sizePerFrameX, int _sizePerFrameY, Settings * _settings);
	~Bird();

	void Draw(SDL_Helper * _helper) override;
	void Update() override;
	void Jump();
	void StopJump();
	bool IsJumping();
	void Reset();
};
#endif