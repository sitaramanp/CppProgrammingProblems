// two neighboring elements are in absolute difference 1, an algorithm to search an element in the array and return its position

#include<iostream>
#include<vector>

using namespace std;

int findPos(vector<int>& iVec, int num)
{
	if(iVec.empty())
		return -1;
	for(int i=0; i<iVec.size(); )
	{
		if(iVec[i] == num)
			return i;
		i += abs(iVec[i]-num);
	}
	return -1;
}

int main()
{
	vector<int> iVec = {4,5,6,5,6,7,8,9,10,9};
	cout << findPos(iVec,9) << endl;
}