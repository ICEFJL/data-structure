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

void exchangeSort(int *Rand)
{
    for (int i = 0; i < N - 1; i++)
        for (int j = 0; j < N - 1 - i; j++)
            if (Rand[j] > Rand[j + 1])
                swap(Rand[j], Rand[j + 1]);
}

void selectSort(int *Rand)
{
    int min, k;

    for (int i = 0; i < N; i++) {
        min = Rand[i];
        k = i;
        for (int j = i + 1; j < N; j++)
            if (Rand[j] < min) {
                min = Rand[j];
                k = j;
            }

        if (i != k)
            swap(Rand[i], Rand[k]);
    }
}

void mergeSort(int *Rand, int *tmp, int l, int r)
{
    if (l >= r)
        return;
    int mid = (l + r) >> 1;
    mergeSort(Rand, tmp, l, mid);
    mergeSort(Rand, tmp, mid + 1, r);
    int i = l, j = mid + 1;
    int cnt = 0;
    while (i <= mid && j <= r)
        if (Rand[i] <= Rand[j])
            tmp[cnt++] = Rand[i++];
        else
            tmp[cnt++] = Rand[j++];

    while (i <= mid)
        tmp[cnt++] = Rand[i++];
    while (j <= r)
        tmp[cnt++] = Rand[j++];
    for (int i = 0; i < r - l + 1; ++i)
        Rand[i + l] = tmp[i];
}

int main()
{
    int *Rand = new int[N];
    int *tmp = new int[N];

    cout << "²âÊÔ½»»»ÅÅÐò" << endl;
    CreateRandom(Rand);
    exchangeSort(Rand);
    Display(Rand);
    cout << endl;

    cout << "²âÊÔÑ¡ÔñÅÅÐò" << endl;
    CreateRandom(Rand);
    selectSort(Rand);
    Display(Rand);
    cout << endl;

    cout << "²âÊÔ¹é²¢ÅÅÐò" << endl;
    CreateRandom(Rand);
    mergeSort(Rand, tmp, 0, N - 1);
    Display(Rand);
    cout << endl;

    return 0;
}