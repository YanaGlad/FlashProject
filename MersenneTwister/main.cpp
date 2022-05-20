#include <iostream>
#include "Generator.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    std::cout << generate_random_seed() << std::endl; // MT19937 test.
    std::cout << generate_fast_random_seed() << std::endl; // XORShift test.
    uint64_t seed = generate_fast_random_seed(); // Generating seed.
    uint8_t a = generate_binary_sequence(seed); // Generating uint8_t value.
    std::cout << unsigned(a); // print uint8_t value. Without unsigned() it should be unreadable.

    for (int i = 0; i < 1000; i++) {
        uint64_t seed = generate_fast_random_seed(); // Generating seed.
        std::cout << "seed = " << seed << std::endl; // XORShift test.
        uint8_t a = generate_binary_sequence(seed); // Generating uint8_t value.
        std::cout << "binary = " << unsigned(a) << std::endl;  // print uint8_t value. Without unsigned() it should be unreadable.
    }
    return 0;
}
