// 229. Majority Element II

// This solution runs in 22ms and is based on majority count algorithm

#include<limits>
#include<iostream>
#include<vector>


vector<int> majorityElement(vector<int>& nums)
{
	vector<int> ret;
	if(nums.empty())
		return ret;
	
	int ele1, count1, ele2, count2;
	ele1 = count1 = ele2 = count2 = 0;
        
	for(auto &val : nums)
	{
		if(ele1 == val)
			count1++;
		else if(ele2 == val)
			count2++;
		else if(count1 == 0)
		{
			ele1 = val;
			count1++;
		}
		else if(count2 == 0)
		{
			ele2 = val;
			count2++;
		}
		else
		{
			count1--;
			count2--;
		}           
	}
        
	int count_1 = 0;
	int count_2 = 0;
	for(auto & val: nums)
	{
		if(val == ele1)
			++count_1;
		else if(val == ele2)
			++count_2;
	}
        
	if(count_1 > nums.size()/3)
		ret.push_back(ele1);
	if(count_2 > nums.size()/3)
		ret.push_back(ele2);
        
	return ret;    
}
