#include<iostream>
using namespace std;
int AdjM[10][10],nodes,visited[10];
class gragh_bfs
{
public:
	void creategraph(int size)
	{
		nodes=size;
		int src,dest;
		for(src=0;src<nodes;src++)
		{
			for(dest=0;dest<nodes;dest++)
			{
				cout<<"from:"<<src<<" to "<<dest<<":";
				cin>>AdjM[src][dest];
			}
		}
	}
	void BFS(int source)
	{
		int i,e,Q[100],front=0,rear=-1;
		visited[source]=1;
		Q[++rear]=source;
		while(front<=rear)
		{
		e=Q[front++];
		cout<<"v"<<e<<"-";
		for(i=0;i<nodes;i++)
		{
			if(AdjM[e][i]==1 && visited[i]!=1)
			{
				visited[i]=1;
				Q[++rear]=i;
			}
		}
	}
	}
};
int main()
{
	gragh_bfs a;
	int no;
	cout<<"enter no of nodes";
	cin>>no;
	a.creategraph(no);
	a.BFS(0);
	return 0;
}