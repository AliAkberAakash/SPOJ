/*
* Solution to SPOJ - MICEMAZE - Mice and Maze Using Floyd Warshal's
* Solved by: Ali AKber Aakash
* Email: cedward318@gmail.com or ali852609@gmail.com
*/


#include<cstdio>
#include<iostream>
#include<algorithm>
#define INF 999999

using namespace std;

int main()
{
    int n,e,t,m,a,b,c;
    int x[105][105];

    scanf("%d %d %d %d", &n,&e, &t, &m);

    while(m--)
    {
        scanf("%d %d %d", &a, &b, &c);
        x[a][b]=c;
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
            if(!x[i][j] && i!=j)
                x[i][j]=INF;
    }

    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
                x[i][j]=min(x[i][j],x[i][k]+x[k][j]);
        }
    }

    int k=0;

    for(int i=1; i<=n; i++)
        if(x[i][e]<=t)
            k++;

    printf("%d\n", k);


    return 0;
}
