// codility
// max double slice sum
// Doesn't take into account of all -ve numbers

#include<iostream>
#include<vector>
#include<algorithm>
#include<limits>
using namespace std;

int doubleSliceSum(vector<int>& iVec)
{
	if(iVec.size() <= 3)
		return 0;
	
	vector<int> lSum(iVec.size(), 0);
	vector<int> rSum(iVec.size(), 0);
	
	for(int i=1; i<iVec.size()-1; ++i)
	{
		lSum[i] = max(0, lSum[i-1]+iVec[i]);
	}
	for(int i=iVec.size()-2; i>0; --i)
	{
		rSum[i] = max(0, rSum[i+1]+iVec[i]);
	}
	
	int ans = numeric_limits<int>::min();
	for(int i=1; i<iVec.size()-1; ++i)
	{
		ans = max(lSum[i-1]+rSum[i+1], ans);
	}
	return ans;
}
