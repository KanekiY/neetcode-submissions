public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        //int[] test = new int[2];
        Dictionary<int,int> map = new();
        for (int i = 0; i < nums.Length; i++)
        {
            int need = target - nums[i];

            if (map.TryGetValue(need, out int value))
            {
                return new int[]{ value, i };
            }

            map[nums[i]] = i;
        }
        return new int[0]; //Array.Empty<int>();
    }
}
