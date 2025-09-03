#ifndef RANDOM_H
#define RANDOM_H

#include "timer.h"

void random_generate_seed();
uint32_t random_get();
uint32_t random_get_between(uint32_t min, uint32_t max);

#endif