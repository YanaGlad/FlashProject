//
// Created by Igor Stikentzin on 20.04.2022.
//

#include <cstring>
#include <string>
#include <fstream>
#include "generate_sequence.h"

#include "check_file.h"

bool check_file_is_valid(std::string const& file_name, uint64_t seed) {
    uint8_t read_buff;
    uint8_t gen_val = generate_binary_sequence(seed);
    bool result = true;

    std::ifstream bin_file(file_name, std::ios::binary);

    if(!bin_file)
        throw std::runtime_error(file_name + ": " + std::strerror(errno));
    
    while (!bin_file.eof())
    {
        bin_file >> read_buff;
        if (read_buff != gen_val) {result = false; break;}
    }
    
    return result;
}