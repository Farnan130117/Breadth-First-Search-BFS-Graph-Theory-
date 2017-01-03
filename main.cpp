#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>

using namespace std;
vector<int>G[100];
 void bfs(int n,int src)
  {
          queue<int>Q;
            Q.push(src);
            int visited[100]={0},level[100];
            int parent[100];
            visited[src]=1;
            level[src]=0;
            while(!Q.empty())
            {

                int u=Q.front();
                for(int i=0;i<G[u].size();i++)
                    {
                            int v=G[u][i];
                           if(!visited[v])
                           {
                              level[v]=level[u]+1;
                              parent[v]=u;
                              visited[v]=1;
                              Q.push(v);
                           }
                     }
                  Q.pop();
              }
              for(int i=1;i<=n;i++)
                        printf("%d to %d distance %d\n",src,i,level[i]);
    }

    int main()
{
    int i,j,k;
    int node,edge,source;

    printf("enter node number & edge number:");
    cin>>node>>edge;//Enter_node_edge

    int e1,e2;
    printf("Enter information:\n");
    for(i=0;i<edge;i++)
    {
        cin>> e1>>e2;
        G[e1].push_back(e2);
        G[e2].push_back(e1);
     }

     printf("Enter source node:");//from_which_node_bfs_start
     scanf("%d",&source);
    bfs(node,1);

    return 0;
}
