#include "Functions.hpp"

void Functions::LerInfixa(Expression &exp_armazenada, std::string &expressao){
  exp_armazenada.expressao_interna.Limpa();
  std::getline(std::cin, expressao);
  if(Verifier::validaInfixa(expressao)){
    std::string expressaoConvertida = Verifier::Infixa_to_Polonesa(expressao);
    exp_armazenada.inserirExpressao(expressaoConvertida);
    std::cout << "EXPRESSAO OK: " << expressao << "\n";
  }
  else {
    std::cout << "ERRO: " << expressao << " NAO VALIDA\n";
  }
}

void Functions::LerPosfixa(Expression &exp_armazenada, std::string &expressao){
  exp_armazenada.expressao_interna.Limpa();
  std::getline(std::cin, expressao);
  if(Verifier::validaPolonesa(expressao)){
    exp_armazenada.inserirExpressao(expressao);
    std::cout << "EXPRESSAO OK: " << expressao << "\n";
  }
  else {
    std::cout << "ERRO: " << expressao << " NAO VALIDA\n";
  }
}

std::string Functions::ConvertepInfixa(Expression &exp_armazenada){
  if(exp_armazenada.expressao_interna.getRaiz() == nullptr){
    std::cout << "ERRO: EXP NAO EXISTE\n";
    return "";
  }
  else{
    std::string exp_polonesa = exp_armazenada.PosOrdem(exp_armazenada.expressao_interna.getRaiz());
    std::string exp_infixa = Verifier::Polonesa_to_Infixa(exp_polonesa);
    std::cout << "INFIXA: " << exp_infixa << "\n";
    return (exp_infixa);
  }
}

std::string Functions::ConvertepPosfixa(Expression &exp_armazenada){
  if(exp_armazenada.expressao_interna.getRaiz() == nullptr){
    std::cout << "ERRO: EXP NAO EXISTE\n";
    return "";
  }
  else{
    std::string exp_polonesa = exp_armazenada.PosOrdem(exp_armazenada.expressao_interna.getRaiz());
    std::cout << "POSFIXA: " << exp_polonesa << "\n";
    return (exp_polonesa);
  }
}

double Functions::Resolve(Expression &exp_armazenada){
  if(exp_armazenada.expressao_interna.getRaiz() == nullptr){
    std::cout << "ERRO: EXP NAO EXISTE\n";
    return (0.0);
  }
  else{
    double resultado = (exp_armazenada.calcularResultado(exp_armazenada.expressao_interna.getRaiz()));
    std::cout << "VAL: " << resultado << "\n";
    return (resultado);
  }
}