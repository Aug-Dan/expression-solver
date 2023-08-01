#include "Node.hpp"
#include "BinaryTree.hpp"
#include "Verifier.hpp"
#include "Expression.hpp"
#include "Functions.hpp"
#include <iostream>

int main(){
  std::string comando;
  std::string expressao;
  Expression exp_armazenada;

  while (std::cin >> comando) {

    if (comando == "LER") {
      std::cin >> comando;
      if (comando == "INFIXA") {
        Functions::LerInfixa(exp_armazenada, expressao);
      }
      else if (comando == "POSFIXA") {
        Functions::LerPosfixa(exp_armazenada, expressao);
      }
    }
    else if (comando == "INFIXA") {
      Functions::ConvertepInfixa(exp_armazenada);
    }
    else if (comando == "POSFIXA")  {
      Functions::ConvertepPosfixa(exp_armazenada);
    }
    else if (comando == "RESOLVE")  {
      Functions::Resolve(exp_armazenada);
    }
  }

  exp_armazenada.expressao_interna.Limpa();
  return 0;

}