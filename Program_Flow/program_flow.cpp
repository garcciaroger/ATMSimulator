#include "program_flow.h"
#include "AccountHolder.h"
#include "CheckingSaving.h"
#include <cstdlib>
#include <fstream>
#include <string>
#include <unordered_map>
#include <sqlite3.h>
//Welcome and sign up/in page
void Flow::start_up_page() {
    int option = 0;
    while(option != 3){
        std::cout << std::endl;
        std::cout << "     Welcome to ATM Simulator     " << std::endl;
        std::cout << "==================================" << std::endl;
        std::cout << "1. Sign Up " << std::endl;
        std::cout << "2. Log In " << std::endl;
        std::cout << "3. Exit " << std::endl;
        std::cout << "==================================" << std::endl;
        std::cout << "Enter Option: ";
        option = get_option();

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
                std::cout << "Exiting program......." << std::endl;
                break;
            }
            default:{
                std::cout << "Invalid option. Try again" << std::endl;
            }
        }
    }
}
//Sign up page
void Flow::sign_up_option() {
    std::string continue_choice;
    do {
        // Create a new account holder
        AccountHolder* newAccount = new AccountHolder;
        bool isInformationCorrect = false;
        do {
            // Gather customer information
            if (newAccount->gather_customer_information()) {
                // Verify customer details
                isInformationCorrect = newAccount->verify_customer_details();
                if (!isInformationCorrect) {
                    std::cout << "Information incorrect. Please re-enter your details." << std::endl;
                }
            } else {
                std::cout << "Error gathering customer information. Please try again." << std::endl;
            }
        } while (!isInformationCorrect);
        // Open SQLite connection
        sqlite3* db;
        int rc = sqlite3_open("accounts.db", &db);
        if (rc) {
            std::cerr << "Error opening SQLite database: " << sqlite3_errmsg(db) << std::endl;
            sqlite3_close(db);
            return;
        }
        // Prepare SQL statement
        sqlite3_stmt* stmt;
        const char* sql = "INSERT INTO accounts (username, password, first_name, last_name, email, phone, street_address, city, state, zip_code) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
        rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
        if (rc != SQLITE_OK) {
            std::cerr << "Error preparing SQL statement: " << sqlite3_errmsg(db) << std::endl;
            sqlite3_finalize(stmt);
            sqlite3_close(db);
            return;
        }
        // Bind parameters and execute statement
        sqlite3_bind_text(stmt, 1, newAccount->get_username().c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 2, newAccount->get_password().c_str(), -1, SQLITE_STATIC);
        // Bind other parameters similarly...
        rc = sqlite3_step(stmt);
        if (rc != SQLITE_DONE) {
            std::cerr << "Error inserting data: " << sqlite3_errmsg(db) << std::endl;
        }
        // Finalize statement and close connection
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        // Delete the dynamically allocated account holder to free memory
        delete newAccount;
        // Ask user if they want to create another account
        std::cout << "Do you want to create another account? (Y/N): ";
        std::cin >> continue_choice;
        for (char &c : continue_choice) {
            c = std::toupper(c);
        }
    } while (continue_choice == "Y");
    // Redirect to start up page
    start_up_page();
}
//Login application of main menu
void Flow::login() {
    std::string username, password;
    std::cout << "Enter username: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear any leftover input
    std::getline(std::cin, username);
    std::cout << "Enter password: ";
    std::getline(std::cin, password);
    // SQLite database operations
    sqlite3* db;
    int rc = sqlite3_open("accounts.db", &db);
    if (rc) {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return;
    }
    std::string query = "SELECT password FROM accounts WHERE username = '" + username + "'";
    sqlite3_stmt* stmt;
    rc = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return;
    }
    rc = sqlite3_step(stmt);
    if (rc == SQLITE_ROW) {
        // Retrieve the stored password
        const unsigned char* storedPassword = sqlite3_column_text(stmt, 0);
        if (password == reinterpret_cast<const char*>(storedPassword)) {
            std::cout << "Login successful" << std::endl;
        } else {
            std::cout << "Incorrect password" << std::endl;
        }
    } else {
        std::cout << "User not found" << std::endl;
    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);
}
//Main menu of the application
void Flow::main_menu() {
    // Implementation of main menu
    int option = 0;
    while(option != 4){
        std::cout << std::endl;
        std::cout << "     Main Menu     " << std::endl;
        std::cout << "===================" << std::endl;
        std::cout << "1. Deposit " << std::endl;
        std::cout << "2. Withdraw " << std::endl;
        std::cout << "3. Check Balance" << std::endl;
        std::cout << "4. Exit " << std::endl;
        std::cout << "===================" << std::endl;
        std::cout << "Enter Option: ";
        option = get_option();
        switch(option){
            case 1:{
                deposit_menu();
                break;
            }
            case 2:{
                withdraw_menu();
                break;
            }
            case 3:{
                check_balance_menu();
                break;
            }
            case 4:{
                std::cout << "Exiting application......" << std::endl;
                exit(0);
            }
        }
    }    
}
//Deposit menu 
int Flow::deposit_menu(){
    int option = 0;
    while(option != 3){
        std::cout << std::endl;
        std::cout << "    Deposit Menu   " << std::endl;
        std::cout << "===================" << std::endl;
        std::cout << "1. Checkings  " << std::endl;
        std::cout << "2. Savings " << std::endl;
        std::cout << "3. Exit " << std::endl;
        std::cout << "===================" << std::endl;
        std::cout << "Enter Option: ";
        option = get_option();

        double deposit_amount;
        switch(option){
            //Checkings Account
            case 1: {
                std::cout << "How much would you like to deposit to checkings? - $";
                deposit_amount = get_option();
                while(!checking_account.deposit(deposit_amount)){
                    std::cout << "Enter a valid amount...." << std::endl;
                    std::cout << "How much would you like to deposit? - $" << std::endl;
                    deposit_amount = get_option();
                }                
                std::cout << "Deposited $" << deposit_amount << " to checkings account." << std::endl;
                break;
            }
            //Savings Account
            case 2:{
                std::cout << "How much would you like to deposit to savings? - $";
                deposit_amount = get_option();
                while(!saving_account.deposit(deposit_amount)){
                    std::cout << "Enter a valid amount...." << std::endl;
                    std::cout << "How much would you like to deposit? - $" << std::endl;
                    deposit_amount = get_option();
                }                
                std::cout << "Deposited $" << deposit_amount << " to savings account." << std::endl;
                break;
            }
            //Exit from program
            case 3:{
                std::cout << "Exiting to main menu" << std::endl;
                exit(0);
            }
            default:
                std::cout << "Invalid Option" << std::endl;
        }
        return option;
    }
}
void Flow::withdraw_menu() {
    int option = 0;
    while (option != 3) {
        std::cout << std::endl;
        std::cout << "   Withdraw Menu   " << std::endl;
        std::cout << "===================" << std::endl;
        std::cout << "1. Checkings  " << std::endl;
        std::cout << "2. Savings " << std::endl;
        std::cout << "3. Exit " << std::endl;
        std::cout << "===================" << std::endl;
        std::cout << "Enter Option: ";
        option = get_option();

        double withdraw_amount;
        switch(option) {
            case 1:{
                std::cout << "How much would you like to withdraw from checkings? - $";
                withdraw_amount = get_option();
                // Loop until a valid withdraw amount is entered
                while (!checking_account.withdraw(withdraw_amount)) {
                    std::cout << "Enter a valid amount..... " << std::endl;
                    std::cout << "How much would you like to withdraw from checkings? - $";
                    withdraw_amount = get_option();
                }
                std::cout << "Withdrew $" << withdraw_amount << " from checkings account." << std::endl;
                break;
            }
            case 2:{
                std::cout << "How much would you like to withdraw from savings? - $";
                withdraw_amount = get_option();
                // Loop until a valid withdraw amount is entered
                while (!saving_account.withdraw(withdraw_amount)) {
                    std::cout << "Enter a valid amount..... " << std::endl;
                    std::cout << "How much would you like to withdraw from savings? - $";
                    withdraw_amount = get_option();
                }
                std::cout << "Withdrew $" << withdraw_amount << " from savings account." << std::endl;
                break;
            }
            case 3:{
                std::cout << "Exiting to main menu." << std::endl;
                return;
            }
                
            default:{
                std::cout << "Invalid option. Please try again." << std::endl;
            }
        }
    }
}
//Check balance for menu
void Flow::check_balance_menu() {
    int option = 0;
    while (option != 4) {
        std::cout << std::endl;
        std::cout << "   Check Balance   " << std::endl;
        std::cout << "===================" << std::endl;
        std::cout << "1. Checkings  " << std::endl;
        std::cout << "2. Savings " << std::endl;
        std::cout << "3. Both Accounts " << std::endl;
        std::cout << "4. Exit " << std::endl;
        std::cout << "===================" << std::endl;
        std::cout << "Enter Option: ";
        option = get_option();

        switch(option) {
            case 1:
                std::cout << "Checkings Account Balance - $" << checking_account.get_balance() << std::endl;
                break;
            case 2:
                std::cout << "Savings Account Balance - $" << saving_account.get_balance() << std::endl;
                break;
            case 3:
                std::cout << "Checkings Account Balance - $" << checking_account.get_balance() << std::endl;
                std::cout << "Savings Account Balance - $" << saving_account.get_balance() << std::endl;
                break;
            case 4:
                std::cout << "Exiting to main menu." << std::endl;
                return;
            default:
                std::cout << "Invalid option. Please try again." << std::endl;
        }
    }
}
//Start program
void Flow::start_program(){
    void start_up_page();
}