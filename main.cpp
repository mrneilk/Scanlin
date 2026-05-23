// Raw code exported from Google Gimini - 26th April  2026
// Backtrack and reverse engineer from the code to create flow and use case

// This code is a simple C++ program that lists the contents of a directory. 
// It uses the POSIX API to read the directory entries and prints the names of the files and 
// subdirectories found in the specified path. The program defines a function `list_directory` that 
// takes a string representing the path to the directory, opens it, and iterates through its contents 
// while skipping the current (`.`) and parent (`..`) directory entries. The main function calls `list_directory` 
// with the current directory (`"."`) as an argument, which means it will list the contents of the directory where the program is executed.

//Header files included in the code:

#include <iostream>

// The following headers are included to provide functionality for directory handling and file status information.
#include <dirent.h>
// The <sys/stat.h> header is included to provide information about file status, although it is not used in the current implementation of the code.
#include <sys/stat.h>
#include <string>
#include <vector>

void list_directory(const std::string& path) {
    DIR* dir = opendir(path.c_str());
    if (dir == nullptr) {
        std::cerr << "Could not open directory: " << path << std::endl;
        return;
    }

    struct dirent* entry;
    // Iterate through directory entries
    while ((entry = readdir(dir)) != nullptr) {
        std::string filename = entry->d_name;
        
        // Skip current and parent directory pointers
        if (filename == "." || filename == "..") continue;

        std::cout << "Found: " << filename << std::endl;
    }

    closedir(dir);
}

// The main function serves as the entry point of the program. It calls the `list_directory` function with the current directory (".") as an argument,
// which will list the contents of the directory where the program is executed.
int main() {
    // call to function
    list_directory(".");
    return 0;
}
