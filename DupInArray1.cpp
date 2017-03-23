// Array contains numbers from 0 to n-2. One number is duplicated. Find that numbers
//

#include <iostream>
#include <vector>
#include <numeric>
#include <stdexcept>

using namespace std;

int findDup(vector<int>& iVec) throw( invalid_argument )
{
    int n =  iVec.size();
    if(n<2)
        return -1;
    //int sum1 = accumulate(iVec.begin(), iVec.end(),0); // sum of all elements in the given vector
    int sum1 = 0;
    for(auto num:iVec)
    {
        if(num < 0 || num > (n-2))
            throw invalid_argument("Vector has element not in range 0 to n-2");
        sum1 += num;    
    }
    int sum2 = ((n-1) *(n-2))/2;
    return sum1 - sum2;
 
}

int main()
{
    vector<int> iVec = {0,1,2,3,2};

    cout << findDup(iVec) << endl;
}
