/*  Given a set of distinct integers, nums, return all possible subsets, without duplicate. LeetCode 78 */

#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

// Using bit manipulation
vector<vector<int>> subsetsSolution1(vector<int>& nums) 
{     
    vector<vector<int>> ret;
    auto totalElements = pow(2,nums.size());    
    for(auto i=1; i<=totalElements; ++i)    
    {
        vector<int> temp;
       
        for(auto j=0; j<nums.size(); ++j)
        {
            if(i & 1<<j)
            {
               temp.push_back(nums[j]);              
            }
        }
        ret.push_back(temp);
    }
    return ret;
}

// backtracking solution
void subsetsSolution2Core(vector<int>& nums, int start, vector<int>& sol, vector<vector<int>>& ans)
{
	//push back whatever the contents of sol. For problems like permutation, where the length of the answer
	//    needs to be same as length of input, we need to have a size check here.
	ans.push_back(sol);
	
	for(auto i=start; i<nums.size(); ++i)
	{
		sol.push_back(nums[i]);
		subsetsSolution2Core(nums, i+1, sol, ans);
		sol.pop_back();
	}
}

vector<vector<int>> subsetsSolution2(vector<int>& nums)
{
	vector<vector<int>> ret;
	vector<int> sol;
	subsetsSolution2Core(nums, 0, sol, ret);
	return ret;
}

//for each new element in the list apart from adding itself to the solution, append to the exsisting elements in the solution to form new elements
vector<vector<int>> subsetsSolution3(vector<int> & nums)
{
	vector<vector<int>> ret (1, vector<int>()); // empty list
	
	for(auto &val : nums)
	{
		auto size = ret.size();
		for(auto i=0; i<size; ++i)
		{
			auto temp = ret[i];
			temp.push_back(val);
			ret.push_back(temp);
		}
	}
	return ret;
}

void printVecVec(vector<vector<int>> ivVec)
{
	for(auto &i: ivVec)
	{
		for(auto &val: i)
		{
			cout << val << " ";
		}
		cout << endl;
	}
}

int main()
{
	vector<int> iVec = {1,2,3};
	vector<vector<int>> ans1 = subsetsSolution1(iVec);
	for_each(ans1.begin(), ans1.end(), [](vector<int>& iVec) { for_each(iVec.begin(), iVec.end(), [](int val) { cout << val <<" ";}); cout << endl; });
	
	vector<vector<int>> ans2 = subsetsSolution2(iVec);
	for_each(ans2.begin(), ans2.end(), [](vector<int>& iVec) { for_each(iVec.begin(), iVec.end(), [](int val) { cout << val <<" ";}); cout << endl; });
	
	vector<vector<int>> ans3 = subsetsSolution3(iVec);
	for_each(ans3.begin(), ans3.end(), [](vector<int>& iVec) { for_each(iVec.begin(), iVec.end(), [](int val) { cout << val <<" ";}); cout << endl; });
}