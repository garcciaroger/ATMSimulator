#pragma once
#include <iostream>
#include <cctype>
#include <string>
#include "CheckingSaving.h"

//Validates the user amount in that there's no characters and amount less than 0
bool Account::validate_amount(double const amount){
    if(amount <= 0){
        std::cout << "ERROR: amout must be greater than 0" << std::endl;
        return false;
    }
    if(amount > CONST_MAX_LIMIT){
        std::cout << "ERROR: amout limit reached" << std::endl;
        return false;
    }
    return true;
}
//deposit method
bool Account::deposit(double const amount){
    balance += amount;
    return true;
}
//withdraw method
bool Account::withdraw(double const amount){
    if(amount > balance){
        std::cout << "ERROR: withdraw amount greater than total balance!" << std::endl;
        return false;
    }
    balance -= amount;
    return true;
}