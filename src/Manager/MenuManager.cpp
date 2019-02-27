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
#include "MenuManager.h"
#include "Menu.h"
//-----------------------------------------------//
MenuManager* MenuManager::instance()
{
    static MenuManager instance;
    return &instance;
}
//-----------------------------------------------//
MenuManager::MenuManager()
{
}
//-----------------------------------------------//
MenuManager::~MenuManager()
{
    for (auto itr : mMenuStateManager)
        delete itr.second;

    mMenuStateManager.clear();
}
//-----------------------------------------------//
Menu* MenuManager::GetMenuByName(std::string name)
{
    MenuMap::iterator itr = mMenuStateManager.find(name);
    if (itr != mMenuStateManager.end())
        return itr->second;

    //LOG(ERROR, "CANNOT FIND MENU STATE");
    return nullptr;
}
//-----------------------------------------------//
Menu* MenuManager::GetCurrentMenu()
{
    return mCurrentMenu;
}
//-----------------------------------------------//
void MenuManager::AddMenu(const char* name, Menu* menu)
{
    // TODO; Check if menu already exists
    mMenuStateManager[name] = menu;
}
//-----------------------------------------------//
void MenuManager::RemoveMenu(const char* name)
{
    MenuMap::iterator itr = mMenuStateManager.find(name);
    if (itr != mMenuStateManager.end())
    {
        delete itr->second;
        mMenuStateManager.erase(itr);
        return;
    }

    //LOG(INFO, "MENU DOESN'T EXIST);
}
//-----------------------------------------------//
void MenuManager::SetCurrentMenu(Menu * menu)
{
    mCurrentMenu = menu;
}
//-----------------------------------------------//
