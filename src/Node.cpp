#include "Node.hpp"

Node::Node(std::string valor){
  item = valor;
  esq = nullptr;
  dir = nullptr;
}

std::string Node::getItem(){
  return item;
}

void Node::setItem(std::string newItem) {
  item = newItem;
}

void Node::setEsquerda(Node* node) {
  esq = node;
}

void Node::setDireita(Node* node) {
  dir = node;
}

Node* Node::getEsquerda() const {
    return esq;
}

Node* Node::getDireita() const {
    return dir;
}