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
* GameManager is responsible for loading all data about the game.
*/
#ifndef _Client_AnimationManager_h_
#include "SharedDefines.h"
#define _Client_AnimationManager_h_
#endif /* _Client_AnimationManager_h_ */

///< ENUMS

///< STRUCT

///< CLASS

///< TYPEDEF

class AnimationManager
{
public:
    static AnimationManager* instance();

public:
    AnimationManager();
    ~AnimationManager();

public:
    void AddAnimation();
};
#define sGameManager AnimationManager::instance()
