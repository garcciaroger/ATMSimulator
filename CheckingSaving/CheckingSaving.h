#pragma once
#include <iostream>
#include <cctype>
#include <string>
#include "AccountHolder.h"

class Account {
private:
    std::string account_name;
    std::string account_number;
    std::string routing_number;
    double balance;
protected:
    static constexpr double CONST_MAX_LIMIT = 10000000; 
public:
    // Default Constructor
    Account() : account_name("Unnamed Account"), account_number("000000"), routing_number("00000000"), balance(0.0) {}
    // Parameterized Constructor
    Account(std::string name, std::string acc_number, std::string rout_number, double initial_balance)
        : account_name(std::move(name)), account_number(std::move(acc_number)), routing_number(std::move(rout_number)), balance(initial_balance) {}
    //Getters
    double get_balance() const { return balance; }
    //Setters
    void set_balance(int account_balance) { balance = account_balance; }
    //Methods
    bool validate_amount(double const amount);
    bool is_digit(double amount);
    bool deposit(double const amount);
    bool withdraw(double const amount);
    // Public getter for CONST_MAX_LIMIT
    static double get_max_limit() { return CONST_MAX_LIMIT; }
};

class Checking : public Account {
private:
    std::string debit_card_number;
    std::string month_expiry;
    int security_code;
public:
    void set_debit_number();
    void set_month_expiry();
    void set_security_code();
    void get_debit_number();
    void get_month_expiry();
    void get_security_code();
};

class Saving : public Account {
private:
    double intrest_rate;
public:
    void set_intrest_rate();
    void get_intrest_rate();
};