//
// Created by Sergey Gorlov on 26.05.2022.
//

/// @file create_directories.h

#include <filesystem>
#include <vector>
#include <string>

#ifndef FLASHPROJECT_CREATE_DIRECTORIES_H
#define FLASHPROJECT_CREATE_DIRECTORIES_H

/*!
 * Считает кол-во папок на каждом уровне
 * @param[in] res данные о файлах
*/
std::vector<int> calc_count_folder(struct space_parting_result res);
/*!
 * Генерирует пути, для последующего создания папок
 * @param[in] device_name путь до устройства
 * @param[in] dirs_per_level кол-во папок на каждом уровне
*/
std::vector<std::filesystem::path> generate_path(std::filesystem::path device_name, std::vector<int> dirs_per_level);
/*!
 * Создает директории и возвращает пути до них
 * @param[in] paths пути до папок
*/
std::vector<std::string> create_directories(std::vector<std::filesystem::path> paths);

#endif //FLASHPROJECT_CREATE_DIRECTORIES_H
