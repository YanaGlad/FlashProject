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
#include "defines.h"

int main(int argc, char *argv[]) {
    if (!(argc == 3 && (std::strcmp(argv[1],"-d") != 0 || std::strcmp(argv[1],"--device") != 0))) return 1;

    std::string start_device_name = std::string(argv[2]);

    std::deque<wrong_pair> wrong_files = {wrong_pair(start_device_name, calc_device_space(start_device_name))};

    uint64_t origin_seed = generate_fast_random_seed();

    while (!wrong_files.empty()) {
        wrong_pair w = wrong_files.front();
        wrong_files.pop_front();

        if (w.second == block_size)
            break;

        space_parting_result parting_res = calc_space(w.second);

        if (w.first != start_device_name) {
            std::remove(w.first.c_str());
            w.first = w.first.substr(0, w.first.rfind(char_separator));
        }

        std::vector<std::string> dirs = create_directories(generate_path(w.first, calc_count_folder(parting_res)));
        FileWorker(parting_res, max_files_per_directory, dirs, origin_seed, wrong_files);
    }

    // TODO: удаление небитых файлов
    // TODO: вывод результата
    return 0;
}


// TODO: добавить переменую для подсчета битого размера