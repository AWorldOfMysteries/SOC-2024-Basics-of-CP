
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define inp(v, n) for(int i = 0; i < n; i++) {cin >> v[i];}


void dfs(vector<string>& v, int n, int m, int r, int c, vector<vector<bool>>& visited, int& cnt){

    cnt++;
    visited[r][c] = 1;

    // right
    if(c+1 < m && v[r][c+1] == '#' && !visited[r][c+1]){
        dfs(v, n, m, r, c+1, visited, cnt);
    }

    // left
    if(c-1 >= 0 && v[r][c-1] == '#' && !visited[r][c-1]){
        dfs(v, n, m, r, c-1, visited, cnt);
    }

    // up
    if(r-1 >= 0 && v[r-1][c] == '#' && !visited[r-1][c])
        dfs(v, n, m, r-1, c, visited, cnt);

    // down
    if(r+1 < n && v[r+1][c] == '#' && !visited[r+1][c])
        dfs(v, n, m, r+1, c, visited, cnt);
}

int gcd(int a, int b){
    while(b){
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
    
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<string> v(n);
    for(int i=0; i<n; i++)
        cin >> v[i];

    vector<int> ans;

    vector<vector<bool>> visited(n, vector<bool> (m, 0));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!visited[i][j] && v[i][j] == '#'){
                int cnt = 0;
                dfs(v, n, m, i, j, visited, cnt);
                ans.push_back(cnt);
            }
        }
    }

    int res = 0;
    for(int i=0; i<ans.size(); i++){
        res = res + ans[i]*ans[i];
        // cout << ans[i] << endl;
    }

    int denominator = n * m;
    int numerator = res;

    if(numerator % denominator == 0){
        cout << numerator / denominator << endl;
    }
    else{
        int g = gcd(numerator, denominator);
        numerator = numerator / g;
        denominator = denominator / g;

        cout << numerator << " / " << denominator << endl; 
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