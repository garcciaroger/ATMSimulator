#pragma once
#include "AccountHolder.h"
#include "CheckingSaving.h"

class Flow {
public:
    int login();
    void main_menu();
    bool sign_up_option();
    int deposit_menu();
    int withdraw_menu();
    int check_balance_menu();
    void start_program();
};

