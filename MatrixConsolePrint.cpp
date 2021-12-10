#include"MatrixConsolePrint.h"
#include "PrintTo.h"

void PrintConsoleMatrix(int **Matrix, int size) {
    printMatrix(Matrix, size, std::cout);
}

