#include <iostream>
#include <windows.h>
#include"MatrixMath.h"
#include "MatrixFilePrint.h"
#include "MatrixConsolePrint.h"
#include <gtest/gtest.h>
using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    srand(time(nullptr));
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
    PrintFileMatrix(Cmatrix,n);
    cout<<endl<<"Матрица B:"<< endl;
    PrintFileMatrix(Bmatrix,n);
    cout<<endl;
    cout<<"Сумма всех элементов матрицы С равна "<<GetSumElemMatrix(Cmatrix,n)<<endl;
    cout<<"Колличество нечетных элементов в этой матрице равно "<<GetCountNechetElemsMatrix(Cmatrix,n)<<endl;
    cout<<"минимальное простое число расположенное на главной диагонали равно "<<GetMinElemOnMainDiag(Cmatrix,n)<<" (если это число равно нулю, то его нет)"<<endl;
    Amatrix = MultMatrix(DiffMatrix(Bmatrix,Cmatrix,n), TranspMatrix(Cmatrix,n),n);
    cout<<"матрица А = (В-С)*С(транспонированное) :"<<endl;
    PrintFileMatrix(Amatrix,n);

    RUN_ALL_TESTS();
    return 0;
}

TEST(MatrixMathTest, GetSumElemMatrix){
    int **TestMatrix = new int *[5];
    for (int i=0;i<5;i++)TestMatrix[i] = new int [5];
    //test1
    for (int i=0;i<5;i++) for (int j=0;j<5;j++) TestMatrix[i][j] = j;
    EXPECT_EQ(GetSumElemMatrix(TestMatrix,5),50);
    //test2
    for (int i=0;i<5;i++) for (int j=0;j<5;j++) TestMatrix[i][j] = 0;
    EXPECT_EQ(GetSumElemMatrix(TestMatrix,5),0);
    //test3
    for (int i=0;i<5;i++) for (int j=0;j<5;j++) TestMatrix[i][j] = 1;
    EXPECT_EQ(GetSumElemMatrix(TestMatrix,5),25);
}

TEST(MatrixMathTest, GetCountNechetElemsMatrix){
    int **TestMatrix = new int *[5];
    for (int i=0;i<5;i++)TestMatrix[i] = new int [5];
    //test1
    for (int i=0;i<5;i++) for (int j=0;j<5;j++) TestMatrix[i][j] = j;
    EXPECT_EQ(GetCountNechetElemsMatrix(TestMatrix,5),10);
    //test2
    for (int i=0;i<5;i++) for (int j=0;j<5;j++) TestMatrix[i][j] = 0;
    EXPECT_EQ(GetCountNechetElemsMatrix(TestMatrix,5),0);
    //test3
    for (int i=0;i<5;i++) for (int j=0;j<5;j++) TestMatrix[i][j] = 1;
    EXPECT_EQ(GetCountNechetElemsMatrix(TestMatrix,5),25);
}

TEST(MatrixMathTest, GetMinElemOnMainDiag){
    int **TestMatrix = new int *[5];
    for (int i=0;i<5;i++)TestMatrix[i] = new int [5];
    //test1
    for (int i=0;i<5;i++) for (int j=0;j<5;j++) TestMatrix[i][j] = j;
    EXPECT_EQ(GetMinElemOnMainDiag(TestMatrix,5),1);
    //test2
    for (int i=0;i<5;i++) for (int j=0;j<5;j++) TestMatrix[i][j] = -1;
    EXPECT_EQ(GetMinElemOnMainDiag(TestMatrix,5),-1);
    //test3
    for (int i=0;i<5;i++) for (int j=0;j<5;j++) TestMatrix[i][j] = 1;
    EXPECT_EQ(GetMinElemOnMainDiag(TestMatrix,5),1);
    //test4
    for (int i=0;i<5;i++) for (int j=5;j>0;j--) TestMatrix[i][j] = j;
    EXPECT_EQ(GetMinElemOnMainDiag(TestMatrix,5),1);
}

TEST(MatrixMathTest, DiffMatrix){
    int **TestMatrix1 = new int *[5];
    int **TestMatrix2 = new int *[5];
    int **TestMatrixRes1 = new int *[5];//результат работы подпрограмм
    int **TestMatrixRes2 = new int *[5];//то, что должно быть

    for (int i=0;i<5;i++)TestMatrix1[i] = new int [5];
    for (int i=0;i<5;i++)TestMatrix2[i] = new int [5];
    for (int i=0;i<5;i++)TestMatrixRes1[i] = new int [5];
    for (int i=0;i<5;i++)TestMatrixRes2[i] = new int [5];

    //test1
    for (int i=0;i<5;i++) for (int j=0;j<5;j++) TestMatrix1[i][j] = j;
    for (int i=0;i<5;i++) for (int j=0;j<5;j++) TestMatrix2[i][j] = j;
    for (int i=0;i<5;i++) for (int j=0;j<5;j++) TestMatrixRes2[i][j] = 0;

    TestMatrixRes1 = DiffMatrix(TestMatrix1,TestMatrix2,5);

    for (int i=0;i<5;i++) for (int j=0;j<5;j++) EXPECT_EQ(TestMatrixRes1[i][j],TestMatrixRes2[i][j]);

    //test2
    for (int i=0;i<5;i++) for (int j=0;j<5;j++) TestMatrix1[i][j] = i;
    for (int i=0;i<5;i++) for (int j=0;j<5;j++) TestMatrix2[i][j] = j;
    for (int i=0;i<5;i++) for (int j=0;j<5;j++) TestMatrixRes2[i][j] = TestMatrix1[i][j] - TestMatrix2[i][j];

    TestMatrixRes1 = DiffMatrix(TestMatrix1,TestMatrix2,5);

    for (int i=0;i<5;i++) for (int j=0;j<5;j++) EXPECT_EQ(TestMatrixRes1[i][j],TestMatrixRes2[i][j]);
}

TEST(MatrixMathTest, TranspMatrix){
    int **TestMatrix1 = new int *[5];
    int **TestMatrixRes1 = new int *[5];//результат работы подпрограмм
    int **TestMatrixRes2 = new int *[5];//то, что должно быть

    for (int i=0;i<5;i++)TestMatrix1[i] = new int [5];
    for (int i=0;i<5;i++)TestMatrixRes1[i] = new int [5];
    for (int i=0;i<5;i++)TestMatrixRes2[i] = new int [5];

    //test1
    for (int i=0;i<5;i++) for (int j=0;j<5;j++) TestMatrix1[i][j] = j;
    for (int i=0;i<5;i++) for (int j=0;j<5;j++) TestMatrixRes2[i][j] = TestMatrix1[j][i];

    TestMatrixRes1 = TranspMatrix(TestMatrix1,5);

    for (int i=0;i<5;i++) for (int j=0;j<5;j++) EXPECT_EQ(TestMatrixRes1[i][j],TestMatrixRes2[i][j]);

    //test2
    for (int i=0;i<5;i++) for (int j=0;j<5;j++) TestMatrix1[i][j] = i;
    for (int i=0;i<5;i++) for (int j=0;j<5;j++) TestMatrixRes2[i][j] = TestMatrix1[j][i];

    TestMatrixRes1 = TranspMatrix(TestMatrix1,5);

    for (int i=0;i<5;i++) for (int j=0;j<5;j++) EXPECT_EQ(TestMatrixRes1[i][j],TestMatrixRes2[i][j]);
}

TEST(MatrixMathTest, MultMatrix){
    int **TestMatrix1 = new int *[5];
    int **TestMatrix2 = new int *[5];
    int **TestMatrixRes1 = new int *[5];//результат работы подпрограмм
    int **TestMatrixRes2 = new int *[5];//то, что должно быть

    for (int i=0;i<5;i++)TestMatrix1[i] = new int [5];
    for (int i=0;i<5;i++)TestMatrix2[i] = new int [5];
    for (int i=0;i<5;i++)TestMatrixRes1[i] = new int [5];
    for (int i=0;i<5;i++)TestMatrixRes2[i] = new int [5];

    //test1
    for (int i=0;i<5;i++) for (int j=0;j<5;j++) TestMatrix1[i][j] = j;
    for (int i=0;i<5;i++) for (int j=0;j<5;j++) TestMatrix2[i][j] = j;
    for (int i=0;i<5;i++) for (int j=0;j<5;j++) TestMatrixRes2[i][j] = j*10;

    TestMatrixRes1 = MultMatrix(TestMatrix1,TestMatrix2,5);

    for (int i=0;i<5;i++) for (int j=0;j<5;j++) EXPECT_EQ(TestMatrixRes1[i][j],TestMatrixRes2[i][j]);
}
