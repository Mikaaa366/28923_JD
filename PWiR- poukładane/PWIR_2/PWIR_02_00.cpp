#include <cstdio>
#include <cstdint>
#include <chrono>
#include <iostream>

uint64_t value = 0;
int32_t i = 0;

int main(){
    auto start = std::chrono::high_resolution_clock::now();
	
	//#pragma omp parallel for shared(value) private(i)
	for (i = 0;i < INT32_MAX; i++){
		value += i;
	}
	
    auto end = std::chrono::high_resolution_clock::now();
    
    printf("Calculated %llu in %llu miliseconds\n",
    value,
    std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());

	getchar();
    return 0;
}

//Calculated 9223372030412324865 in 12041 miliseconds
//Calculated 9223372030412324865 in 12242 miliseconds