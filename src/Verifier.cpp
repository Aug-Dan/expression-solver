#include "Verifier.hpp"
#include <sstream>

bool Verifier::validaPolonesa(std::string expressao){
  std::stringstream ss(expressao);
  std::string parte;
  Stack pilha;

    while (ss >> parte) {
      if (isdigit(parte[0]) || (parte[0] == '-' && isdigit(parte[1]))) {
          // Se for um número, empilha na pilha
          pilha.empilha(parte);
      } 
      else {
          // Senão, é um operador, desempilha os dois últimos operandos e faz a operação correspondente, empilhando o resultado
        if (pilha.get_tamanho() < 2) { // Verifica se há pelo menos dois operandos na pilha
            return false;
        }
        double op2 = std::stod(pilha.desempilha());
        double op1 = std::stod(pilha.desempilha());
        if (parte == "+") {
            pilha.empilha(std::to_string(op1 + op2));
        } else if (parte == "-") {
            pilha.empilha(std::to_string(op1 - op2));
        } else if (parte == "*") {
            pilha.empilha(std::to_string(op1 * op2));
        } else if (parte == "/") {
            if (op2 == 0) { // Verifica divisão por zero
                return false;
            }
          pilha.empilha(std::to_string(op1 / op2));
        } 
        else { // Operador inválido
          return false;
        }
      }
    }

  if (pilha.get_tamanho() != 1) {  // Verifica se há exatamente um valor na pilha
    return false;
  }

  return true;
}

bool Verifier::validaInfixa(std::string expressao) {
  std::string versao_polonesa = Infixa_to_Polonesa(expressao);
  if(!validaPolonesa(versao_polonesa)){
    return false;
  }

  Stack pilha;
  std::istringstream ss(expressao);
  std::string parte;
  bool operandoNecessario = true;

  while (ss >> parte) {
    if (parte == "+" || parte == "-" || parte == "*" || parte == "/") {
      if (operandoNecessario) {
        return false;
      }
      operandoNecessario = true;
    } 
    else if (parte == "(") {
      pilha.empilha(parte);
    } 
    else if (parte == ")") {
      if (pilha.vazia() || pilha.ver_topo() != "(") {
        return false;
      }
      pilha.desempilha();
    } 
    else if (std::isdigit(parte[0])) {
      operandoNecessario = false;
    } 
    else {
      return false;
    }
  }

  return (pilha.vazia() && !operandoNecessario);
}

std::string Verifier::Infixa_to_Polonesa(std::string expressao){

  std::stringstream ss(expressao);
  std::string parte;
  std::string expressao_polonesa = "";
  Stack pilha;

  while (ss >> parte){

    if (parte=="("){
      pilha.empilha(parte);
    }

    if (parte==")"){
      while(pilha.ver_topo() != "("){
        expressao_polonesa = expressao_polonesa + " " + pilha.desempilha();
      }
      pilha.desempilha();
    }

    if ((parte=="+") || (parte=="-")){
      if((pilha.ver_topo() == "*") || (pilha.ver_topo() == "/")){
        expressao_polonesa = expressao_polonesa + " " + pilha.desempilha();
      }
      pilha.empilha(parte); 
    }

    if ((parte=="*") || (parte=="/")){
      pilha.empilha(parte);
    }

    if (isdigit(parte[0])){ // verifica se é um número
      expressao_polonesa = expressao_polonesa + " " + parte;
    }
  }

  while (!pilha.vazia()){ // adiciona os operadores restantes à expressão polonesa
    expressao_polonesa = expressao_polonesa + " " + pilha.desempilha();
  }
  
  return expressao_polonesa;
}

std::string Verifier::Polonesa_to_Infixa(std::string expressao){
  std::stringstream ss(expressao);
  std::string parte;
  Stack pilha;

  while (ss >> parte) {
    if (isdigit(parte[0])){
      pilha.empilha(parte);
    }
    else {
      std::string op2 = pilha.ver_topo();
      pilha.desempilha();
      std::string op1 = pilha.ver_topo();
      pilha.desempilha();
      pilha.empilha("( " + op1 + " " + parte + " " + op2 + " )");
    }
  }

  return pilha.ver_topo();
}