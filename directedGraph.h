#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

class directedGraph
{
protected:
	class vertex
	{
	public:
		string data;
		bool visited = false;
		vertex * pred;

		vector<vertex*> neighbors;

		vertex(string x)
		{
			data = x;
		}
	};

	vector<vertex*> vertexList;

	vertex * findVertex(string x)
	{
		for (size_t i = 0; i < vertexList.size(); i++)
		{
			if (vertexList[i]->data == x)
				return vertexList[i];
		}
		return NULL;
	}

public:
	void addVertex(string x)
	{
		vertexList.push_back(new vertex(x));
	}

	void addDirectedEdge(string x, string y)
	{
		vertex * a = findVertex(x);
		vertex * b = findVertex(y);

		if (a == NULL || b == NULL) {
			cout << "Sorry. You typed an invalid item" << endl;
		}
		else {
			a->neighbors.push_back(b);
		}
	}

	void addEdge(string x, string y)
	{
		vertex * a = findVertex(x);
		vertex * b = findVertex(y);

		if (a == NULL || b == NULL) {
			cout << "Sorry. You typed an invalid item" << endl;
		}
		else {
			a->neighbors.push_back(b);
			b->neighbors.push_back(a);
		}
	}

	void testDisplay()
	{
		for (size_t i = 0; i<vertexList.size(); i++)
		{
			cout << vertexList[i]->data << ":: ";
			for (size_t j = 0; j<vertexList[i]->neighbors.size(); j++)
			{
				cout << vertexList[i]->neighbors[j]->data << ", ";
			}
			cout << endl;
		}
	}

	void settingAllToFalse() {
		for (int i = 0; i < vertexList.size(); i++) {
			vertexList[i]->pred = NULL;
			vertexList[i]->visited = false;
		}
	}

	void breadthFirstSearch(vertex * s) {
		queue<vertex*> q;
		vertex * myVertex;

		settingAllToFalse();

		q.push(s);
		s->visited = true;

		while (!q.empty()) {
			myVertex = q.front();
			q.pop();

			for (int i = 0; i < myVertex->neighbors.size(); i++) {
				if (myVertex->neighbors[i]->visited == false) {
					q.push(myVertex->neighbors[i]);
					myVertex->neighbors[i]->visited = true;
					myVertex->neighbors[i]->pred = myVertex;
				}
			}
		}
	}

	void findShortestPath(string source) {
		vertex * myVertex = findVertex(source);
		breadthFirstSearch(myVertex);
		vertex * survived = findVertex("Survived");

		stack <vertex*> path;
		while (survived->pred != NULL) {
			path.push(survived);
			survived = survived->pred;
		}
		while (!path.empty()) {
			cout << path.top()->data << ", ";
			path.pop();
		}
	}
};