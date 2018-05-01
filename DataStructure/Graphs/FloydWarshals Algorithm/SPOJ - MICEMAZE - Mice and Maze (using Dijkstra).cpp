/*
* Solution to SPOJ - MICEMAZE - Mice and Maze using Djkstra
* Solved by: Ali AKber Aakash
* Email: cedward318@gmail.com or ali852609@gmail.com
*/

#include<bits/stdc++.h>

using namespace std;

int minNode(int v[], bool visited[], int n)
{
    int Min=INT_MAX;
    int node=0;
    for(int i=1; i<=n; i++)
    {
        if(!visited[i])
        {
            if(v[i]<Min && v[i]>=0)
            {
            	Min=v[i];
            	node = i;
            }
        }
    }
    //printf("minNode = %d\n",node);
    return node;
}

int main()
{
    int adj[105][105];
    int n,e,t,m,a,b,c;
    bool visited[105];
    int v[105];

    memset(adj,0,sizeof(adj));
    memset(visited,0,sizeof(visited));
    memset(v,-1,sizeof(v));


    scanf("%d %d %d", &n, &e, &t);
    scanf("%d", &m);

    for(int i=0; i<m; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        adj[a][b]=c;
    }

    int l=0;

    for(int x=1; x<=n; x++)
    {
        memset(visited,0,sizeof(visited));
        memset(v,-1,sizeof(v));

        v[x]=0;

        int flag=0,currentNode=minNode(v,visited,n);

        while(flag<n)
        {
            for(int i=1; i<=n; i++)
            {
                if(adj[currentNode][i]>0)
                {
                	if(v[i]<0)
            			v[i] = v[currentNode]+adj[currentNode][i];
            		else
                    	v[i]=min(v[currentNode]+adj[currentNode][i], v[i]);
                }

            }
            visited[currentNode]=true;
            flag++;
            currentNode=minNode(v,visited,n);
        }

        if(v[e]<=t && v[e]>=0)
            l++;

    }

    printf("%d\n", l);


    return 0;
}
