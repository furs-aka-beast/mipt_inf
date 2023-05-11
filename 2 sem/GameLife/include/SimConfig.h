#include "Types.h"


static const i16 grass_max = 100;
static const i16 grass_inc = 1;

static const size_t field_h = 10;
static const size_t field_w = 20;

static const i16 satiety_hungry = 50;
static const i16 satiety_mitosis = 80;
static const i16 satiety_max = 100;
static const i16 satiety_default = 70;
static const i16 min_grass_for_herbivorous = 10;
static const i16 satiety_per_tick = 5;
static const std::chrono::milliseconds time_between_ticks{200};