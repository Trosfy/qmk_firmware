 /* Copyright 2021 OpenAnnePro community
  * 
  * This program is free software: you can redistribute it and/or modify 
  * it under the terms of the GNU General Public License as published by 
  * the Free Software Foundation, either version 2 of the License, or 
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
  
#pragma once

// Obins stock firmware has something similar to this already enabled, but disabled by default in QMK
#define PERMISSIVE_HOLD

// Mouse setting
#define MK_KINETIC_SPEED
#define MOUSEKEY_INITIAL_SPEED 200
#define MOUSEKEY_BASE_SPEED 1600

// Leaderkey
#define LEADER_PER_KEY_TIMING
#define LEADER_TIMEOUT 250

