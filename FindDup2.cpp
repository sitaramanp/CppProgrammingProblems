//Vector has elements from 0 to n-1. some numbers are duplicated. Find any

//Approach is to place the elements in its proper index
#include<iostream>
#include<vector>
#include<stdexcept>
#include<algorithm>

using namespace std;

int findDup2(vector<int>& iVec)
{
    if(iVec.size() <=1 )
        throw invalid_argument("Too few elements in vector");
    int n = iVec.size();
    for(int i=0; i<n;++i)
    {
        while(iVec[i] != i)
        {
            if(iVec[i] < 0 || iVec[i] > n-1)
                throw out_of_range("element not in range 0 to n-1");
            int temp = iVec[i];
            iVec[i] = iVec[temp];
            if(iVec[temp] == temp)
                return temp;
            iVec[temp] = temp;
        }
    }

    throw invalid_argument("no duplicates");
}

int main()
{
    vector<int> iVec = {2,3,1,0,2,5,3};

    cout << findDup2(iVec) << endl;
}

