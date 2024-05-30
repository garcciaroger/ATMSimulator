#include <gtest/gtest.h>
#include "AccountHolder.h"

/*
    TESTS FOR set_first_name()
*/
class AccountHolderFirstNameTest : public ::testing::Test {
protected:
    AccountHolder holder; // AccountHolder instance for use in all tests
};
// Test for valid first name with a dash
TEST_F(AccountHolderFirstNameTest, Dash) {
    EXPECT_TRUE(holder.set_first_name("John-Doe"));
    EXPECT_EQ(holder.get_first_name(), "John-Doe");
}
// Test for a five-letter name
TEST_F(AccountHolderFirstNameTest, FiveLetters) {
    EXPECT_TRUE(holder.set_first_name("Roger"));
    EXPECT_EQ(holder.get_first_name(), "Roger");
}
// Test for a normal name
TEST_F(AccountHolderFirstNameTest, NormalName) {
    EXPECT_TRUE(holder.set_first_name("Zideane"));
    EXPECT_EQ(holder.get_first_name(), "Zideane");
}
// Test for an empty name
TEST_F(AccountHolderFirstNameTest, Empty) {
    EXPECT_FALSE(holder.set_first_name(""));
    EXPECT_EQ(holder.get_first_name(), "");
}
// Test for a name containing only numbers
TEST_F(AccountHolderFirstNameTest, Numbers) {
    EXPECT_FALSE(holder.set_first_name("65416351"));
    EXPECT_EQ(holder.get_first_name(), "");
}
// Test for a name with a zero in it
TEST_F(AccountHolderFirstNameTest, ZeroInName) {
    EXPECT_FALSE(holder.set_first_name("J0onson"));
    EXPECT_EQ(holder.get_first_name(), "");
}
// Test for a name with special characters
TEST_F(AccountHolderFirstNameTest, SpecialCharacters) {
    EXPECT_FALSE(holder.set_first_name("!@#$%"));
    EXPECT_EQ(holder.get_first_name(), "");
}

/*
    TESTS FOR set_last_name()
*/
class AccountHolderLastNameTest : public ::testing::Test {
protected:
    AccountHolder holder; // AccountHolder instance for use in all tests
};
// Test for valid last name with a dash
TEST_F(AccountHolderLastNameTest, Dash) {
    EXPECT_TRUE(holder.set_last_name("Doe-Smith"));
    EXPECT_EQ(holder.get_last_name(), "Doe-Smith");
}
// Test for a five-letter name
TEST_F(AccountHolderLastNameTest, FiveLetters) {
    EXPECT_TRUE(holder.set_last_name("Smith"));
    EXPECT_EQ(holder.get_last_name(), "Smith");
}
// Test for a normal name
TEST_F(AccountHolderLastNameTest, NormalName) {
    EXPECT_TRUE(holder.set_last_name("Johnson"));
    EXPECT_EQ(holder.get_last_name(), "Johnson");
}
// Test for an empty name
TEST_F(AccountHolderLastNameTest, Empty) {
    EXPECT_FALSE(holder.set_last_name(""));
    EXPECT_EQ(holder.get_last_name(), "");
}
// Test for a name containing only numbers
TEST_F(AccountHolderLastNameTest, Numbers) {
    EXPECT_FALSE(holder.set_last_name("65416351"));
    EXPECT_EQ(holder.get_last_name(), "");
}
// Test for a name with a zero in it
TEST_F(AccountHolderLastNameTest, ZeroInName) {
    EXPECT_FALSE(holder.set_last_name("Sm1th"));
    EXPECT_EQ(holder.get_last_name(), "");
}
// Test for a name with special characters
TEST_F(AccountHolderLastNameTest, SpecialCharacters) {
    EXPECT_FALSE(holder.set_last_name("!@#$%"));
    EXPECT_EQ(holder.get_last_name(), "");
}


/*
    TESTS FOR set_email()
*/
class AccountHolderEmailTest : public ::testing::Test {
protected:
    AccountHolder holder; // AccountHolder instance for use in all tests
};
// Test for a valid email
TEST_F(AccountHolderEmailTest, ValidEmail) {
    EXPECT_TRUE(holder.set_email_address("john.doe@example.com"));
    EXPECT_EQ(holder.get_email_address(), "john.doe@example.com");
}
// Test for an email without an "@" symbol
TEST_F(AccountHolderEmailTest, MissingAtSymbol) {
    EXPECT_FALSE(holder.set_email_address("john.doeexample.com"));
    EXPECT_EQ(holder.get_email_address(), "");
}
// Test for an email without a domain
TEST_F(AccountHolderEmailTest, MissingDomain) {
    EXPECT_FALSE(holder.set_email_address("john.doe@.com"));
    EXPECT_EQ(holder.get_email_address(), "");
}
// Test for an email without a top-level domain
TEST_F(AccountHolderEmailTest, MissingTopLevelDomain) {
    EXPECT_FALSE(holder.set_email_address("john.doe@example"));
    EXPECT_EQ(holder.get_email_address(), "");
}
// Test for an empty email
TEST_F(AccountHolderEmailTest, Empty) {
    EXPECT_FALSE(holder.set_email_address(""));
    EXPECT_EQ(holder.get_email_address(), "");
}
// Test for an email with special characters
TEST_F(AccountHolderEmailTest, SpecialCharacters) {
    EXPECT_FALSE(holder.set_email_address("john!doe@example.com"));
    EXPECT_EQ(holder.get_email_address(), "");
}


/*
    TESTS FOR set_phone_number()
*/
class AccountHolderPhoneNumberTest : public ::testing::Test {
protected:
    AccountHolder holder; // AccountHolder instance for use in all tests
};
// Test for a valid phone number
TEST_F(AccountHolderPhoneNumberTest, ValidPhoneNumber) {
    EXPECT_TRUE(holder.set_phone_number("1234567890"));
    EXPECT_EQ(holder.get_phone_number(), "123-456-7890");
}
// Test for a phone number with spaces
TEST_F(AccountHolderPhoneNumberTest, PhoneNumberWithSpaces) {
    EXPECT_FALSE(holder.set_phone_number("123 456 7890"));
    EXPECT_EQ(holder.get_phone_number(), "");
}
// Test for a phone number with dashes
TEST_F(AccountHolderPhoneNumberTest, PhoneNumberWithDashes) {
    EXPECT_FALSE(holder.set_phone_number("123-456-7890"));
    EXPECT_EQ(holder.get_phone_number(), "");
}
// Test for a phone number with parentheses
TEST_F(AccountHolderPhoneNumberTest, PhoneNumberWithParentheses) {
    EXPECT_FALSE(holder.set_phone_number("(123) 456-7890"));
    EXPECT_EQ(holder.get_phone_number(), "");
}
// Test for an empty phone number
TEST_F(AccountHolderPhoneNumberTest, EmptyPhoneNumber) {
    EXPECT_FALSE(holder.set_phone_number(""));
    EXPECT_EQ(holder.get_phone_number(), "");
}
// Test for a phone number with non-numeric characters
TEST_F(AccountHolderPhoneNumberTest, NonNumericPhoneNumber) {
    EXPECT_FALSE(holder.set_phone_number("1234567890a"));
    EXPECT_EQ(holder.get_phone_number(), "");
}

/*
    TESTS FOR set_street_address()
*/
class AccountHolderAddressTest : public ::testing::Test {
protected:
    AccountHolder holder; // AccountHolder instance for use in all tests
};
// Test for a valid street address
TEST_F(AccountHolderAddressTest, ValidStreetAddress) {
    EXPECT_TRUE(holder.set_street_address("123 Main St"));
    EXPECT_EQ(holder.get_street_address(), "123 Main St");
}
// Test for an empty street address
TEST_F(AccountHolderAddressTest, EmptyStreetAddress) {
    EXPECT_FALSE(holder.set_street_address(""));
    EXPECT_EQ(holder.get_street_address(), "");
}
TEST_F(AccountHolderAddressTest, DoubleSpaceWithinAddress) {
    EXPECT_FALSE(holder.set_street_address("123  Main St"));
    EXPECT_EQ(holder.get_street_address(), "");
}
// Test for a street address with special characters
TEST_F(AccountHolderAddressTest, StreetAddressWithSpecialCharacters) {
    EXPECT_TRUE(holder.set_street_address("456 Oak St #3"));
    EXPECT_EQ(holder.get_street_address(), "456 Oak St #3");
}
// Test for a street address with invalid characters
TEST_F(AccountHolderAddressTest, StreetAddressWithInvalidCharacters) {
    EXPECT_FALSE(holder.set_street_address("789 Pine St @4"));
    EXPECT_EQ(holder.get_street_address(), "");
}
// Test for a street address with numbers only
TEST_F(AccountHolderAddressTest, StreetAddressNumbersOnly) {
    EXPECT_FALSE(holder.set_street_address("5678"));
    EXPECT_EQ(holder.get_street_address(), "");
}

/*
    TESTS for set_city()
*/
class AccountHolderCityTest : public ::testing::Test {
protected:
    AccountHolder holder; // AccountHolder instance for use in all tests
};
// Test for a valid city name
TEST_F(AccountHolderCityTest, ValidCityName) {
    EXPECT_TRUE(holder.set_city("Dallas"));
    EXPECT_EQ(holder.get_city(), "Dallas");
}
// Test for an empty city name
TEST_F(AccountHolderCityTest, EmptyCityName) {
    EXPECT_FALSE(holder.set_city(""));
    EXPECT_EQ(holder.get_city(), "");
}
// Test for a city name with leading space
TEST_F(AccountHolderCityTest, LeadingSpaceCityName) {
    EXPECT_FALSE(holder.set_city(" Dallas"));
    EXPECT_EQ(holder.get_city(), "");
}
// Test for a city name with trailing space
TEST_F(AccountHolderCityTest, TrailingSpaceCityName) {
    EXPECT_FALSE(holder.set_city("Dallas "));
    EXPECT_EQ(holder.get_city(), "");
}
// Test for a city name with double spaces within the name
TEST_F(AccountHolderCityTest, DoubleSpaceWithinCityName) {
    EXPECT_FALSE(holder.set_city("New  York"));
    EXPECT_EQ(holder.get_city(), "");
}
// Test for a city name with special characters
TEST_F(AccountHolderCityTest, CityNameWithSpecialCharacters) {
    EXPECT_TRUE(holder.set_city("St. Louis"));
    EXPECT_EQ(holder.get_city(), "St. Louis");
}
// Test for a city name with invalid characters
TEST_F(AccountHolderCityTest, CityNameWithInvalidCharacters) {
    EXPECT_FALSE(holder.set_city("New@York"));
    EXPECT_EQ(holder.get_city(), "");
}
// Test for a city name with numbers only
TEST_F(AccountHolderCityTest, CityNameNumbersOnly) {
    EXPECT_FALSE(holder.set_city("1234"));
    EXPECT_EQ(holder.get_city(), "");
}

/*
    TESTS for set_state()
*/
class AccountHolderStateTest : public ::testing::Test {
protected:
    AccountHolder holder; // AccountHolder instance for use in all tests
};
// Test for a valid state abbreviation
TEST_F(AccountHolderStateTest, ValidStateAbbreviation) {
    EXPECT_TRUE(holder.set_state("TX"));
    EXPECT_EQ(holder.get_state(), "TX");
}
// Test for an empty state abbreviation
TEST_F(AccountHolderStateTest, EmptyStateAbbreviation) {
    EXPECT_FALSE(holder.set_state(""));
    EXPECT_EQ(holder.get_state(), "");
}
// Test for a state abbreviation with leading space
TEST_F(AccountHolderStateTest, LeadingSpaceStateAbbreviation) {
    EXPECT_FALSE(holder.set_state(" TX"));
    EXPECT_EQ(holder.get_state(), "");
}
// Test for a state abbreviation with trailing space
TEST_F(AccountHolderStateTest, TrailingSpaceStateAbbreviation) {
    EXPECT_FALSE(holder.set_state("TX "));
    EXPECT_EQ(holder.get_state(), "");
}
// Test for a state abbreviation with double spaces within the abbreviation
TEST_F(AccountHolderStateTest, DoubleSpaceWithinStateAbbreviation) {
    EXPECT_FALSE(holder.set_state("N Y"));
    EXPECT_EQ(holder.get_state(), "");
}
// Test for a state abbreviation with lowercase characters
TEST_F(AccountHolderStateTest, StateAbbreviationWithLowercaseCharacters) {
    EXPECT_FALSE(holder.set_state("tx"));
    EXPECT_EQ(holder.get_state(), "");
}
// Test for a state abbreviation with more than two characters
TEST_F(AccountHolderStateTest, StateAbbreviationWithMoreThanTwoCharacters) {
    EXPECT_FALSE(holder.set_state("TEX"));
    EXPECT_EQ(holder.get_state(), "");
}
// Test for a state abbreviation that is not a valid state abbreviation
TEST_F(AccountHolderStateTest, InvalidStateAbbreviation) {
    EXPECT_FALSE(holder.set_state("ZZ"));
    EXPECT_EQ(holder.get_state(), "");
}

/*
    TESTS for set_zip()
*/
class AccountHolderZipCodeTest : public ::testing::Test {
protected:
    AccountHolder holder; // AccountHolder instance for use in all tests
};
// Test for a valid 5-digit ZIP code
TEST_F(AccountHolderZipCodeTest, ValidFiveDigitZipCode) {
    EXPECT_TRUE(holder.set_zip_code("12345"));
    EXPECT_EQ(holder.get_zip_code(), "12345");
}
// Test for a valid 9-digit ZIP code (ZIP+4 format)
TEST_F(AccountHolderZipCodeTest, ValidNineDigitZipCode) {
    EXPECT_TRUE(holder.set_zip_code("12345-6789"));
    EXPECT_EQ(holder.get_zip_code(), "12345-6789");
}
// Test for an empty ZIP code
TEST_F(AccountHolderZipCodeTest, EmptyZipCode) {
    EXPECT_FALSE(holder.set_zip_code(""));
    EXPECT_EQ(holder.get_zip_code(), "");
}
// Test for a ZIP code with less than 5 digits
TEST_F(AccountHolderZipCodeTest, LessThanFiveDigitZipCode) {
    EXPECT_FALSE(holder.set_zip_code("1234"));
    EXPECT_EQ(holder.get_zip_code(), "");
}
// Test for a ZIP code with more than 5 but less than 9 digits
TEST_F(AccountHolderZipCodeTest, MoreThanFiveButLessThanNineDigitZipCode) {
    EXPECT_FALSE(holder.set_zip_code("123456"));
    EXPECT_EQ(holder.get_zip_code(), "");
}
// Test for a ZIP code with more than 5 digits and not in ZIP+4 format
TEST_F(AccountHolderZipCodeTest, MoreThanFiveDigitsNotInZipPlusFourFormat) {
    EXPECT_FALSE(holder.set_zip_code("123456789"));
    EXPECT_EQ(holder.get_zip_code(), "");
}
// Test for a ZIP code with invalid characters
TEST_F(AccountHolderZipCodeTest, ZipCodeWithInvalidCharacters) {
    EXPECT_FALSE(holder.set_zip_code("1234a"));
    EXPECT_EQ(holder.get_zip_code(), "");
}
// Test for a ZIP+4 code with invalid characters
TEST_F(AccountHolderZipCodeTest, ZipPlusFourWithInvalidCharacters) {
    EXPECT_FALSE(holder.set_zip_code("12345-67a9"));
    EXPECT_EQ(holder.get_zip_code(), "");
}
// Test for a ZIP+4 code with missing dash
TEST_F(AccountHolderZipCodeTest, ZipPlusFourMissingDash) {
    EXPECT_FALSE(holder.set_zip_code("123456789"));
    EXPECT_EQ(holder.get_zip_code(), "");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
