#pragma once

#include "bank.hpp"
#include <cstdlib>
#include <random>

static int rand_int() {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> distribution(0, 99999999);

  return distribution(gen);
}

class account {
private:
  int id = rand_int();
  std::string name;
};
