#include <iostream>
#include <time.h>
#include <Windows.h>
#include <iomanip>

using namespace std;

//ІТЕРАЦІЙНИЙ СПОСІБ
void coutT_i(int** a, const int row, const int coll, const int low, const int high);
void print_i(int** a, const int row, const int col);
int kilkist_i(int** a, const int row, const int col, int k);
int suma_i(int** a, const int row, const int col, int S);
void zamina_i(int** a, const int row, const int col);
void sort_i(int** a, const int row, const int col);
void change(int** a, const int row0, const int row1, const int col);
//РЕКУРСИВНИЙ СПОСІБ
void coutT_r(int** a, const int row, const int col, const int low, const int high, int i, int j);
void print_r(int** a, const int row, const int col, int i, int j);
void sort_r(int** a, const int row, const int col, int i, int j);
int kilkist_r(int** a, const int row, const int col, int i, int j, int k);
void zamina_r(int** a, const int row, const int col, int i, int j);
int suma_r(int** a, const int row, const int col, int i, int j, int S);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    srand((unsigned)time(NULL));

    int low = -42;
    int high = 51;

    int row = 7;
    int col = 6;
    int** a = new int* [row];
    for (int i = 0; i < row; i++)
        a[i] = new int[col];
                        //ІТЕРАЦІЙНИЙ СПОСІБ//
    cout << setw(22) << "===>ІТЕРАЦІЙНИЙ СПОСІБ<===" << endl; cout << endl;
    cout << setw(21) << "Початкова матриця" << endl; 
    coutT_i(a, row, col, low, high);
    print_i(a, row, col); cout << endl;
    cout << setw(23) << "Впорядкована матриця" << endl;
    sort_i(a, row, col);
    print_i(a, row, col); cout << endl;
    cout << "Кількість елементів, які задовільняють умову(всі крім додатних кратних 5): ";
    cout << kilkist_i(a, row, col, 0) << endl; cout << endl;
    cout << "Сума цих елементів: " << suma_i(a, row, col, 0) << endl; cout << endl;
    cout << setw(23) << "Модифікована матриця" << endl; cout << endl;
    zamina_i(a, row, col); cout << endl;
   
                         //РЕКУРСИВНИЙ СПОСІБ//
    cout << setw(22) << "===>РЕКУРСИВНИЙ СПОСІБ<===" << endl; cout << endl;
    cout << setw(21) << "Початкова матриця" << endl;
    coutT_r(a, row, col, low, high, 0, 0); cout << endl;
    print_r(a, row, col, 0, 0); cout << endl;
    cout << setw(23) << "Впорядкована матриця" << endl; cout << endl;
    print_r(a, row, col, 0, 0); cout << endl;
    cout << "\nКількість елементів, які задовільняють умову(всі крім додатних кратних 5): ";
    cout << kilkist_r(a, row, col, 0, 0, 0) << endl; cout << endl;
    cout << "Сума цих елементів: " << suma_r(a, row, col, 0, 0, 0) << endl; cout << endl;
    cout << setw(23) << "Модифікована матриця" << endl; cout << endl;
    zamina_r(a, row, col, 0, 0); cout << endl; cout << endl;
   
    
    for (int i = 0; i < row; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

//ІТЕРАЦІЙНИЙ СПОСІБ

void coutT_i(int** a, const int row, const int col, const int low, const int high)
{
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            a[i][j] = low + rand() % (high - low + 1);
}
void print_i(int** a, const int row, const int col)
{
    cout << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}
int kilkist_i(int** a, const int row, const int col, int k)
{
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            if (!((a[i][j] > 0) && (a[i][j] % 5 == 0)))
                k++;
    return k;
}
int suma_i(int** a, const int row, const int col, int S)
{
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            if (!((a[i][j] > 0) && (a[i][j] % 5 == 0)))
                S += a[i][j];
    return S;
}
void zamina_i(int** a, const int row, const int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            if (!((a[i][j] > 0) && (a[i][j] % 5 == 0)))
            {
                a[i][j] = 0;
                cout << setw(4) << a[i][j];
            }
            else
                cout << setw(4) << a[i][j];
        cout << endl;
    }
}
void sort_i(int** a, const int row, const int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < row - 1; j++)
            if ((a[j][0] > a[j + 1][0])
                ||
                (a[j][0] == a[j + 1][0] &&
                    a[j][1] < a[j + 1][1])
                ||
                (a[j][0] == a[j + 1][0] &&
                    a[j][1] == a[j + 1][1] &&
                    a[j][2] > a[j + 1][2]))
                change(a, j, j + 1, col);
    }
}
void change(int** a, const int row0, const int row1, const int col)
{
    int temp;
    for (int k = 0; k < col; k++)
    {
        temp = a[row0][k];
        a[row0][k] = a[row1][k];
        a[row1][k] = temp;
    }
}

//РЕКУРСИВНИЙ СПОСІБ

void coutT_r(int** a, const int row, const int col, const int low, const int high, int i, int j)
{
    if (j < col)
    {
        a[i][j] = low + rand() % (high - low + 1);
        return coutT_r(a, row, col, low, high, i, j + 1);
    }
    if (i < row - 1)
        return coutT_r(a, row, col, low, high, i + 1, 0);
}
void print_r(int** a, const int row, const int col, int i, int j)
{
    if (j < col)
    {
        cout << setw(4) << a[i][j];
        return print_r(a, row, col, i, j + 1);
    }
    cout << endl;
    if (i < row - 1)
        return print_r(a, row, col, i + 1, 0);
}
int kilkist_r(int** a, const int row, const int col, int i, int j, int k)
{
    if (j < col)
        if (!((a[i][j] > 0) && (a[i][j] % 5 == 0)))
        {
            k++;
            return kilkist_r(a, row, col, i, j + 1, k);
        }
        else
            return kilkist_r(a, row, col, i, j + 1, k);
    if (i < row - 1)
        return kilkist_r(a, row, col, i + 1, 0, k);
    return k;      
}
void zamina_r(int** a, const int row, const int col, int i, int j)
{
    if (j < col)
    {
        if (!((a[i][j] > 0) && (a[i][j] % 5 == 0)))
            cout << setw(4) << 0;
        else
            cout << setw(4) << a[i][j];
        return zamina_r(a, row, col, i, j + 1);
    }
    if (i < row - 1)
    {
        cout << endl;
        return zamina_r(a, row, col, i + 1, 0);
    }
}
int suma_r(int** a, const int row, const int col, int i, int j, int S)
{
    if (j < col)
        if (!((a[i][j] > 0) && (a[i][j] % 5 == 0)))
        {
            S += a[i][j];
            return suma_r(a, row, col, i, j + 1, S);
        }
        else
            return suma_r(a, row, col, i, j + 1, S);
    if (i < row - 1)
        return suma_r(a, row, col, i + 1, 0, S);
    return S;
}
void sort_r(int** a, const int row, const int col, int i, int j)
{
    if (j < col)
    {
        if ((a[j][0] > a[j + 1][0])
            ||
            (a[j][0] == a[j + 1][0] &&
                a[j][1] < a[j + 1][1])
            ||
            (a[j][0] == a[j + 1][0] &&
                a[j][1] == a[j + 1][1] &&
                a[j][2] > a[j + 1][2]))
            change(a, j, j + 1, col);
        return sort_r(a, row, col, i, j + 1);
    }
    if (i < row - 1)
        return sort_r(a, row, col, i + 1, 0);
}
