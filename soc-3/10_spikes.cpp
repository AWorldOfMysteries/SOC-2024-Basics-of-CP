// Can be done through BFS as well

#include <bits/stdc++.h>

using namespace std;

#define int long long
#define inp(v, n) for(int i = 0; i < n; i++) {cin >> v[i];}

// M1 : DFS

bool dfs(vector<string> v, int n, int m, int r, int c, int cnt, int j, vector<vector<bool>>& visited){
    // base case
    if(v[r][c] == 'x'){
        return (2*cnt <= j);
    }

    visited[r][c] = true;
    if(v[r][c] == 's')
        cnt++;

    // right
    if(c+1 < m && v[r][c+1] != '#' && !visited[r][c+1]){
        bool ans = dfs(v, n, m, r, c+1, cnt, j, visited);
        if(ans)
            return true;
    }

    // left
    if(c-1 >= 0 && v[r][c-1] != '#' && !visited[r][c-1]){
        bool ans = dfs(v, n, m, r, c-1, cnt, j, visited);
        if(ans)
            return true;
    }

    // up
    if(r-1 >= 0 && v[r-1][c] != '#' && !visited[r-1][c]){
        bool ans = dfs(v, n, m, r-1, c, cnt, j, visited);
        if(ans)
            return true;
    }

    // down
    if(r+1 < n && v[r+1][c] != '#' && !visited[r+1][c]){
        bool ans = dfs(v, n, m, r+1, c, cnt, j, visited);
        if(ans)
            return true;
    }
    
    return false;
}

void solve() {
    int n, m, j;
    cin >> n >> m >> j;

    vector<string> v(n);
    for(int r=0; r<n; r++){
        cin >> v[r];
    }

    // # walls
    // x tre
    // @ ent/exit
    // . path
    // s spikes

    for(int r=0; r<n; r++){
        for(int c=0; c<m; c++){
            if(v[r][c] == '@'){
                vector<vector<bool>> visited(n, vector<bool> (m, 0));
                bool ans = dfs(v, n, m, r, c, 0, j, visited);
                if(ans){
                    cout << "SUCCESS" << endl;
                    return;
                }                            
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;
    return;
}

    
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}