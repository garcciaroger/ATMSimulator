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
