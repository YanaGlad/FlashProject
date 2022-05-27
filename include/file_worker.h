//
// Created by black on 26.05.2022.
//

#include "space_parting.h"
#include "defines.h"
#include "vector"
#include "string"

#ifndef FLASHPROJECT_FILE_WORKER_H
#define FLASHPROJECT_FILE_WORKER_H

void FileWorker(
        space_parting_result s,
        std::uintmax_t max_files_per_directory,
        std::vector<std::string> dirs,
        uint64_t origin_seed,
        std::deque<wrong_pair> &wrong);

#endif //FLASHPROJECT_FILE_WORKER_H
