class Solution {
public:

    // M1 : Recursion - Top Down

    // int solve(vector<int> &cost, int k){
        
    //     if(k == 0 || k == 1){
    //         return cost[k];
    //     }

    //     return min(solve(cost, k-1), solve(cost, k-2)) + cost[k];
    // }

    // int minCostClimbingStairs(vector<int>& cost){
    //     int n = cost.size();
    //     return min(solve(cost, n-1), solve(cost, n-2));
    // }

    //------------------------------------------------

    // M2 : Recursion + Memoization
    // TC : O(N)
    // SC : O(N)+O(N)

    // int solve(vector<int> &cost, int k, vector<int> &dp){
        
    //     if(k == 0 || k == 1){
    //         return cost[k];
    //     }

    //     if(dp[k] != -1)
    //         return dp[k];

    //     dp[k] = min(solve(cost, k-1, dp), solve(cost, k-2, dp)) + cost[k];
    //     return dp[k];
    // }

    // int minCostClimbingStairs(vector<int>& cost){
    //     int n = cost.size();
    //     vector<int> dp(n+1, -1);
    //     return min(solve(cost, n-1, dp), solve(cost, n-2, dp));
    // }

    //------------------------------------------------

    // M3 : Tabulation
    // TC : O(N)
    // SC : O(N)

    // int solve(vector<int> &cost, int n){

    //     vector<int> dp(n+1);

    //     dp[0] = cost[0];
    //     dp[1] = cost[1];

    //     for(int i=2; i<n; i++){
    //         dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
    //     }

    //     return min(dp[n-1], dp[n-2]);
    // }

    // int minCostClimbingStairs(vector<int>& cost){
    //     int n = cost.size();
    //     return solve(cost, n);
    // }

    //------------------------------------------------

    // M4 : Tabulation + Space Optimization
    // TC : O(N)
    // SC : O(1)

    int solve(vector<int> &cost, int n){

        int prev2 = cost[0];
        int prev1 = cost[1];

        for(int i=2; i<n; i++){
            int curr = cost[i] + min(prev1, prev2);
            prev2 = prev1;
            prev1 = curr;
        }

        return min(prev1, prev2);
    }

    int minCostClimbingStairs(vector<int>& cost){
        int n = cost.size();
        return solve(cost, n);
    }
};