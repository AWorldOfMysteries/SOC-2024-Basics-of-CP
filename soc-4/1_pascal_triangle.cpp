class Solution {
public:

    // M1 - Recursion
    // TC : O(n^2)
    // SC : O(n) + O(n)

    void solve(vector<vector<int>> &ans, int n){
        if(n == 1){
            ans.push_back({1});
            return;
        }   
        if(n == 2){
            ans.push_back({1});
            ans.push_back({1, 1});
            return;
        }
        
        solve(ans, n-1);
        
        vector<int> row;
        row.push_back(1);
        for(int i=1; i<=n-2; i++){
            row.push_back(ans[n-2][i-1] + ans[n-2][i]);
        }
        row.push_back(1);

        ans.push_back(row);

    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        solve(ans, numRows);
        return ans;
    }

    //---------------------------------------------------

    // M2 - Tabulation
    // ?

};