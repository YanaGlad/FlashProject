//
// Created by Igor Stikentzin on 20.05.2022.
//

#ifndef UNTITLED7_GENERATOR_H
#define UNTITLED7_GENERATOR_H

#include <cstdint>

uint64_t generate_random_seed();

uint64_t generate_fast_random_seed(uint64_t max = UINT64_MAX);

uint8_t generate_binary_sequence(uint64_t &seed);

#endif //UNTITLED7_GENERATOR_H
