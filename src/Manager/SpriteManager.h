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
* This file is responsible for creating sf::Sprite from loading images,
* from a directory which the user supplies.
* The sprites are loading into a map container using the key as the sprites name.
* The user can get sprites from the container or remove existing sprites from the container.
*/
#ifndef _Client_SpriteManager_h_
#include "SharedDefines.h"
#include "Animation.h"
#define _Client_SpriteManager_h_
#endif /* _Client_SpriteManager_h_ */

///< ENUMS

///< STRUCT

///< CLASS
class Menu;

///< TYPEDEF
typedef struct SpriteStruct
{
    sf::Sprite* sSprite;
    sf::Texture* sTexture;

} SpriteData;

typedef std::map<std::string, SpriteData> SpriteMap;
typedef std::map<std::string, Animation*> SpriteAnimationMap;

class SpriteManager
{
public:
    static SpriteManager* instance();
public:
    SpriteManager();
    ~SpriteManager();

public:
    SpriteData* GetSprite(std::string name);
    void RemoveSprite(std::string name);

    Animation* GetSpriteAnimation(std::string name);

    void AddSprite(std::string fileName);
    void AddSpriteAnimation(std::string fileName);

private:
    SpriteMap mSprites;
    SpriteAnimationMap mAnimationSprites;
};
#define sSpriteManager SpriteManager::instance()

