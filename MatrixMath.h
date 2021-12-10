//
// Created by vladi on 02.12.2021.
//

#ifndef UNTITLED3_MATRIXMATH_H
#define UNTITLED3_MATRIXMATH_H
int** FillMatrixRand(int **Matrix, int size);
int GetSumElemMatrix(int **Matrix, int size);
int GetCountNechetElemsMatrix(int **Matrix, int size);
int GetMinElemOnMainDiag(int **Matrix, int size);
int** DiffMatrix(int **MatrixA,int **MatrixB,int size);
int** TranspMatrix(int **Matrix,int size);
int** MultMatrix(int** MatrixA, int** MatrixB, int size);
#endif UNTITLED3_MATRIXMATH_H
