#pragma once
#include <iostream>
#include <cctype>
#include <string>
#include "CheckingSaving.h"

//converts user amount to string to check for non digits
bool Account::is_digit(double amount){
    std::string string_to_int = std::to_string(amount);
    for(char c: string_to_int){
        if(!isdigit*static_cast<unsigned char>(c)){
            return true;
        }
    }
    return false;
}
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
    bool digit = is_digit(amount);
    if(!digit){
        std::cout << "ERROR: Non-digit characters found " << std::endl;
        return false;
    }
}
//deposit method
bool Account::deposit(double const amount){
    if(!validate_amount(amount)){
        return false;
    }
    return true;
}
//withdraw method
bool Account::withdraw(double const amount){
    if(!validate_amount(amount)){
        return false;
    }
    if(amount > balance){
        std::cout << "ERROR: withdraw amount greater than total balance!" << std::endl;
        return false;
    }
    return true;
}