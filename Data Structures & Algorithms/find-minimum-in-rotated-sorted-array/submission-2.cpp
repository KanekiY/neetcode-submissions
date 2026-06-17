class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0;
        int right = nums.size()-1;
        int mid = left + (right - left)/2;

        while(left< right)
        {
            if(nums[right]< nums[mid])// left unorded
            {
                left = mid+1; // 因为我们在找最小值， mid可能是最小值(nums[right]< nums[mid])，所以right = mid
                mid = left + (right - left)/2;
              
            }else //if(nums[right]< nums[mid])
            {
                right = mid;// 因为我们在找最小值，所以 mid肯定不是最小值(nums[right]< nums[mid])，所以mid+1
                mid = left + (right - left)/2;
            }
            
        }

        return nums[left];
    }
};
