class Solution {
public:
    int characterReplacement(string s, int k) {
     std::vector<int> count(26, 0);
     
    int l = 0;
    int maxCount = 0;
    int result = 0;

    for (int r = 0; r < s.size(); ++r) {
        count[s[r] - 'A']++;
        
        maxCount = std::max(maxCount, count[s[r] - 'A']);

        // 如果不合法，收缩窗口
        while ((r - l + 1) - maxCount > k) {
            count[s[l] - 'A']--;
            l++;
        }

        result = std::max(result, r - l + 1);
    }

    return result;
    }
};
