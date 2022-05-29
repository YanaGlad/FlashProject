//
// Created by Igor Stikenzin on 27.05.2022.
//

/// @file defines.h

#ifndef FLASHPROJECT_DEFINES_H
#define FLASHPROJECT_DEFINES_H

/**
* информация об испорченном файле (имя, размер)
*/
#define wrong_pair std::pair<std::string, std::uintmax_t>
/**
* символ-разделитель для пути в файловой системе
*/
#define char_separator static_cast<char>(std::filesystem::path::preferred_separator)
/**
* символ обозначающий поврежденный файл
*/
#define corrupted_mark '.'

#endif //FLASHPROJECT_DEFINES_H
