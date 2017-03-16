// Left rotate an vector k number of times

#include<iostream>
#include<vector>
#include<algorithm>
#include<assert.h>

using namespace std;

// O(n) time complexity and O(k) space complexity
void solution1(vector<int>& iVec, const int k)
{
	if(iVec.size() <= 1 || k == 1 || k >= iVec.size())
		return;
	
	// Use a temp vector to store first k elements.
	// Shift the rest from iVec
	// Copy from temp to iVec
	
	vector<int> temp(iVec.begin(), iVec.begin()+k);
	copy(iVec.begin()+k, iVec.end(), iVec.begin());
	copy(temp.begin(), temp.end(), iVec.begin()+iVec.size()-k);
	return;
}

// Based on Rotation. O(n) time and space complexity
void solution2(vector<int>& iVec, const int k)
{
	if(iVec.size() <=1 || k == 1 || k >= iVec.size())
		return;
	
	reverse(iVec.begin(), iVec.begin()+k);
	reverse(iVec.begin()+k, iVec.end());
	reverse(iVec.begin(), iVec.end());
}

int main()
{
	vector<int> iVec1 = {1,2,3,4,5,6,7};
	solution1(iVec1,2);
	vector<int> iVec2 = {1,2,3,4,5,6,7};
	solution1(iVec2,2);
	assert(iVec1 == iVec2);
}