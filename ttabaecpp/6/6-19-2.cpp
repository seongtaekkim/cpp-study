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

    int *r1 = new int[col];
    int *r2 = new int[col];
    int *r3 = new int[col];

    int **rows = new int*[row];

    for (int r = 0 ; r < row ; ++r)
    {
        for (int c = 0 ; c < col ; ++c)
            cout << s2da[r][c] << " ";
        cout << endl;
    }

    delete[] r1;
    delete[] r2;
    delete[] r3;
    delete[] rows;



    int **matrix = new int*[row];

    for (int r =0 ; r<row ; ++r)
        matrix[r] = new int[col];

    for (int r = 0 ; r < row ; ++r)
    {
        for (int c = 0 ; c < col ; ++c)
            matrix[r][c] = s2da[r][c];
    }

    for (int r = 0 ; r < row ; ++r)
    {
        for (int c = 0 ; c < col ; ++c)
            cout << matrix[r][c] << " ";
        cout << endl;
    }

    for (int r =0 ; r<row ; ++r)
        delete[] matrix[r];
    delete[] matrix;

}