//
// Created by Boris Gusarov on 25.04.2022.
//

/// @file config.h

/*!
\file
\brief Заголовочный файл с константыми значениями программы
*/

#ifndef FLASHPROJECT_CONFIG_H
#define FLASHPROJECT_CONFIG_H

/**
* размер одного блока(мининамальная единица памяти)
*/
inline constexpr std::uintmax_t block_size = 262144; // 256 кб
/**
* минимальный размер файла
*/
inline constexpr std::uintmax_t min_file_size = block_size;
/**
* максимальный размер файла
*/
inline constexpr std::uintmax_t max_file_size = 268435456; // 256 мб
/**
* максимальное кол-во файлов на директорию
*/
inline constexpr std::uintmax_t max_files_per_directory = 128;

#endif //FLASHPROJECT_CONFIG_H
