#include<bits/stdc++.h>
using namespace std;
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
		
		int parent[V],edgeCount=0,answer=0;
		for(int i=0;i<V;i++)
		parent[i]=i;
		for(int i=0;i<E&&edgeCount<V-1;i++)
		{
			int num1=edgeList[i].second.first,num2=edgeList[i].second.second;
			int a=findParent(num1,parent),b=findParent(num2,parent);
			if(a!=b)
			{
				cout<<num1<<"-"<<num2<<endl;
				edgeCount++;
				if(num1<=num2)
				parent[b]=a;
				else parent[a]=b;
				answer+=edgeList[i].first;
			}
		}
		cout<<findParent(1,parent)<<" "<<findParent(2,parent)<<endl;
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
