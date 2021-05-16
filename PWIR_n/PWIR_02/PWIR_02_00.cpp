#include <cstdio>
#include <cstdint>
#include <chrono>

uint64_t value = 0;

int main(){
    auto start = std::chrono::high_resolution_clock::now();

    for (uint32_t i = 0;i < UINT32_MAX; i++){
        value += i;
    }

    auto end = std::chrono::high_resolution_clock::now();
    
    printf("Calculated %llu in %llu miliseconds\n",
    value,
    std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());

    return 0;
}