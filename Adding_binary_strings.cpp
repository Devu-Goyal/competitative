#include <bits/stdc++.h>
#define ll long long int

using namespace std;

// 1110
//  111 
// adding in this fashion where last index must be filled

string add(string &a,string &b){
    // reverse(a.begin(), a.end());
    // reverse(b.begin(), b.end());
   
    int mini=min(a.size(), b.size());
    int c=0;
    string ans="",s;
    int i;
    
    for(i=0;i<mini;i++){
        int x=a[i]-48;
        int y=b[i]-48;
        int z=x+y+c;
        
        if(z>1)
            c=1;
        ans+=to_string(z%2);
    }
    
    if(a.size()>b.size())
        s=a;
    else
        s=b;
    
    for(int j=i;j<s.size();j++){
        int x=s[i]-48;
        int z=x+c;
        
        if(z>1)
            c=1;
        ans+=to_string(z%2);
    }
    
    if(c)
        ans+="1";
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    int a,b,i;
    cin >> a >> b;
    string sa="", sb="";
    while(a){
        sa+=to_string(a%2);
        a/=2;
    }
    while(b){
        sb+=to_string(b%2);
        b/=2;
    }
    
    cout << add(sa, sb);
    
}