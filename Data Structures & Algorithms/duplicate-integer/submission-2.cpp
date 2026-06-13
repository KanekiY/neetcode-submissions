class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> numberMap;
       for(int num: nums)
       {
            if (!numberMap.insert(num).second)
            {
                return true;
            }

       } 
       return false;
    }
};