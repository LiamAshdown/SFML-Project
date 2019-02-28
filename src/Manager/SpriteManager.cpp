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
//-----------------------------------------------//
SpriteManager* SpriteManager::instance()
{
    static SpriteManager instance;
    return &instance;
}
//-----------------------------------------------//
SpriteManager::SpriteManager()
{
}
//-----------------------------------------------//
SpriteManager::~SpriteManager()
{
    for (auto itr : mSprites)
        delete itr.second;

    for (auto itr : mAnimationSprites)
        delete itr.second;

    mSprites.clear();
    mAnimationSprites.clear();
}
//-----------------------------------------------//
sf::Sprite* SpriteManager::GetSprite(std::string name)
{
    SpriteMap::iterator itr = mSprites.find(name);
    if (itr != mSprites.end())
        return itr->second;

    return nullptr;
}
//-----------------------------------------------//
void SpriteManager::RemoveSprite(std::string name)
{
    SpriteMap::iterator itr = mSprites.find(name);
    if (itr != mSprites.end())
    {
        delete itr->second;
        mSprites.erase(itr);
    }
}
//-----------------------------------------------//
Animation * SpriteManager::GetSpriteAnimation(std::string name)
{
    SpriteAnimationMap::iterator itr = mAnimationSprites.find(name);
    if (itr != mAnimationSprites.end())
        return itr->second;
  
    return nullptr;
}
//-----------------------------------------------//
void SpriteManager::AddSprite(std::string fileName)
{
    sf::Texture texture;

    if (texture.loadFromFile(fileName))
    {
        sf::Sprite* sprite = new sf::Sprite;
        sprite->setTexture(texture);

        mSprites[fileName] = sprite;
    }
}
//-----------------------------------------------//
void SpriteManager::AddSpriteAnimation(std::string fileName)
{
    sf::Texture* texture = new sf::Texture;
    if (texture->loadFromFile(fileName))
    {
        sf::Sprite* sprite = new sf::Sprite;
        sprite->setTexture(*texture);

        Animation* animation = new Animation(sprite, texture);

        animation->AddFrame(sf::IntRect(32, 0, 32, 32), MOVEMENT_WALKING_DOWN);
        animation->AddFrame(sf::IntRect(32, 96, 32, 32), MOVEMENT_WALKING_DOWN);

        mAnimationSprites[fileName] = animation;

        // We also add it into our sprite container aswell
        AddSprite(fileName);
    }
}
//-----------------------------------------------//
