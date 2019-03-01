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
#ifndef _Client_Player_h_
#include "SharedDefines.h"
#define _Client_Player_h_
#endif /* _Client_Player_h_ */

///< ENUMS

///< STRUCT

///< CLASS
class Menu;

///< TYPEDEF

class Player
{
public:
    friend class Menu;
public:
    Player();
    ~Player();

public:
    sf::Sprite* GetSprite();
    void PlayerMovement(sf::RenderWindow* window, uint8 triggerID);

private:
    sf::Sprite* mSprite;
};

