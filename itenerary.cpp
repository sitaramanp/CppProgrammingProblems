// Leetcode 332. Reconstruct Itinerary

// Kinda toposort. But here we can have cycles. We move through the edges and remove them once travelled.

#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<set>

using namespace std;

void explore(string node, vector<string>& ans, unordered_map<string, multiset<string>>& graph)
{
    while(!graph[node].empty())
    {
        string nextNode = *(graph[node].begin());
        graph[node].erase(graph[node].begin());
        explore(nextNode, ans, graph);
    }
    ans.push_back(node);
}

vector<string> findItinerary(vector<pair<string, string>> tickets) {
    vector<string> ret;
    if(tickets.empty())
        return ret;
    
    unordered_map<string, multiset<string>> graph;
    for(auto &it : tickets)
    {
      graph[it.first].insert(it.second);
    }
    
    explore("JFK", ret, graph);
	// As with toposort, nodes from which there are no out-going edges are added to the result first. 
    reverse(ret.begin(), ret.end());
    return ret;
}
