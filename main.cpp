#include <iostream>
#include <windows.h>
#include"MatrixMath.cpp"
#include "MatrixPrint.cpp"
using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    //srand(time(nullptr));
    int n=0;
    cout<<"Введите размерность матриц А, В и С"<<endl;
    cin>>n;
    //создание матриц
    int **Amatrix = new int *[n];
    for (int i=0;i<n;i++)Amatrix[i] = new int [n];

    int **Bmatrix = new int *[n];
    for (int i=0;i<n;i++)Bmatrix[i] = new int [n];

    int **Cmatrix = new int *[n];
    for (int i=0;i<n;i++)Cmatrix[i] = new int [n];

    Bmatrix = FillMatrixRand(Bmatrix,n);
    Cmatrix = FillMatrixRand(Cmatrix,n);

    cout<< "Матрица С:"<< endl;
    PrintMatrix(Cmatrix,n);
    cout<<endl<<"Матрица B:"<< endl;
    PrintMatrix(Bmatrix,n);
    cout<<endl;
    cout<<"Сумма всех элементов матрицы С равна "<<GetSumElemMatrix(Cmatrix,n)<<endl;
    cout<<"Колличество нечетных элементов в этой матрице равно "<<GetCountNechetElemsMatrix(Cmatrix,n)<<endl;
    cout<<"минимальное простое число расположенное на главной диагонали равно "<<GetMinElemOnMainDiag(Cmatrix,n)<<" (если это число равно нулю, то его нет)"<<endl;
    Amatrix = MultMatrix(DiffMatrix(Bmatrix,Cmatrix,n), TranspMatrix(Cmatrix,n),n);
    cout<<"матрица А = (В-С)*С(транспонированное) :"<<endl;
    PrintMatrix(Amatrix,n);
    return 0;
}
