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
#include "GameUI.h"
#include "TriggerEvents.h"
//-----------------------------------------------//
GameUI::GameUI(const char* windowTitle) : mWidth(WIDTH), mHeight(HEIGHT)
{
    mWindow = new sf::RenderWindow(sf::VideoMode(mWidth, mHeight), windowTitle);
}
//-----------------------------------------------//
GameUI::~GameUI()
{
}
void GameUI::CreateUI()
{
    // Create our main loop
    UILoop();
}
//-----------------------------------------------//
void GameUI::UILoop()
{
    while (mWindow->isOpen())
    {
        sf::Event event;
        while (mWindow->pollEvent(event))
        {
            switch (event.type)
            {  
            case sf::Event::Closed:
            {
                mWindow->close();
            }
            break;

            default:
                break;
            }
        }

        mWindow->clear();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            sMenuManager->GetCurrentMenu()->TriggerEvent(mWindow, TRIGGER_PLAY_KEYBOARD_D, "PLAY");
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            sMenuManager->GetCurrentMenu()->TriggerEvent(mWindow, TRIGGER_MAIN_MENU_PLAY, "MAIN");
        }

        // Draw our current menu
        sMenuManager->GetCurrentMenu()->DrawMenu(mWindow);

        mWindow->display();
    }
}
//-----------------------------------------------//