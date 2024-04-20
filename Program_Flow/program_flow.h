#pragma once
#include "AccountHolder.h"
#include "CheckingSaving.h"

class Flow {
public:
    int login();
    int main_menu(Account& account);
    bool sign_up_option();
    int deposit_menu(Account& account);
    int withdraw_menu(Account& account);
    int check_balance_menu(Account& account);
    void start_program();
};

