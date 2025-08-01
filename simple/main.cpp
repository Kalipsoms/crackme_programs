#include <iostream>
#include <string>
#include <vector>

std::string decode_password() {
    const int data[] = {100, 103, 102, 97, 96, 111, 38, 60, 56, 37, 57, 48};
    std::string decoded;
    for (int c : data) {
        decoded += static_cast<char>(c ^ 0x55);
    }
    return decoded;
}

int main() {
    std::string username;
    std::string password;

    std::cout << "Username: ";
    std::getline(std::cin, username);
    std::cout << "Password: ";
    std::getline(std::cin, password);

    if (username == "admin" && password == decode_password()) {
        std::cout << "Access granted\n";
    } else {
        std::cout << "Access denied\n";
    }
    return 0;
}
