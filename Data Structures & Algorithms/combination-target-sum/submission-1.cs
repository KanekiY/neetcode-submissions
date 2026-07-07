public class Solution {

    public List<List<int>> allResults = new();
    public List<List<int>> CombinationSum(int[] nums, int target) {
        Array.Sort(nums);
       List<int> result = new();
       dfs(nums,target,result,0);
       return this.allResults;
     
    }
    void dfs(int[] nums, int target, List<int> result, int index )
    {
        if(target == 0)
        {
            this.allResults.Add(new List<int>(result));
        }
        if(target < 0 || index > nums.Length-1)
        {
            return;
        }

        for(int i = index; i< nums.Length;i++)
        {
            if(nums[i]<=target)
            {
                result.Add(nums[i]);
                dfs(nums, target - nums[i], result,i);
                result.RemoveAt(result.Count-1);
            }
        }
    }
}
