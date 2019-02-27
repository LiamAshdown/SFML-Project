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
//-----------------------------------------------//
void TriggerEvents::InitializeTriggerEvents()
{
    StoreTriggerEvent(Triggers::TRIGGER_PLAY_MOUSE_LEFT, "MOUSE_LEFT", &Menu::TriggerPlayMouseLeft);
}
TriggerStruct TriggerEvents::GetTrigger(uint16 id)
{
    TriggerMap::iterator itr = mTrigger.find(id);
    if (itr != mTrigger.end())
        return itr->second;

    //LOG(INFO, "CANNOT FIND TRIGGER");
    return EmptyHandler;
}
//-----------------------------------------------//
void TriggerEvents::StoreTriggerEvent(uint16 id, const char* name, void(Menu::* handler)(MenuData* menu))
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