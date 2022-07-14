#include <iostream>


#include "windows.h"


using namespace std;

int Sticks[3][64];
int top[3] = { -1,-1,-1 };
int Size;
char ch[3] = { 'A', 'B', 'C' };

void Add_O(int index, int item)
{
    top[index]++;
    Sticks[index][top[index]] = item;
}

int Delete_O(int index)
{
    int item = Sticks[index][top[index]];
    top[index]--;
    return item;
}


void Print_O()
{
  
    for (int i = Size; i >= 0; i--) {
        for (int j = 0; j < 3; j++) {
            if (i <= top[j])
                cout << Sticks[j][i] << "  ";
            else
                cout << "   ";
        }
        cout << endl;
    }
    cout << "A  B  C \n\n";
}

void Move_O(int n, int source, int dest, int spare)
{

    if (n == 1) {
        Add_O(dest, Delete_O(source));
        Print_O();
        cout << "Перемещение с " << ch[source] << " на " << ch[dest] << " \n";
    }
    else {
        Move_O(n - 1, source, spare, dest);
        Move_O(1, source, dest, spare);
        Move_O(n - 1, spare, dest, source);
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Введите размер башни: ";
    cin >> Size;
    for (int i = 0; i < Size; i++) {
        Sticks[0][i] = Size - i;
    }
    top[0] = Size - 1;
    Print_O();
    Move_O(Size, 0, 2, 1);
    Print_O();
    system("pause");
    return 0;
}