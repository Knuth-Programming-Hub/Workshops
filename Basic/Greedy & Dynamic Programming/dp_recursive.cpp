#include<bits/stdc++.h>

using namespace std;

vector<int> height,dp;

int rec(int ind)
{
    // base cases
    if(ind==1)
        return 0;

    if(ind==2)
        return abs(height[2]-height[1]);

    // we have already computed dp[ind]
    if(dp[ind]!=-1)
        return dp[ind];

    // recurrence relation
    return dp[ind] = min(rec(ind-1) + abs(height[ind]-height[ind-1]), rec(ind-2) + abs(height[ind]-height[ind-2]));
}

int main()
{
    int n;
    cin>>n;

    height.resize(n+1);
    for(int i=1;i<=n;++i)
        cin>>height[i];

    dp.assign(n+1,-1);

    int ans=rec(n);
    cout<<ans;

    return 0;
}
