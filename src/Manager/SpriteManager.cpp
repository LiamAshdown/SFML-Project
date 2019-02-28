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
SpriteManager::SpriteManager()
{
}
//-----------------------------------------------//
SpriteManager::~SpriteManager()
{
    for (auto itr : mSprites)
        delete itr.second;

    mSprites.clear();
}
//-----------------------------------------------//
void SpriteManager::LoadSprites()
{
    ///< Loading an image
    AddSprite("test.png");
}
//-----------------------------------------------//
sf::Sprite* SpriteManager::GetSprite(const char * name)
{
    SpriteMap::iterator itr = mSprites.find(name);
    if (itr != mSprites.end())
        return itr->second;
}
//-----------------------------------------------//
void SpriteManager::RemoveSprite(const char * name)
{
    SpriteMap::iterator itr = mSprites.find(name);
    if (itr != mSprites.end())
    {
        delete itr->second;
        mSprites.erase(itr);
    }
}
//-----------------------------------------------//
void SpriteManager::AddSprite(const char * fileName)
{
    sf::Texture texture;

    if (texture.loadFromFile(fileName))
    {
        sf::Sprite* sprite = new sf::Sprite;
        sprite->setTexture(texture);

        mSprites[fileName] = sprite;
    }
    else
        ;//LOG(INFO, "CANNOT LOAD IMAGE");
}
//-----------------------------------------------//
