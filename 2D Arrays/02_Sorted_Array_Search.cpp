/*
    1. Start from top right corner.
    2. If key is greater move down else move left.
    3. Try this analogy on notebook on row and column sorted matrix, you'll understand.
    4. Also called "staircase search".
*/

#include <iostream>
using namespace std;
#define r 4
#define c 4

pair<int, int> staircaseSearch(int matrix[][c], int m, int n, int key){
    // Check if element is out of our sorted matrix.
    if (key>matrix[m-1][n-1] || key<matrix[0][0])
        return {-1, -1};
    
    // Searching.
    int i = 0; 
    int j = n-1;
    while(i<m && j>=0){
        if (key == matrix[i][j])
            return {i, j};
        else if (key > matrix[i][j])
            i++;
        else
            j--;
    }

    return {-1, -1};
}

int main()
{
    int matrix[r][c] = {{1, 2, 3, 4},
                        {5, 6, 7, 8},
                        {9, 10, 11, 12},
                        {13, 14, 15, 16}};

    int key;
    cout << "Enter key to find: ";
    cin >> key;

    auto res = staircaseSearch(matrix, r, c, key);

    cout << "{" << res.first << ", " << res.second << "}" << endl; 

    return 0;
}