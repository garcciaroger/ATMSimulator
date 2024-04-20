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

bool sign_up_option(){
    //Creates new account class
    AccountHolder newAccount;
    //Gathers customer information
    newAccount.gather_customer_information();
    std::cout << std::endl;
    //Creates a bool value to verify information
    bool valid_information = newAccount.print_customer_details();
    //If information is incorrect, sets to false and then re-enter data
    if(!valid_information){
        std::cout << "Re-enter your information correctly" << std::endl;
        newAccount.gather_customer_information();
    }
    //If information is correct, data is set to true
    newAccount.print_customer_details();
    return true;
}

int Flow::main_menu(Account& account) {
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

    Account account;
    switch(option){
        case 1:{
            deposit_menu(account);
        }
        case 2:{
            withdraw_menu(account);
        }
        case 3:{
            check_balance_menu(account);
        }
        case 4:{
            exit(0);
        }
    }
}

int Flow::deposit_menu(Account& account){
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
        case 1: {
            double deposit_amount;
            bool isValid = false;
            do {
                std::cout << "How much would you like to deposit?" << std::endl;
                std::cin >> deposit_amount;
                isValid = account.validate_amount(deposit_amount);

                if (!isValid) {
                    std::cout << "Invalid deposit amount. Please enter a valid amount." << std::endl;
                }
            } while (!isValid);
            // Deposit the amount into the account
            account.deposit(deposit_amount);

            main_menu(account);
            break;
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


// int Flow::withdraw_menu(Account& account){
//     int option;
//     std::cout << "    Withdraw Menu   " << std::endl;
//     std::cout << "===================" << std::endl;
//     std::cout << "1. Checkings  " << std::endl;
//     std::cout << "2. Savings " << std::endl;
//     std::cout << "3. Exit " << std::endl;
//     std::cout << "===================" << std::endl;
//     std::cout << "Enter Option"; std::cin >> option;

//     switch(option){
//         //Checkings Account
//         case 1:{

//         }
//         //Savings Account
//         case 2:{

//         }
//         //Exit from program
//         case 3:{

//         }
//     }
// }

// int Flow::check_balance_menu(Account& account){
//     int option;
//     std::cout << "   Check Balance   " << std::endl;
//     std::cout << "===================" << std::endl;
//     std::cout << "1. Checkings  " << std::endl;
//     std::cout << "2. Savings " << std::endl;
//     std::cout << "3. Exit " << std::endl;
//     std::cout << "===================" << std::endl;
//     std::cout << "Enter Option"; std::cin >> option;

//     switch(option){
//         //Checkings Account
//         case 1:{

//         }
//         //Savings Account
//         case 2:{

//         }
//         //Exit from program
//         case 3:{

//         }
//     }
// }

