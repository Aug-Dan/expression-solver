#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "Verifier.hpp"
#include "Expression.hpp"

#include <iostream>
#include <sstream>

class Functions {
  public:
  static void LerInfixa(Expression &exp_armazenada, std::string &expressao);
  static void LerPosfixa(Expression &exp_armazenada, std::string &expressao);
  static std::string ConvertepInfixa(Expression &exp_armazenada);
  static std::string ConvertepPosfixa(Expression &exp_armazenada);
  static double Resolve(Expression &exp_armazenada);

};

#endif