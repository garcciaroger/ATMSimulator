#pragma once
#include<iostream>
#include<cctype>
#include<string>
#include"AccountHolder.h"

bool AccountHolder::gather_customer_information(){
    std::string first_name;
    std::string last_name;
    std::string email_address;
    std::string phone_number;
    std::string street_address;
    std::string city;
    std::string state;
    std::string zip_code;

    std::cout << "\n      New Account     " << std::endl;
    std::cout << "========================" << std::endl;

    std::cout << "Enter First Name - "; 
    std::cin.ignore(); // Clear any remaining newline characters
    std::getline(std::cin, first_name);
    if (!set_first_name(first_name)) {
        std::cerr << "Invalid first name!" << std::endl;
        return false; // Gathering failed
    }

    std::cout << "Enter Last Name - ";
    std::getline(std::cin, last_name);
    if (!set_last_name(last_name)) {
        std::cerr << "Invalid last name!" << std::endl;
        return false; // Gathering failed
    }

    std::cout << "Enter your Email Address - ";
    std::getline(std::cin, email_address);
    if(!set_email_address(email_address)){
        std::cout << "Invalid Email Address! " << std::endl;
        return false;
    }

    std::cout << "Enter Phone Number - "; 
    std::getline(std::cin, phone_number);
    if (!set_phone_number(phone_number)) {
        std::cerr << "Invalid phone number!" << std::endl;
        return false; // Gathering failed
    }

    std::cout << "Enter Street Address - "; 
    std::getline(std::cin, street_address);
    if (!set_street_address(street_address)) {
        std::cerr << "Invalid street address!" << std::endl;
        return false; // Gathering failed
    }

    std::cout << "Enter City - "; 
    std::getline(std::cin, city);
    if (!set_city(city)) {
        std::cerr << "Invalid city!" << std::endl;
        return false; // Gathering failed
    }

    std::cout << "Enter State - "; 
    std::getline(std::cin, state);
    if (!set_state(state)) {
        std::cerr << "Invalid state!" << std::endl;
        return false; // Gathering failed
    }

    std::cout << "Enter Zip Code - "; 
    std::getline(std::cin, zip_code);
    if (!set_zip_code(zip_code)) {
        std::cerr << "Invalid zip code!" << std::endl;
        return false; // Gathering failed
    }

    std::cout << std::endl;
    return true; // Gathering successful
}

//Display customer details
bool AccountHolder::print_customer_details(){
    std::cout << "\n   Customer Details     " << std::endl;
    std::cout << "==========================" << std::endl;
    std::cout << "First Name - " << get_first_name() << std::endl;
    std::cout << "Last Name - " << get_last_name() << std::endl;
    std::cout << "Email Address - " << get_email_address() << std::endl;
    std::cout << "City - " << get_city() << std::endl; 
    std::cout << "State - " << get_state() << std::endl;
    std::cout << "Zip Code " << get_zip_code() << std::endl;

    //Choice option
    std::string choice;
    std::cout << "Is the following information correct? (Y/N): ";
    std::cin >> choice;

    //Logic for returning true or false
    if(choice == "Yes" || choice == "Y" || choice == "yes" || choice == "y"){
        return true;
    }else{
        return false;
    }
}
