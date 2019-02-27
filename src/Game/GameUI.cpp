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
GameUI::GameUI(const char* windowTitle) : mWidth(1200), mHeight(800)
{
    mWindow = new sf::RenderWindow(sf::VideoMode(mWidth, mHeight), windowTitle);

    // Initialize Trigger Events
    sTriggerEvent->InitializeTriggerEvents();
}
//-----------------------------------------------//
GameUI::~GameUI()
{
}
void GameUI::CreateUI()
{
    // Initialize our menu states
    InitializeMenu();

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

            case sf::Event::MouseButtonPressed:
            {
                sMenuManager->GetCurrentMenu()->TriggerEvent(mWindow);
            }
            break;

            default:
                break;
            }
        }

        mWindow->clear();
        // Draw our current menu
        sMenuManager->GetCurrentMenu()->DrawMenu(mWindow);
        mWindow->display();
    }
}
//-----------------------------------------------//
void GameUI::InitializeMenu()
{
    ///< MAIN MENU
    Menu* mainMenu = new Menu(mWidth, mHeight);
    mainMenu->CreateButton("Play", sf::Color::White, 24, sf::Vector2f(mWidth / 2, 300), TRIGGER_PLAY_MOUSE_LEFT, true);
    mainMenu->CreateButton("Help", sf::Color::White, 24, sf::Vector2f(mWidth / 2, mHeight / 2), TRIGGER_HELP_MOUSE_LEFT, true);

    sMenuManager->AddMenu("Menu", mainMenu);
    sMenuManager->SetCurrentMenu(sMenuManager->GetMenuByName("Menu"));

    ///< PLAY MENU
    Menu* playMenu = new Menu(mWidth, mHeight);
    playMenu->CreateText("Working!", sf::Color::White, 24, sf::Vector2f(mWidth / 2, mHeight / 2));
    sMenuManager->AddMenu("Play", playMenu);
}
//-----------------------------------------------//