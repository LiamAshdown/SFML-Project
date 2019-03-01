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
#include "Animation.h"
#include <Windows.h>
//-----------------------------------------------//
Animation::Animation(sf::Sprite* sprite, sf::Texture* texture)
{
    mTexture = texture;
    mSprite = sprite;
    mIncrementCounter = 0;
    mMaxIncrementCounter = 0;
}
//-----------------------------------------------//
Animation::~Animation()
{
    for (auto itr : mFrames)
        delete itr.second;

    mFrames.clear();

    delete mSprite;
    delete mTexture;
}
//-----------------------------------------------//
void Animation::AddFrame(const sf::IntRect rect, const uint8 Id)
{
    // Increment our max frame counter
    mMaxIncrementCounter++;

    // Check if the frame already exists, if so add it into the frame
    AnimationMap::iterator itr = mFrames.find(Id);
    if (itr != mFrames.end())
    {
        AnimationData* animation = itr->second;
        animation->sIntRect.push_back(rect);
        return;
    }

    // Else we add the new frame
    AnimationData* animation = new AnimationData;
    animation->sId = Id;
    animation->sIntRect.push_back(rect);

    mFrames[Id] = animation;
}
//-----------------------------------------------//
void Animation::ExecuteAnimation(const uint8 Id, sf::RenderWindow* window, sf::Sprite* sprite, bool useSprite)
{
    mSprite->setPosition(sf::Vector2f(300, 400));
    AnimationMap::iterator itr = mFrames.find(Id);
    if (itr != mFrames.end())
    {
        AnimationData* animation = itr->second;

        if (mIncrementCounter >= mMaxIncrementCounter)
            mIncrementCounter = 0;

        if (useSprite)
        {
            sprite->setTextureRect(animation->sIntRect.at(mIncrementCounter));
            window->draw(*sprite);
        }
        else
        {
            mSprite->setTextureRect(animation->sIntRect.at(mIncrementCounter));
            window->draw(*mSprite);
        }

        mIncrementCounter++;
    }
}
//-----------------------------------------------//
void Animation::PlayAnimation(const uint8 Id, sf::RenderWindow & window)
{
    ;
}
//-----------------------------------------------//