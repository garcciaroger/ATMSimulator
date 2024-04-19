#pragma once
#include <iostream>
#include <cctype>
#include <string>
#include "AccountHolder.h"

class Account{
private:
    std::string account_name;
    std::string account_number;
    std::string routing_number;
    double balance;
    static constexpr double CONST_MAX_LIMIT = 10000000; 
public:
     // Default Constructor
    Account() : account_name("Unnamed Account"), account_number("000000"), routing_number("00000000"), balance(0.0) {}
    // Parameterized Constructor
    Account(std::string name, std::string acc_number, std::string rout_number, double initial_balance)
        : account_name(std::move(name)), account_number(std::move(acc_number)), routing_number(std::move(rout_number)), balance(initial_balance) {}
    //Getters
    inline std::string get_account_name() const {return account_name;}
    inline std::string get_account_number() const {return account_number;}
    inline std::string get_routing_number() const {return routing_number;}
    inline double get_balance() const {return balance;}
    //Setters
    void set_account_name(){

    }
    void set_account_number(){

    }
    void set_routing_number(){

    }
    void set_balance(){

    } 
    //Methods
    //Validates the user amount in that there's no characters and amount less than 0
    bool validate_amount(double const amount);
    //converts user amount to string to check for non digits
    bool is_digit(double amount);
    //deposit method
    bool deposit(double const amount);
    //withdraw method
    bool withdraw(double const amount);
};