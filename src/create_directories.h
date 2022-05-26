//
// Created by black on 26.05.2022.
//

#include "filesystem"

#ifndef FLASHPROJECT_CREATE_DIRECTORIES_H
#define FLASHPROJECT_CREATE_DIRECTORIES_H

std::vector<int> calc_count_folder(struct space_parting_result res);

std::vector<std::filesystem::path> generate_path(std::filesystem::path device_name, std::vector<int> dirs_per_level);

std::vector<std::string> create_directories(std::vector<std::filesystem::path> paths);

#endif //FLASHPROJECT_CREATE_DIRECTORIES_H
