#include <iostream>
#include <cmath>
#include <array>
#include <vector>
#include <GL/glut.h>
#include <string>
#include <chrono>
#include <thread>
#include <functional>

#include "Coin.h"
#include "BoundingBoard.h"
#include "Striker.h"
#include "Pocket.h"
#include "GenericCollidingChip.h"
#include "Player.h"

extern BoundingBoard *board;
extern Striker *striker;
extern std::array<Pocket * , 4> pockets;
extern std::vector<Coin *> coins;
extern Player *player;


#ifndef E
#define E 0.8
#endif

#ifndef MuMg
#define MuMg 0.99
#endif

