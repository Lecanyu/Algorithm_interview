/*
 * https://www.geeksforgeeks.org/topological-sorting-indegree-based-solution/
 *
 * Topological sorting has a lot of applications like
 * 1. judge if a graph is a directed acyclic graph
 * 2. calculate the earliest start time of projects in task schedule.
 *
 * There are several algorithms to implement topological sorting.
 *
 * I elaborate the indegree-based solution here.
 * 1. Compute in-degree (number of incoming edges) for each of the vertex present in the DAG and initialize the count of visited nodes as 0.
 * 2. Pick all the vertices with in-degree as 0 and add them into a queue (Enqueue operation)
 * 3. Remove a vertex from the queue (Dequeue operation) and then.
		3.1 Increment count of visited nodes by 1.
		3.2 Decrease in-degree by 1 for all its neighboring nodes.
		3.3 If in-degree of a neighboring nodes is reduced to zero, then add it to the queue.
 * 4. Repeat Step 3 until the queue is empty.
 * 5. If count of visited nodes is not equal to the number of nodes in the graph then the topological sort is not possible for the given graph.
 *
 *
 * The implementation below is a solution for https://leetcode.com/problems/course-schedule/
 * 
 */

#include <iostream>
#include <vector>
#include <queue>

struct Vertex
{
	int id_, inDegree_;
	std::vector<int> toIds_;		// from this vertex to other vertex id
	
	Vertex():id_(-1), inDegree_(-1){}
	Vertex(int id, int in_degree):id_(id),inDegree_(in_degree){}
};

bool IsDAG(int vertex_num, std::vector<std::vector<int>>& edges)
{
	int visited_vertex_num = 0;
	std::vector<Vertex> vertices;
	std::queue<int> active_vertice_ids;

	// build graph
	for(int i=0;i<vertex_num;++i)
		vertices.push_back(Vertex(i, 0));

	for(int i=0;i<edges.size();++i)
	{
		int from_id = edges[i][1];
		int to_id = edges[i][0];
		vertices[from_id].toIds_.push_back(to_id);
		vertices[to_id].inDegree_ += 1;
	}

	for(int i=0;i<vertex_num;++i)
	{
		if (vertices[i].inDegree_ == 0)
			active_vertice_ids.push(i);
	}

	while (!active_vertice_ids.empty())
	{
		int id = active_vertice_ids.front();
		active_vertice_ids.pop();
		visited_vertex_num++;
		
		for(int to_id: vertices[id].toIds_)
		{
			vertices[to_id].inDegree_ -= 1;
			if (vertices[to_id].inDegree_ == 0)
				active_vertice_ids.push(to_id);
		}
	}

	if (visited_vertex_num < vertex_num)
		return false;
	return true;
}


int main()
{
	int vertex_num = 2;
	std::vector<std::vector<int>> edges = { {1,0}, {0,1} };

	bool result = IsDAG(vertex_num, edges);
	std::cout << result << std::endl;
	
	system("pause");
	return 0;
}


