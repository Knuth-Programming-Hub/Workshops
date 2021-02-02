#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<int> height(n+1);
    for(int i=1;i<=n;++i)
        cin>>height[i];

    vector<int> dp(n+1);

    // dp[i] -> min. cost incurred to reach stone 'i'
    // state: index of the stone
    // transitions: from i to i-1 and i-2

    // base cases
    dp[1] = 0;
    dp[2] = abs(height[2]-height[1]);

    // iteration
    for(int i=3;i<=n;++i)
        dp[i] = min(dp[i-1] + abs(height[i]-height[i-1]), dp[i-2] + abs(height[i]-height[i-2]));    // recurrence relation

    cout<<dp[n];

    return 0;
}
