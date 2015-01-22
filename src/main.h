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


#ifndef RESTITUTION_CONSTANT
#define RESTITUTION_CONSTANT 0.8
#endif

#ifndef LINEAR_FRICTIONAL_EFFECT
#define LINEAR_FRICTIONAL_EFFECT 0.99
#endif

#ifndef COINS_COUNT
#define COINS_COUNT 10
#endif

#ifndef BOARD_HEIGHT
#define BOARD_HEIGHT 10
#endif

#ifndef BOARD_WIDTH
#define BOARD_WIDTH 10
#endif

#ifndef SPACING_RADIUS
#define SPACING_RADIUS 0.5
#endif
