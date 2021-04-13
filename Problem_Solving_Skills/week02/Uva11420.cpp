#include <iostream>

using namespace std;

int main()
{
    int l,n,maxn=70;
    int dp[maxn][maxn][2]= {0};
    dp[1][0][0]=1;
    dp[1][1][1]=1;
    for(int i=2; i<maxn; i++)
    {
        dp[i][0][0]=dp[i-1][1][1]+dp[i-1][0][0];
        for(int j=1; j<=i; j++)
        {
            dp[i][j][0]=dp[i-1][j+1][1]+dp[i-1][j][0];
            dp[i][j][1]=dp[i-1][j-1][1]+dp[i-1][j-1][0];
        }
    }
    while(1)
    {
        cin>>l>>n;
        if((l+n)<=0)
        {
            break;
        }
        cout<<dp[l][n][1]+dp[l][n][0]<<endl;
    }
    return 0;
}
