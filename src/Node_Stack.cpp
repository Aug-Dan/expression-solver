#include "Node_Stack.hpp"
#include <iostream>

Node_Stack::Node_Stack() : m_topo(-1) {}

Node_Stack::~Node_Stack() {}

void Node_Stack::empilha(Node* valor) {
    if (m_topo == Max_tamanho - 1) {
        std::cout << "Pilha cheia!\n";
        return;
    }
    m_topo++;
    m_dados[m_topo] = valor;
}

Node* Node_Stack::desempilha() {
    if (vazia()) {
        std::cout << "Pilha vazia!\n";
        return nullptr;
    }
    Node* valor = m_dados[m_topo];
    m_topo--;
    return valor;
}

void Node_Stack::limpa() {
    m_topo = -1;
}

bool Node_Stack::vazia() const {
    return m_topo == -1;
}

Node* Node_Stack::ver_topo() const {
    if (vazia()) {
        std::cout << "Pilha vazia!\n";
        return nullptr;
    }
    return m_dados[m_topo];
}

int Node_Stack::get_tamanho() const {
    return m_topo + 1;
}