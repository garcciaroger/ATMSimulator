#include<iostream>
#include<cctype>
#include<string>
#include <memory>
#include"AccountHolder.h"
bool AccountHolder::gather_customer_information() {
    // Define Customer structure locally
    struct Customer {
        std::string username;
        std::string password;
        std::string first_name;
        std::string last_name;
        std::string email_address;
        std::string phone_number;
        std::string street_address;
        std::string city;
        std::string state;
        std::string zip_code;
    };

    Customer customer_information; // Local variable

    std::cout << "\n      New Account     " << std::endl;
    std::cout << "========================" << std::endl;

    // Clear the input buffer before taking new input to avoid skipping input fields
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore any leftover newline character

    std::cout << "Create Username: ";
    std::getline(std::cin, customer_information.username);
    if (!set_usernames(customer_information.username)) {
        std::cerr << "Invalid username!" << std::endl;
        return false;
    }

    std::cout << "Create Password: ";
    std::getline(std::cin, customer_information.password);
    if (!set_password(customer_information.password)) {
        std::cerr << "Invalid password!" << std::endl;
        return false;
    }

    std::cout << "Enter First Name: ";
    std::getline(std::cin, customer_information.first_name);
    if (!set_first_name(customer_information.first_name)) {
        std::cerr << "Invalid first name!" << std::endl;
        return false;
    }

    std::cout << "Enter Last Name: ";
    std::getline(std::cin, customer_information.last_name);
    if (!set_last_name(customer_information.last_name)) {
        std::cerr << "Invalid last name!" << std::endl;
        return false;
    }

    std::cout << "Enter your Email Address: ";
    std::getline(std::cin, customer_information.email_address);
    if (!set_email_address(customer_information.email_address)) {
        std::cerr << "Invalid email address!" << std::endl;
        return false;
    }

    std::cout << "Enter Phone Number: ";
    std::getline(std::cin, customer_information.phone_number);
    if (!set_phone_number(customer_information.phone_number)) {
        std::cerr << "Invalid phone number!" << std::endl;
        return false;
    }

    std::cout << "Enter Street Address: ";
    std::getline(std::cin, customer_information.street_address);
    if (!set_street_address(customer_information.street_address)) {
        std::cerr << "Invalid street address!" << std::endl;
        return false;
    }

    std::cout << "Enter City: ";
    std::getline(std::cin, customer_information.city);
    if (!set_city(customer_information.city)) {
        std::cerr << "Invalid city!" << std::endl;
        return false;
    }

    std::cout << "Enter State: ";
    std::getline(std::cin, customer_information.state);
    if (!set_state(customer_information.state)) {
        std::cerr << "Invalid state!" << std::endl;
        return false;
    }

    std::cout << "Enter Zip Code: ";
    std::getline(std::cin, customer_information.zip_code);
    if (!set_zip_code(customer_information.zip_code)) {
        std::cerr << "Invalid zip code!" << std::endl;
        return false;
    }

    std::cout << "Information successfully gathered and validated." << std::endl;
    return true; // Information successfully gathered and validated
}
//Verify customer details
bool AccountHolder::verify_customer_details(){
    std::cout << "\n   Customer Details     " << std::endl;
    std::cout << "==========================" << std::endl;
    std::cout << "Username - " << get_username() << std::endl;
    std::cout << "Password - " << get_password() << std::endl;
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
//print customer details
void AccountHolder::customer_details(){
    std::cout << "\n   Customer Details     " << std::endl;
    std::cout << "==========================" << std::endl;
    std::cout << "Username - " << get_username() << std::endl;
    std::cout << "First Name - " << get_first_name() << std::endl;
    std::cout << "Last Name - " << get_last_name() << std::endl;
    std::cout << "Email Address - " << get_email_address() << std::endl;
    std::cout << "City - " << get_city() << std::endl; 
    std::cout << "State - " << get_state() << std::endl;
    std::cout << "Zip Code " << get_zip_code() << std::endl;
}
