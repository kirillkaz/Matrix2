#include <iostream>
#include "MatrixMath.h"
using namespace std;

///заполняет квадратную матрицу рандомными числами
int** FillMatrixRand(int **Matrix, int size){
    for (int i=0;i < size;i++){
        for(int j=0;j < size;j++) Matrix[i][j] = rand()%100-50;
    }
    return Matrix;
}

///возвращает сумму всех элементов матрицы
int GetSumElemMatrix(int **Matrix, int size){
    int sum=0;
    for (int i=0;i < size;i++)
        for(int j=0;j < size;j++) sum+=Matrix[i][j];
    return sum;
}

///возвращает количество нечетных элементов в матрице
int GetCountNechetElemsMatrix(int **Matrix, int size){
    int nechet=0;
    for (int i=0;i < size;i++)
        for(int j=0;j < size;j++) if((Matrix[i][j] % 2) == 0) nechet+=1;
    return nechet;
}

///возвращает минимальный простой элемент главной диагонали
int GetMinElemOnMainDiag(int **Matrix, int size){
    int min=0;
    bool IsSimple = true;
    for (int i=0;i < size;i++){
        IsSimple = true;
        for (int j=2;j<Matrix[i][i]/2;j++) if ((Matrix[i][i] % j) == 0) IsSimple = false;
        if (IsSimple && ((min == 0) || (Matrix[i][i]<min))) min = Matrix[i][i];
    }
    return min;
}

/**
 * DiffMatrix вычитает из одной матрицы другую
 * @param MatrixA Матрица, из которой вычитаем
 * @param MatrixB Матрица, которую вычитаем
 * @param size размер матриц (size x size)
 * @return ResultMatrix - матрица разности двух матриц
 */
int** DiffMatrix(int **MatrixA,int **MatrixB,int size){
    int **ResultMatrix = new int *[size];
    for (int i=0;i<size;i++) ResultMatrix[i] = new int [size];

    for (int i=0;i<size;i++)
        for (int j=0;j<size;j++) ResultMatrix[i][j] = MatrixA[i][j] - MatrixB[i][j];
    return ResultMatrix;
}
///транспонирует данную матрицу
int** TranspMatrix(int **Matrix,int size){
    int **Tmatrix = new int *[size];
    for (int i=0;i<size;i++) Tmatrix[i] = new int [size];

    for (int i=0;i<size;i++)
        for (int j=0;j<size;j++) Tmatrix[j][i] = Matrix[i][j];

    return Tmatrix;
}

/**
 * MultMatrix Возвращает матрицу произведения матрицы А с матрицей В (матрицы A и B квадратные)
 * @param MatrixA первый множитель
 * @param MatrixB второй множитель
 * @return ResultMatrix - матрица произведения двух матриц
 */
int** MultMatrix(int** MatrixA, int** MatrixB, int size){
    int **ResultMatrix = new int *[size];
    for (int i=0;i < size;i++) ResultMatrix[i] = new int [size];

    for (int i=0;i< size;i++)
        for(int j=0;j<size;j++){
            int sum=0;
            for (int r=0;r< size;r++) sum = sum+MatrixA[i][r]*MatrixB[r][j];
            ResultMatrix[i][j]=sum;
        }
    return ResultMatrix;
}
