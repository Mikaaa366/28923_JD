#include <cstdio>
#include <cstdint>
#include <cstdlib>
#include <chrono>
#include <assert.h>
#include <windows.h>
#include <omp.h>

void wait(int x){
    Sleep(x);
}

int main(){
    uint32_t i;
    uint32_t n = 10;
    auto start = std::chrono::high_resolution_clock::now();
    #pragma omp parallel num_threads(2) default(none) shared(n)
    {
        #pragma omp sections nowait
        {
            #pragma omp section
            {
                printf("Sections - Thread %d working...\n", omp_get_thread_num());
                wait(2000);
            }

            #pragma omp section
            {
                printf("Sections - Thread %d working ...\n", omp_get_thread_num());
                wait(4000);
            }
        }

        #pragma omp for schedule(dynamic) private(i)
        for (i = 0; i < n; i++) {
            printf("Iteration %d execute thread %d.\n", i, omp_get_thread_num());
            wait(400);
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    printf("Parallel normal way %llu ms\r\n",
    std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());

    return 0;
}