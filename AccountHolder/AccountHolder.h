#pragma once
#include<iostream>
#include<cctype>
#include<string>
#include <regex>
#include <unordered_set>

class AccountHolder{
private:
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
public:
    //Default Constructor
    AccountHolder() = default;
    //Getters
    std::string get_username() const {return username;}
    std::string get_password() const {return password;}
    std::string get_first_name() const {return first_name;}
    // Returns the last name of the account owner
    const std::string& get_last_name() const noexcept { return last_name; }
    // Returns the email address of the account owner
    const std::string& get_email_address() const noexcept { return email_address; }
    // Returns the phone number of the account owner
    const std::string& get_phone_number() const noexcept { return phone_number; }
    // Returns the street address of the account owner
    const std::string& get_street_address() const noexcept { return street_address; }
    // Returns the city of the account owner
    const std::string& get_city() const noexcept { return city; }
    // Returns the state of the account owner
    const std::string& get_state() const noexcept { return state; }
    // Returns the zip code of the account owner
    const std::string& get_zip_code() const noexcept { return zip_code; }

    //Default Initllization
    explicit AccountHolder(std::string fn, std::string ln, std::string email, std::string phone,
                 std::string address, std::string city, std::string state, std::string zip)
            : first_name(std::move(fn)), last_name(std::move(ln)), email_address(std::move(email)),
              phone_number(std::move(phone)), street_address(std::move(address)),
              city(std::move(city)), state(std::move(state)), zip_code(std::move(zip)) {}

    //Setters
    bool set_usernames(std::string new_username){
        username = new_username;
        return true;
    }
    bool set_password(std::string new_password){
        password = new_password;
        return true;
    }
    //This function will get the users first name and check to see if it meets requirements
    bool set_first_name(const std::string& new_firstName) {
        // Maximum length of first name
        const size_t MAX_LENGTH = 15;
        // Check if the string is too long
        if (new_firstName.size() > MAX_LENGTH) {
            std::cout << "ERROR: First name is too long. It must be no more than " << MAX_LENGTH << " characters." << std::endl;
            return false;
        }
        // Check if the string is empty
        if (new_firstName.empty()) {
            std::cout << "ERROR: Name cannot be empty." << std::endl;
            return false;
        }
        // Check for invalid characters in a single pass
        for (char c : new_firstName) {
            if (!std::isalpha(c) && c != ' ' && c != '-') {
                std::cout << "ERROR: Invalid character in first name: " << c << std::endl;
                return false;
            }
        }
        // Check for invalid characters in the rest of the name and no consecutive spaces
        char previousChar = new_firstName[0]; // Initialize previousChar to the first character
        for (size_t i = 1; i < new_firstName.length(); i++) {
            char c = new_firstName[i];
            if (!std::isalpha(c) && c != ' ' && c != '-' && c != '.') {
                std::cout << "ERROR: Invalid character in last name: " << c << std::endl;
                return false;
            }
            // Check for consecutive spaces
            if (c == ' ' && previousChar == ' ') {
                std::cout << "ERROR: Consecutive spaces are not allowed." << std::endl;
                return false;
            }
            previousChar = c; // Update previousChar to current char for next iteration
        }
        // If all characters are valid, set the first name and return true
        first_name = new_firstName;
        return true;
    }
    //This function will get the users last name and check to see if it meets requirements
    bool set_last_name(std::string new_lastName){
        // Maximum length of last name
        const size_t MAX_LENGTH = 25;
        // Check if the string is too long
        if (new_lastName.size() > MAX_LENGTH) {
            std::cout << "ERROR: Last name is too long. It must be no more than " << MAX_LENGTH << " characters." << std::endl;
            return false;
        }
        // Check if the string is empty
        if (new_lastName.empty()) {
            std::cout << "ERROR: Last name cannot be empty." << std::endl;
            return false;
        }
        // Check the first character is alphabetic
        if (!std::isalpha(new_lastName[0])) {
            std::cout << "ERROR: The first character of the last name must be alphabetic." << std::endl;
            return false;
        }
        // Check for invalid characters in the rest of the name and no consecutive spaces
        char previousChar = new_lastName[0]; // Initialize previousChar to the first character
        for (size_t i = 1; i < new_lastName.length(); i++) {
            char c = new_lastName[i];
            if (!std::isalpha(c) && c != ' ' && c != '-' && c != '.') {
                std::cout << "ERROR: Invalid character in last name: " << c << std::endl;
                return false;
            }
            // Check for consecutive spaces
            if (c == ' ' && previousChar == ' ') {
                std::cout << "ERROR: Consecutive spaces are not allowed." << std::endl;
                return false;
            }
            previousChar = c; // Update previousChar to current char for next iteration
        }
        // If all characters are valid, set the last name and return true
        last_name = new_lastName;
        return true;
    }
    //Gets user email address and tests input
    bool set_email_address(std::string new_email_address){
        // Check if the email address is empty first
        if (new_email_address.empty()) {
            std::cout << "ERROR: Email cannot be empty." << std::endl;
            return false;
        }
        // Check if email contains the .com domain
        size_t found = new_email_address.find(".com");
        if(found != std::string::npos){
            std::cout << "ERROR: Cannot find the domain .com" << std::endl;
        }
        // Check for the presence of '@' symbol
        size_t at_pos = new_email_address.find('@');
        if (at_pos == std::string::npos) {
            std::cout << "ERROR: Invalid Email address. '@' symbol missing." << std::endl;
            return false;
        }
        // Check for the presence of a dot after '@'
        size_t dot_pos = new_email_address.find('.', at_pos);
        if (dot_pos == std::string::npos) {
            std::cout << "ERROR: Invalid Email address. '.' missing after '@'." << std::endl;
            return false;
        }
        // Ensure that '@' is not the first character and '.' is not directly after '@'
        if (at_pos == 0 || dot_pos == at_pos + 1) {
            std::cout << "ERROR: Invalid Email address. Misplaced '@' or '.'." << std::endl;
            return false;
        }
        // Check for spaces, which are illegal in email addresses
        if (new_email_address.find(' ') != std::string::npos) {
            std::cout << "ERROR: Invalid Email address. Spaces are not allowed." << std::endl;
            return false;
        }
        // Check for spaces, which are illegal in email addresses
        if (new_email_address.find(' ') != std::string::npos) {
            std::cout << "ERROR: Invalid Email address. Spaces are not allowed." << std::endl;
            return false;
        }
        // Check for special characters in the email name (before the '@' symbol)
        for (size_t i = 0; i < at_pos; ++i) {
            if (!isalnum(new_email_address[i]) && new_email_address[i] != '.' && new_email_address[i] != '_' && new_email_address[i] != '-') {
                std::cout << "ERROR: Invalid Email address. Special characters are not allowed in the email name." << std::endl;
                return false;
            }
        }
        // Set the email address if all checks are passed
        email_address = new_email_address;
        return true;
    }
    //Sets user phone number as well as test input
    bool set_phone_number(const std::string& new_phone_number) {
    // Check if the phone number is empty
        if (new_phone_number.empty()) {
            std::cout << "ERROR: Phone Number Cannot be empty" << std::endl;
            return false;
        }
        // Check for the length of the phone number
        if (new_phone_number.length() != 10) {
            std::cout << "ERROR: Invalid Phone number. It must contain exactly 10 digits." << std::endl;
            return false;
        }
        // Check for any invalid characters (including whitespace)
        for (char c : new_phone_number) {
            if (!std::isdigit(c)) {
                std::cout << "ERROR: Invalid Character '" << c << "' found. Phone number must be numeric." << std::endl;
                return false;
            }
        }
        // Format the phone number
        std::string formatted_number;
        int count = 0;
        for (char digit : new_phone_number) {
            if (count == 3 || count == 6) {
                formatted_number += '-';
            }
            formatted_number += digit;
            count++;
        }

        // Assuming phone_number is a member of the class, set its value
        phone_number = formatted_number;
        return true;
    }
    //Sets user address as well as test input for correctness
    bool set_street_address(const std::string& new_street_address) {
        // Check if the street address is empty
        if (new_street_address.empty()) {
            std::cout << "ERROR: Street address cannot be empty." << std::endl;
            return false;
        }
        // Check for leading whitespace
        if (std::isspace(static_cast<unsigned char>(new_street_address.front()))) {
            std::cout << "ERROR: Street address should not start with a space." << std::endl;
            return false;
        }
        // Check for trailing whitespace
        if (std::isspace(static_cast<unsigned char>(new_street_address.back()))) {
            std::cout << "ERROR: Street address should not end with a space." << std::endl;
            return false;
        }
        // Check for multiple consecutive spaces
        if (new_street_address.find("  ") != std::string::npos) {
            std::cout << "ERROR: Street address should not contain consecutive spaces." << std::endl;
            return false;
        }
        // Check for special characters (allowing letters, digits, spaces, and standard punctuation)
        std::regex valid_characters_pattern("^[a-zA-Z0-9 .,#-]*$");
        if (!std::regex_match(new_street_address, valid_characters_pattern)) {
            std::cout << "ERROR: Street address contains invalid characters." << std::endl;
            return false;
        }
        // Check if the address contains at least one alphabetic character
        std::regex alphabetic_pattern(".*[a-zA-Z]+.*");
        if (!std::regex_match(new_street_address, alphabetic_pattern)) {
            std::cout << "ERROR: Street address must contain at least one alphabetic character." << std::endl;
            return false;
        }
        // Set the street address if all checks pass
        street_address = new_street_address;
        return true;
    }
    //This will set city and test for user input
    bool set_city(const std::string& new_city) {
        // Check if the city name is empty
        if (new_city.empty()) {
            std::cout << "ERROR: City name cannot be empty." << std::endl;
            return false;
        }
        // Check for leading or trailing whitespace
        if (std::isspace(static_cast<unsigned char>(new_city.front())) || std::isspace(static_cast<unsigned char>(new_city.back()))) {
            std::cout << "ERROR: City name should not start or end with a space." << std::endl;
            return false;
        }
        // Check for multiple consecutive spaces
        if (new_city.find("  ") != std::string::npos) {
            std::cout << "ERROR: City name should not contain consecutive spaces." << std::endl;
            return false;
        }
        // Check for invalid characters (allowing only letters, spaces, and dots)
        std::regex valid_characters_pattern("^[a-zA-Z .]*$");
        if (!std::regex_match(new_city, valid_characters_pattern)) {
            std::cout << "ERROR: City name contains invalid characters. Only letters, spaces, and dots are allowed." << std::endl;
            return false;
        }
        // Set the city name if all checks pass
        city = new_city;
        return true;
    }
    //This will set state and test input
    bool set_state(const std::string& new_state) {
        // Check if the state name is empty
        if (new_state.empty()) {
            std::cout << "ERROR: State abbreviation cannot be empty." << std::endl;
            return false;
        }
        // Check for leading or trailing whitespace
        if (std::isspace(static_cast<unsigned char>(new_state.front())) || std::isspace(static_cast<unsigned char>(new_state.back()))) {
            std::cout << "ERROR: State abbreviation should not start or end with a space." << std::endl;
            return false;
        }
        // Check for invalid characters (allowing only uppercase letters)
        std::regex valid_characters_pattern("^[A-Z]{2}$");
        if (!std::regex_match(new_state, valid_characters_pattern)) {
            std::cout << "ERROR: State abbreviation is invalid. It should consist of two uppercase letters." << std::endl;
            return false;
        }
        // Check if the abbreviation is a valid state abbreviation
        static const std::unordered_set<std::string> valid_state_abbreviations = {
            "AL", "AK", "AZ", "AR", "CA", "CO", "CT", "DE", "FL", "GA",
            "HI", "ID", "IL", "IN", "IA", "KS", "KY", "LA", "ME", "MD",
            "MA", "MI", "MN", "MS", "MO", "MT", "NE", "NV", "NH", "NJ",
            "NM", "NY", "NC", "ND", "OH", "OK", "OR", "PA", "RI", "SC",
            "SD", "TN", "TX", "UT", "VT", "VA", "WA", "WV", "WI", "WY"
        };

        if (valid_state_abbreviations.find(new_state) == valid_state_abbreviations.end()) {
            std::cout << "ERROR: State abbreviation is not a valid state abbreviation." << std::endl;
            return false;
        }
        // Set the state abbreviation if all checks pass
        state = new_state;
        return true;
    }
    //This is to set a zip code and test to ensure input valitity
    bool set_zip_code(const std::string& new_zip_code) {
        // Check if the zip code is empty
        if (new_zip_code.empty()) {
            std::cout << "ERROR: ZIP code cannot be empty." << std::endl;
            return false;
        }
        // Check for valid ZIP code format
        std::regex valid_zip_code_pattern("^[0-9]{5}(-[0-9]{4})?$");
        bool is_match = std::regex_match(new_zip_code, valid_zip_code_pattern);
        std::cout << "Checking ZIP code: " << new_zip_code << " Match: " << (is_match ? "true" : "false") << std::endl;
        if (!is_match) {
            std::cout << "ERROR: ZIP code is invalid. It should be either a 5-digit number or a ZIP+4 format (5-digit number followed by a dash and 4-digit number)." << std::endl;
            return false;
        }
        // Set the ZIP code if all checks pass
        zip_code = new_zip_code;
        return true;
    }
    //Method
    bool gather_customer_information();
    bool print_customer_details();
    bool verify_customer_details();
    void customer_details();
};