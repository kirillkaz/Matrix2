#include"MatrixPrint.h"

using namespace std;

void PrintMatrix(int **Matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (Matrix[i][j]< 0) cout<<Matrix[i][j]<<" ";
            else if (Matrix[i][j] < 10) cout << 0 << Matrix[i][j] << " ";
            else cout << Matrix[i][j] << " ";
        }
        cout<<endl;
    }
}

