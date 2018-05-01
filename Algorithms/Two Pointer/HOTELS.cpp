#include<cstdio>

long long int max(long long int x, long long int y)
{
    if(x>y) return x;
    return y;
}

int main()
{
    long long int m,n,a[1000001];
    long long int l,r,sum,ans;

    l=r=sum=ans=0;

    scanf("%lld %lld", &n,&m);

    for(int i=0; i<n; i++)
        scanf("%lld", &a[i]);

    while(l<n)
    {
        while(r<n&&(sum+a[r]<=m))
        {
            sum+=a[r];
            r++;
        }
        ans=max(sum,ans);
        sum-=a[l];
        l++;
    }

    printf("%lld\n", ans);


    return 0;
}
