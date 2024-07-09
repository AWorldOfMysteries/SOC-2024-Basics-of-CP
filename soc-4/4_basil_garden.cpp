#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {

    // M1 - Brute force
    // TC : O(n*max(hi)) ~ 10^14

    // int n; cin >> n;

    // vector<int> h(n);
    // for(int i=0; i<n; i++)
    //     cin >> h[i];

    // bool isAllZero = false;
    // int cnt = 0;

    // while(!isAllZero){
    //     for(int i=0; i<n; i++){
    //         if(i == n-1){
    //             h[i] = max(0LL, h[i]-1);
    //         }
    //         else if(h[i] > h[i+1]){
    //             h[i] = max(0LL, h[i]-1);
    //         }
    //         else{
    //             // nothing
    //         }
    //     }
    //     cnt++;

    //     isAllZero = true;
    //     for(int i=0; i<n; i++){
    //         if(h[i] != 0){
    //             isAllZero = false;
    //             break;
    //         }
    //     }
    // }

    // cout << cnt << endl;

    //-----------------------------------------------

    // M2 : Building from right - Tabulation
    // TC : O(n)

    int n; cin >> n;

    vector<int> h(n);
    for(int i=0; i<n; i++)
        cin >> h[i];

    vector<int> t(n);
    int ans = INT_MIN;
    for(int i=n-1; i>=0; i--){
        if(i == n-1)
            t[i] = h[i];
        else{
            int prevTime = t[i+1];
            int prevHeight = h[i+1];
            int currHeight = h[i];
            int waitingTime = prevTime - prevHeight;

            if(currHeight <= prevHeight){
                int diff = prevHeight - currHeight;
                t[i] = waitingTime + diff + 1 + currHeight;
            }
            else{
                int diff = currHeight - prevHeight;
                if(diff <= waitingTime)
                    t[i] = waitingTime + 1 + prevHeight;
                else
                    t[i] = currHeight;
            }
        }
        ans = max(ans, t[i]);
    }

    cout << ans << endl;

    //-----------------------------------------------

    // M3 - Recursion
    // ?
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