//place all odd in begining and even in end of array

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void groupOddEven(vector<int>& iVec)
{
	if(iVec.empty())
		return;
	int start = 0;
	int end = iVec.size()-1;
	
	while(start < end)
	{
		while(start <= end && iVec[start]%2 == 1)
		{
			++start;
		}
		while(end >= start && iVec[end]%2 == 0)
			-- end;
		if(start < end)
		{
			swap(iVec[start], iVec[end]);
		}
	}
}

int main()
{
	vector<int> iVec = {1,2,3,4,2,2,5,5,8};
	for_each(iVec.begin(), iVec.end(), [](int val) { cout << val << " "; });
	cout << endl;
	groupOddEven(iVec);
	for_each(iVec.begin(), iVec.end(), [](int val) { cout << val << " "; });
	cout << endl;
}