class Solution {
public:
    int rob(vector<int>& nums) {
        
        if(nums.size() == 1)
        {
            return nums[0];
        }
        if(nums.size() == 2)
        {
            return max(nums[0],nums[1]);
        }

        auto fnLinearRob = [&nums](int start, int end )
        {
            vector<int> dp(end - start + 1);
            dp[0] =nums[start];
            dp[1] =max(nums[start],nums[start+1]);

            for(int i = 2; i<=(end-start); i++)
            {
                dp[i] = max(dp[i - 1], nums[start+i] + dp[i - 2]);
            }

            
            return dp[end-start];
        };
        return max(fnLinearRob(0,nums.size()-2),fnLinearRob(1,nums.size()-1));

    }
};
