#include "BinaryTree.hpp"

BinaryTree::BinaryTree(){
  raiz = nullptr;
}

BinaryTree::~BinaryTree(){
  Limpa();
}

Node* BinaryTree::getRaiz() const {
  return raiz;
}

void BinaryTree::setRaiz(Node* novaRaiz) {
  raiz = novaRaiz;
}

void BinaryTree::Limpa(){
  ApagaRecursivo(raiz);
  raiz = nullptr;
}

void BinaryTree::ApagaRecursivo(Node *p){
  if(p!=nullptr){
    ApagaRecursivo(p->esq);
    ApagaRecursivo(p->dir);
    delete p;
  }
}

//Métodos de imprimir árvore

void BinaryTree::ImprimeNo(Node* p, const std::string& prefix, bool ehEsquerda) {
    if (p == nullptr) {
      return;
    }
    std::cout << prefix;
    std::cout << (ehEsquerda? "├──" : "└──");
    std::cout << p->item << std::endl;
    ImprimeNo(p->esq, prefix + (ehEsquerda ? "│   " : "    "), true);
    ImprimeNo(p->dir, prefix + (ehEsquerda ? "│   " : "    "), false);
}

void BinaryTree::ImprimeArvore() {
    ImprimeNo(this->raiz, "", false);
}