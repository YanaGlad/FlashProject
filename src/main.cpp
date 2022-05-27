//
// Created by Boris Gusarov on 26.05.2022.
//

#include <deque>
#include <string>
#include <cstring>

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
    std::string root_dir = generate_uuid();
    std::uint64_t origin_seed = generate_fast_random_seed();
    std::uintmax_t corrupted_space = 0;

    std::filesystem::current_path(std::filesystem::path(start_device_name));
    std::filesystem::create_directory(root_dir);

    std::deque<wrong_pair> wrong_files = {wrong_pair(root_dir + char_separator, calc_device_space(start_device_name))};

    while (!wrong_files.empty()) 
    {
        wrong_pair w = wrong_files.front();
        wrong_files.pop_front();

        if (w.second == block_size)
            break;

        space_parting_result parting_res = calc_space(w.second);

        if (w.first != start_device_name) 
        {
            std::remove(w.first.c_str());
            w.first = w.first.substr(0, w.first.rfind(char_separator));
        }

        std::vector<std::string> dirs = create_directories(generate_path(w.first, calc_count_folder(parting_res)));
        FileWorker(parting_res, max_files_per_directory, dirs, origin_seed, wrong_files);
    }

    std::deque<std::filesystem::path> dirs_to_check = {std::filesystem::current_path()};

    while (!dirs_to_check.empty())
    {
        std::filesystem::path current_dir = dirs_to_check.front();
        dirs_to_check.pop_front();

        for (const auto & entry : std::filesystem::directory_iterator(current_dir))
        {
            if (std::filesystem::is_directory(entry.path())) dirs_to_check.push_back(entry.path());
            else {
	            if(entry.path().string().find(".") == 0) corrupted_space += entry.file_size();
                else std::filesystem::remove(entry.path());
            }
        }
    }
    
    // TODO: вывод результата
    return 0;
}


// TODO: добавить переменую для подсчета битого размера