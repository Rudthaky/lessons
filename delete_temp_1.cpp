#include <iostream>
#include <cstdint>
#include <stdio.h>
#include <filesystem>
namespace fs = std::filesystem;
int main()
{
    fs::path dir = fs::temp_directory_path();
    fs::create_directories(dir / "/home/rudthaky/Документы/Temp_dir2");
    std::uintmax_t n = fs::remove_all(dir / "/home/rudthaky/Документы/Temp_dir");
    //std::experimental::filesystem::create_directories("/home/rudthaky/Документы/Temp_dir2");
    //std::experimental::filesystem::remove_all("/home/rudthaky/Документы/Temp_dir");
    std::cout<<"Deleted files or directories\n";
    std::cin.get();
}