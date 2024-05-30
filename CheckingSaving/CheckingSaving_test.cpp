#include "CheckingSaving.h"
#include <gtest/gtest.h>

/*
    Test cases for validate_amount()
*/
TEST(AccountTest, ValidateAmountNegativeMaxLimit) {
    Account account;
    // Test for negative amount
    EXPECT_FALSE(account.validate_amount(-10));
    // Test for zero amount
    EXPECT_FALSE(account.validate_amount(0));
    // Test for amount greater than negative maximum limit
    EXPECT_FALSE(account.validate_amount(-Account::get_max_limit() - 1));
    // Test for valid amount
    EXPECT_TRUE(account.validate_amount(100));
}

TEST(AccountTest, ValidateAmountZeroMaxLimit) {
    Account account;
    // Test for negative amount
    EXPECT_FALSE(account.validate_amount(-10));
    // Test for zero amount
    EXPECT_FALSE(account.validate_amount(0));
    // Test for amount greater than zero maximum limit
    EXPECT_FALSE(account.validate_amount(Account::get_max_limit() + 1));
    // Test for valid amount
    EXPECT_TRUE(account.validate_amount(100));
}

TEST(AccountTest, ValidateAmountLargeMaxLimit) {
    Account account;
    // Test for negative amount
    EXPECT_FALSE(account.validate_amount(-10));
    // Test for zero amount
    EXPECT_FALSE(account.validate_amount(0));
    // Test for amount greater than large maximum limit
    EXPECT_FALSE(account.validate_amount(std::numeric_limits<double>::max()));
    // Test for valid amount
    EXPECT_TRUE(account.validate_amount(100));
}

TEST(AccountTest, ValidateAmountEdgeCases) {
    Account account;
    // Test for negative amount
    EXPECT_FALSE(account.validate_amount(-10));
    // Test for zero amount
    EXPECT_FALSE(account.validate_amount(0));
    // Test for amount just below the maximum limit
    EXPECT_TRUE(account.validate_amount(Account::get_max_limit() - 1));
    // Test for amount just above the maximum limit
    EXPECT_FALSE(account.validate_amount(Account::get_max_limit() + 1));
    // Test for maximum allowed amount
    EXPECT_TRUE(account.validate_amount(Account::get_max_limit()));
}

/*
    Test case for deposit()
*/
TEST(AccountDepositTest, PositiveDeposit) {
    Account account;
    double initialBalance = account.get_balance();

    double depositAmount = 100.0;
    ASSERT_TRUE(account.deposit(depositAmount));

    double expectedBalance = initialBalance + depositAmount;
    ASSERT_EQ(account.get_balance(), expectedBalance);
}
TEST(AccountDepositTest, ZeroDeposit) {
    Account account;
    double initialBalance = account.get_balance();

    double depositAmount = 0.0;
    ASSERT_TRUE(account.deposit(depositAmount));

    ASSERT_EQ(account.get_balance(), initialBalance); // Balance should remain unchanged
}
TEST(AccountDepositTest, NegativeDeposit) {
    Account account;
    double initialBalance = account.get_balance();

    double depositAmount = -50.0;
    ASSERT_FALSE(account.deposit(depositAmount));

    ASSERT_EQ(account.get_balance(), initialBalance); // Balance should remain unchanged
}
TEST(AccountDepositTest, LargeDeposit) {
    Account account;
    double initialBalance = account.get_balance();

    double depositAmount = 100000.0; // Large deposit amount
    ASSERT_TRUE(account.deposit(depositAmount));

    double expectedBalance = initialBalance + depositAmount;
    ASSERT_EQ(account.get_balance(), expectedBalance); // Balance should be increased by the deposit amount
}
TEST(AccountDepositTest, MultipleDeposits) {
    Account account;
    double initialBalance = account.get_balance();

    double depositAmount1 = 50.0;
    double depositAmount2 = 75.0;

    // Make multiple deposits
    ASSERT_TRUE(account.deposit(depositAmount1));
    ASSERT_TRUE(account.deposit(depositAmount2));

    double expectedBalance = initialBalance + depositAmount1 + depositAmount2;
    ASSERT_EQ(account.get_balance(), expectedBalance); // Balance should be increased by the total deposit amount
}
TEST(AccountDepositTest, ExceedMaxLimitDeposit) {
    Account account;
    double initialBalance = account.get_balance();

    double depositAmount = Account::get_max_limit() - initialBalance + 1; // Deposit amount exceeds the maximum limit
    ASSERT_FALSE(account.deposit(depositAmount));

    ASSERT_EQ(account.get_balance(), initialBalance); // Balance should remain unchanged
}

/*
    Test case for withdraw()
*/
TEST(AccountWithdrawTest, SufficientBalance) {
    Account account;
    account.deposit(100.0); // Deposit some initial amount

    double initialBalance = account.get_balance();
    double withdrawAmount = 50.0;
    ASSERT_TRUE(account.withdraw(withdrawAmount));

    double expectedBalance = initialBalance - withdrawAmount;
    ASSERT_EQ(account.get_balance(), expectedBalance);
}

TEST(AccountWithdrawTest, InsufficientBalance) {
    Account account;
    account.deposit(100.0); // Deposit some initial amount

    double initialBalance = account.get_balance();
    double withdrawAmount = 150.0; // Try to withdraw more than the balance
    ASSERT_FALSE(account.withdraw(withdrawAmount));

    ASSERT_EQ(account.get_balance(), initialBalance); // Balance should remain unchanged
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}