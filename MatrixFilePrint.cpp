#include <fstream>
#include <iostream>
#include "PrintTo.h"
#include "MatrixFilePrint.h"

void PrintFileMatrix(int **Matrix, int size){
    std::fstream stream;
    stream.open(R"(C:\FileForTest\testfile.txt)", std::fstream::app);
    printMatrix(Matrix,size,stream);

}