#include <gtest/gtest.h>
#include "AccountHolder.h" // Ensure this includes the AccountHolder class definition

// Test Fixture for AccountHolder
class AccountHolderTest : public ::testing::Test {
protected:
    AccountHolder holder; // AccountHolder instance for use in all tests
};

// Test for valid first name
TEST_F(AccountHolderTest, ValidFirstName) {
    EXPECT_TRUE(holder.set_first_name("John-Doe"));
    EXPECT_EQ(holder.get_first_name(), "John-Doe");
}

// Test for invalid first name with invalid characters
TEST_F(AccountHolderTest, InvalidCharactersFirstName) {
    EXPECT_FALSE(holder.set_first_name("John123"));
}

// Test for empty first name
TEST_F(AccountHolderTest, EmptyFirstName) {
    EXPECT_FALSE(holder.set_first_name(""));
}

// Test for first name with special characters that should fail
TEST_F(AccountHolderTest, SpecialCharactersFirstName) {
    EXPECT_FALSE(holder.set_first_name("John*"));
}

TEST_F(AccountHolderTest, LongestName){
    EXPECT_FALSE(holder.set_first_name("QWERTYUIOPASDFGHJKLSZXCVBNMNBVCXZ"));
}

TEST_F(AccountHolderTest, digittest){
    EXPECT_FALSE(holder.set_first_name("123456"));
}

TEST_F(AccountHolderTest, specialChar){
    EXPECT_FALSE(holder.set_first_name("###$#$!@#"));
}