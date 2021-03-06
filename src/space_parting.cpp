//
// Created by kirill N on 20.04.2022.
//

#include <string>
#include <filesystem>
#include <cmath>
#include "config.h"

#include "space_parting.h"

std::uintmax_t calc_size_file(std::uintmax_t prev_available) {
    std::uintmax_t new_size = (std::uintmax_t)(sqrtl(prev_available / block_size)) * block_size;

    if (new_size > max_file_size) return max_file_size;
    return new_size;
}

space_parting_result calc_space(std::uintmax_t available) {
    space_parting_result res = {0, 0, 0};
    res.size_base = calc_size_file(available);
    res.count_files = available / res.size_base;
    res.size_optional = available % res.size_base;
    return res;
}

std::uintmax_t calc_device_space(std::string device_name) {
    std::filesystem::space_info si = std::filesystem::space(device_name);
    return si.available;
}
