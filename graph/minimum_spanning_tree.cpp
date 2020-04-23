/*
 * https://www.geeksforgeeks.org/kruskals-minimum-spanning-tree-algorithm-greedy-algo-2/
 *
 * Kruskal's minimum spanning tree
 *
 * Union find operations
 * 
 */


#include <iostream>
#include <vector>
#include <algorithm>


struct Edge
{
	int v1_, v2_;
	int weight_;

	Edge():v1_(-1),v2_(-1),weight_(0){}
	Edge(int v1, int v2, int weight):v1_(v1),v2_(v2),weight_(weight){}
};

struct EdgeCmp
{
	bool operator()(const Edge& e1, const Edge& e2)
	{
		return e1.weight_ < e2.weight_;
	}
};


// find the set id for specific vertex id 
int FindSet(const std::vector<int>& father, int vertex_id)
{
	if (vertex_id == father[vertex_id])
		return vertex_id;

	return FindSet(father, father[vertex_id]);
}

// union two sets which v1 and v2 belong to 
bool UnionSet(std::vector<int>& father, int v1, int v2)
{
	int set1 = FindSet(father, v1);
	int set2 = FindSet(father, v2);

	if (set1 == set2)
		return false;
	
	if (set1 < set2)
		father[set2] = set1;
	else
		father[set1] = set2;
	return true;
}


std::vector<Edge> KruskalMST(std::vector<Edge>& graph, int vertex_num)
{
	std::sort(graph.begin(), graph.end(), EdgeCmp());

	std::vector<int> father(vertex_num);
	for (int i = 0; i < vertex_num; ++i)
		father[i] = i;

	// greedily select
	std::vector<Edge> selected_edges;
	for (int i = 0; i<graph.size(); ++i)
	{
		int v1 = graph[i].v1_;
		int v2 = graph[i].v2_;
		if (UnionSet(father, v1, v2))
		{
			selected_edges.push_back(graph[i]);
		}
	}

	return selected_edges;
}


int main()
{
	int vertex_num = 8;
	
	std::vector<Edge> graph;
	
	/*Edge e1(0, 1, 10);
	Edge e2(0, 3, 5);
	Edge e3(0, 2, 6);
	Edge e4(1, 3, 15);
	Edge e5(2, 3, 4);

	graph.push_back(e1);
	graph.push_back(e2);
	graph.push_back(e3);
	graph.push_back(e4);
	graph.push_back(e5);*/

	Edge e1(0, 6, 3);
	Edge e2(0, 7, 4);
	Edge e3(1, 2, 9);
	Edge e4(1, 3, 1);
	Edge e5(2, 3, 5);
	Edge e6(4, 7, 2);
	Edge e7(5, 7, 1);
	Edge e8(5, 6, 2);
	Edge e9(0, 1, 3);

	graph.push_back(e1);
	graph.push_back(e2);
	graph.push_back(e3);
	graph.push_back(e4);
	graph.push_back(e5);
	graph.push_back(e6);
	graph.push_back(e7);
	graph.push_back(e8);
	graph.push_back(e9);

	
	std::vector<Edge> selected_edges = KruskalMST(graph, vertex_num);
	int total_weight = 0;
	
	std::cout << "selected edges:\n";
	for(auto e:selected_edges)
	{
		total_weight += e.weight_;
		std::cout << e.v1_ << " ----- " << e.v2_ << "\n";
	}
	std::cout << "the sum of weight: " << total_weight << "\n";
	
	system("pause");
	return 0;
}