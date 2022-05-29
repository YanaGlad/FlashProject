//
// Created by Boris Gusarov on 26.05.2022.
//

/// @file file_worker.h

#include "space_parting.h"
#include "defines.h"
#include "vector"
#include "string"

#ifndef FLASHPROJECT_FILE_WORKER_H
#define FLASHPROJECT_FILE_WORKER_H

/*!
 * Функция обрабоки файлов
 * @param[in] s информация об количестве и размерах файлов
 * @param[in] max_files_per_directory максимальное возможной кол-во файлов в директории
 * @param[in] dirs вектор с именами(путями до) папок
 * @param[in] origin_seed изначальный seed, для генерации последовательностей в файлах
 * @param[out] wrong очередь, содержащая информацию об битых файлах
*/
void FileWorker(
        space_parting_result s,
        std::uintmax_t max_files_per_directory,
        std::vector<std::string> dirs,
        uint64_t origin_seed,
        std::deque<wrong_pair> &wrong);

#endif //FLASHPROJECT_FILE_WORKER_H
