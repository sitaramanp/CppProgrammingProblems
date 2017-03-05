// Codility question
// Leader is if an element occurs more than n/2 times. 
// split array so that this element is leader in both the halfs. Count number of such splits

#include<iostream>
#include<vector>

using namespace std;

int countEquiLeader(vector<int> & A)
{
	if(A.empty())
		return 0;
	
	int leaderCount = 0;
	int leaderEle = 0;
	for(auto& val: A)
	{
		if(val == leaderEle)
			leaderCount++;
		else
			leaderCount--;
		if(leaderCount <= 0)
		{
			leaderCount = 1;
			leaderEle = val;
		}
	}
	
	vector<int> counts(A.size(),0);
	int totalCount = 0;
	int i = 0;
	
	for(auto& val: A)
	{
		if(val == leaderEle)
			++totalCount;
		counts[i] = totalCount;
		++i;
	}
	
	if(totalCount <= A.size()/2)
		return 0;
	
	int ret = 0;
	for(int i = 0; i<counts.size(); ++i)
	{
		int leftCount = counts[i];
		int rightCount = totalCount - leftCount;
		
		if(leftCount > (i+1)/2 && rightCount > (counts.size()-i-1)/2)
			ret++;
	}
	return ret;
}
