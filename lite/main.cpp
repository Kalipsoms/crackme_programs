#include <iostream>
#include <string>

int main() {
    std::string username;
    std::string password;

    std::cout << "Username: ";
    std::getline(std::cin, username);
    std::cout << "Password: ";
    std::getline(std::cin, password);

    if (username == "admin" && password == "12345:lite") {
        std::cout << "Access granted\n";
    } else {
        std::cout << "Access denied\n";
    }
    return 0;
}
