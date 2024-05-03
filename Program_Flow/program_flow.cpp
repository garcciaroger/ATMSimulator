#include "program_flow.h"
#include "AccountHolder.h"
#include "CheckingSaving.h"
#include <cstdlib>

void Flow::login() {
    int option;
    std::cout << "     Welcome to ATM Simulator     " << std::endl;
    std::cout << "==================================" << std::endl;
    std::cout << "1. Log In " << std::endl;
    std::cout << "2. Sign Up " << std::endl;
    std::cout << "3. Exit " << std::endl;
    std::cout << "==================================" << std::endl;
    std::cout << "Enter Option"; std::cin >> option;

    switch(option){
        case 1:{

        }
        case 2:{
            sign_up_option();
            break;
        }
        case 3:{
            exit(0);
            break;
        }
    }
}

void Flow::login() {
    std::string username, password;
    // Prompt for username and password
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;
    // Hardcoded credentials for the example
    const std::string storedUsername = "admin";
    const std::string storedPassword = "password123";
    // Check if the entered credentials match the stored credentials
    if (username == storedUsername && password == storedPassword) {
        std::cout << "Login successful!" << std::endl;
        // Code to handle successful login
    } else {
        std::cout << "Login failed: Incorrect username or password." << std::endl;
        // Optionally, you can handle retries or log the failed attempt
    }
}

void Flow::sign_up_option(){
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
}

//Main menu of the application
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

    switch(option){
        case 1:{
            deposit_menu();
        }
        case 2:{
            withdraw_menu();
        }
        case 3:{
            check_balance_menu();
        }
        case 4:{
            exit(0);
        }
    }
}
//Deposit menu 
int Flow::deposit_menu(){
    int option;
    std::cout << "    Deposit Menu   " << std::endl;
    std::cout << "===================" << std::endl;
    std::cout << "1. Checkings  " << std::endl;
    std::cout << "2. Savings " << std::endl;
    std::cout << "3. Exit " << std::endl;
    std::cout << "===================" << std::endl;
    std::cout << "Enter Option"; std::cin >> option;

    Checking checking_account;
    Saving saving_account;

    switch(option){
        //Checkings Account
        case 1: {
            double deposit_amount;
            bool isValid = false;
            do {
                std::cout << "How much would you like to deposit?" << std::endl;
                std::cin >> deposit_amount;
                isValid = checking_account.validate_amount(deposit_amount);

                if (!isValid) {
                    std::cout << "Invalid deposit amount. Please enter a valid amount." << std::endl;
                }
            } while (!isValid);
            // Deposit the amount into the account
            double total_balance = checking_account.deposit(deposit_amount) + checking_account.get_balance();
            checking_account.set_balance(total_balance);
            main_menu();
            break;
        }
        //Savings Account
        case 2:{
            double deposit_amount;
            bool isValid = false;
            do {
                std::cout << "How much would you like to deposit?" << std::endl;
                std::cin >> deposit_amount;
                isValid = saving_account.validate_amount(deposit_amount);

                if (!isValid) {
                    std::cout << "Invalid deposit amount. Please enter a valid amount." << std::endl;
                }
            } while (!isValid);
            // Deposit the amount into the account
            double total_balance = saving_account.deposit(deposit_amount) + saving_account.get_balance();
            saving_account.set_balance(total_balance);
            main_menu();
            break;
        }
        //Exit from program
        case 3:{
            exit(0);
        }
    }
    return option;
}
//Withdraw menu 
int Flow::withdraw_menu(){
    int option;
    std::cout << "    Withdraw Menu   " << std::endl;
    std::cout << "===================" << std::endl;
    std::cout << "1. Checkings  " << std::endl;
    std::cout << "2. Savings " << std::endl;
    std::cout << "3. Exit " << std::endl;
    std::cout << "===================" << std::endl;
    std::cout << "Enter Option"; std::cin >> option;

    Checking checking_account;
    Saving saving_account;

    switch(option){
        //Checkings Account
        case 1: {
            double withdraw_amount;
            bool isValid = false;
            do {
                std::cout << "How much would you like to deposit?" << std::endl;
                std::cin >> withdraw_amount;
                isValid = checking_account.validate_amount(withdraw_amount);
                if (!isValid) {
                    std::cout << "Invalid withdraw amount. Please enter a valid amount." << std::endl;
                }
            } while (!isValid);
            // Withdraw the amount into the account
            double total_balance = checking_account.withdraw(withdraw_amount) - checking_account.get_balance();
            checking_account.set_balance(total_balance);
            main_menu();
            break;
        }
        //Savings Account
        case 2:{
            double withdraw_amount;
            bool isValid = false;
            do {
                std::cout << "How much would you like to withdraw?" << std::endl;
                std::cin >> withdraw_amount;
                isValid = saving_account.validate_amount(withdraw_amount);
                if (!isValid) {
                    std::cout << "Invalid deposit amount. Please enter a valid amount." << std::endl;
                }
            } while (!isValid);
            // Withdraw the amount into the account
            double total_balance = saving_account.withdraw(withdraw_amount) - saving_account.get_balance();
            saving_account.set_balance(total_balance);
            main_menu();
            break;
        }
        //Exit from program
        case 3:{
            exit(0);
        }
    }
    return option;
}
//Check balance for menu
int Flow::check_balance_menu(){
    int option;
    std::cout << "   Check Balance   " << std::endl;
    std::cout << "===================" << std::endl;
    std::cout << "1. Checkings  " << std::endl;
    std::cout << "2. Savings " << std::endl;
    std::cout << "3. Exit " << std::endl;
    std::cout << "===================" << std::endl;
    std::cout << "Enter Option"; std::cin >> option;

    Checking checking_account;
    Saving saving_account;

    switch(option){
        //Checkings Account
        case 1:{
            std::cout << "Checkings Account Balance - $" << checking_account.get_balance();
            main_menu();
            break;
        }
        //Savings Account
        case 2:{
            std::cout << "Savings Account Balance - $" << checking_account.get_balance();
            main_menu();
            break;
        }
        //Exit Function
        case 3:{
            exit(0);
        }
    }
}
//Start program
void Flow::start_program(){
    int login();
}