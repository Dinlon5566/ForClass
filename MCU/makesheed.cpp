#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string sheet="";
    vector<double> notespeed;
    char tmp;
    double sp;
    while(cin>>tmp&&tmp!='0'){
        sheet+=tmp;
        cin>>sp;
        notespeed.push_back(sp);

    }
    cout<<sheet<<endl;
    for(double n:notespeed){
        cout<<n<<",";
    }
    return 0;
}
