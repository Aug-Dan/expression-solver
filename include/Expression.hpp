#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "BinaryTree.hpp"
#include "Stack.hpp"
#include "Node_Stack.hpp"
#include <iostream>
#include <sstream>


class Expression{
  public:
    Expression();
    void inserirExpressao(std::string expressao);
    double calcularResultado(Node* no);
    std::string PosOrdem(Node* raiz);

    BinaryTree expressao_interna;
};

#endif