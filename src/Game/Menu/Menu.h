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
************************************************************************
*                           PURPOSE
* Menu is created in GameUI and stored in MenuManager. The user can construct its
* own text and buttons (also automatically creates a trigger; hover, leave, click)
*/
#ifndef _Client_Menu_h_
#include "SharedDefines.h"
#include "Player.h"
#define _Client_Menu_h_
#endif /* _Client_Menu_h_ */

///< ENUMS

///< STRUCT
struct TriggerStruct;

///< CLASS

///< TYPEDEF
typedef struct MenuStruct
{
    MenuStruct(bool button) : sIsButton(button), sTriggerID(0) {}

    ///< Text
    sf::Text sText;

    ///< Button
    sf::RectangleShape sButton;
    sf::Color sOriginial;
    sf::Color sHover;

    ///< Data
    bool sIsButton = false;
    uint16 sTriggerID;

} MenuData;

typedef std::map<uint32, MenuData*> SlotMap;

class Menu
{
public:
    friend class GameUI;

public:
    Menu(const uint32 width, const uint32 height, std::string name);
    ~Menu();
    void DrawMenu(sf::RenderWindow* window);
    bool CheckIntersect(sf::RenderWindow* window, MenuData* menu);

public:
    void InitializeFont();
    void CreateText(std::string name, sf::Color colour, uint32 size, sf::Vector2f windowSize);
    void CreateButton(std::string name, sf::Color colour, uint32 size, sf::Vector2f windowSize, uint32 triggerID, bool transparent = false, sf::Color hoverColour = sf::Color::Red);

public:
    ////////////////////////////////////
    //         TRIGGER EVENTS         //
    ////////////////////////////////////
    void TriggerEvent(sf::RenderWindow* window, uint8 triggerID, std::string menuName);
    void ExecuteTrigger(const TriggerStruct& triggerHandle, sf::RenderWindow* window);

    ///< MENU
    void TriggerMainMenu(sf::RenderWindow* window);
    void TriggerMainHelp(sf::RenderWindow* window);
    void TriggerHelpBack(sf::RenderWindow* window);
    void TriggerAllCurrentButtons(sf::RenderWindow* window);

    ///< PLAYER
    void TriggerPlayerMoveDown(sf::RenderWindow* window);
    void TriggerPlayerMoveUp(sf::RenderWindow* window);
    void TriggerPlayerMoveLeft(sf::RenderWindow* window);
    void TriggerPlayerMoveRight(sf::RenderWindow* window);

    void HandleNULL(sf::RenderWindow* window) {}
    ////////////////////////////////////
    //      END OF TRIGGER EVENTS    //
    ////////////////////////////////////

private:
    ////////////////////////////////////
    //         MENUS                 //
    ////////////////////////////////////
    void PlayMenu(sf::RenderWindow* window);

private:
    uint32 mHeight;
    uint32 mWidth;

    SlotMap mSlot;
    sf::Font* mFont;

    std::string mMenuName;

    uint8 mLastTriggerId;

    Player* mPlayer;
};