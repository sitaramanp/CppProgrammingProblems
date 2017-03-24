#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int merge(vector<int> & iVec, vector<int>& buff, int start, int mid, int end)
{
	int lStart = start;
	int rStart = mid+1;
	int count = 0;
	int buffStart = 0;

	for(; lStart<=mid && rStart <=end; ++buffStart)
	{
		if(iVec[lStart] <= iVec[rStart])
		{
			buff[buffStart] = iVec[lStart];
			++lStart;
		}
		else
		{
			buff[buffStart] = iVec[rStart];
			++rStart;
			count += mid-lStart+1;
		}
	}
	
	while(lStart <= mid)
	{
		buff[buffStart++] = iVec[lStart++];
		
	}
	
	while(rStart <= end)
	{
		buff[buffStart++] = iVec[rStart++];
	}

	copy(buff.begin(), buff.begin()+end+1, iVec.begin()+start);
	return count;
}

int countInv(vector<int> & iVec, vector<int>& buff, int start, int end)
{
    if(end<=start)
        return 0;

    int mid = start + (end-start)/2;
    int left = countInv(iVec, buff, start, mid);
    int right = countInv(iVec, buff, mid+1, end);
    int middle = merge(iVec, buff, start, mid, end);
	return left+right+middle;
}

int countInversions(vector<int> & iVec)
{
    if(iVec.size()<=1)
        return 0;
    vector<int> buff;
    buff.resize(iVec.size());
    return countInv(iVec, buff, 0, iVec.size()-1);
}

int main()
{
    vector<int> iVec = {5,4,3,2,1};
    cout << "numInversions: " << countInversions(iVec) << endl;
}
