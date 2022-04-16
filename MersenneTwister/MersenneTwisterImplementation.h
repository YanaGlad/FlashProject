//
// Created by Kirill Zhukov on 15.04.2022.
//

#ifndef MERSENNETWISTERCLASS_MERSENNETWISTERIMPLEMENTATION_H
#define MERSENNETWISTERCLASS_MERSENNETWISTERIMPLEMENTATION_H

#include <random>
#include <exception>
#include <vector>

struct IncompatibleException : std::exception {
    const char *what() const throw() {
        return "Incompatible type. Available types: int, long, uint16_t, uint32_t, uint_64_t.";
    }
};

struct ValueException : std::exception {
    const char *what() const throw() {
        return "Minimum value should be lower than maximum value.";
    }
};

struct SeedException : std::exception {
    const char *what() const throw() {
        return "Size of vector of seed is lower than size of quantity to generate";
    }
};

template<typename T>
class MersenneTwisterImplementation : public std::exception {

private:
    T minimum;
    T maximum;
protected:
    bool checkIfCompatible() {
        return std::is_same<T, uint32_t>::value || std::is_same<T, uint64_t>::value;
    }

public:
    MersenneTwisterImplementation(T minimum, T maximum) {
        if (!this->checkIfCompatible()) {
            IncompatibleException e;
            throw e;
        }

        if (minimum > maximum) {
            ValueException e;
            throw e;
        }

        this->minimum = minimum;
        this->maximum = maximum;
    }

    uint32_t generateUint32Value(T seed = 0) {
        std::random_device device;
        std::mt19937 generator(device());
        if (seed != 0) {
            generator.seed(seed);
        }
        std::uniform_int_distribution<int> distribution(this->minimum, this->maximum);
        return distribution(generator);
    }

    uint64_t generateUint64Value(T seed = 0) {
        std::random_device device;
        std::mt19937_64 generator(device());
        if (seed != 0) {
            generator.seed(seed);
        }
        std::uniform_int_distribution<int> distribution(this->minimum, this->maximum);
        return distribution(generator);
    }

    std::vector<uint32_t> generateUint32Vector(int quantity, T seed = 0) {
        std::vector<uint32_t> vec;
        for (int i = 0; i < quantity; i++) {
            vec.push_back(this->generateUint32Value(seed));
        }
        return vec;
    }

    std::vector<uint64_t> generateUint64Vector(int quantity, T seed = 0) {
        std::vector<uint64_t> vec;
        for (int i = 0; i < quantity; i++) {
            vec.push_back(this->generateUint64Value(seed));
        }
        return vec;
    }

    void setMinimum(T minimum) {
        this->minimum = minimum;
    }

    void setMaximum(T maximum) {
        this->maximum = maximum;
    }

    T getMinimum() {
        return this->minimum;
    }

    T getMaximum() {
        return this->maximum;
    }

    template<class T1>
    std::vector<uint32_t> generateUint32VectorWithVectorOfSeeds(T quantity, std::vector<T1> seed) {
        if (seed.size() < quantity) {
            SeedException e;
            throw e;
        }

        std::vector<uint32_t> vec;
        for (int i = 0; i < quantity; i++) {
            vec.push_back(this->generateUint32Value(seed[i]));
        }
        return vec;
    }

    template<class T1>
    std::vector<uint64_t> generateUint64VectorWithVectorOfSeeds(T quantity, std::vector<T1> seed) {
        if (seed.size() < quantity) {
            SeedException e;
            throw e;
        }

        std::vector<uint64_t> vec;
        for (int i = 0; i < quantity; i++) {
            vec.push_back(this->generateUint64Value(seed[i]));
        }
        return vec;
    }
};

#endif //MERSENNETWISTERCLASS_MERSENNETWISTERIMPLEMENTATION_H
