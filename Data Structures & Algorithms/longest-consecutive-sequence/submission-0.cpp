class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> set(nums.begin(), nums.end());

        int best = 0;

        for (int num : set)
        {
            // only start counting from the beginning of a sequence
            if (!set.contains(num - 1))
            {
                int current = num;
                int length = 1;

                while (set.contains(current + 1))
                {
                    current++;
                    length++;
                }

                best = std::max(best, length);
            }
        }

        return best;
    }
};
