#include <iostream>

using namespace std;
int onfeet(int num)
{
    if(num<=1)
    {
        return 0;
    }
    else
    {
        return (num-1)+onfeet(num-1);
    }
}
int another(int n)
{
    //this is teacher's anser.
    int m;
    if (n%2==0)
    {
        m=(n/2)*(n/2-1);
    }
    else
    {
        m=(n-1)*(n-1)/4;
    }
    return m;
}
int main()
{
    int t;
    cin>>t;
    int ans;
    while(t--)
    {
        int num;
        cin>>num;
        cout<<"real: "<<another(num)<<endl;
        if(num>3)
        {
            int p=num/2;
            num-=p;
            ans=onfeet(num)+onfeet(p);
        }
        else if(num==2)
        {
            ans=1;
        }
        else
        {
            ans=3;
        }
        cout<<"myed: "<<ans<<endl;
    }

    return 0;
}
