#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string before;
    string after;
    string str;
    while(cin>>before){
        if(before[0]=='*'){
            return 0;
        }
        cin>>after>>str;
        while(str.find(before)!=string::npos){
            str.replace(str.find(before),before.length(),after);
        }
        cout<<str<<endl;
    }
    return 0;
}
