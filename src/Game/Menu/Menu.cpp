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
    mFont = new sf::Font;
    mMenuName = menu;
    mLastTriggerId = 0;
    InitializeFont();
}
//-----------------------------------------------//
Menu::~Menu()
{
    delete mPlayer;

    for (auto itr : mSlot)
        delete itr.second;

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
void Menu::CreateText(std::string name, sf::Color colour, uint32 size, sf::Vector2f windowSize)
{
    MenuData* menu = new MenuData(false);

    menu->sText.setFont(*mFont);
    menu->sText.setString(name);
    menu->sText.setFillColor(colour);
    menu->sText.setCharacterSize(size);
    menu->sText.setPosition(windowSize);

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
                break;
            }
        }
    }

    // Initialize Player
    mPlayer = new Player;

    mPlayer->mSprite = sSpriteManager->GetSprite("test.png");

}
//-----------------------------------------------//
void Menu::TriggerPlayerMoveDown(sf::RenderWindow* window)
{
    mPlayer->PlayerMovement(window, TRIGGER_PLAY_KEYBOARD_D);
}
//-----------------------------------------------//
void Menu::PlayMenu(sf::RenderWindow& window)
{
    ;
}
//-----------------------------------------------//