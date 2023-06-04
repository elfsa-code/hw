
#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
void swap(typename std::vector<T>::iterator i, typename std::vector<T>::iterator j) {
    T temp = *i;
    *i = *j;
    *j = temp;
}

template<typename T>
typename std::vector<T>::iterator partition(typename std::vector<T>::iterator begin, typename std::vector<T>::iterator end) {
    auto pivot = *begin;
    auto i = begin+1, j = end-1;
    while ((i-begin) <= (j-begin)) {
        while ((i-begin) < (end-1-begin) && *i <= pivot) {
            i++;
        }
        while ((j-begin) > 0 && *j > pivot) {
            j--;
        }

        if ((i-begin) >= (j-begin)) {
            break;
        }
        swap<int>(i, j);
    }
    swap<int>(begin, j);
    return j;
}

template<typename T>
void quickSort(typename std::vector<T>::iterator begin, typename std::vector<T>::iterator end)
{
    if (end-1-begin <= 0) {
        return;
    }

    auto p = partition<int>(begin, end);

    quickSort<int>(begin, p);
    quickSort<int>(p + 1, end);
}

int main() {
    std::vector<int> v = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    quickSort<int>(v.begin(), v.end());
    for (auto i : v) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}


