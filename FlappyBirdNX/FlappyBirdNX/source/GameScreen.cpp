/* This file is part of Manurocker95's Template!

this is made for my tutorial: https://gbatemp.net/threads/tutorial-setting-up-visual-studio-2017-environment-for-nintendo-switch-homebrew-development.525977/#post-8439059

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

#include "GameScreen.hpp"
#include "SceneManager.hpp"
#include "Filepaths.h"
#include "Colors.h"

GameScreen::GameScreen(Settings * _settings) : Scene(_settings)
{
	this->m_settings = _settings;
	this->m_changeScene = false;
	this->m_score = 0;
	this->m_gameTimer = 0;
	this->m_secondsToStart = _settings->m_secondsToStart;
	this->m_secondsToJump = _settings->m_secondsToJump;
	this->m_gameStarted = false;
	this->m_showingTutorial = true;
	this->m_gameOver = false;
}

GameScreen::~GameScreen()
{
	this->m_music->End(this->m_helper);
	delete(this->m_music);

	this->m_buttonTapSFX->End(this->m_helper);
	delete(this->m_buttonTapSFX);

	this->m_background->End(this->m_helper);
	delete(this->m_background);

	this->m_background2->End(this->m_helper);
	delete(this->m_background2);

	this->m_tutorialSprite->End(this->m_helper);
	delete(this->m_tutorialSprite);

	this->m_getReadySprite->End(this->m_helper);
	delete(this->m_getReadySprite);

	this->m_text->End(this->m_helper);
	delete(this->m_text);	
	
	this->m_debugText->End(this->m_helper);
	delete(this->m_debugText);	
	
	this->m_scoreText->End(this->m_helper);
	delete(this->m_scoreText);

	this->m_bestScoreText->End(this->m_helper);
	delete(this->m_bestScoreText);

	this->m_bird->End(this->m_helper);
	delete(this->m_bird);	
	
	this->m_gameOverSprite->End(this->m_helper);
	delete(this->m_gameOverSprite);	
	
	this->m_buttonMenu->End(this->m_helper);
	delete(this->m_buttonMenu);
}

void GameScreen::Start(SDL_Helper * helper)
{
	this->m_helper = helper;
	this->m_background = new Sprite(0, 0, helper, IMG_BACKGROUND, 1, 1, SWITCH_SCREEN_WIDTH, SWITCH_SCREEN_HEIGHT, 0, 0, false, false, 1);
	this->m_background2 = new Sprite(SWITCH_SCREEN_WIDTH, 0, helper, IMG_BACKGROUND, 1, 1, SWITCH_SCREEN_WIDTH, SWITCH_SCREEN_HEIGHT, 0, 0, false, false, 1);

	this->m_getReadySprite = new Sprite(350, 350, helper, IMG_GET_READY, 1, 1, 368, 100, 0, 0, false, false, 1);
	this->m_gameOverSprite = new Sprite(450, 150, helper, IMG_GAME_OVER, 1, 1, 452, 325, 0, 0, false, false, 1);

	this->m_tutorialSprite = new Sprite(450, 200, helper, IMG_TUTORIAL, 1, 1, 456, 392, 0, 0, false, false, 1);

	this->m_text = new Text(helper, "0", 635, 80, 85, true, FONT_FLAPPY_2, C_WHITE);
	this->m_debugText = new Text(helper, "DEBUG MODE", 595, 670, 25, true, FONT_FLAPPY_2, C_BLUE);

	this->m_scoreText = new Text(helper, "0", 635, 290, 35, true, FONT_FLAPPY_2, C_ORANGE);
	this->m_bestScoreText = new Text(helper, std::to_string(SceneManager::Instance()->GetBestScore()), 635, 290, 35, true, FONT_FLAPPY_2, C_ORANGE);

	this->m_buttonMenu = new Button(60, 60, helper, IMG_BTN_MENU, IMG_BTN_MENU_NOT_INTERACTABLE, IMG_BTN_MENU_PRESSED, true, false, 1, 1, 160, 56, false, 0, 0);

	this->m_bird = new Bird(430, 350, helper, IMG_BIRD, 167, 147, this->m_settings);

	this->m_buttonTapSFX = new SfxSound(helper, SND_SFX_TAP, false, 2);
	this->m_music = new MusicSound(helper, SND_BGM_TITLE, true, 1);
	this->m_music->Play(helper);

	if (this->m_settings->m_muted)
		helper->SDL_PauseMusic();
}

void GameScreen::Draw()
{
	this->m_background->Draw(this->m_helper);

	if (!this->m_showingTutorial)
	{
		if (!this->m_gameOver)
		{
			this->m_background2->Draw(this->m_helper);
			this->m_bird->Draw(this->m_helper);
			this->m_text->Draw(this->m_helper);
		}

		if (!this->m_gameStarted)
			this->m_getReadySprite->Draw(this->m_helper);
	}
	else
	{
		this->m_tutorialSprite->Draw(this->m_helper);
	}

	if (this->m_gameOver)
	{
		this->m_gameOverSprite->Draw(this->m_helper);
		this->m_scoreText->Draw(this->m_helper);
		this->m_bestScoreText->Draw(this->m_helper);
	}
	
	this->m_buttonMenu->Draw(this->m_helper);

	if (this->m_debugMode)
		this->m_debugText->Draw(this->m_helper);
}

void GameScreen::Update()
{
	if (!this->m_showingTutorial)
	{
		this->m_currentTime = SDL_GetTicks();
		if (this->m_currentTime > this->m_lastTime + 1000)
		{
			this->m_lastTime = this->m_currentTime;

			if (!this->m_gameStarted)
			{
				++this->m_gameTimer;
				if (this->m_gameTimer >= this->m_secondsToStart)
				{
					this->m_gameTimer = 0;
					this->m_gameStarted = true;
					return;
				}
			}
		}

		if (this->m_gameStarted && !this->m_gameOver)
		{
			++this->m_gameTimer;

			if (m_gameTimer >= this->m_secondsToJump)
			{
				this->m_bird->StopJump();
				this->m_canJump = true;
			}

			this->m_background->MoveX(-1);
			if (this->m_background->GetX() <= -SWITCH_SCREEN_WIDTH)
			{
				this->m_background->SetX(SWITCH_SCREEN_WIDTH);
			}

			this->m_background2->MoveX(-1);
			if (this->m_background2->GetX() <= -SWITCH_SCREEN_WIDTH)
			{
				this->m_background2->SetX(SWITCH_SCREEN_WIDTH);
			}

			this->m_bird->Update();

			if (this->m_bird->GetY() > SWITCH_SCREEN_HEIGHT)
			{
				GameOver();
			}
		}
	}

	if (this->m_changeScene)
		NextScene();
}

void GameScreen::CheckInputs(u64 kDown, u64 kHeld, u64 kUp)
{
	if (this->m_showingTutorial)
	{
		if (kDown & KEY_TOUCH || kDown & KEY_A)
		{
			this->m_showingTutorial = false;
		}
	}
	else if (this->m_gameOver)
	{
		if (kDown & KEY_TOUCH || kDown & KEY_A)
		{
			this->m_changeScene = true;
		}
	}
	else if (this->m_gameStarted)
	{
		if (kHeld & KEY_TOUCH)
		{
			u32 i;
			hidTouchRead(&this->touch, i);
			if (this->m_buttonMenu->IsPressed(&touch))
			{
				//
			}
		}
		else if (kUp & KEY_TOUCH)
		{
			if (this->m_buttonMenu->GetPressed())
			{
				this->m_changeScene = true;
				return;
			}
			else
			{
				if (this->m_canJump)
					this->m_bird->Jump();
			}		
		}	

		if (kDown & KEY_A)
		{
			if (this->m_canJump)
				this->m_bird->Jump();
		}
	}

	if (kDown & KEY_R)
	{
		if (kDown & KEY_L)
		{
			this->m_debugMode = !this->m_debugMode;
		}
		else
		{
			if (this->m_debugMode)
			{
				++this->m_score;
				this->m_text->SetText(std::to_string(this->m_score));
			}
		}
	}
	
	if (kDown & KEY_PLUS)
	{
		this->m_changeScene = true;
	}
}

// * We go to the next scene = GameScreen
void GameScreen::NextScene()
{
	this->m_settings->m_debugMode = this->m_debugMode;
	SceneManager::Instance()->SaveData(this->m_score);
	SceneManager::Instance()->LoadScene(SceneManager::TITLE);
}

void GameScreen::ResetGame()
{
	this->m_score = 0;
	this->m_text->SetText(std::to_string(this->m_score));
	this->m_gameStarted = false;
	this->m_background->SetX(0);
	this->m_background2->SetActive(SWITCH_SCREEN_WIDTH);
}

void GameScreen::GameOver()
{
	this->m_scoreText->SetText(std::to_string(this->m_score));
	this->m_gameOver = true;
}