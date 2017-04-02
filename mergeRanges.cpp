// Given array of ranges, merge the overlapping ones

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool cmp(const pair<int,int>& a, const pair<int,int>& b)
{
	return a.first <= b.first;
}

bool doPointsOverlap(const pair<int,int>& a, const pair<int,int>& b)
{
	if(b.first >= a.first && b.first <= a.second)
		return true;
	if(a.first >= b.first && a.first <= b.second)
		return true;
	
	return false;
}

pair<int,int> mergePoints(const pair<int,int>& a, const pair<int,int>& b)
{
	pair<int,int> result;
	int first = min(a.first, b.first);
	int second = max(a.second, b.second);
	return make_pair(first,second);
}

vector<pair<int,int>> mergeRanges(vector<pair<int,int>>& ranges)
{
	vector<pair<int,int>> result;
	if(ranges.empty())
		return result;
	
	sort(ranges.begin(), ranges.end(), cmp);
	result.push_back(ranges[0]);
	
	for(int i=1; i<ranges.size(); ++i)
	{
		if(doPointsOverlap(ranges[i], result.back()))
		{
			result.back() = mergePoints(ranges[i], result.back());
		}
		else
			result.push_back(ranges[i]);
	}
	return result;
}

int main()
{
	vector<pair<int,int>> ranges;
	ranges.push_back(make_pair(5,13));
	ranges.push_back(make_pair(8,19));
	ranges.push_back(make_pair(27,39));
	ranges.push_back(make_pair(31,37));

	vector<pair<int,int>> result = mergeRanges(ranges);
	for_each(result.begin(), result.end(), [](pair<int,int>& a) { cout << a.first << "," << a.second << endl; });
	return 0;
		
}