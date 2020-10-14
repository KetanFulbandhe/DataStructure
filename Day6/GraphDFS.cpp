#include<iostream>
using namespace std;
int AdjM[10][10],nodes,visited[10];
void createGraph(int size)
{
    nodes=size;
    int src,dest;
    for(src=0;src<nodes;src++)
    {
        for(dest=0;dest<nodes;dest++)
        {
            cout<<"\n from:"<<src<<"to "<<dest<<":"<<endl;
            cin>>AdjM[src][dest];
        }
    }
}
void DFS(int source)
{
    int i;
    visited[source]=1;
    cout<<source<<",";
    for(i=0;i<nodes;i++)
    {
        if(AdjM[source][i]==1 && visited[i]==0)
        {
            DFS(i);
        }
    }
}
int main()
{
    int nds,source;
    cout<<"Enter no of nodes:"<<endl;
    cin>>nds;
    createGraph(nds);
    cout<<"Enter Source:"<<endl;
    cin>>source;
    DFS(source);
    return 0;
}
