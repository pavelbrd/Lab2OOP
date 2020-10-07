// Lab2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;

class Mass
{
    int* arr;
    int n;
public:
    Mass();
    ~Mass();
    void Max();
    void Min();
    void MaxMin();
    void WriteMass();
};

Mass::Mass() {
    srand(time(0));
    cout << "Вветите размер массива: ";
    cin >> n;
    arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = -100 + rand() % 201;
    }
}

Mass::~Mass() {
    delete[] arr;
}

void Mass::Max() {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) max = arr[i];
    }
    cout << "Максимальный элемент массива = " << max << endl;
}

void Mass::Min() {
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) min = arr[i];
    }
    cout << "Минимальный элемент массива = " << min << endl;
}

void Mass::WriteMass() {
    for (int i = 0; i < n; i++) {
        cout << setw(5) << arr[i];
    }
    cout << endl;
}

void Mass::MaxMin() {
    int imin, imax, min, max;
    min = arr[0];
    max = arr[0];
    imin = 0;
    imax = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
            imin = i;
        }
        if (arr[i] > max) {
            max = arr[i];
            imax = i;
        }
    }
    int b = arr[imin];
    arr[imin] = arr[imax];
    arr[imax] = b;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    Mass a1, a2;
    cout << "Первый массив:" << endl;
    a1.WriteMass();
    a1.Max();
    cout << "Второй массив:" << endl;
    a2.WriteMass();
    a2.Min();
    a1.MaxMin();
    a2.MaxMin();
    cout << "Замена минимального и максимального элементов"<< endl;
    cout << "Первый массив:" << endl;
    a1.WriteMass();
    cout << "Второй массив:" << endl;
    a2.WriteMass();
}