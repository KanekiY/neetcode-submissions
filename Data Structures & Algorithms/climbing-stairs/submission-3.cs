public class Solution {
    public int ClimbStairs(int n) {
        int[] memo = new int[n+1];
        Array.Fill(memo, int.MaxValue);    
        return dfs(n, memo);
    }

    private int dfs(int n, int[] memo)
    {
        if(n == 1) return 1;
        if(n == 2) return 2;
        if(memo[n] != int.MaxValue) return memo[n];
        memo[n-1] = dfs(n-1, memo);
        memo[n-2] = dfs(n-2, memo);
        return  memo[n-1] +   memo[n-2];

    }
}
