#include "algorytmy.hpp"
#include <algorithm>

using namespace std;

void insert_sort(int* tab, int n) {
    int i, x, j;

    for (i = 1; i < n; i++) {
        x = tab[i];
        j = i - 1;
        while (tab[j] > x && j >= 0) {
            tab[j + 1] = tab[j];
            j--;
        }
        tab[j + 1] = x;
    }
}


void selection_sort(int* tab, int n) {
    int i, j, index, temp;

    for (i = 0; i < n - 1; i++) {
        index = i;

        for (j = i + 1; j < n; j++) {
            if (tab[j] < tab[index])
                index = j;
        }
        if (index != i) {
            temp = tab[index];
            tab[index] = tab[i];
            tab[i] = temp;
        }
    }
}

void bubble_sort(int* tab, int n) {
    int i, j, temp, flag = 1;

    for (i = 0; i < n - 1 && flag; i++) {
        flag = 0;
        for (j = n - 2; j >= i; j--) {
            if (tab[j] > tab[j + 1]) {
                temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
                flag = 1;
            }
        }
    }
}


void quick_sort(int* tab, int left, int right) {
    if (right <= left) return;

    int i, j, middle, temp;

    i = left - 1;
    j = right + 1;
    middle = tab[(left + right) / 2];

    while (1) {
        while (middle > tab[++i]);
        while (middle < tab[--j]);

        if (i <= j) {
            //swap(tab[i], tab[j]);
            temp = tab[i];
            tab[i] = tab[j];
            tab[j] = temp;
        }
        else
            break;

    }

    if (i > left)
        quick_sort(tab, left, j);
    if (i < right)
        quick_sort(tab, i, right);

}

void shell_sort(int* tab, int n) {
    int gap, i, j, temp;

    for (gap = n / 2; gap > 0; gap /= 2) {
        for (i = gap; i < n; i++) {
            temp = tab[i];

            for (j = i; j >= gap && tab[j - gap] > temp; j -= gap)
                tab[j] = tab[j - gap];
            tab[j] = temp;
        }
    }
}

void heapify(int* tab, int n, int i) {
    int largest, left, right, temp;
    largest = i;
    left = 2 * i + 1;
    right = 2 * i + 2;

    if (left < n && tab[left] > tab[largest])
        largest = left;

    if (right < n && tab[right] > tab[largest])
        largest = right;

    if (largest != i) {
        temp = tab[i];
        tab[i] = tab[largest];
        tab[largest] = temp;
        heapify(tab, n, largest);
    }
}

void heap_sort(int* tab, int n) {
    int i, temp;
    for (i = n / 2 - 1; i >= 0; i--)
        heapify(tab, n, i);

    for (int i = n - 1; i > 0; i--) {
        temp = tab[0];
        tab[0] = tab[i];
        tab[i] = temp;
        heapify(tab, i, 0);
    }
}