#* Liam Ashdown
#* Copyright (C) 2018
#*
#* This program is free software: you can redistribute it and/or modify
#* it under the terms of the GNU General Public License as published by
#* the Free Software Foundation, either version 3 of the License, or
#* (at your option) any later version.
#*
#* This program is distributed in the hope that it will be useful,
#* but WITHOUT ANY WARRANTY; without even the implied warranty of
#* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#* GNU General Public License for more details.
#*
#* You should have received a copy of the GNU General Public License
#* along with this program.  If not, see <http://www.gnu.org/licenses/>.
#*/

#Set the minimum version of CMake that can be used
# To find the cmake version run
# $ cmake --version
# Set the project name
project (UknownProject)

cmake_minimum_required(VERSION 3.2)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Entity)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Entity/Ships)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Entity/Player)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Game)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Game/Handlers)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Game/Menu)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Game/Menu/Trigger)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Manager)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Resources)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Resources/Fonts)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Resources/Images)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Resources/Images/Ships)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Resources/Images/Ships/Vegeance)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Shared)

file(GLOB_RECURSE source_list RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" "*.cpp" "*.h")

add_executable(Client ${source_list})

foreach(source IN LISTS source_list)
    get_filename_component(source_path "${source}" PATH)
    string(REPLACE "/" "\\" source_path_msvc "${source_path}")
    source_group("${source_path_msvc}" FILES "${source}")
endforeach()
