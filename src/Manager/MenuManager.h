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
* The MenuManager stores the users menu into a container, which the user can
* easily switch menu during run time. 
* A variable called 'mCurrentMenu' holds the current menu which is currently
* being drawn on the screen.
*/

#ifndef _Client_MenuManager_h_
#include "SharedDefines.h"
#define _Client_MenuManager_h_
#endif /* _Client_MenuManager_h_ */

///< ENUMS

///< STRUCT

///< CLASS
class Menu;

///< TYPEDEF
typedef std::map<std::string, Menu*> MenuMap;

class MenuManager
{
public:
    static MenuManager* instance();
public:
    MenuManager();
    ~MenuManager();

public:
    Menu* GetMenuByName(std::string name);
    Menu* GetCurrentMenu();
    void AddMenu(const char* name, Menu* menu);
    void RemoveMenu(const char* name);
    void SetCurrentMenu(Menu* menu);

private:
    MenuMap mMenuStateManager;
    Menu* mCurrentMenu;
};
#define sMenuManager MenuManager::instance()
