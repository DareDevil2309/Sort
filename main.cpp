#include "Sort.h"
#include <random>
#include <chrono>
#include <fstream>

int main() {
    std::random_device r;
    std::default_random_engine e(r());
    std::uniform_int_distribution<int> uniform_dist(0, 100);

    std::ofstream output;

    output.open("Test.txt");

    if (output.is_open()) {
        for (int n = 10; n <= 10000; n += 10) {
            int* insArr = static_cast<int*>(malloc(n * sizeof(int)));
            int* quickArr = static_cast<int*>(malloc(n * sizeof(int)));

            for (int i = 0; i < n; i++) {
                new(&insArr[i]) int(n - i);
            }

            for (int i = 0; i < n; i++) {
                new(&quickArr[i]) int(n - i);
            }

            auto start = std::chrono::high_resolution_clock::now();
            insertionSort(insArr, n, [](int a, int b) { return a < b; });
            auto stop = std::chrono::high_resolution_clock::now();
            auto insDuration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
            start = std::chrono::high_resolution_clock::now();
            quickSort(quickArr, &quickArr[n - 1], [](int a, int b) {return a < b; });
            stop = std::chrono::high_resolution_clock::now();
            auto quickDuration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
            output << n << " " << insDuration.count() << " " << quickDuration.count() << std::endl;

            free(insArr);
            free(quickArr);
        }
    }
}