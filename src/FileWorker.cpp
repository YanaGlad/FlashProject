#include <iostream>
//#include "MersenneTwisterImplementation.h"
#include <fstream>
#include "space_parting.h"
#include "generate_sequence.h"
#include <vector>

void create_files(std::string path, std::uintmax_t max_files_per_directory, std::uintmax_t size_base, uint64_t &seed) {
    for (int j = 1; j <= max_files_per_directory; j++) {
        std::string s = std::to_string(j);
        std::ofstream ofs(s, std::ios::binary);
        for (int i = 0; i < size_base; i++) // проверка на конец файла
            ofs << seed;
        seed++;
    }
}

 void FileWorker(space_parting_result s, std::uintmax_t max_files_per_directory, std::vector<std::string> dirs, uint64_t myseed) {
    myseed = generate_fast_random_seed();
    for (int i = 1; i <= dirs.size() - 1; i++) { // до последней папки
        create_files(dirs[i], max_files_per_directory, s.size_base, myseed); // создание файлов и заполнение их сидом
    }
    if (s.size_optional != 0) {
        create_files(dirs[dirs.size() - 1], s.count_files%max_files_per_directory - 1, s.size_base, myseed); // до последнего файла
        create_files(dirs[dirs.size() - 1], 1, s.size_optional, myseed); // для последнего файла с опциональным размером
    }
    else {
        create_files(dirs[dirs.size() - 1], s.count_files%max_files_per_directory, s.size_base, myseed); // без опционального размера
    }
};

