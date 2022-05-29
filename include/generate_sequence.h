//
// Created by Igor Stikentzin on 20.05.2022.
//

/// @file generate_sequence.h

#ifndef UNTITLED7_GENERATOR_H
#define UNTITLED7_GENERATOR_H

#include <cstdint>

/*!
 * Генерирует рандомный seed с помощью алгоритма Вихрь Мерсенна
*/
uint64_t generate_random_seed();

/*!
 * Генерирует рандомный seed (быстро)
 * @param[in] max макс значение seed
*/
uint64_t generate_fast_random_seed(uint64_t max = UINT64_MAX);

/*!
 * Генерирует бинарную последовательность из переданного seed
*/
uint8_t generate_binary_sequence(uint64_t &seed);

#endif //UNTITLED7_GENERATOR_H
