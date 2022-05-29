//
// Created by Sergey Gorlov on 29.05.2022.
//

/// @file logger.h

#include <string>

#ifndef FLASHPROJECT_LOGGER_H
#define FLASHPROJECT_LOGGER_H

/*!
 * Выводит активность программы в консоль
 * @param[in] message сообщение для вывода в консоль
*/
void log(const std::string& message);

#endif //FLASHPROJECT_LOGGER_H
