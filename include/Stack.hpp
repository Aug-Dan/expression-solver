#ifndef STACK_H
#define STACK_H

#include <iostream>

class Stack{
public:
  Stack();
  ~Stack();

  void empilha(std::string valor);
  std::string desempilha();
  void limpa();
  bool vazia() const;
  std::string ver_topo() const;
  int get_tamanho() const;

private:
  static const int Max_tamanho = 100;
  std::string m_dados[Max_tamanho];
  int m_topo;
};

#endif