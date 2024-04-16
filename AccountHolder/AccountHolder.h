#pragma once
#include<iostream>

class AccountHolder{
private:
    std::string first_name;
    std::string last_name;
    std::string email_address;
    std::string phone_number;
    std::string street_address;
    std::string city;
    std::string state;
    std::string zip_code;
public:
    //Default Constructor
    AccountHolder() = default;

    //Default Initllization
    explicit AccountHolder(std::string fn, std::string ln, std::string email, std::string phone,
                 std::string address, std::string city, std::string state, std::string zip)
            : first_name(std::move(fn)), last_name(std::move(ln)), email_address(std::move(email)),
              phone_number(std::move(phone)), street_address(std::move(address)),
              city(std::move(city)), state(std::move(state)), zip_code(std::move(zip)) {}

    //Getters
    inline std::string get_first_name() const {return first_name;}
    // Returns the last name of the account owner
    inline const std::string& get_last_name() const noexcept { return last_name; }
    // Returns the email address of the account owner
    inline const std::string& get_email_address() const noexcept { return email_address; }
    // Returns the phone number of the account owner
    inline const std::string& get_phone_number() const noexcept { return phone_number; }
    // Returns the street address of the account owner
    inline const std::string& get_street_address() const noexcept { return street_address; }
    // Returns the city of the account owner
    inline const std::string& get_city() const noexcept { return city; }
    // Returns the state of the account owner
    inline const std::string& get_state() const noexcept { return state; }
    // Returns the zip code of the account owner
    inline const std::string& get_zip_code() const noexcept { return zip_code; }

    //Setters
    bool set_first_name(std::string new_firstName){
        for (char c : new_firstName) {
            // Check if the character is a valid character for a last name
            if (!std::isalpha(c) && c != '-') {
                std::cout << "ERROR: Invalid character in first name: " << c << std::endl;
                return false;
            }
        }
        if(new_firstName.empty()){
            std::cout << "ERROR: Name Cannot be empty" << std::endl;
            return false;
        }
        first_name = new_firstName;
        return true;
    }

    bool set_last_name(std::string new_lastName){
        for (char c : new_lastName) {
            // Check if the character is a valid character for a last name
            if (!std::isalpha(c) && c != '-') {
                std::cout << "ERROR: Invalid character in last name: " << c << std::endl;
                return false;
            }
        }
        if(new_lastName.empty()){
            std::cout << "ERROR: Name Cannot be empty" << std::endl;
            return false;
        }
        last_name = new_lastName;
        return true;
    }
    bool set_email_address(std::string new_email_address){
        if (new_email_address.find('@') == std::string::npos) {
            std::cout << "ERROR: Invalid Email address" << std::endl;
            return false;
        }
        if(new_email_address.empty()){
            std::cout << "ERROR: Email Cannot be empty" << std::endl;
            return false;
        }
        email_address = new_email_address;
        return true;
    }
    bool set_phone_number(const std::string& new_phone_number) {
        if (new_phone_number.length() != 10) {
            std::cout << "ERROR: Invalid Phone number" << std::endl;
            return false;
        }
        for (char c : new_phone_number) {
            if (!std::isdigit(c)) {
                std::cout << "ERROR: Invalid Character" << std::endl;
                return false;
            }
        }
        std::string formatted_number;
        int count = 0;
        for (char digit : new_phone_number) {
            if (count == 3 || count == 6) {
                formatted_number += '-';
            }
            formatted_number += digit;
            count++;
        }
        if(new_phone_number.empty()){
            std::cout << "ERROR: Phone Number Cannot be empty" << std::endl;
            return false;
        }
        phone_number = formatted_number;
        return true;
    }
    bool set_street_address(std::string new_street_address){
        for(char c: new_street_address){
            if(!std::isalpha(c) && !std::isspace(c)){
                return false;
            }
        }
        if(new_street_address.empty()){
            std::cout << "ERROR: Street Address Cannot be empty" << std::endl;
            return false;
        }
        street_address = new_street_address;
        return true;
    }
    bool set_city(std::string new_city){
        for(char c: new_city){
            if(!std::isalpha(c) && !std::isspace(c)){
                return false;
            }
        }
        if(new_city.empty()){
            std::cout << "ERROR: City Cannot be empty" << std::endl;
            return false;
        }
        city = new_city;
        return true;
    }
    //This will set state and test input
    bool set_state(std::string new_state){
        for(char c: new_state){
            if(!std::isalpha(c) && !std::isspace(c)){
                return false;
            }
        }
        if(new_state.empty()){
            std::cout << "ERROR: State Cannot be empty" << std::endl;
            return false;
        }
        state = new_state;
        return true;
    }
    //This is to set a zip code and test to ensure input valitity
    bool set_zip_code(std::string new_zip){
        if(new_zip.length() != 5){
            std::cout  << "Zip Length is 5 digits" << std::endl;
            return false;
        }
        for(char c: new_zip){
            if(!std::isdigit(c)){
                std::cout << "ERROR: Invalid Character " << std::endl;
                return false;
            }
        }
        if(new_zip.empty()){
            std::cout << "ERROR: Zip Code Cannot be empty" << std::endl;
            return false;
        }
        zip_code = new_zip;
        return true;
    }

    //Method
    bool gather_customer_information();
    void print_customer_details();
};