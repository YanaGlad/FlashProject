//
// Created by kirill N on 20.04.2022.
//

#include <string>
#include <filesystem>
#include <cstdint>

struct space_parting_result {
    std::uintmax_t count_files;
    std::uintmax_t size_base; //измеряем в байтах
    std::uintmax_t size_optional;
};

space_parting_result calc_space(std::string device_name) {
    std::filesystem::space_info si = std::filesystem::space(device_name);
    space_parting_result res = {0, 0, 0};
    res.size_base = calc_size_file(si.available);
    res.count_files = si.available / res.size_base;
    res.size_optional = si.available % res.size_base;
    return res;
}


