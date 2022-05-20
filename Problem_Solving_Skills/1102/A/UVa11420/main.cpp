#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//i : L ; i+1 : U ->s2  -P1
//    N  lock  0L1U
/*
long long int dp[75][75][2];
void makeDp(){
    memset(dp,0,sizeof(dp));

    dp[1][0][0]=1;//1B0L->0
    //dp[1][0][1]=0;
    dp[1][1][1]=1;
    for(int i=2;i<70;i++){
        dp[i][0][0]=dp[i-1][0][0]+dp[i-1][1][1];//P1
        for(int j=1;j<=i;j++){
            dp[i][j][0]=dp[i-1][j][0]+dp[i-1][j+1][1];
            dp[i][j][1]=dp[i-1][j-1][0]+dp[i-1][j-1][1];
        }
    }

}*/
int main()
{
    int n,s;
    //makeDp();
    long long int dp[75][75][2];
    memset(dp,0,sizeof(dp));

    dp[1][0][0]=1;//1B0L->0
    //dp[1][0][1]=0;
    dp[1][1][1]=1;
    for(int i=2;i<70;i++){
        dp[i][0][0]=dp[i-1][0][0]+dp[i-1][1][1];//P1
        for(int j=1;j<=i;j++){
            dp[i][j][0]=dp[i-1][j][0]+dp[i-1][j+1][1];
            dp[i][j][1]=dp[i-1][j-1][0]+dp[i-1][j-1][1];
        }
    }

    while(cin>>n>>s){
        if(n<0||s<0){
            break;
        }
        //int res=dp[n][s][0]+dp[n][s][1];
        cout<<dp[n][s][0]+dp[n][s][1]<<endl;
    }
    return 0;
}
