#include<bits/stdc++.h>
using namespace std;
class Graph{
	int V;
	vector<int> *edge;
	void DFSUtil(int v,bool visited[]);
	public:
		Graph(int v);
		void addEdge(int v,int w);
		void DFS(int v);
		void print();
		void BFS(int s);
};
Graph::Graph(int v)
{
	this->V=v;
	edge=new vector<int>[V];
	
}
void Graph::addEdge(int v,int w)
{
	edge[v].push_back(w);
}
void Graph::print()
{
	for(int i=0;i<V;i++)
	{
		cout<<i<<"-";
		for(int j=0;j<edge[i].size();j++)
		cout<<edge[i][j]<<" ";
		cout<<endl;
	}
}
void Graph::BFS(int v)
{
	bool visited[V];
	for(int i=0;i<V;i++)
	visited[i]=false;
	visited[v]=true;
	queue<int> nodes;
	nodes.push(v);
	cout<<v<<" ";
	while(!nodes.empty())
	{
		v=nodes.front();
		nodes.pop();
		for(int i=0;i<edge[v].size();i++)
		{
			if(!visited[edge[v][i]])
			{
				nodes.push(edge[v][i]);
				cout<<edge[v][i]<<" ";
				visited[edge[v][i]]=true;
			}
		}
	}
}
void Graph::DFS(int s)
{
	 bool *visited = new bool[V]; 
	for(int i=0;i<V;i++)
	visited[i]=false;
	DFSUtil(s,visited);
}
void Graph::DFSUtil(int v,bool visited[])
{
	cout<<v<<endl;
	visited[v]=true;
	for(int i=0;i<edge[v].size();i++)
	{
		if(!visited[edge[v][i]])
		{
			DFSUtil(edge[v][i],visited);
		}
	}
}
int main()
{
	int V=5;
	Graph g(4);
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(1,2);
	g.addEdge(2,0);
	g.addEdge(2,3);
	g.addEdge(3,3);
	g.DFS(2);
}
