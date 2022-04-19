#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> spiltNum(string str)
{
    vector<int> res;
    int t=0;
    for(char c:str)
    {
        if(c==' ')
        {
            res.push_back(t);
            t=0;
            continue;
        }
        t*=10;
        t+=c-'0';
    }
    if(t!=0)
    {
        res.push_back(t);
    }
    return res;
}
int main()
{
    int cas;
    vector<int> numarr;
    string str;
    getline(cin,str);
    numarr=spiltNum(str);
    cas=numarr[0];
    while(cas--)
    {
        getline(cin,str);   //void
        getline(cin,str);
        numarr=spiltNum(str);
        int w=numarr[0];
        int n=numarr[1];
        int cmap[w][n];
        memset(cmap,0,sizeof(cmap));
        for(int i=0; i<w; i++)
        {
            getline(cin,str);
            numarr=spiltNum(str);
            for(int j=1; j<numarr.size(); j++)
            {
                cmap[i][numarr[j]-1]=-1;
            }
        }

        for(int i=0; i<n; i++)
        {
            if(cmap[0][i]>=0)
            {
                cmap[0][i]=1;
            }
            else
            {
                break;
            }
        }
        for(int i=0; i<w; i++)
        {
            if(cmap[i][0]>=0)
            {
                cmap[i][0]=1;
            }
            else
            {
                break;
            }
        }

        for(int i=1; i<w; i++)
        {
            for(int j=1; j<n; j++)
            {
                if(cmap[i][j]>=0)
                {
                    int a=cmap[i-1][j];
                    int b=cmap[i][j-1];
                    a=a>0?a:0;
                    b=b>0?b:0;
                    cmap[i][j]=a+b;
                }
            }
        }
        /*
        //Draw map
        for(int i=0;i<w;i++){
            for(int j=0;j<n;j++){
                cout<<cmap[i][j]<<" ";
            }
            cout<<endl;
        }*/
        cout<<cmap[w-1][n-1]<<endl;

    }

    return 0;
}
