class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        if (s[n - 1] == '1') return false;

        vector<bool> dp(n, false);
        dp[0] = true;
        int prefixSum = 0; // count of reachable indices so far

        for (int j = 1; j < n; j++) {
            if (j >= minJump) prefixSum += dp[j - minJump];
            if (j > maxJump) prefixSum -= dp[j - maxJump - 1];

            if (s[j] == '0' && prefixSum > 0)
                dp[j] = true;
        }

        return dp[n - 1];
    }
};