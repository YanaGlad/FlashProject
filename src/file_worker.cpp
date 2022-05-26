#include <iostream>
#include <fstream>
#include "space_parting.h"
#include "generate_sequence.h"
#include <vector>
#include "filesystem"
#include "check_file.h"
#include "deque"

void create_files(std::string path, std::uintmax_t files_per_directory, std::uintmax_t size_base, uint64_t &seed) {
    for (int j = 1; j <= files_per_directory; j++) {
        auto file_path = path + static_cast<char>(std::filesystem::path::preferred_separator) + std::to_string(j);
        std::ofstream ofs(file_path, std::ios::binary);
        for (int i = 0; i < size_base; i++) // проверка на конец файла
            ofs << seed;
        seed++;
    }
}

void create_optional(std::string path, std::uintmax_t size_optional, uint64_t &seed) {
    auto file_path = path + static_cast<char>(std::filesystem::path::preferred_separator) + "optional";
    std::ofstream ofs(file_path, std::ios::binary);
    for (int i = 0; i < size_optional; i++)
        ofs << seed;
}

void check_files(std::string path, std::uintmax_t files_per_directory, uint64_t &seed, std::deque<std::string> &wrong) {
    for (int j = 1; j <= files_per_directory; j++) {
        auto file_path = path + static_cast<char>(std::filesystem::path::preferred_separator) + std::to_string(j);
        if (!check_file_is_valid(file_path, seed))
            wrong.push_back(file_path);
        seed++;
    }
}

void FileWorker(
        space_parting_result s,
        std::uintmax_t max_files_per_directory,
        std::vector<std::string> dirs,
        uint64_t origin_seed,
        std::deque<std::string> &wrong) {
    // генерим файлы
    uint64_t seed_copy = origin_seed;
    for (int i = 0; i < dirs.size() - 1; i++) { // до последней папки
        create_files(dirs[i], max_files_per_directory, s.size_base, seed_copy); // создание файлов и заполнение их сидом
    }
    create_files(dirs[dirs.size() - 1], s.count_files % max_files_per_directory, s.size_base, seed_copy);
    if (s.size_optional != 0)
        create_optional(dirs[dirs.size() - 1], s.size_optional, seed_copy);

    // проверяем
    seed_copy = origin_seed;
    for (int i = 0; i <= dirs.size() - 1; i++) {
        check_files(dirs[i], max_files_per_directory, seed_copy, wrong);
    }
    check_files(dirs[dirs.size() - 1], s.count_files % max_files_per_directory, seed_copy, wrong);
    if (s.size_optional != 0) {
        auto file_path = dirs[dirs.size() - 1] + static_cast<char>(std::filesystem::path::preferred_separator) + "optional";
        if (!check_file_is_valid(file_path, seed_copy))
            wrong.push_back(file_path);
    }
}
