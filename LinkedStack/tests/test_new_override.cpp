#include <cstdlib>
#include <new>
#include <stdexcept>

bool simulateAllocationFailure = false;

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
