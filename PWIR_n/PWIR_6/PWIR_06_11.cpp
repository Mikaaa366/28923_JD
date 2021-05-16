#include <cstdio>
#include <cstdint>
#include <cstdlib>
#include <chrono>
#include <assert.h>
#include <omp.h>
#include <iostream>



void oblicz(int n)
{
    long long a = 0, b = 1;
  
     for(int i=0;i<n;i++)
     {
            
            b += a; //pod zmienną b przypisujemy wyraz następny czyli a+b
            a = b-a; //pod zmienną a przypisujemy wartość zmiennej b
     } 
}
int main(int argc, char *argv[])
{
    long n = 10000000000;
    printf("Normal way: \n");
    auto start = std::chrono::high_resolution_clock::now();
    oblicz(n);;
    oblicz(n);
    auto end = std::chrono::high_resolution_clock::now();

    printf("Calculated normal way in %llu miliseconds\n",
    std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());

    printf("Parallel way: \n");
    start = std::chrono::high_resolution_clock::now();
    #pragma omp parallel sections
    {
        
        #pragma omp section
        { 
            oblicz(n);
            printf("Section 1, watek: %d\n", omp_get_thread_num());
            
        }
        #pragma omp section
        { 
            oblicz(n);
            printf("Section 2, watek: %d\n", omp_get_thread_num());
           
        }
        
        
    }
    end = std::chrono::high_resolution_clock::now();

    printf("Calculated parrallel way in %llu miliseconds\n",
    std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());
    printf("Koniec");
    return 0;
}