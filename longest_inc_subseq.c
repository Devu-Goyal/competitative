#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007

using namespace std;

int binary_search(vector<int>& height, vector<int>& s, int first, int last, int x) {

    while(last > first)
    {
        int mid = first + (last - first) / 2;
        if(height[s[mid]] > x)
            last = mid;
        else
            first = mid + 1;
    }

    return first; /* or last */
}

int longest_increasing_subsequence_nlgn(vector<int>& height, int n) {

    int i, k, index;
    vector<int>s(500000, 0);

    //memset(s, 0, sizeof(s));

    index = 1;
    s[1] = 0; /* s[i] = 0 is the index of the element that ends an increasing sequence of length  i = 1 */

    for (i = 1; i < n; i++) {

        if (height[i] >= height[s[index]]) { /* larger element, extend the sequence */

            index++; /* increase the length of my subsequence */
            s[index] = i; /* the current doll ends my subsequence */

        }
        /* else find the smallest element in s >= a[i], basically insert a[i] in s such that s stays sorted */
        else {
            k = binary_search(height, s, 1, index, height[i]);

            if (height[s[k]] >= height[i]) { /* if truly >= greater */
                s[k] = i;
            }
        }
    }
    return index;
}


int main()
{
    int t=1;
    cin >>t;
    while(t--){
        int n,m,i,j,f=0,k,maxi=0;
        cin >> n;
        vector<int>a(n);

        for(i=0;i<n;i++){
            cin >> a[i];

        }

        int sz=longest_increasing_subsequence_nlgn(a, n);
        cout << sz << "\n";



    }
}
