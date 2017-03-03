// Leetcode 456. 132 Pattern

// This solution ran in 22ms and beats 96.4% of submission

// It is O(n) algorithm. We scan the given vector left to right to store minimum number from [0, i). Similarly we store values from right to left.
// Aux space used is O(n) as well.

#include<iostream>
#include<vector>
#include<limits>

using namespace std;

bool find132pattern(vector<int>& nums) 
{
	if(nums.size() <= 2)
		return false;
	vector<int> lArr(nums.begin(), nums.end());
	vector<int> rArr(nums.size(), numeric_limits<int>::max());
	lArr[0] = numeric_limits<int>::max();
	for(int i=1; i<nums.size(); ++i)
	{
		lArr[i] = min(lArr[i-1], nums[i-1]);
	}

	for(int i=nums.size()-2; i>=0; --i)
	{
		int minVal = min(rArr[i+1], nums[i+1]);
		if(minVal > lArr[i])
			rArr[i] = minVal;
		else
			rArr[i] = rArr[i+1];
	}

	for(int i=1; i< nums.size()-1; ++i)
	{
		if(lArr[i] < rArr[i] && rArr[i] < nums[i])
			return true;
	}
	return false;
}
