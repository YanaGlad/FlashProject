//
// Created by Sergey Gorlov on 25.04.2022.
//
#include <vector>
#include <math.h>
#include <string>
#include <filesystem>
#include <map>
#include "space_parting.h"
#include "config.h"
#include "generate_uuid.h"

std::vector<int> calc_count_folder(struct space_parting_result res){
    std::vector<int> result;
    auto count_files = (double)res.count_files;
    if (res.size_optional != 0) {count_files++;}

    while (count_files != 1) {
        count_files = ceil(count_files / max_files_per_directory);
        result.push_back((int)count_files);
    }

    return result;
}

std::vector<std::filesystem::path> generate_path(std::filesystem::path device_name, std::vector<int> dirs_per_level){
    std::uintmax_t last_elem = dirs_per_level.size() - 1;
    std::uintmax_t vector_size = dirs_per_level.size();
    std::uintmax_t level;

    std::filesystem::path current_path;
    std::map<int, std::vector<std::filesystem::path>> paths;

    paths.insert(std::pair<int, std::vector<std::filesystem::path>>(0,std::vector<std::filesystem::path>{device_name}));

    current_path /= device_name;
    current_path /= generate_uuid();

    while (!dirs_per_level.empty()){
        std::vector<std::filesystem::path> q;
        std::vector<std::filesystem::path> path_on_level;
        level = vector_size - dirs_per_level.size() + 1;

        auto it = paths.begin();
        for (; it != paths.end(); it++) {
            if (it->first == level - 1)q = it->second;
        }

        for (int i = 0; i < dirs_per_level[last_elem]; ++i) {
            for (std::filesystem::path &path:q) {
                current_path = path;
                current_path /= generate_uuid();
                path_on_level.push_back(current_path);
            }
        }
        paths.insert(std::pair<int, std::vector<std::filesystem::path>>(level, path_on_level));
        dirs_per_level.pop_back();
        last_elem = dirs_per_level.size() - 1;
    }

    return paths[(int)level];
}

std::vector<std::string> create_directories(std::vector<std::filesystem::path> paths){
    std::vector<std::string> res;

    for (auto & path : paths) {
        std::filesystem::create_directories(path);
        res.push_back(path.string());
    }
    return res;
}

