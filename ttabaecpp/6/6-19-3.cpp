#include <iostream>

using namespace std;


int main(void)
{
    const int row = 3;
    const int col = 5;

    const int s2da[][5] =
    {
        {1,2,3,4,5},
        {6,7,8,9,10},
        {11,12,13,14,15}
    };

    int *matrix = new int[row*col];
    
    for (int r = 0 ; r < row ; ++r)
    {
        for (int c = 0 ; c < col ; ++c)
            matrix[c + r*col] = s2da[r][c];
    }

    for (int r = 0 ; r < row ; ++r)
    {
        for (int c = 0 ; c < col ; ++c)
            cout << matrix[c + r * col] << " ";
        cout << endl;
    }

    delete[] matrix;

    return (0);
}