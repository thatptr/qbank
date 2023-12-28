#pragma once

#include "bank.hpp"
#include <cstdlib>
#include <random>
#include <stdexcept>

static int rand_int() {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> distribution(0, 99999999);

  return distribution(gen);
}

class account {
private:
  std::string name;
  int balance;
  int id;
  bank *linked_bank;

public:
  account(const std::string &name, bank &linked_bank)
      : name(name), balance(0), id(rand_int()), linked_bank(&linked_bank) {}

  // Deposits amount from account, return account balance or an exception for an
  // error
  int deposit(int amount) {
    if (amount <= 0)
      throw std::invalid_argument("Amount must be greater than 0");

    this->balance += static_cast<int>(
        amount - (amount * this->linked_bank->get_interest_rate()));
    return this->balance;
  }

  // Withdraws amount from account, returns account balance or an exception for
  // an error
  int withdraw(int amount) {
    if (amount <= 0 || balance <= 0 || balance < amount)
      throw std::invalid_argument("Amount must be greater than 0");

    int interest =
        static_cast<int>(amount * this->linked_bank->get_interest_rate());
    int withdraw_balance = this->balance - (amount + interest);

    this->balance = withdraw_balance;

    return this->balance;
  }

  // Gets balance
  int get_balance() { return this->balance; }
};
