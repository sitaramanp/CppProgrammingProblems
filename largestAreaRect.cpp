#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int largestRectangleArea(vector<int>& heights) {
	if(heights.empty())
		return 0;
    
	heights.push_back(0);
	int ret = 0;
	stack<size_t> indexStack;
	//indexStack.push(0);
	for(size_t idx = 0; idx<heights.size(); ++idx)
	{
		if(indexStack.empty())
		{
			indexStack.push(idx);
			continue;
		}
		
		if(heights[indexStack.top()] <= heights[idx])
			indexStack.push(idx);
		else
		{
			while(!indexStack.empty())    
			{
				size_t curIdx = indexStack.top();
				if(heights[curIdx] < heights[idx])
					break;
				indexStack.pop();
				
				int width = 0;
				if(!indexStack.empty())
				{
					width = idx - indexStack.top() -1;
				}
				else
				{
					width = idx;    
				}
				
				if(ret < width*heights[curIdx])
					ret = width*heights[curIdx];
				
			}
			indexStack.push(idx);
		}
          
	}
        
	return ret;
}

int main()
{
	vector<int> iVec = {2,1,5,6,2,3};
	cout << largestRectangleArea(iVec) << endl;
}