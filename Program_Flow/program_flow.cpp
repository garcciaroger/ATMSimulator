#include "program_flow.h"
#include "AccountHolder.h"
#include "CheckingSaving.h"
#include <cstdlib>

int Flow::login() {
    int option;
    std::cout << "     Welcome to ATM Simulator     " << std::endl;
    std::cout << "==================================" << std::endl;
    std::cout << "1. Log In " << std::endl;
    std::cout << "2. Sign Up " << std::endl;
    std::cout << "3. Exit " << std::endl;
    std::cout << "==================================" << std::endl;
    std::cout << "Enter Option"; std::cin >> option;
    return option;
}

int Flow::main_menu() {
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
    return option;
}

int Flow::deposit_menu(){
    int option;
    std::cout << "    Deposit Menu   " << std::endl;
    std::cout << "===================" << std::endl;
    std::cout << "1. Checkings  " << std::endl;
    std::cout << "2. Savings " << std::endl;
    std::cout << "3. Exit " << std::endl;
    std::cout << "===================" << std::endl;
    std::cout << "Enter Option"; std::cin >> option;

    switch(option){
        //Checkings Account
        case 1:{

        }
        //Savings Account
        case 2:{

        }
        //Exit from program
        case 3:{

        }
    }
    return option;
}

int Flow::withdraw_menu(){
    int option;
    std::cout << "    Withdraw Menu   " << std::endl;
    std::cout << "===================" << std::endl;
    std::cout << "1. Checkings  " << std::endl;
    std::cout << "2. Savings " << std::endl;
    std::cout << "3. Exit " << std::endl;
    std::cout << "===================" << std::endl;
    std::cout << "Enter Option"; std::cin >> option;

    switch(option){
        //Checkings Account
        case 1:{

        }
        //Savings Account
        case 2:{

        }
        //Exit from program
        case 3:{

        }
    }
}

int Flow::check_balance_menu(){
    int option;
    std::cout << "   Check Balance   " << std::endl;
    std::cout << "===================" << std::endl;
    std::cout << "1. Checkings  " << std::endl;
    std::cout << "2. Savings " << std::endl;
    std::cout << "3. Exit " << std::endl;
    std::cout << "===================" << std::endl;
    std::cout << "Enter Option"; std::cin >> option;

    switch(option){
        //Checkings Account
        case 1:{

        }
        //Savings Account
        case 2:{

        }
        //Exit from program
        case 3:{

        }
    }
}
void Flow::start_program() {    
    int login_option = login();
    switch(login_option){
        //Login
        case 1: {
            //Main Menu
            int main_menu_option = main_menu();
            switch(main_menu_option){
                case 1:{//Deposit
                    int depsoit_menu_option = deposit_menu();
                    break;
                }
                case 2:{//Withdraw
                    int withdraw_menu_option = withdraw_menu();
                    break;
                }
                case 3:{//Check Balance
                    int check_balance_option = check_balance_menu();
                    break;
                }
            }
            break;
        }
        //Sign Up
        case 2: {



            break;
        }
        //Exit
        case 3: {
            exit(0);
            break;
        }
    }
    main_menu();
}
