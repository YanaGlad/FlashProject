//
// Created by Igor Stikentzin on 20.04.2022.
//

/// @file check_file.h

#ifndef FLASHPROJECT_CHECK_FILE_H
#define FLASHPROJECT_CHECK_FILE_H

#include <string>

/*!
 * Проверяет файл на ошибки
 * @param[in] file_name Путь до файла
 * @param[in] seed Seed, с помощью которого генерировался файл
*/
bool check_file_is_valid(std::string const& file_name, uint64_t seed);

#endif //FLASHPROJECT_CHECK_FILE_H