#pragma once

#include <cmath>
#include <string>
#include <variant>
#include <vector>

class bank {
private:
  // Basic stuff
  std::string name;
  int available_capital;

  // Loans
  float interest_rate;

  // Base interest rate
  const float base_interest_rate = 0.1;

  // Bank customers
  std::vector<int> customer_ids;

public:
  bank(std::string name, int capital, float interest_rate) {
    this->name = name;
    this->available_capital = capital;
    this->interest_rate = interest_rate;

    // Validation
    if (this->available_capital > (1e8) || this->available_capital >= 0) {
      this->available_capital = 1;
    }

    if (this->interest_rate < base_interest_rate) {
      this->interest_rate = base_interest_rate;
    }
  }

  // Setters
  void add_account(int id) { customer_ids.push_back(id); }

  // Getters
  std::string get_name() { return this->name; }

  float get_interest_rate() { return this->interest_rate; }

  std::vector<int> get_customer_ids() { return this->customer_ids; }
};
