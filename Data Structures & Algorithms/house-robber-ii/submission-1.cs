public class Solution {
    public int Rob(int[] nums) {
        
        if(nums.Length == 1)
        {
            return nums[0];
        }
        if(nums.Length == 2)
        {
            return Math.Max(nums[0],nums[1]);
        }

        var fnLinearRob = (int start, int end ) =>
        {
            List<int> dp =Enumerable.Repeat(0, end - start + 1).ToList();
      
            dp[0] =nums[start];
            dp[1] =Math.Max(nums[start],nums[start+1]);

            for(int i = 2; i<=(end-start); i++)
            {
                dp[i] = Math.Max(dp[i - 1], nums[start+i] + dp[i - 2]);
            }

            
            return dp[end-start];
        };
        return Math.Max(fnLinearRob(0,nums.Length-2),fnLinearRob(1,nums.Length-1));

    }
}
