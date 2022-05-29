//
// Created by Sergey Gorlov on 25.04.2022.
//

/// @file space_parting.h

#include <cstdint>
#include <string>

#ifndef FLASHPROJECT_SPACE_PARTING_H
#define FLASHPROJECT_SPACE_PARTING_H

/**
 * Структура содержащая информацию о кол-ве создаваемых файлов и их размере 
 */
struct space_parting_result {
    std::uintmax_t count_files; /**< кол-во файлов */
    std::uintmax_t size_base; /**< размер файлов (в байтах) */
    std::uintmax_t size_optional; /**< доп. поле, если не получается распределить место на равные блоки */
};

/*!
 * Вычисляем размер следующего измельчения (на файлы какого размера его можно разбить)
 * @param[in] prev_available размер предыдущего измельчения
*/
std::uintmax_t calc_size_file(std::uintmax_t prev_available);
/*!
 * Получаем структуру с информацией о файлах
 * @param[in] available размер доступного места
*/
space_parting_result calc_space(std::uintmax_t available);
/*!
 * Получаем информацию о доступном месте на устройстве
 * @param[in] device_name путь до устройства
*/
std::uintmax_t calc_device_space(std::string device_name);

#endif //FLASHPROJECT_SPACE_PARTING_H
