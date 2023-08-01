#ifndef VERIFIER_H
#define VERIFIER_H

#include <iostream>
#include "Stack.hpp"
#include <cctype>

class Verifier{
  public:
  static std::string Infixa_to_Polonesa(std::string expressao);
  static std::string Polonesa_to_Infixa(std::string expressao);
  static bool validaPolonesa(std::string expressao);
  static bool validaInfixa(std::string expressao);
};

#endif
