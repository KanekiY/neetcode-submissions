class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(t.size()< s.size())
        {
            return false;
        }
        
        int left = 0;
        int right = 0;

        while(right <= t.size()-1 && left <= s.size()-1)
        {
            if(s[left] == t[right])
            {
                left++;
            }
            right++;
        }
        return left >= s.size();
    }
};