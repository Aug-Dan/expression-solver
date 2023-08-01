#include "Expression.hpp"

Expression::Expression(){
  expressao_interna.setRaiz(nullptr);
}

void Expression::inserirExpressao(std::string expressao) {
  std::stringstream ss(expressao);
  std::string parte;
  Node_Stack pilha;

  while (ss >> parte) { // Lê cada item da expressão polonesa
    Node *novoNo = new Node(parte); // Cria um novo nó com o valor do item

    if (parte == "+" || parte == "-" || parte == "*" || parte == "/") { // Se o item lido for um operador
      Node *dir = pilha.desempilha(); // Desempilha o último nó da pilha e o define como filho direito
      Node *esq = pilha.desempilha(); // Desempilha o penúltimo nó da pilha e o define como filho esquerdo

      novoNo->setEsquerda(esq);
      novoNo->setDireita(dir);
    }
    pilha.empilha(novoNo); // Empilha o novo nó
  }
  
  Node *novaRaiz = pilha.desempilha();
  expressao_interna.setRaiz(novaRaiz); // A raiz da árvore será o último nó da pilha
}

double Expression::calcularResultado(Node* no) {
  // se o nó for nulo, retorna zero
  if (no == nullptr) {
    return 0.0;
  }

  // se o nó for uma folha, retorna o valor convertido para double
  if (no->getEsquerda() == nullptr && no->getDireita() == nullptr) {
    return std::stod(no->getItem());
  }

  // calcula o resultado dos filhos esquerdo e direito
  double esq = calcularResultado(no->getEsquerda());
  double dir = calcularResultado(no->getDireita());

  // realiza a operação correspondente ao operador do nó atual
  if (no->getItem() == "+") {
    return esq + dir;
  }
  else if (no->getItem() == "-") {
    return esq - dir;
  }
  else if (no->getItem() == "*") {
    return esq * dir;
  }
  else if (no->getItem() == "/") {
    return esq / dir;
  }
  else {
    // caso o nó não seja uma operação válida, retorna zero
    return 0.0;
  }
}

std::string Expression::PosOrdem(Node* raiz) {
  std::string expressao = "";
  if (raiz == nullptr) {
    return expressao;
  }

  expressao = expressao + PosOrdem(raiz->getEsquerda());  // percorre a subárvore esquerda
  expressao = expressao + PosOrdem(raiz->getDireita());   // percorre a subárvore direita
  expressao = expressao + raiz->getItem() + " ";           // processa o nó atual

  return expressao;
}
