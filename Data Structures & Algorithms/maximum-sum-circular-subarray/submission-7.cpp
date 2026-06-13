class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int maxSum = nums[0];

        for (int start = 0; start < n; start++)
        {
            int currentSum = 0;

            for (int length = 1; length <= n; length++)
            {
                int index = (start + length - 1) % n;

                currentSum += nums[index];
                maxSum = std::max(maxSum, currentSum);
            }
        }

        return maxSum;
        /*
        int totalSum = 0;

        int currentMax = 0;
        int maxSum = nums[0];

        int currentMin = 0;
        int minSum = nums[0];

        for (int num : nums)
        {
            totalSum += num;

            currentMax = std::max(num, currentMax + num);
            maxSum = std::max(maxSum, currentMax);

            currentMin = std::min(num, currentMin + num);
            minSum = std::min(minSum, currentMin);
        }

        // 全是负数的情况
        if (maxSum < 0)
            return maxSum;

        return std::max(maxSum, totalSum - minSum);
        */
        /*
        if(nums.empty())
        {
            return 0;
        }
        int maxSum = nums[0];
        int currentSum = nums[0];
        int left = 0;
        int right = 1;
        if(nums.size() > 1)
        {
            while(left!=right && left<nums.size())
            {

                if(currentSum + nums[right]< nums[right])
                {
                    currentSum = nums[right];
                    if(left > right)
                    {
                        return maxSum;
                    }
                    else
                    {
                        left = right;
                    }
                }else
                {
                       currentSum += nums[right];
                }

             
                if(right < nums.size()-1)
                {
                    right++;
                }
                else
                {
                    right = 0;
                    if(left == 0)
                    {
                        currentSum-= nums[left];
                        left++;
                    }
                }    
                maxSum = std::max(maxSum, currentSum);
            }
        }
        return maxSum;
        */
    }
};