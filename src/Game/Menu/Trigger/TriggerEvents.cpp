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
//-----------------------------------------------//
TriggerEvents* TriggerEvents::instance()
{
    static TriggerEvents instance;
    return &instance;
}
//-----------------------------------------------//
TriggerEvents::TriggerEvents()
{
}
//-----------------------------------------------//
TriggerEvents::~TriggerEvents()
{
}
//-----------------------------------------------//a
void TriggerEvents::InitializeTriggerEvents()
{
    ///< MENU
    StoreTriggerEvent(Triggers::TRIGGER_MAIN_MENU_PLAY,       "MOUSE_LEFT",     &Menu::TriggerMainMenu            );
    StoreTriggerEvent(Triggers::TRIGGER_MAIN_MENU_HELP,       "MOUSE_LEFT",     &Menu::TriggerMainHelp            );
    StoreTriggerEvent(Triggers::TRIGGER_HELP_MENU_BACK,       "MOUSE_LEFT",     &Menu::TriggerHelpBack            );
    StoreTriggerEvent(Triggers::TRIGGER_CURRENT_MENU_BUTTONS, "MOUSE_LEFT",     &Menu::TriggerAllCurrentButtons   );


    ///< PLAYER
    StoreTriggerEvent(Triggers::TRIGGER_PLAY_KEYBOARD_W,      "KEYBOARD_W",     &Menu::TriggerPlayerMoveUp        );
    StoreTriggerEvent(Triggers::TRIGGER_PLAY_KEYBOARD_A,      "KEYBOARD_A",     &Menu::TriggerPlayerMoveLeft      );
    StoreTriggerEvent(Triggers::TRIGGER_PLAY_KEYBOARD_S,      "KEYBOARD_S",     &Menu::TriggerPlayerMoveDown      );
    StoreTriggerEvent(Triggers::TRIGGER_PLAY_KEYBOARD_D,      "KEYBOARD_D",     &Menu::TriggerPlayerMoveRight     );

}
//-----------------------------------------------//
TriggerStruct TriggerEvents::GetTrigger(uint16 id)
{
    TriggerMap::iterator itr = mTrigger.find(id);
    if (itr != mTrigger.end())
        return itr->second;

    //LOG(INFO, "CANNOT FIND TRIGGER");
    return EmptyHandler;
}
//-----------------------------------------------//
void TriggerEvents::StoreTriggerEvent(uint16 id, const char* name, void(Menu::* handler)(sf::RenderWindow* window))
{
    TriggerStruct& trigger = mTrigger[id];
    trigger.name = name;
    trigger.handler = handler;
}
//-----------------------------------------------//
TriggerStruct const TriggerEvents::EmptyHandler =
{
    "<none>",
    &Menu::HandleNULL
};