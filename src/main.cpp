#include "../lib/account.hpp"
#include "../lib/bank.hpp" // Include necessary headers
#include "gtest/gtest.h"
// Test fixture for the account class
class AccountTest : public ::testing::Test {
protected:
  void SetUp() override {
    // Setup code if needed before each test
  }

  void TearDown() override {
    // Teardown code if needed after each test
  }

  // Add any helper functions or member variables here
};

// Test deposit function
TEST_F(AccountTest, Deposit) {
  bank myBank("Test Bank", 100000, 0.05); // Provide the required parameters
  account myAccount("John Doe", myBank);  // Create an account

  // Test deposit with a valid amount
  EXPECT_NO_THROW({
    int new_balance = myAccount.deposit(100);
    EXPECT_EQ(new_balance,
              100 - static_cast<int>(100 * myBank.get_interest_rate()));
  });

  // Test deposit with an invalid amount
  EXPECT_THROW({ myAccount.deposit(-50); }, std::invalid_argument);
}

// Test withdraw function
TEST_F(AccountTest, Withdraw) {
  bank myBank("Test Bank", 100000, 0.05); // Provide the required parameters
  account myAccount("John Doe", myBank);  // Create an account

  // Test withdraw with a valid amount
  EXPECT_NO_THROW({
    myAccount.deposit(200); // Deposit some money first
    int new_balance = myAccount.withdraw(100);
    EXPECT_EQ(new_balance,
              100 - static_cast<int>(100 * myBank.get_interest_rate()));
  });

  // Test withdraw with an invalid amount
  EXPECT_THROW(
      {
        myAccount.withdraw(300); // Attempt to withdraw more than the balance
      },
      std::invalid_argument);

  // Test withdraw with insufficient balance
  EXPECT_THROW({ myAccount.withdraw(100); }, std::invalid_argument);
}

// Test get_balance function
TEST_F(AccountTest, GetBalance) {
  bank myBank("Test Bank", 100000, 0.05); // Provide the required parameters
  account myAccount("John Doe", myBank);  // Create an account

  // Test get_balance after deposit
  myAccount.deposit(100);
  EXPECT_EQ(myAccount.get_balance(),
            100 - static_cast<int>(100 * myBank.get_interest_rate()));
}

// Add more tests as needed

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
