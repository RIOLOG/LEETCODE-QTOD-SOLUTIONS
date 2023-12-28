int dp[101][27][101][101];
class Solution {
public:
    string str;
    int helpme(int i, int prev, int len, int k )
    {
        if(k<0)    return INT_MAX;
        if(i>=str.size())    return 0;
        
        if(dp[i][prev][len][k] != -1)   return dp[i][prev][len][k];
        
        int notTake = helpme(i+1,prev, len,k-1);
        
        int take = 0;
        if(str[i]-'a'==prev)
        {
            if(len==1||len==9||len==99)   take += 1;
            take = take + helpme(i+1,prev, len+1, k);
        }
        else   take= 1 + helpme(i+1, str[i]-'a', 1, k);
        
        dp[i][prev][len][k] = min(take,notTake);
        return dp[i][prev][len][k];
    }
    
    
    int getLengthOfOptimalCompression(string s, int k) 
    {
        //recursive approach
        str=s;
        memset(dp,-1,sizeof(dp));
        return helpme(0, 26, 0, k);
    }
};