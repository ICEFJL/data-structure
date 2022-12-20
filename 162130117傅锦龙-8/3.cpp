#include <iostream>
using namespace std;
#define N 10

void Display(int *Rand)
{
    for (int i = 0; i < N; i++) {
        cout << Rand[i] << ' ';
    }
    cout << endl;
}

void CreateRandom(int *Rand)
{
    for (int i = 0; i < N; i++) {
        Rand[i] = rand() % 100;
    }
    Display(Rand);
}

int Paritition(int *Rand, int l, int r)
{
    int temp = Rand[l];

    while (l < r) {
        while (l < r && Rand[r] >= temp)
            r--;
        Rand[l] = Rand[r];

        while (l < r && Rand[l] <= temp)
            l++;
        Rand[r] = Rand[l];
    }
    Rand[l] = temp;
    return l;
}

void QuickSort(int *Rand, int l, int r)
{
    if (l < r) {
        int temp = Paritition(Rand, l, r);
        QuickSort(Rand, l, temp - 1);
        QuickSort(Rand, temp + 1, r);
    }
}

int main()
{
    int *Rand = new int[N];
    srand((int)time(0));
    cout << "²âÊÔ¿ìËÙÅÅÐò" << endl << endl;
    CreateRandom(Rand);
    QuickSort(Rand, 0, N - 1);
    Display(Rand);
    cout << endl;

    return 0;
}