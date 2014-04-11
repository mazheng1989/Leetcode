#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;

// Definition for undirected graph.
struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if(!node)
			return NULL;
		unordered_map<int,UndirectedGraphNode*> outNodeV;
		queue<UndirectedGraphNode*> candidates;
		UndirectedGraphNode *tempNode = node;
		UndirectedGraphNode *output = new UndirectedGraphNode(node->label);
		UndirectedGraphNode *tempNodeOut = output;
		outNodeV[node->label] = output;
		candidates.push(tempNode);

		while(!candidates.empty())
		{
			tempNode = candidates.front();
			candidates.pop();
			tempNodeOut = outNodeV[tempNode->label];
			for(int i=0;i<tempNode->neighbors.size();++i)
			{
				int label = (tempNode->neighbors[i])->label;
				if(!outNodeV.count(label))
				{
					outNodeV[label] = new UndirectedGraphNode(label);
					candidates.push(tempNode->neighbors[i]);
				}
				tempNodeOut->neighbors.push_back(outNodeV[label]);
			}
		}
		return output;
	}
};