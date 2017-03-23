#include<iostream>
#include<vector>

using namespace std;

int binarySearch(const vector<int> & iVec, int num)
{
    if(iVec.empty())
        return -1;
    int start = 0;
    int end = iVec.size() - 1;

    while(start<=end)
    {
        int mid = start + (end-start)/2;
        if(iVec[mid] < num)
            start = mid+1;
        else if(iVec[mid] > num)
            end = mid-1;
        else    
            return mid;
    }

    return -1;

}

int lastOccurance(const vector<int>& iVec, int num, bool& found)
{
    if(iVec.empty())
        return -1;
    int start = 0;
    int end = iVec.size()-1;

    while(start <= end)
    {
        int mid = start + (end-start)/2;

        if(iVec[mid] == num)
        {
			found = true;
            if(mid == end || iVec[mid+1] != num)
                return mid;
            else
                start = mid+1;
        }
        
        else if(iVec[mid] < num)
            start = mid +1;
        
        else
            end = mid -1;
    }

    return -1;
}

int firstOccurance(const vector<int>& iVec, int num, bool& found)
{
    if(iVec.empty())
        return -1;
    int start = 0;
    int end = iVec.size()-1;

    while(start <= end)
    {
        int mid = start + (end-start)/2;

        if(iVec[mid] == num)
        {
			found = true;
		
            if(mid == start || iVec[mid-1] != num)
                return mid;
            else
                end = mid-1;
        }
        
        else if(iVec[mid] < num)
            start = mid +1;
        
        else
            end = mid -1;
    }

    return -1;
}

int main()
{
    vector<int> iVec = {1,2,2,2,4,7,8,8};
	int numToSearch = 8;
	
	bool found = false;
    
	int last = lastOccurance(iVec, numToSearch, found);
	int first = firstOccurance(iVec, numToSearch, found);
	int numTimes = 0;
	if(found)
		numTimes = last - first + 1;
	
    cout << "num: " << numToSearch << " occurs " << numTimes << " times" << endl;
}
