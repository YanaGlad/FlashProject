#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
#include <filesystem>

#include "space_parting.h"
#include "generate_sequence.h"
#include "check_file.h"
#include "defines.h"

void create_files(const std::string& path, std::uintmax_t files_per_directory, std::uintmax_t size_base, uint64_t &seed) {
    for (int j = 1; j <= files_per_directory; j++) {
        auto file_path = path + char_separator + std::to_string(j);
        std::ofstream ofs(file_path, std::ios::binary);
        for (int i = 0; i < size_base; i++) // проверка на конец файла
            ofs << seed;
        seed++;
    }
}

void create_optional(const std::string& path, std::uintmax_t size_optional, uint64_t &seed) {
    auto file_path = path + char_separator + "optional";
    std::ofstream ofs(file_path, std::ios::binary);
    for (int i = 0; i < size_optional; i++)
        ofs << seed;
}

void check_files(const std::string& path, std::uintmax_t size, std::uintmax_t files_per_directory, uint64_t &seed, std::deque<wrong_pair> &wrong) {
    for (int j = 1; j <= files_per_directory; j++) {
        auto file_path = path + char_separator + std::to_string(j);
        if (!check_file_is_valid(file_path, seed)) {
            auto new_file_path = path + char_separator + corrupted_mark + std::to_string(j);
            std::rename(file_path.c_str(), new_file_path.c_str());

            wrong.emplace_back(new_file_path, size);
        }
        seed++;
    }
}

void check_optional(const std::string& path, std::uintmax_t size, uint64_t &seed, std::deque<wrong_pair> &wrong) {
    auto file_path = path + char_separator + "optional";

    if (check_file_is_valid(file_path, seed)) return;

    auto new_file_path = path + char_separator + ".optional";
    std::rename(file_path.c_str(), new_file_path.c_str());

    wrong.emplace_back(new_file_path, size);
}

void FileWorker(
        space_parting_result s,
        std::uintmax_t max_files_per_directory,
        std::vector<std::string> dirs,
        uint64_t origin_seed,
        std::deque<wrong_pair> &wrong) {
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
        check_files(dirs[i], s.size_base, max_files_per_directory, seed_copy, wrong);
    }
    check_files(dirs[dirs.size() - 1], s.size_base, s.count_files % max_files_per_directory, seed_copy, wrong);

    if (s.size_optional != 0)
        check_optional(dirs[dirs.size() - 1] + char_separator + "optional", s.size_optional, seed_copy, wrong);
}
