class Solution {
public:
    int helper(int i, string s, vector<int> &dp){
        if(s[i] == '0') return 0;
        if(i == s.size()) return 1;
        if(dp[i] != -1) return dp[i];

        int sum = 0;
        sum += helper(i+1, s, dp);
        if( (s[i] == '1' && (s[i+1] >= '0' && s[i+1] <= '9')) ||
            (s[i] == '2' && (s[i+1] >= '0' && s[i+1] <= '6'))
          ){
            sum +=  helper(i+2, s, dp);
        }

        dp[i] = sum;
        return dp[i];

    }
    int numDecodings(string s) {
        if(s.size() == 0) return 0;
        int i = 0;
        int n = s.size() - 1;
        vector<int> dp(n+1, -1);
        return helper(i, s, dp);
    }
};