#include <iostream>
#include <cstdlib>
#include <ctime>

/*Задача 1
Даны два динамических массива A[n] и B[m].
Необходимо создать динамический массив C[n + m],
который состоит из элементов массивов A и B. После
создания массива C массивы A и B должны быть удалены.*/

template <typename T>
void show_arr(T arr[], const int length) {
    std::cout << '[';
    for (int i = 0; i < length; i++)
        std::cout << arr[i] << ", ";
    std::cout << "\b\b]\n";
}

template <typename T>
void rand_arr(T arr[], const int length, T a, T b) {
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        arr[i] = rand() % (b + 1 - a) + a;
    }
}

/*Задача 2
Создайте функцию resize_arr, которая принимает
динамический массив, текущую длину массива и новую
длину массива.
Переданный массив меняет свою изначальную длину на новую.
Вызов функции:
resize_arr(arr, 10, 15);*/

void resize_arr(int* arr, int length, int new_length) {
    int* newArr = new int[new_length];
    for (int i = 0; i < new_length; i++) {
        newArr[i] = arr[i];
    }
    delete[] arr;
}

int main() {
    setlocale(LC_ALL, "rus");

    //Задача 1
    int n, m;
    std::cout << "Введите длину массива А: ";
    std::cin >> n;
    int* d_A = new int[n];
    rand_arr(d_A, n, 0, 50);
    show_arr(d_A, n);

    std::cout << "Введите длину массива В: ";
    std::cin >> m;
    int* d_B = new int[m];
    rand_arr(d_B, m, 0, 50);
    show_arr(d_B, m);

    int* d_C = new int[n + m];
    for (int i = 0; i < n; i++)
        d_C[i] = d_A[i];
    for (int i = n; i < (n + m); i++)
        d_C[i] = d_B[i - n];

    std::cout << "Итоговый массив: ";
    show_arr(d_C, n + m);
    delete[] d_A;
    delete[] d_B;

    //Задача2

    int Size = 3;
    int* arr2 = new int[Size];
    for (int i = 0; i < Size; i++)
    {
        arr2[i] = 1;
    }

    int NewSize = 6;
    resize_arr(arr2, Size, NewSize);
    rand_arr(arr2, NewSize, 0, 50);
    std::cout << std::endl;
    for (int i = 0; i < NewSize; i++)
    {
        std::cout << arr2[i] << ',';
    }

    delete[] arr2;

    return 0;
}