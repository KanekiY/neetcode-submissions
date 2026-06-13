class Solution {
public:
int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> lastIndex;

    int left = 0;
    int maxLen = 0;

    for (int right = 0; right < s.size(); right++) {
        char c = s[right];

        if (lastIndex.count(c) && lastIndex[c] >= left) {
            left = lastIndex[c]+1;
            cout<<"left"<<left<<c<<endl;
        }

        lastIndex[c] = right;
        cout<<"right"<<right<< c<<endl;
        maxLen = max(maxLen, right - left+1);
    }

    return maxLen;
}
};
