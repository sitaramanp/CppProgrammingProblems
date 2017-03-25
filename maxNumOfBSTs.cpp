// Given number of keys find the number of possible BSTs
// Answer is to find the nth Catalan Number
// DP method is given below

#include<iostream>
#include<vector>

using namespace std;

int findMaxBST( int keys)
{
    if(keys <= 1)
        return 1;

    vector<int> dp;
    dp.resize(keys+1);
    
    dp[0] = 1;
    dp[1] = 1;

    for(int i=1; i<=keys; ++i)
    {
        int sum = 0;
        for(int j=1;j<=i; ++j)
        {
            int left = dp[j-1];
            int right = dp[i-j];
            sum += left*right;
        }
        dp[i] = sum;
    }

    return dp[keys];
}

int main()
{
    int key;
    cin >> key;
    cout << findMaxBST(key) << endl;    
}