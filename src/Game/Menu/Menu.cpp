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
#include "TriggerEvents.h"
#include "MenuManager.h"
#include "SpriteManager.h"
//-----------------------------------------------//
Menu::Menu(const uint32 width, const uint32 height, std::string menu)
{
    mWidth = width;
    mHeight = height;
    mMenuName = menu;
    mLastTriggerId = 0;
    mFont = new sf::Font;
    mPlayer = nullptr;
    InitializeFont();
}
//-----------------------------------------------//
Menu::~Menu()
{
    for (auto itr : mSlot)
        delete itr.second;

    if (mPlayer)
        delete mPlayer;

    delete mFont;
    mSlot.clear();
}
//-----------------------------------------------//
void Menu::DrawMenu(sf::RenderWindow* window)
{
    SlotMap::iterator itr;
    for (itr = mSlot.begin(); itr != mSlot.end(); itr++)
    {
        MenuData* menu = itr->second;
        if (menu->sIsButton)
        {
            if (CheckIntersect(window, menu))
                menu->sText.setFillColor(menu->sHover);
            else
                menu->sText.setFillColor(menu->sOriginial);

            window->draw(menu->sText);
            window->draw(menu->sButton);
        }

        window->draw(menu->sText);
    }

    if (mMenuName == "PLAY")
        PlayMenu(window);
}
//-----------------------------------------------//
bool Menu::CheckIntersect(sf::RenderWindow * window, MenuData* menu)
{
    if (menu->sButton.getGlobalBounds().contains(window->mapPixelToCoords(sf::Mouse::getPosition(*window))))
        return true;

    return false;
}
//-----------------------------------------------//
void Menu::InitializeFont()
{
    if (!mFont->loadFromFile("arial.ttf"))
    {
        ;//LOG(ERROR, "ERROR_CANNOT_LOAD_FONT");
    }
}
//-----------------------------------------------//
void Menu::CreateText(std::string name, sf::Color colour, uint32 size, sf::Vector2f position)
{
    MenuData* menu = new MenuData(false);

    menu->sText.setFont(*mFont);
    menu->sText.setString(name);
    menu->sText.setFillColor(colour);
    menu->sText.setCharacterSize(size);
    menu->sText.setPosition(position);

    mSlot[TRIGGER_NONE] = menu;
}
//-----------------------------------------------//
void Menu::CreateButton(std::string name, sf::Color colour, uint32 size, sf::Vector2f position, uint32 triggerID, bool transparent /*false*/, sf::Color hoverColour /*= sf::Color::Red*/)
{
    MenuData* menu = new MenuData(true);

    menu->sText.setFont(*mFont);
    menu->sText.setString(name);
    menu->sText.setFillColor(colour);
    menu->sText.setCharacterSize(size);
    menu->sText.setPosition(position);

    menu->sButton.setSize(sf::Vector2f(menu->sText.getLocalBounds().width, menu->sText.getLocalBounds().height));
    if (transparent)
    {
        menu->sButton.setFillColor(sf::Color::Transparent);

        // Set our hover colour and our original colour
        menu->sHover = hoverColour;
        menu->sOriginial = colour;
    }
    else
        menu->sButton.setFillColor(colour);

    menu->sTriggerID = triggerID;

    // Align our button in middle of the text
    menu->sButton.setPosition(sf::Vector2f(menu->sText.getPosition().x, menu->sText.getPosition().y + CENTRE_BUTTON));

    mSlot[triggerID] = menu;
}
//-----------------------------------------------//
void Menu::ExecuteTrigger(const TriggerStruct& triggerHandle, sf::RenderWindow* window)
{
    (this->*triggerHandle.handler)(window);
}
//-----------------------------------------------//
void Menu::TriggerEvent(sf::RenderWindow* window, uint8 triggerID, std::string menuName)
{
    if (mMenuName == menuName)
    {
        mLastTriggerId = triggerID;

        const TriggerStruct& triggerHandle = sTriggerEvent->GetTrigger(triggerID);
        ExecuteTrigger(triggerHandle, window);
    }
}
//-----------------------------------------------//
void Menu::TriggerMainMenu(sf::RenderWindow* window)
{
    SlotMap::iterator itr;
    for (itr = mSlot.begin(); itr != mSlot.end(); itr++)
    {
        MenuData* menu = itr->second;

        if (menu->sTriggerID != mLastTriggerId)
            continue;

        if (menu->sIsButton)
        {
            if (CheckIntersect(window, menu))
            {
                // Change to our play menu
                sMenuManager->SetCurrentMenu(sMenuManager->GetMenuByName("PLAY"));
                sMenuManager->GetCurrentMenu()->mPlayer = new Player;
                break;
            }
        }
    }
}
//-----------------------------------------------//
void Menu::TriggerMainHelp(sf::RenderWindow * window)
{
    sMenuManager->SetCurrentMenu(sMenuManager->GetMenuByName("HELP"));
}
//-----------------------------------------------//
void Menu::TriggerHelpBack(sf::RenderWindow * window)
{
    sMenuManager->SetCurrentMenu(sMenuManager->GetMenuByName("MAIN"));
}
//-----------------------------------------------//
void Menu::TriggerAllCurrentButtons(sf::RenderWindow * window)
{
    SlotMap::iterator itr;
    for (itr = mSlot.begin(); itr != mSlot.end(); itr++)
    {
        MenuData* menu = itr->second;

        if (menu->sIsButton)
        {
            if (CheckIntersect(window, menu))
            {
                mLastTriggerId = menu->sTriggerID;
                const TriggerStruct& triggerHandle = sTriggerEvent->GetTrigger(menu->sTriggerID);
                ExecuteTrigger(triggerHandle, window);
                break;
            }
        }
    }
}
//-----------------------------------------------//
void Menu::TriggerPlayerMoveDown(sf::RenderWindow* window)
{
    mPlayer->PlayerMovement(window, TRIGGER_PLAY_KEYBOARD_S);
}
//-----------------------------------------------//
void Menu::TriggerPlayerMoveUp(sf::RenderWindow* window)
{
    mPlayer->PlayerMovement(window, TRIGGER_PLAY_KEYBOARD_W);
}
//-----------------------------------------------//
void Menu::TriggerPlayerMoveLeft(sf::RenderWindow* window)
{
    mPlayer->PlayerMovement(window, TRIGGER_PLAY_KEYBOARD_A);
}
//-----------------------------------------------//
void Menu::TriggerPlayerMoveRight(sf::RenderWindow* window)
{
    mPlayer->PlayerMovement(window, TRIGGER_PLAY_KEYBOARD_D);
}
//-----------------------------------------------//
void Menu::PlayMenu(sf::RenderWindow* window)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        sMenuManager->GetCurrentMenu()->TriggerEvent(window, TRIGGER_PLAY_KEYBOARD_D, "PLAY");
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        sMenuManager->GetCurrentMenu()->TriggerEvent(window, TRIGGER_PLAY_KEYBOARD_W, "PLAY");
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        sMenuManager->GetCurrentMenu()->TriggerEvent(window, TRIGGER_PLAY_KEYBOARD_A, "PLAY");
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        sMenuManager->GetCurrentMenu()->TriggerEvent(window, TRIGGER_PLAY_KEYBOARD_S, "PLAY");
    }

    window->draw(mPlayer->mSprite);
}
//-----------------------------------------------//