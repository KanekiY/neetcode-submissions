public class Solution {
    public bool hasDuplicate(int[] nums) {
        HashSet<int> dict = new HashSet<int>();
        foreach(var num in nums)
        {
            if(!dict.Contains(num))
            {
                dict.Add(num);
            }else
            {
                return true;
            }
        }

        return false;

    }
}