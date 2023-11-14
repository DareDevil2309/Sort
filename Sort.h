#include <iostream>

template<typename T, typename Compare>
void insertionSort(T* arr, int n, Compare comp) {
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0; j--) {
            if (comp(arr[j], arr[j - 1])) {
                std::swap(arr[j], arr[j - 1]);
            }
        }
    }
}

template<typename T, typename Compare>
T* partition(T* first, T* last, Compare comp) {
    T pivot = *first;
    T* i = first - 1;
    T* j = last + 1;

    while (true) {
        do {
            ++i;
        } while (comp(*i, pivot));

        do {
            --j;
        } while (comp(pivot, *j));

        if (i >= j) {
            return j;
        }

        std::swap(*i, *j);
    }
}

template<typename T, typename Compare>
void quickSort(T* first, T* last, Compare comp) {
    if (first >= last)
        return;

    T* pivot = partition(first, last, comp);
    quickSort(first, pivot, comp);
    quickSort(pivot + 1, last, comp);
}

template<typename T, typename Compare>
void sort(T* first, T* last, Compare comp)
{
    if (last <= first) {
        return;
    }

    int count = last - first + 1;
    
    if (count <= 50) {
        insertionSort(first, count, comp);
    }
    else {
        quickSort(first, last, comp);
    }
}

template<typename T>
bool comp(const T& a, const T& b) {
    
}