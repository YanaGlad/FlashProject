//
// Created by Boris Gusarov on 26.05.2022.
//

#include <deque>
#include <string>
#include <cstring>
#include <iostream>

#include "space_parting.h"
#include "create_directories.h"
#include "file_worker.h"
#include "config.h"
#include "generate_sequence.h"
#include "generate_uuid.h"
#include "defines.h"

int main(int argc, char *argv[]) 
{
    if (!(argc == 3 && (std::strcmp(argv[1],"-d") != 0 || std::strcmp(argv[1],"--device") != 0))) return 1;

    std::string start_device_name = std::string(argv[2]);
    if (start_device_name.back() != char_separator)
        start_device_name += char_separator;

    std::string root_dir = generate_uuid();
    std::uint64_t origin_seed = generate_fast_random_seed();

    std::filesystem::create_directory(start_device_name + root_dir);
    std::filesystem::current_path(std::filesystem::path(start_device_name + root_dir));

    std::deque<wrong_pair> wrong_files = {wrong_pair(root_dir + char_separator, calc_device_space(start_device_name))};

    while (!wrong_files.empty()) 
    {
        wrong_pair w = wrong_files.front();
        wrong_files.pop_front();

        if (w.second == block_size) // пропускаем, если размер предыдущего разбиения равен минимальному
            continue;

        space_parting_result parting_res = calc_space(w.second); // следующее разбиение

        if (w.first.back() != char_separator) // если работаем с путем к битому файлу, удаляем этот файл
        {
            std::remove(w.first.c_str());
            w.first = w.first.substr(0, w.first.rfind(char_separator));
        }

        // создание директорий, получение путей к ним
        std::vector<std::string> dirs = create_directories(generate_path(w.first, calc_count_folder(parting_res)));
        // создание файлов и их проверка
        FileWorker(parting_res, max_files_per_directory, dirs, origin_seed, wrong_files);
    }

    // процесс удаления целых файлов
    std::deque<std::filesystem::path> dirs_to_check = {std::filesystem::current_path()};
    std::uintmax_t corrupted_space = 0;

    while (!dirs_to_check.empty())
    {
        std::filesystem::path current_dir = dirs_to_check.front();
        dirs_to_check.pop_front();

        for (const auto & entry : std::filesystem::directory_iterator(current_dir))
        {
            if (std::filesystem::is_directory(entry.path())) dirs_to_check.push_back(entry.path());
            else {
                if(entry.path().string().front() == corrupted_mark) corrupted_space += entry.file_size();
                else std::filesystem::remove(entry.path());
            }
        }
    }

    // Вывод результата
    std::uintmax_t kb = corrupted_space / 1024;
    std::uintmax_t mb = kb / 1024;
    std::uintmax_t gb = mb / 1024;
    std::cout << "Corrupted space: " << gb << " GB, " << mb % 1024 << " MB, " << kb % 1024 << " KB, " << corrupted_space % 1024 << " B";
    return 0;
}
