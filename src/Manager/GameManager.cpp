/*
* Liam Ashdown
* Copyright (C) 2018
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
//-----------------------------------------------//
#include "GameManager.h"
#include "TriggerEvents.h"
//-----------------------------------------------//
GameManager* GameManager::instance()
{
    static GameManager instance;
    return &instance;
}
//-----------------------------------------------//
GameManager::GameManager()
{
    game = new GameUI("Client FrameWork");
}
//-----------------------------------------------//
GameManager::~GameManager()
{
}
//-----------------------------------------------//
void GameManager::LoadEngineData()
{
    ///< This is where you load your sprite(s)
    sSpriteManager->AddSprite("ship.png");

    ///< This is where you load your menu(s)
    Menu* mainMenu = new Menu(WIDTH, HEIGHT);
    mainMenu->CreateButton("Play", sf::Color::White, 24, sf::Vector2f(WIDTH / 2, 300), TRIGGER_PLAY_MOUSE_LEFT, true);
    mainMenu->CreateButton("Help", sf::Color::White, 24, sf::Vector2f(WIDTH / 2, HEIGHT / 2), TRIGGER_HELP_MOUSE_LEFT, true);

    sMenuManager->AddMenu("Menu", mainMenu);
    sMenuManager->SetCurrentMenu(sMenuManager->GetMenuByName("Menu"));

    Menu* playMenu = new Menu(WIDTH, HEIGHT);
    sMenuManager->AddMenu("Play", playMenu);

    ///< Loading trigger events
    sTriggerEvent->InitializeTriggerEvents();

    ///< Once we have loaded everything we need, we now pass it off to GameUI
    game->CreateUI();
}
//-----------------------------------------------//
