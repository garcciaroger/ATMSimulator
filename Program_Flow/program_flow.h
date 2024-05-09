#pragma once
#include "AccountHolder.h"
#include "CheckingSaving.h"

class Flow {
public:
    void start_up_page();
    void login();
    void main_menu();
    void sign_up_option();
    int deposit_menu();
    int withdraw_menu();
    int check_balance_menu();
    void start_program();

private:
     // Create a new account object
    Checking checking_account;
    Saving saving_account;
};

