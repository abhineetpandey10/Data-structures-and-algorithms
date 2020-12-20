#include<iostream>
using std::cin;
using std::cout;
#include<algorithm>
using std::sort;
#include<vector>
using std::vector;
#include<cstring>
class edge
{
public:
    int src,dest,weight;
    edge(int a,int b,int wt)
    {
        src=a;
        dest=b;
        weight=wt;
    }
};
bool compare(edge a,edge b)
{
    return a.weight<b.weight;
}
class graph
{
public:
    vector<edge> edgeList;
    int V,E;
    graph(){}
    void initGraph()
    {
        int v,e;
        cout<<"Enter the number of vertices in the graph:\n";
        cin>>v;
        this->V=v;
        cout<<"Enter the number of edges in the graph:\n";
        cin>>e;
        this->E=e;
        cout<<"Enter the vertices constituting each edge followed by the weight of each edge:\n";
        cout<<"Each vertex must be between 0 and "<<v-1<<", both 0 and "<<v-1<<"inclusive\n";
        //edgeList=new vector<edge>[e];
        for(int i=0;i<e;i++)
        {
            int src,dest,wt;
            cin>>src>>dest>>wt;
            edge newEdge(src,dest,wt);
            edgeList.push_back(newEdge);
        }
    }
    void kruskalMST()
    {
        sort(edgeList.begin(),edgeList.end(),compare);
        bool isVertexPresent[V];
        memset(isVertexPresent,0,sizeof(isVertexPresent));
        vector<edge> MST;
        int edgeCount=0;
        for(int i=0;i<E;i++)
        {
            if(edgeCount==(V-1)) break;
            if(!isVertexPresent[edgeList[i].src] || !isVertexPresent[edgeList[i].dest])
            {
                MST.push_back(edgeList[i]);
                edgeCount++;
                isVertexPresent[edgeList[i].src]=true;
                isVertexPresent[edgeList[i].dest]=true;
            }
        }
        //cout<<edgeCount<<'\n';
        for(int i=0;i<V;i++) cout<<isVertexPresent[i]<<' ';
        cout<<'\n';
        cout<<"Edge\tWeight\n";
        for(int i=0;i<MST.size();i++)
            cout<<MST[i].src<<"-"<<MST[i].dest<<"\t"<<MST[i].weight<<'\n';
    }
};
int main()
{
    graph g;
    g.initGraph();
    g.kruskalMST();
}
