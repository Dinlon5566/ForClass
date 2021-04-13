#include <iostream>

using namespace std;

int main()
{
    int num,ans,def;
    cin>>num;
    while(num--)
    {
        int k;
        cin>>k;
        ans=1;
        def=2;
        for(int i=1; i<k; i++)
        {

            ans+=def;
            if(i%2)
            {
                def+=2;
            }

        }
        if(k==1)
        {
            ans=1;
        }
        cout<<ans<<endl;
    }
    return 0;
}
