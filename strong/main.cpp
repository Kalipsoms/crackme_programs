#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdint>
#ifdef _WIN32
#include <windows.h>
#else
#include <fstream>
#endif

bool is_debugger_attached() {
#ifdef _WIN32
    return IsDebuggerPresent();
#else
    std::ifstream status("/proc/self/status");
    std::string line;
    while (std::getline(status, line)) {
        if (line.rfind("TracerPid:", 0) == 0) {
            return line.find('0', 10) == std::string::npos;
        }
    }
    return false;
#endif
}

uint64_t checksum(const std::string& s) {
    uint64_t sum = 0;
    for (char c : s) {
        sum = sum * 31 + static_cast<unsigned char>(c ^ 0xAA);
    }
    return sum;
}

int main() {
    if (is_debugger_attached() || std::getenv("DEBUG")) {
        std::cout << "Tampering detected!\n";
        return 1;
    }

    std::string username;
    std::string password;

    std::cout << "Username: ";
    std::getline(std::cin, username);
    std::cout << "Password: ";
    std::getline(std::cin, password);

    const uint64_t expected = 4067081946268680494ULL; // checksum of 12345:strong

    if (username == "admin" && checksum(password) == expected) {
        std::cout << "Access granted\n";
    } else {
        std::cout << "Access denied\n";
    }
    return 0;
}
