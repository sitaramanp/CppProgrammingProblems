// find minimum number in a rotated array, which was sorted
// in arr 6,8,9,3,5 min is 3

#include<iostream>
#include<vector>
#include<stdexcept>

using namespace std;

int getMinSequentially(vector<int>& iVec)
{
	if(iVec.empty())
		throw invalid_argument("empty vector");
	
	int min = iVec[0];
	for(auto val: iVec)
		if(min > val)
			min = val;
			
	return min;			
}

int getMin(vector<int>& iVec)
{
	if(iVec.empty())
		throw invalid_argument("empty vector");
	
	int start = 0;
	int end = iVec.size()-1;
	while(end > start+1)
	{
		int mid = start + (end-start)/2 ;
		if(iVec[start] == iVec[end] && iVec[start] == iVec[mid])
			return getMinSequentially(iVec);
		if(iVec[mid] > iVec[start])
			start = mid;
		else
			end = mid;
	}
	
	return iVec[start] > iVec[end] ? iVec[end]:iVec[start];
}

int main()
{
	vector<int> iVec = {9,3,5,6,8};
	cout << getMin(iVec) << endl;
}