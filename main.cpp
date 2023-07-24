#include "header.h"
// Define and initialize the OS variable
std::string OS;

int main() {
    std::ifstream osRelease("/etc/os-release");
    std::string line, distribution, distro;

    if (osRelease.is_open()) {
        while (std::getline(osRelease, line)) {
            if (line.find("PRETTY_NAME=") != std::string::npos){
                distribution = line.substr(line.find("=") + 1);
            }
            if (line.find("ID_LIKE=") != std::string::npos){
                distro = line.substr(line.find("=") + 1);
                break;
            }
        
        }
        
    }

    #if defined(_WIN32) || defined(_WIN64)
        OS = "Windows ";
        #if defined(_WIN32)
            OS += "(x32)";
        #elif defined(_WIN64)
            OS += "(x64)";
    #endif

    #elif defined(__linux__)
        OS = "Linux (" + distribution + ") on " + distro + " distro";
    #elif defined(__APPLE__)
        OS = "MacOS";
    #else
        OS = "Not recognised";
    #endif

    std::cout << "\nYou are using the OS " << OS << ".\n";

    return 0;
}