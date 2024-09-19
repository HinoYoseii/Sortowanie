#include <cstdlib>
#include <sys/time.h>
#include <iostream>
#include "algorytmy.hpp"
using namespace std;

void czytaj_plik(FILE* plik, int* tab, int n) {
    for (int i = 0; i < n; i++)
        fscanf(plik, "%d", &tab[i]);
}

void wyswietl_tablice(int* tab, int n) {
    for (int i = 0; i < n; i++)
        cout << tab[i] << " ";
    cout << "\n";
}

void zapisz_plik(FILE* plik, int* tab, int n) {
    for (int i = 0; i < n; i++)
        fprintf(plik, "%d ", tab[i]);
}

int main() {
    FILE* dane;
    timeval start, end;
    int n, op = 1;
    long seconds, microseconds;
    double elapsed;

    cout << "Podaj liczbe elementow w tablicy \n";
    cout << "n = ";
    cin >> n;
    int tab[n];

    if (!(dane = fopen("dane", "r"))) {
        cout << "Nie mozna otworzyc pliku\n";
        return 0;
    }

    while (1) {
        cout << "Wybierz opcje\n";
        cout << "1. Sortowanie przez wstawianie\n";
        cout << "2. Sortowanie przez selekcje\n";
        cout << "3. Sortowanie babelkowe\n";
        cout << "4. Quicksort\n";
        cout << "5. Sortowanie Shella\n";
        cout << "6. Sortowanie przez kopcowanie\n";
        cout << "7. Zakoncz program\n";
        cin >> op;

        if (op == 7) {
            FILE* wynik = fopen("wynik", "w");
            zapisz_plik(wynik, tab, n);
            fclose(dane);
            fclose(wynik);
            return 0;
        }

        else if (op <= 6 && op >= 1) {
            fseek(dane, 0, SEEK_SET);
            czytaj_plik(dane, tab, n);

            cout << "\nTablica przed sorotwaniem: ";
            wyswietl_tablice(tab, n);

            switch (op) {
            case 1:
                gettimeofday(&start, NULL);
                insert_sort(tab, n);
                gettimeofday(&end, NULL);
                break;
            case 2:
                gettimeofday(&start, NULL);
                selection_sort(tab, n);
                gettimeofday(&end, NULL);
                break;
            case 3:
                gettimeofday(&start, NULL);
                bubble_sort(tab, n);
                gettimeofday(&end, NULL);
                break;
            case 4:
                gettimeofday(&start, NULL);
                quick_sort(tab, 0, n - 1);
                gettimeofday(&end, NULL);
                break;
            case 5:
                gettimeofday(&start, NULL);
                shell_sort(tab, n);
                gettimeofday(&end, NULL);
                break;
            case 6:
                gettimeofday(&start, NULL);
                heap_sort(tab, n);
                gettimeofday(&end, NULL);
            }

            seconds = end.tv_sec - start.tv_sec;
            microseconds = end.tv_usec - start.tv_usec;
            elapsed = seconds + microseconds * 1e-6;

            cout << "Tablica po sortowaniu:     ";
            wyswietl_tablice(tab, n);
            cout << "Czas sortowania = " << elapsed << " s\n\n";
        }

        else
            cout << "Wybrana opcja nie istnieje\n\n";
    }

}
