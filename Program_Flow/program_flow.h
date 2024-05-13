#pragma once
#include "AccountHolder.h"
#include "CheckingSaving.h"
#include <unordered_map>
#include <string>

class Flow {
public:
    void start_up_page();
    void login();
    void main_menu();
    void sign_up_option();
    int deposit_menu();
    void withdraw_menu();
    void check_balance_menu();
    void start_program();
    void clear_input();
    ~Flow(){
        for (auto& pair : accounts) {
            delete pair.second; // Properly deallocate memory for each account
        }
    }

private:
    Checking checking_account;
    Saving saving_account;
    AccountHolder newAccount;
    std::unordered_map<std::string, AccountHolder*> accounts; // Hash table to store accounts
    int get_option();
};