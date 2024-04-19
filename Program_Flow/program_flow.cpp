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
    int option;
    std::cout << "     Main Menu     " << std::endl;
    std::cout << "===================" << std::endl;
    std::cout << "1. Deposit " << std::endl;
    std::cout << "2. Withdraw " << std::endl;
    std::cout << "3. Check Balance" << std::endl;
    std::cout << "4. Exit " << std::endl;
    std::cout << "===================" << std::endl;
    std::cout << "Enter Option"; std::cin >> option;
}

void Flow::start_program(){
    login();
}