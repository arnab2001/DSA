//https://www.hackerrank.com/challenges/non-divisible-subset/problem?isFullScreen=false

#include <bits/stdc++.h>
using namespace std;

typedef vector<int> v;

int main() {
    int n, k;
    cin >> n >> k;
    v a(n);
    v c(k);
    for (int i=0; i<n; ++i) {
        cin >> a[i];
        ++c[a[i] % k];
    }

    int res = min(1, c[0]);

    for (int i=1; 2*i<k; ++i) 
        res += max(c[i], c[k-i]);
    
    if (k%2 == 0) res += min(1, c[k/2]);
    cout << res << endl;
    return 0;
}