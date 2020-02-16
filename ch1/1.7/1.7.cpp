#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void rotateMatrix(int (*image)[4], int size) {

    for(int layer = 0; layer < size/2; ++layer) {
        int first = layer;
        int last = size-1-layer;
        for(int i = first; i < last; ++i) {
            int offset = i - first;
            int temp = image[layer][i];
            image[layer][i] = image[last-offset][layer];
            image[last-offset][layer] = image[last][last-offset];
            image[last][last-offset] = image[i][last];
            image[i][last] = temp;
        }
    }
}

int main() {
    
//    int size = 4;
//    int **image = new int*[size];
//    for(int i = 0; i < size; ++i) {
//        image[i] = new int[size];
//    }

    int image[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    rotateMatrix(image, 4);

    for(int i = 0; i < 4; ++i) {
        for(int j = 0; j < 4; ++j) {
            cout << image[i][j] << " ";
        }
        cout << endl;
    }

    return 0;

}
