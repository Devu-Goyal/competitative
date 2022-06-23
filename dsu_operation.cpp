#include <bits/stdc++.h>

using namespace std;

vector<int>par;

int find(int x){
    if(x!=par[x])
        par[x]=find(par[x]);
    return par[x];
}

void merge(int x, int y){
    x=find(x);
    y=find(y);

    if(x!=y)
        par[max(x, y)] = min(x, y);
}

int main()
{
    int n,i,m,x,y;
    cin >> n >> m; // n nodes and m edges
    par.resize(n+1);
    for(i=1;i<=n;i++){
        par[i]=i;
    }

    // edge input
    while(m--){
        cin >> x >> y;
        merge(x, y);
    }
    for(i=1;i<=n;i++){
        cout << i << " -> " << par[i] << "\n";
    }
    set<int>st;
    for(i=1;i<=n;i++){
        int k=st.size();
        st.insert(find(i));
        if(k<st.size())
            merge(i, 1);
    }
    cout << "----------------------------\n";
    for(i=1;i<=n;i++){
        cout << i << " -> " << par[i] << "\n";
    }
    cout << st.size();
}
// Input :
// 10
// 8
// 1 2
// 1 3
// 2 3
// 5 4
// 5 8
// 5 6
// 6 8
// 9 10
