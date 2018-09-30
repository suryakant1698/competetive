#include<bits/stdc++.h>
using namespace std;
struct DisjointSets{
	int *rank,*parent,V;
	DisjointSets(int v)
	{
		this->V=v;
		rank=new int[V]();
		parent=new int [V]();
		for(int i=0;i<V;i++)
		{
			rank[i]=0;
			parent[i]=i;
		}
	}
	int findSet(int u)
	{
		if(parent[u]!=u)
		parent[u]=findSet(parent[u]);
		return parent[u];
	}
	void merge(int x,int y)
	{
		x=findSet(x);
		y=findSet(y);
		if(rank[x]>rank[y])
		parent[y]=x;
		else parent[x]=y;
		if(rank[x]==rank[y])
		rank[y]++;
	}
};
struct Graph
{
	int V,E;
	vector<pair<int,pair<int,int> > > edgeList;
	Graph(int v,int e)
	{
		this->V=v;
		this->E=e;
	}
	void addEdge(int w,int u,int v)
	{
		edgeList.push_back({w,{u,v}});
	}
	int kruskalMST()
	{
		sort(edgeList.begin(),edgeList.end());
		DisjointSets ds(V);
		int answer=0,edgeCount=0;
		for(int i=0;edgeCount<V-1;i++)
		{
			int u=edgeList[i].second.first;
			int v=edgeList[i].second.second;
			int set_u=ds.findSet(u);
			int set_v=ds.findSet(v);
			if(set_u!=set_v)
			{
				edgeCount++;
				answer+=edgeList[i].first;
				ds.merge(set_u,set_v);
			}
		}
		return answer;
	}
	int findParent(int v,int arr[])
	{
		while(arr[v]!=v)
		v=arr[v];
		return v;
	}
};
int main()
{
	int v=9,e=14;
	Graph g(v,e);
	g.addEdge(4,0,1);
	g.addEdge(8,0,7);
	g.addEdge(11,1,7);
	g.addEdge(8,1,2);
	g.addEdge(7,7,8);
	g.addEdge(1,7,6);
	g.addEdge(6,6,8);
	g.addEdge(2,2,8);
	g.addEdge(7,2,3);
	g.addEdge(2,5,6);
	g.addEdge(4,2,5);
	g.addEdge(14,3,5);
	g.addEdge(9,3,4);
	g.addEdge(10,5,4);
	cout<<g.kruskalMST();
}
