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
#include "SpriteManager.h"
#include "TriggerEvents.h"
//-----------------------------------------------//
Player::Player()
{

}
//-----------------------------------------------//
Player::~Player()
{

}
//-----------------------------------------------//
sf::Sprite Player::GetSprite()
{
    return mSprite;
}
//-----------------------------------------------//
void Player::PlayerMovement(sf::RenderWindow* window, uint8 triggerID)
{
    switch (triggerID)
    {
    case TRIGGER_KEYBOARD_D:
    {
        sSpriteManager->GetSpriteAnimation("test.png")->ExecuteAnimation(MOVEMENT_WALKING_DOWN, window, mSprite, true);
    }
    break;

    default:
        break;
    }
}
//-----------------------------------------------//