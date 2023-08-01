#ifndef NODE_STACK_H
#define NODE_STACK_H

#include "Node.hpp"

class Node_Stack {
public:
  Node_Stack();
  ~Node_Stack();

  void empilha(Node* valor);
  Node* desempilha();
  void limpa();
  bool vazia() const;
  Node* ver_topo() const;
  int get_tamanho() const;

private:
  static const int Max_tamanho = 100;
  Node* m_dados[Max_tamanho];
  int m_topo;
};

#endif