#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int r, c;
    cin >> r >> c;
    int start, end;

    if(r > c){
        int diag = r*r-r+1;
        int diff = r - c;
        cout << (r%2==0 ? diag + diff : diag - diff) << endl;
    }
    else if(r < c){
        int diag = c*c-c+1;
        int diff = c - r;
        cout << (c%2==0 ? diag - diff : diag + diff) << endl;
    }
    else{
        cout << r*r-r+1 << endl; 
    }
}
    
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}