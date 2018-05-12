#ifndef _GAME_H_
#define _GAME_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

#define WEIGHT 60
#define HIGHT 45
#define FW_X 20
#define FW_Y 9

int init_framework(char (*fw)[FW_X]);
int dispaly_framework(char (*fw)[FW_X]);
#endif
