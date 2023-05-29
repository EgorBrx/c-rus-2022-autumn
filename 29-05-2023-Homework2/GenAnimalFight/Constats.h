#pragma once
#include "Point.h"

#define north Point(-1,0)
#define south Point(1,0)
#define west Point(0,-1)
#define east Point(0,1)
#define north_west Point(-1,-1)
#define north_east Point(-1,1)
#define south_west Point(1,-1)
#define south_east Point(1,1)

#ifndef CONSTANTS_H
#define CONSTANTS_H
extern const int         minPower;
extern const int         maxPower;
extern const int         countCommand;
extern const int         BrainPowerMax;/////количество действия животного
extern const int         MutationLvl;///количество генов, которые меняются
extern const int         maxHunger;
extern const Point       cardinalGroup[8];
extern int   FIGHT;
extern const int         countParentinGen;
extern const int         nameCount;
extern const int	     foodCount;
extern const int         foodEfficiency;
extern const int		 typecount;
extern const int		 GameSize;
#endif

