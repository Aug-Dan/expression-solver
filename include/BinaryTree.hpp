#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "Node.hpp"
#include <iostream>

class BinaryTree{
  public:
    BinaryTree();
    ~BinaryTree();
    Node* getRaiz() const;
    void setRaiz(Node* novaRaiz);
    void Limpa();
    void ImprimeNo(Node* p, const std::string& prefix, bool ehEsquerda);
    void ImprimeArvore();

  private:
    void ApagaRecursivo(Node* p);
    Node* raiz;
};

#endif