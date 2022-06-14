//
// Created by Sergey Gorlov on 29.05.2022.
//
#include <iostream>
#include <ctime>
#include <iomanip>
#include <string>

#include "logger.h"


void log(const std::string& message){
    system("CLS");
    std::time_t result = std::time(nullptr);
    std::tm tm = *std::localtime(&result);
    std::cout << std::put_time(&tm, "%c") << message <<'\n';
}