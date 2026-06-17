class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        
        while(left< right)// 注意<= 
        {   int mid = left + (right - left)/2;
            if(nums[mid] == target) return mid;

            if(nums[right]> nums[mid])
            {
               if(nums[right]>=target && target> nums[mid]) // 注意左闭右开
               {
                    left = mid+1; // 一定要+1不然有edge case不移动
               }else
               {
                    right = mid; // 一定要-1，不然有edge case不移动
               }
            }
            else
            {
                if(nums[left]<= target && target< nums[mid])
                {
                        right = mid; // 一定要-1，不然有edge case不移动
                }else
                {
                        left = mid+1;  // 一定要+1不然有edge case不移动
                }
            }
            
        }

        return nums[left] == target ? left : -1;
    }
};
