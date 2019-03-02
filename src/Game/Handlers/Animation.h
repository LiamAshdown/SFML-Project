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
* This is the main file which draws onto the screen.
*/
#ifndef _Client_Animation_h_
#include "SharedDefines.h"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Texture.hpp>
#define _Client_Animation_h_
#endif /* _Client_GameUI_h_ */

///< ENUMS
enum MovementType
{
    MOVEMENT_WALKING_DOWN                 = 0x000,
    MOVEMENT_WALKING_UP                   = 0x001,
    MOVEMENT_WALKING_LEFT                 = 0x002,
    MOVEMENT_WALKING_RIGHT                = 0x003,
    MOVEMENT_WALKING_STRAFE_LEFT          = 0x004,
    MOVEMENT_WALKING_STRAFE_RIGHT         = 0x005,
};

///< STRUCT

///< CLASS

///< TYPEDEF
typedef struct AnimationStruct
{
    AnimationStruct() : sId(0), sMaxFrame(0) {}
    uint8 sId;
    uint8 sMaxFrame;
    std::vector<sf::IntRect> sIntRect;

}AnimationData;

typedef std::map<uint8, AnimationData*> AnimationMap;

class Animation
{
public:
    Animation(sf::Sprite* sprite, sf::Texture* texture);
    ~Animation();

public:
    void AddFrame(const sf::IntRect rect, const uint8 Id);
    void ExecuteAnimation(const uint8 Id, sf::RenderWindow* window, sf::Sprite* sprite = nullptr, bool useSprite = false);

private:
    void PlayAnimation(const uint8 Id, sf::RenderWindow& window);

private:
    sf::Sprite* mSprite;
    const sf::Texture* mTexture;
    AnimationMap mFrames;
    uint8 mIncrementCounter;
    uint8 mMaxIncrementCounter;

    static sf::Clock mClock;
};

