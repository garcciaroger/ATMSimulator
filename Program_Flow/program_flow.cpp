#include "program_flow.h"
#include "AccountHolder.h"
#include "CheckingSaving.h"
#include <cstdlib>
#include <fstream>
#include <string>

//Welcome and sign up/in page
void Flow::start_up_page() {
    int option;
    std::cout << std::endl;
    std::cout << "     Welcome to ATM Simulator     " << std::endl;
    std::cout << "==================================" << std::endl;
    std::cout << "1. Sign Up " << std::endl;
    std::cout << "2. Log In " << std::endl;
    std::cout << "3. Exit " << std::endl;
    std::cout << "==================================" << std::endl;
    std::cout << "Enter Option: "; std::cin >> option;

    switch(option){
        case 1:{
            sign_up_option();
            break;
        }
        case 2:{
            login(); 
            break;
        }
        case 3:{
            exit(0);
            break;
        }
    }
}
//Sign up page
void Flow::sign_up_option(){
    newAccount.gather_customer_information();
    std::cout << std::endl;
    // Print customer details for verification
    bool valid_information = newAccount.print_customer_details();
    //Re-enter information if false
    while(!valid_information){
        std::cout << "Please re-enter your information again." << std::endl;
        newAccount.gather_customer_information();
    }
    // Print customer details again for final verification
    std::string AccountFile = newAccount.get_last_name() + newAccount.get_first_name() + "_account.txt";
    std::ofstream outFile(AccountFile);
    if(outFile.is_open()){
        outFile << "First Name - " << newAccount.get_first_name() << "\n";
        outFile << "Last Name - " << newAccount.get_last_name() << "\n";
        outFile << "Email Address - " << newAccount.get_email_address() << "\n";
        outFile << "Phone Number - " << newAccount.get_phone_number() << "\n";
        outFile << "Street Address - " << newAccount.get_street_address() << "\n";
        outFile << "City - " << newAccount.get_city() << "\n";
        outFile << "State - " << newAccount.get_state() << "\n";
        outFile << "Zip Code - " << newAccount.get_zip_code() << "\n";
        outFile.close();
    }
    start_up_page();
}
//Login application of main menu
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
//Main menu of the application
void Flow::main_menu() {
    // Implementation of main menu
    int option;
    std::cout << std::endl;
    std::cout << "     Main Menu     " << std::endl;
    std::cout << "===================" << std::endl;
    std::cout << "1. Deposit " << std::endl;
    std::cout << "2. Withdraw " << std::endl;
    std::cout << "3. Check Balance" << std::endl;
    std::cout << "4. Exit " << std::endl;
    std::cout << "===================" << std::endl;
    std::cout << "Enter Option: "; std::cin >> option;

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
    std::cout << std::endl;
    std::cout << "    Deposit Menu   " << std::endl;
    std::cout << "===================" << std::endl;
    std::cout << "1. Checkings  " << std::endl;
    std::cout << "2. Savings " << std::endl;
    std::cout << "3. Exit " << std::endl;
    std::cout << "===================" << std::endl;
    std::cout << "Enter Option: "; std::cin >> option;

    switch(option){
        //Checkings Account
        case 1: {
            double deposit_amount;
            std::cout << "How much would you like to deposit to checkings? - $";
            std::cin >> deposit_amount;
            std::cout << std::endl;
            // Deposit the amount into the account
            checking_account.deposit(deposit_amount);
            main_menu();
            break;
        }
        //Savings Account
        case 2:{
            double deposit_amount;
            std::cout << "How much would you like to deposit to savings? - $";
            std::cin >> deposit_amount;
            std::cout << std::endl;
            // Deposit the amount into the account
            saving_account.deposit(deposit_amount);
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
    std::cout << std::endl;
    std::cout << "   Withdraw Menu   " << std::endl;
    std::cout << "===================" << std::endl;
    std::cout << "1. Checkings  " << std::endl;
    std::cout << "2. Savings " << std::endl;
    std::cout << "3. Exit " << std::endl;
    std::cout << "===================" << std::endl;
    std::cout << "Enter Option: "; std::cin >> option;

    switch(option){
        //Checkings Account
        case 1: {
            double withdraw_amount;
            std::cout << "How much would you like to withdraw from checkings? - $";
            std::cin >> withdraw_amount;
            std::cout << std::endl;
            // Deposit the amount into the account
            checking_account.withdraw(withdraw_amount);
            main_menu();
            break;
        }
        //Savings Account
        case 2:{
            double withdraw_amount;
            std::cout << "How much would you like to withdraw from savings? - $";
            std::cin >> withdraw_amount;
            std::cout << std::endl;
            // Deposit the amount into the account
            saving_account.withdraw(withdraw_amount);
            main_menu();
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
    std::cout << std::endl;
    std::cout << "   Check Balance   " << std::endl;
    std::cout << "===================" << std::endl;
    std::cout << "1. Checkings  " << std::endl;
    std::cout << "2. Savings " << std::endl;
    std::cout << "3. Both Accounts " << std::endl;
    std::cout << "4. Exit " << std::endl;
    std::cout << "===================" << std::endl;
    std::cout << "Enter Option: "; std::cin >> option;

    switch(option){
        //Checkings Account
        case 1:{
            std::cout << "Checkings Account Balance - $" << checking_account.get_balance();
            std::cout << std::endl;
            main_menu();
            break;
        }
        //Savings Account
        case 2:{
            std::cout << "Savings Account Balance - $" << saving_account.get_balance();
            std::cout << std::endl;
            main_menu();
            break;
        }
        //Exit Function
        case 3:{
            std::cout << "Checkings Account Balance - $" << checking_account.get_balance() << std::endl;
            std::cout << "Savings Account Balance - $" << saving_account.get_balance() << std::endl;
            std::cout << std::endl;
            main_menu();
            break;
        }
        case 4:{
            exit(0);
        }
    }
}
//Start program
void Flow::start_program(){
    void start_up_page();
}