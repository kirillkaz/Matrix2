#include "PrintTo.h"

void printMatrix(int **Matrix, int size, std::ostream& stream) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (Matrix[i][j] < 0) stream << Matrix[i][j] << " ";
            else if (Matrix[i][j] < 10) stream << 0 << Matrix[i][j] << " ";
            else stream << Matrix[i][j] << " ";
        }
        stream << std::endl;
    }
    stream << std::endl;
}
