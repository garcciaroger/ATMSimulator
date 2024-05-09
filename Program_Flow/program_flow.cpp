#include "program_flow.h"
#include "AccountHolder.h"
#include "CheckingSaving.h"
#include <cstdlib>
#include <fstream>
#include <string>
#include <sqlite3.h>


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
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;

    //Open DB
    rc = sqlite3_open("account_holders.db", &db);
    if (rc) {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
        return;
    }
   
    AccountHolder* new_account = new AccountHolder();
    new_account->gather_customer_information();
    std::cout << std::endl;
    // Print customer details for verification
    bool valid_information = new_account->print_customer_details();
    //Re-enter information if false
    while(!valid_information){
        std::cout << "Please re-enter your information again." << std::endl;
        new_account->gather_customer_information();
    }
    // Construct SQL command to insert data
    std::string sql = "INSERT INTO AccountHolder (first_name, last_name, email_address, phone_number, street_address, city, state, zip_code) VALUES ('" +
                      new_account->get_first_name() + "', '" + 
                      new_account->get_last_name() + "', '" +
                      new_account->get_email_address() + "', '" +
                      new_account->get_phone_number() + "', '" +
                      new_account->get_street_address() + "', '" +
                      new_account->get_city() + "', '" +
                      new_account->get_state() + "', '" +
                      new_account->get_zip_code() + "');";
    // Execute SQL statement
    rc = sqlite3_exec(db, sql.c_str(), 0, 0, &zErrMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << zErrMsg << std::endl;
        sqlite3_free(zErrMsg);
    }
    //Clean up
    delete new_account;
    sqlite3_close(db);
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