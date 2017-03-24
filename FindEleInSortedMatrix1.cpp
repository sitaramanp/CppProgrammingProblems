//In a 2-D matrix, every row is increasingly sorted from left to right, and the last number in each
//row is not greater than the first number of the next row.
//
#include<iostream>
#include<vector>

using namespace std;

bool IsElementPresentInMatrix(vector<vector<int> >& mat, int numToFind)
{
    if(mat.empty() || mat[0].empty())
        return false;

    int start = 0;
    int rowSize = mat.size();
    int colSize = mat[0].size();
    int end = rowSize*colSize - 1;

    while(start <= end)
    {
        int mid = start + (end-start)/2;
        int row = mid/colSize; 
        int col = mid%colSize;
        if(numToFind == mat[row][col])
            return true;
        if(numToFind < mat[row][col])
            end = mid-1;
        else
            start = mid+1;
    }

    return false;
}

int main()
{
    vector<vector<int> > mat = {{1,3,5}, {7, 9, 11}, {13, 15, 17}};

    cout << IsElementPresentInMatrix(mat, 13) << endl;
	return 0;
}
