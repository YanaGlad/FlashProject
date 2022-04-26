//
// Created by Boris G on 25.04.2022.
//

#ifndef FLASHPROJECT_CONFIG_H
#define FLASHPROJECT_CONFIG_H

inline constexpr std::uintmax_t block_size = 262144; // 256 кб
inline constexpr std::uintmax_t min_file_size = block_size;
inline constexpr std::uintmax_t max_file_size = 268435456; // 256 мб

#endif //FLASHPROJECT_CONFIG_H
