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
#include "SpriteManager.h"
//-----------------------------------------------//
Player::Player()
{
    mTexture = *sSpriteManager->GetSprite("test.png")->sTexture;
    mSprite.setTexture(mTexture);
}
//-----------------------------------------------//
Player::~Player()
{
}
//-----------------------------------------------//
sf::Sprite& Player::GetSprite()
{
    return mSprite;
}
//-----------------------------------------------//
void Player::PlayerMovement(sf::RenderWindow* window, uint8 triggerID)
{
    switch (triggerID)
    {
    case TRIGGER_PLAY_KEYBOARD_S:
    {
        sSpriteManager->GetSpriteAnimation("test.png")->ExecuteAnimation(MOVEMENT_WALKING_DOWN, window, &mSprite, true);
        mSprite.move(NULL, PLAYER_BASE_SPEED);
    }
    break;

    case TRIGGER_PLAY_KEYBOARD_W:
    {
        sSpriteManager->GetSpriteAnimation("test.png")->ExecuteAnimation(MOVEMENT_WALKING_UP, window, &mSprite, true);
        mSprite.move(NULL, -PLAYER_BASE_SPEED);
    }
    break;

    case TRIGGER_PLAY_KEYBOARD_A:
    {
        sSpriteManager->GetSpriteAnimation("test.png")->ExecuteAnimation(MOVEMENT_WALKING_LEFT, window, &mSprite, true);
        mSprite.move(-PLAYER_BASE_SPEED, NULL);
    }
    break;

    case TRIGGER_PLAY_KEYBOARD_D:
    {
        sSpriteManager->GetSpriteAnimation("test.png")->ExecuteAnimation(MOVEMENT_WALKING_RIGHT, window, &mSprite, true);
        mSprite.move(PLAYER_BASE_SPEED, NULL);
    }
    break;

    default:
        break;
    }
}
//-----------------------------------------------//