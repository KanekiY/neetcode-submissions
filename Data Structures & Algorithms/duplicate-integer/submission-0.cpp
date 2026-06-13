class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> numberMap;
       for(int num: nums)
       {
            if(numberMap.contains(num))
            {
                return true;
            }else
            {
                numberMap.insert(num);
            }

       } 
       return false;
    }
};