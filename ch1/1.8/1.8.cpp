#include <iostream>
#include <memory.h>

using namespace std;

void checkZero(int** matrix, int m, int n) {

    bool rows[m];
    bool cols[n];
    memset(rows, false, sizeof(rows));
    memset(cols, false, sizeof(cols));

    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            if(matrix[i][j] == 0) {
                rows[i] = true;
                cols[j] = true;
            }
        }
    }

    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            if(rows[i] || cols[j]) {
                matrix[i][j] = 0;
            }
        }
    }
}

void checkZero2(int** matrix, int m, int n) {

    bool firstRowZero = false;
    bool firstColZero = false;

    for(int i = 0; i < m; ++i) {
        if(matrix[i][0] == 0) {
            firstColZero = true;
            break;
        }
    }

    for(int j = 0; j < n; ++j) {
        if(matrix[0][j] == 0) {
            firstRowZero = true;
            break;
        }
    }

    for(int i = 1; i < m; ++i) {
        for(int j = 1; j < n; ++j) {
            if(matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    for(int i = 0; i < m; ++i) {
        if(matrix[i][0] == 0) {
            for(int j = 0; j < n; ++j) {
                matrix[i][j] = 0;
            }
        }
    }

    for(int j = 0; j < n; ++j) {
        if(matrix[0][j] == 0) {
            for(int i = 0; i < m; ++i) {
                matrix[i][j] = 0;
            }
        }
    }

    if(firstColZero) {
        for(int i = 0; i < m; ++i) {
            matrix[i][0] = 0;
        }
    }

    if(firstRowZero) {
        for(int j = 0; j < n; ++j) {
            matrix[0][j] = 0;
        }
    }
}

int main() {

    int* rowMatrix[4];
    int matrix[][4] = {
        1, 0, 2, -1, 3, 4, 5, 6, 1, 9, 2, 0, 3, 4, 1, 5
    };
    for(int i = 0; i < 4; ++i) {
        rowMatrix[i] = matrix[i];
    }

    checkZero2(rowMatrix, 4, 4);

    for(int i = 0; i < 4; ++i) {
        for(int j = 0; j < 4; ++j) {
            cout << rowMatrix[i][j];
        }
        cout << endl;
    }

    return 0;

}
