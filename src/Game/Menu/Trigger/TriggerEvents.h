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
* This file is responsible for triggering events. Triggers are linked with an event(Sprite, Text)
* If the sprite has a trigger 'Click' if the click is made, the event will fire the trigger.
*/
#ifndef _Client_TriggerEvents_h_
#define _Client_TriggerEvents_h_
#include "SharedDefines.h"
#include "Menu.h"
#endif /* _Client_TriggerEvents_h_ */

///< ENUMS
enum Triggers : uint16
{
    TRIGGER_NONE                             = 0x00,
    TRIGGER_MAIN_MENU_PLAY                   = 0x01,
    TRIGGER_PLAY_KEYBOARD_D                  = 0x02,
};

///< STRUCT

///< CLASS

///< TYPEDEF
struct TriggerStruct
{
    char const* name;
    void (Menu::*handler)(sf::RenderWindow* window);
};

typedef std::map<uint16, TriggerStruct> TriggerMap;

class TriggerEvents
{
public:
    static TriggerEvents* instance();
public:
    TriggerEvents();
    ~TriggerEvents();

public:
    void InitializeTriggerEvents();
    TriggerStruct GetTrigger(uint16 id);
    static TriggerStruct const EmptyHandler;

private:
    void StoreTriggerEvent(uint16 id, const char* name, void(Menu::* handler)(sf::RenderWindow* window));

private:
    TriggerMap mTrigger;
    
};
#define sTriggerEvent TriggerEvents::instance()

