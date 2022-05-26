//
// Created by Boris Gusarov on 26.05.2022.
//

#include "space_parting.h"
#include "deque"
#include "string"
#include "create_directories.h"
#include "file_worker.h"
#include "config.h"
#include "generate_sequence.h"

int main() {
    std::string start_device_name = ""; // TODO

    std::uintmax_t available = calc_device_space(start_device_name);
    std::deque<std::string> wrong_files = {start_device_name};

    uint64_t origin_seed = generate_fast_random_seed();

    while (!wrong_files.empty()) {
        if (available == block_size)
            break;

        std::string device_name = wrong_files.front();
        wrong_files.pop_front();

        space_parting_result parting_res = calc_space(available);
        std::vector<std::string> dirs = create_directories(generate_path(device_name, calc_count_folder(parting_res)));
        FileWorker(parting_res, max_files_per_directory, dirs, origin_seed, wrong_files);

        available = parting_res.size_base;
    }

    // TODO: удаление небитых файлов
    // TODO: вывод результата
}
