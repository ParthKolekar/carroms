#include <iostream>
#include <cmath>
#include <array>
#include <vector>
#include <GL/glut.h>

#include "Coin.h"
#include "BoundingBoard.h"
#include "Striker.h"
#include "Pocket.h"

extern BoundingBoard *board;
extern Striker *striker;
extern std::array<Pocket * , 4> pockets;
extern std::vector<Coin *> coins;
