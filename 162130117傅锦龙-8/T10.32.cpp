#include <iostream>
using namespace std;
#define N 20

enum { RED, WHITE, BLUE } color;
void sort(int *color)
{
    int l = 0, j = 0, r = N - 1;
    while (j <= r) {
        switch (color[j]) {
            case RED:
                swap(color[l++], color[j++]);
                break;
            case WHITE:
                j++;
                break;
            case BLUE:
                swap(color[r--], color[j]);
                break;
        }
    }
}
int main()
{
    int *color = new int[N];
    for (int i = 0; i < N; i++) {
        color[i] = rand() % 3;
        cout << color[i] << " ";
    }
    cout << endl;
    sort(color);
    for (int i = 0; i < N; i++){
        cout << color[i] << " ";
    }
}