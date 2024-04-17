#include <gtest/gtest.h>
#include "AccountHolder.h"

/*
    THE FUNCTION BELOW TESTS set_first_name()
*/

class AccountHolderTest : public ::testing::Test {
protected:
    AccountHolder holder; // AccountHolder instance for use in all tests
    AccountHolder last_name_test; //test for set_last_name();
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



/*
    THE FUNCTION BELOW TESTS set_last_name()
*/
//Test for numbers
TEST_F(AccountHolderTest, specialChar){
    EXPECT_FALSE(holder.set_last_name("###$#$!@#"));
}
//Test for white spaces
TEST_F(AccountHolderTest, specialChar){
    EXPECT_FALSE(holder.set_last_name("###$#$!@#"));
}
//Test for Special Characters
TEST_F(AccountHolderTest, specialChar){
    EXPECT_FALSE(holder.set_last_name("###$#$!@#"));
}
//Test for max length
TEST_F(AccountHolderTest, specialChar){
    EXPECT_FALSE(holder.set_last_name("###$#$!@#"));
}
//Test for Empty String
TEST_F(AccountHolderTest, specialChar){
    EXPECT_FALSE(holder.set_last_name("###$#$!@#"));
}