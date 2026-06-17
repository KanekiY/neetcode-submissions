class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int minResult = INT_MAX;
        dfs(coins, amount, coins.size()-1,0, minResult);
        return minResult == INT_MAX? -1 : minResult;
    }

    void dfs(vector<int>& coins, int amount, int index, int count, int& minResult )
    {   if(index < 0 ) return;
        if(amount == 0 ) 
        {
            minResult = min(count,minResult);
            return;
        }
  
        count++;

        for(int i = index; i>=0; i--)
        {
            int remain = amount - coins[i];
            if(remain >=0)
            {
                dfs(coins, remain,i,count,minResult);
            }
        }
        count--;
    }
};
