#ifndef NODE_H
#define NODE_H
#include <iostream>

class Node  {
  public:
    Node(std::string valor);
    std::string getItem();
    void setItem(std::string newItem);
    void setEsquerda(Node* node);
    void setDireita(Node* node);
    Node* getEsquerda() const;
    Node* getDireita() const;
    
  private:
    std::string item;
    Node *esq;
    Node *dir;
  
  friend class BinaryTree;
};

#endif