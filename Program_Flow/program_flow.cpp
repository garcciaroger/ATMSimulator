#include "program_flow.h"
#include "AccountHolder.h"
#include "CheckingSaving.h"

void Flow::login() {
    int option;
    std::cout << "     Welcome to ATM Simulator     " << std::endl;
    std::cout << "==================================" << std::endl;
    std::cout << "1. Log In " << std::endl;
    std::cout << "2. Sign Up " << std::endl;
    std::cout << "3. Exit " << std::endl;
    std::cout << "==================================" << std::endl;
    std::cout << "Enter Option"; std::cin >> option;
}

void Flow::main_menu() {
    // Implementation of main menu
}

void Flow::start_program(){
    login();
}