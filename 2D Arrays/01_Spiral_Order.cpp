#include <iostream>
using namespace std;

#define R 3
#define C 6
 
 void spiralPrint(int matrix[][C], int m, int n)
{
    int startRow = 0, endRow = m - 1;
    int startCol = 0, endCol = n - 1;

    while (startRow <= endRow && startCol <= endCol)
    {
        for (int i = startCol; i <= endCol; i++)
        {
            cout << matrix[startRow][i] << " ";
        }

        for (int i = startRow+1; i <= endRow; i++)
        {
            cout << matrix[i][endCol] << " ";
        }

        if (startRow < endRow)
        {
            for (int i = endCol - 1; i >= startCol; i--)
            {
                cout << matrix[endRow][i] << " ";
            }
        }

        if (startCol < endCol)
        {
            for (int i = endRow - 1; i >= startRow + 1; i--)
            {
                cout << matrix[i][startCol] << " ";
            }
        }

        startRow++;
        endRow--;
        startCol++;
        endCol--;
    }

    cout << endl;
}


int main()
{
    int matrix[R][C] = { { 1, 2, 3, 4, 5, 6 },
                    { 7, 8, 9, 10, 11, 12 },
                    { 13, 14, 15, 16, 17, 18 } };
    spiralPrint(matrix, R, C);

    return 0;
}