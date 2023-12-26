#include <gtest/gtest.h>
#include "../lib/account.hpp"

// Test fixture for the account class
class AccountTest : public ::testing::Test {
protected:
  void SetUp() override {
    // You can perform setup steps here if needed
  }

  void TearDown() override {
    // You can perform cleanup steps here if needed
  }

  // You may want to declare common variables accessible to your tests
};

// Test deposit functionality
TEST_F(AccountTest, Deposit) {
  bank testBank("Test Bank", 1000, 0.05);  // Add an initial capital of 1000 to the test bank
  account testAccount("John Doe", testBank);

  EXPECT_EQ(testAccount.get_balance(), 0);

  // Deposit some money
  int depositAmount = 100;
  testAccount.deposit(depositAmount);

  // Verify the balance after deposit
  EXPECT_EQ(testAccount.get_balance(), depositAmount - static_cast<int>(depositAmount * testBank.get_interest_rate()));
}

// Test withdrawal functionality
TEST_F(AccountTest, Withdraw) {
  bank testBank("Test Bank", 1000, 0.05);  // Add an initial capital of 1000 to the test bank
  account testAccount("John Doe", testBank);

  EXPECT_EQ(testAccount.get_balance(), 0);

  // Withdraw without sufficient balance (expect exception)
  EXPECT_THROW(testAccount.withdraw(100), std::invalid_argument);

  // Deposit some money
  testAccount.deposit(200);

  // Withdraw a valid amount
  int withdrawalAmount = 50;
  testAccount.withdraw(withdrawalAmount);

  // Verify the balance after withdrawal
  EXPECT_EQ(testAccount.get_balance(), 200 - withdrawalAmount);
}

// Add more test cases as needed...

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
