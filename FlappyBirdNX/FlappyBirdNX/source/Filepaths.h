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


#pragma once
#ifndef _FILEPATHS_HPP_
#define _FILEPATHS_HPP_

/* Save data */
#define DATA_FOLDER "sdmc:/switch/Manurocker95/FlappyBird/"
#define DATA_FILE "sdmc:/switch/Manurocker95/FlappyBird/data.sav"

/* Localization */
#define LOCALIZATION_TEXT_FOLDER  "romfs:/Assets/Files/"
#define LOCALIZATION_TEXT_FILE "romfs:/Assets/Files/en.localization"

/* Sounds */
#define SND_BGM_GAME  "romfs:/Assets/Audio/Music/game.mp3"
#define SND_BGM_TITLE  "romfs:/Assets/Audio/Music/title.mp3"

//SFX
#define SND_SFX_TAP "romfs:/Assets/Audio/SFX/tap.wav"
#define SND_SFX_SPLASH "romfs:/Assets/Audio/SFX/bbb.wav"
#define SND_SFX_SCORE "romfs:/Assets/Audio/SFX/point.wav"
#define SND_SFX_JUMP "romfs:/Assets/Audio/SFX/jump.wav"

/* Images */
// Backgrounds
#define IMG_BACKGROUND "romfs:/Assets/Graphics/Background.png"
#define IMG_BACKGROUND_TITLE "romfs:/Assets/Graphics/BackgroundTitle.png"

#define IMG_TUTORIAL "romfs:/Assets/Graphics/tutorial.png"

#define IMG_GET_READY "romfs:/Assets/Graphics/GetReady.png"
#define IMG_GAME_OVER "romfs:/Assets/Graphics/gameOver.png"

#define IMG_TUBE "romfs:/Assets/Graphics/tube.png"

#define IMG_TOGGLE_SOUND "romfs:/Assets/Graphics/sound.png"
#define IMG_TOGGLE_NO_SOUND "romfs:/Assets/Graphics/nosound.png"

//Splash Screen
#define IMG_SPLASHSCREEN "romfs:/Assets/Graphics/Splash.png"

// Loading Screen
#define IMG_BG_LOADING "romfs:/Assets/Graphics/Loading.png" 
// Intro - same cinematic as TREKT
#define IMG_CINEMATIC_INTRO "romfs:/Assets/Graphics/intro.png" 

// Bytton
#define IMG_BTN_PLAY "romfs:/Assets/Graphics/playBtn.png" 
#define IMG_BTN_PLAY_PRESSED "romfs:/Assets/Graphics/playBtnPressed.png" 
#define IMG_BTN_PLAY_NON_INTERACTABLE "romfs:/Assets/Graphics/playBtnNonInteractable.png" 

#define IMG_BTN_MENU "romfs:/Assets/Graphics/menuBtn.png" 
#define IMG_BTN_MENU_PRESSED "romfs:/Assets/Graphics/menuBtnPressed.png" 
#define IMG_BTN_MENU_NOT_INTERACTABLE "romfs:/Assets/Graphics/menuBtnNotInteractable.png" 

#define IMG_BIRD "romfs:/Assets/Graphics/bird.png" 

// Logo
#define IMG_LOGO "romfs:/Assets/Graphics/Logo.png"

/* Fonts */
#define FONT_NORMAL "romfs:/Assets/Fonts/normal.ttf"
#define FONT_FLAPPY "romfs:/Assets/Fonts/FlappyBirdy.ttf"
#define FONT_FLAPPY_2 "romfs:/Assets/Fonts/FlappyBird2.ttf"

#endif