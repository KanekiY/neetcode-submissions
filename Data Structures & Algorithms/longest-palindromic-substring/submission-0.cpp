class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length() ==1)
        {
            return s;
        }
        int start = 0;
        int maxLength = 0;

        for(int i = 0; i<s.length(); i++)
        {
            expand(s,i,i,start,maxLength);
            expand(s,i,i+1,start,maxLength);
        }
        return s.substr(start, maxLength);
    }

    void expand(string& s, int left, int right, int& start, int& maxLength )
    {
        while(left >=0 && right <=s.length()-1 && s[left]== s[right])
        {
            left--;
            right++;
        }
        int length = right - left -1;
        if(length >maxLength)
        {
            maxLength = length;
            start = left+1;
        }
    }
};
