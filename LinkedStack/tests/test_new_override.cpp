#include <cstdlib>
#include <new>
#include <stdexcept>

// Flag para simular a falha de alocação.
bool simulateAllocationFailure = false;

// Redefinição global do operador new para o escopo do teste.
void* operator new(std::size_t size) {
    if (simulateAllocationFailure) {
        throw std::bad_alloc();
    }
    void* ptr = std::malloc(size);
    if (!ptr) {
        throw std::bad_alloc();
    }
    return ptr;
}

void operator delete(void* ptr) noexcept {
    std::free(ptr);
}
