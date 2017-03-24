//Find an equilibrium index such that the prefix sum == suffix sum


#include<iostream>
#include<vector>

using namespace std;

size_t equi(vector<int>& iVec)
{
    size_t ret = -1;

    if(iVec.size() <= 1)
        return ret;

    vector<long long> sumVec(iVec.size(), 0);
    sumVec[0] = iVec[0];
    for(size_t i = 1; i<iVec.size(); ++i)
        sumVec[i] = sumVec[i-1] + iVec[i];   

    for(size_t pos = 0; pos < iVec.size(); ++pos)
    {
        long long leftSum, rightSum;
        if(pos == 0)
        {
            leftSum = 0;
            rightSum = sumVec[iVec.size()-1] - sumVec[0];
        }
        else if(pos == iVec.size() -1 )
        {
            rightSum = 0;
            leftSum = sumVec[iVec.size()-2];
        }
        else
        {
            leftSum = sumVec[pos-1];
            rightSum = sumVec[iVec.size()-1] - sumVec[pos];
        }
        
        if(leftSum == rightSum)
        {
            ret = pos;
            break;
        }
    }

    return ret;
}

int main()
{
    vector<int>iVec = {1,4,3,5};
    cout << equi(iVec) << endl;    
}
