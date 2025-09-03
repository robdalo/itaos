#include "random.h"

uint32_t random_seed = 1;

void random_generate_seed() {
    random_seed = timer_get_counter_lower();
}

uint32_t random_get() {
    random_seed = random_seed * 1664525 + 1013904223;
    return random_seed;
}

uint32_t random_get_between(uint32_t min, uint32_t max) {
    return min + (random_get() % (max - min + 1));
}
