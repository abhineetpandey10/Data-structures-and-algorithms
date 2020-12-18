#include<iostream>
using std::cin;
using std::cout;
#include<cstdlib>
#include<cstring>
class graph
{
public:
    int **adjMatrix;
    int V;
    int E;
    graph(int numVertices)
    {
        this->V=numVertices;
        adjMatrix =new int*[V];
        for(int i=0;i<V;i++)
            adjMatrix[i]=new int[V];
    }
    void initGraph()
    {
        cout<<"Enter the adjacency matrix representation of the wieghted graph\n"
            <<"The vertices that are connected should have the weights of the weightd edge in the matrix,\n"
            <<"instead of simply being denoted by 1\n";
        int a[V][V];
        for(int i=0;i<V;i++)
            for(int j=0;j<V;j++) 
                cin>>adjMatrix[i][j];
    }
    void printGraph()
    {
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
                cout<<adjMatrix[i][j]<<' ';
            cout<<'\n';
        }
    }
    int minKey(bool mstSet[],int key[])
    {
        int pos=0,min=INT32_MAX;
        for(int i=0;i<V;i++)
            if(!mstSet[i] && key[i]<min) 
            {
                min=key[i];
                pos=true;
            }
        return pos;
    }   
    void primMST()
    {
        bool mstSet[V];
        int parent[V];
        int key[V];
        for(int i=0;i<V;i++)
        {
            key[i]=INT32_MAX;
            //parent[i]=INT32_MAX;
        }
        parent[0]=-1;
        memset(mstSet,0,sizeof(mstSet));
        key[0]=0;
        mstSet[0]=true;
        for(int count=1;count<V;count++)
        {
            int min=minKey(mstSet,key);
            mstSet[min]=true;
            for(int i=0;i<V;i++)
            {
                if(adjMatrix[min][i] && !mstSet[i] && key[i]>adjMatrix[min][i]) 
                {
                    key[i]=adjMatrix[min][i];
                    parent[i]=min;
                }
            }
        }
        cout<<"The Minimum Spanning Tree of the given graph is:\n"
            <<"Edge\tWeight\n";
        //for(int i=0;i<V;i++) cout<<parent[i]<<' ';
        cout<<'\n';
        for(int i=1;i<V;i++)
        {
            cout<<parent[i]<<"-"<<i<<"\t"<<adjMatrix[i][parent[i]]<<'\n';
        }
    }
};
int main()
{
    graph g(5);
    g.initGraph();
    g.primMST();
}
