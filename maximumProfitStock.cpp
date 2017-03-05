// Codility
// maximum profit from list of share prices.

#include<iostream>
#include<vector>
#include<limits>
#include<algorithm>

using namespace std;

int maxProfit(vector<int>& iVec)
{
	int ans = 0;
	int min = numeric_limits<int>::max();
	
	for(auto& val: iVec)
	{
		if(val < min)
		{
			min = val;
		}
		else
		{
			ans = max(ans, val-min);
		}
	}
	
	return ans;
}
