//
// Created by Sergey Gorlov on 25.04.2022.
//

#include <cstdint>
#include <string>

#ifndef FLASHPROJECT_SPACE_PARTING_H
#define FLASHPROJECT_SPACE_PARTING_H

struct space_parting_result {
    std::uintmax_t count_files;
    std::uintmax_t size_base; // измеряем в байтах
    std::uintmax_t size_optional;
};

std::uintmax_t calc_size_file(std::uintmax_t prev_available);

space_parting_result calc_space(std::uintmax_t available);

std::uintmax_t calc_device_space(std::string device_name);

#endif //FLASHPROJECT_SPACE_PARTING_H
