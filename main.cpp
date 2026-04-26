#include <iostream>
#include <dirent.h>
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

int main() {
    list_directory(".");
    return 0;
}
