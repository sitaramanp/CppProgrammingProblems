// Given number of elements, find all possible BSTs.
// Sort the input vector first and then call the recursive funtion to make trees 
#include<iostream>
#include<vector>
#include<numeric>

using namespace std;

typedef struct tree
{
    int num;
    struct tree *left;
    struct tree *right;

    tree(int val, struct tree *l=NULL, struct tree *r=NULL):num(val),left(l), right(r)
    {
    }
}tree;

void preOrder(tree *root)
{
    if(root == NULL)
        return;

    cout << root->num;
    preOrder(root->left);
    preOrder(root->right);
}

vector<tree *> findBST(vector<int> iVec, int start, int end)
{
    vector<tree *> ret;

    if( end < start || start < 0 || end < 0)
    {
        ret.push_back(NULL);
        return ret;
    }

    for(int i=start; i<=end; ++i)
    {
        vector<tree *> left = findBST(iVec,start, i-1); 
        vector<tree *> right = findBST(iVec, i+1, end);

        for(auto& l: left)
        {
            for(auto& r: right)
            {
                tree *root = new tree(iVec[i], l, r);
                ret.push_back(root);
            }
        }
    }
    return ret;
}

int main()
{
    int key;
    cin >> key;
    
    vector<tree *> ans;
    vector<int> iVec(key);
	iota(iVec.begin(), iVec.end(), 1);
	// Here we are filling the vector in sorted order. Incase we have been given a random vector sort it first
    ans = findBST(iVec, 0, iVec.size()-1);

    for(int i=0; i<ans.size(); ++i)
    {
        preOrder(ans[i]);
        cout << endl;
    }

}
