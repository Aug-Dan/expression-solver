#include "Stack.hpp"
#include <sstream>

Stack::Stack() : m_topo(-1) {}

Stack::~Stack() {}

void Stack::empilha(std::string valor) {
  if (m_topo == Max_tamanho - 1) {
      std::cout << "Pilha cheia!\n";
  }
  m_topo++;
  m_dados[m_topo] = valor;
}

std::string Stack::desempilha() {
  if (vazia()) {
    std::cout << "Pilha Vazia!\n";
  }
  std::string valor = m_dados[m_topo];
  m_topo--;
  return valor;
}

void Stack::limpa() {
  m_topo = -1;
}

bool Stack::vazia() const {
  return m_topo == -1;
}

std::string Stack::ver_topo() const {
  if (vazia()) {
    std::cout << "Pilha Vazia!\n";
  }
  return m_dados[m_topo];
}

int Stack::get_tamanho() const {
  return m_topo + 1;
}




