//
// Created by Sergey Gorlov on 25.04.2022.
//

#ifndef FLASHPROJECT_SPACE_PARTING_H
#define FLASHPROJECT_SPACE_PARTING_H

struct space_parting_result {
    std::uintmax_t count_files;
    std::uintmax_t size_base; // измеряем в байтах
    std::uintmax_t size_optional;
};

#endif //FLASHPROJECT_SPACE_PARTING_H
