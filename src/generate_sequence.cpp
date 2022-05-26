//
// Created by Kirill Zhukov on 14.05.2022.
//

#define N_MAX 8 // change for max value you need(excluded from the fix task)
#include <random>
#include <exception>
#include <vector>
#include <bitset>
#include <ctime>
#include <chrono>

#include "generate_sequence.h"

uint64_t generate_random_seed() { // Mersenne twister. P.S it's slow. But period is 2**19937 - 1
    std::random_device device;
    std::mt19937_64 generator(device());
    std::uniform_int_distribution<uint64_t> distribution(0, 0xFFFFFFFF);
    return distribution(generator);
};

uint64_t generate_fast_random_seed(uint64_t max) { // XORShift. P.S much faster than MT19937. But period is only 2**127
    std::chrono::nanoseconds ns = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch());
    long last = ns.count() | 1;
    long inc = ns.count();
    last ^= (last << 21);
    last ^= (last >> 35);
    last ^= (last << 4);
    inc += 123456789123456789L;
    int out = (int) ((last+inc) & max);
    return (out < 0) ? -out : out;
}


uint8_t generate_binary_sequence(uint64_t &seed) { // Converting seed(uint64_t) into uint8_t
    return (seed & 0xFF);
}
