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

void HeadAdjust(int *Rand, int k, int len)
{
    int temp = Rand[k];
    for (int i = 2 * k + 1; i <= len; i *= 2) {
        if (i < len && Rand[i] < Rand[i + 1])
            i++;
        if (temp >= Rand[i])
            break;
        Rand[k] = Rand[i];
        k = i;
    }
    Rand[k] = temp;
}

void HeapSort(int *Rand)
{
    for (int i = N / 2; i >= 0; i--)
        HeadAdjust(Rand, i, N - 1);
    for (int i = N - 1; i > 0; i--) {
        swap(Rand[i], Rand[0]);
        HeadAdjust(Rand, 0, i - 1);
    }
}

int main()
{
    int *Rand = new int[N];
    srand((int)time(0));
    cout << "²âÊÔ¶ÑÅÅĞò" << endl << endl;
    CreateRandom(Rand);
    HeapSort(Rand);
    Display(Rand);

    return 0;
}
