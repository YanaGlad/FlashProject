#include <iostream>
#include "MersenneTwisterImplementation.h"
#include <string>
#include <vector>

int main() {
    std::cout << "Hello, World!" << std::endl;

//    MersenneTwisterImplementation<uint64_t> mers = MersenneTwisterImplementation<uint64_t>(9, 7); // test for minimum > maximum exception

    MersenneTwisterImplementation<uint64_t> mersenneTwisterImplementation = MersenneTwisterImplementation<uint64_t>(7, 9);
    std::cout << mersenneTwisterImplementation.generateUint32Value() << std::endl;

//    MersenneTwisterImplementation<std::string> mers = MersenneTwisterImplementation<std::string>("csddcc"); // test for Incompatible type exception

    for (size_t i = 0; i < 10; ++i) {
        MersenneTwisterImplementation<uint64_t> mersenneTwisterImplementation = MersenneTwisterImplementation<uint64_t>(0, 100000);
        std::cout << mersenneTwisterImplementation.generateUint32Value() << std::endl;
    }

    MersenneTwisterImplementation<uint64_t> mersenneTwister = MersenneTwisterImplementation<uint64_t>(0, 1001);

    std::vector<uint32_t> vec = mersenneTwister.generateUint32Vector(3);

    std::cout << "Test for uint32_t vectors" << std::endl;

    for (auto item : vec) {
        std::cout << item << std::endl;
    }

    std::cout << "Test for uint64_t vectors" << std::endl;

    std::vector<uint64_t> vec1 = mersenneTwister.generateUint64Vector(3);

    for (auto item : vec1) {
        std::cout << item << std::endl;
    }

    std::vector<uint32_t> vec11 = mersenneTwister.generateUint32Vector(3, 1);

    std::cout << "Test for uint32_t vectors with seed" << std::endl;

    for (auto item : vec11) {
        std::cout << item << std::endl;
    }

    std::cout << "Test for uint64_t vectors with seed" << std::endl;

    std::vector<uint64_t> vec12 = mersenneTwister.generateUint64Vector(3, 1);

    for (auto item : vec12) {
        std::cout << item << std::endl;
    }

    std::vector<uint32_t> seedUint32 = {1, 2, 3};
    std::vector<uint32_t> vec111 = mersenneTwister.generateUint32VectorWithVectorOfSeeds(3, seedUint32);

    std::cout << "Test for uint32_t vectors with vector of seeds" << std::endl;

    for (auto item : vec111) {
        std::cout << item << std::endl;
    }

    std::cout << "Test for uint64_t vectors with vector of seeds" << std::endl;

    std::vector<uint32_t> seedUint64 = {4, 5, 6};
    std::vector<uint64_t> vec122 = mersenneTwister.generateUint64VectorWithVectorOfSeeds(3, seedUint64);

    for (auto item : vec122) {
        std::cout << item << std::endl;
    }

    std::cout << "Test with seed" << std::endl;

    MersenneTwisterImplementation<uint64_t> mersenneWithSeed = MersenneTwisterImplementation<uint64_t>(0, 100000);

    std::cout << mersenneTwister.generateUint32Value(1) << std::endl;
    std::cout << mersenneTwister.generateUint32Value(1) << std::endl;

    std::cout << "EQUALS!" << std::endl;

    return 0;
}
