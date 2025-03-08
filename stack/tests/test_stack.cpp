#include "stack.hpp"
#include <cassert>
#include <iostream>

using namespace std;

void testStack() {
    cout << "Iniciando testes com assert...\n";

    // Teste 1: Verificar se a pilha está vazia após a criação.
    Stack s;
    assert(s.isEmpty());
    cout << "Teste 1 passou: A pilha está vazia após a criação.\n";

    // Teste 2: Após inserir um elemento, a pilha não deve estar vazia.
    s.push(10);
    assert(!s.isEmpty());
    cout << "Teste 2 passou: A pilha não está vazia após o push.\n";

    // Teste 3: O valor retornado pelo pop deve ser o esperado.
    int valor = s.pop();
    assert(valor == 10);
    cout << "Teste 3 passou: pop() retornou 10.\n";

    // Teste 4: Remover de uma pilha vazia deve lançar exceção.
    bool exceptionCaught = false;
    try {
        s.pop();
    } catch (const char* msg) {
        exceptionCaught = true;
    }
    assert(exceptionCaught);
    cout << "Teste 4 passou: pop() lançou exceção ao tentar remover de uma pilha vazia.\n";

    // Teste 5: Preencher a pilha até o limite e verificar se está cheia.
    Stack s2;
    for (int i = 0; i < MAX_SIZE; i++) {
        s2.push(i);
    }
    assert(s2.isFull());
    cout << "Teste 5 passou: A pilha está cheia após inserir " << MAX_SIZE << " elementos.\n";

    // Teste 6: Tentar inserir um elemento em uma pilha cheia deve lançar exceção.
    exceptionCaught = false;
    try {
        s2.push(999);
    } catch (const char* msg) {
        exceptionCaught = true;
    }
    assert(exceptionCaught);
    cout << "Teste 6 passou: push() lançou exceção ao tentar inserir em pilha cheia.\n";

    cout << "\nTodos os testes passaram com sucesso!\n";
}

int main() {
    testStack();
    return 0;
}
