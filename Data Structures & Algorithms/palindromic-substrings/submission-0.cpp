class Solution {
public:
    int countSubstrings(string s) {
        int start = 0;
        int maxLength = 0;
        int count = 0;
        for(int i = 0; i<s.length(); i++)
        {
            expand(s,i,i,start,maxLength, count);
            expand(s,i,i+1,start,maxLength, count);
        }
        return count;
    }

    void expand(string& s, int left, int right, int& start, int& maxLength, int& count )
    {
        while(left >=0 && right <=s.length()-1 && s[left]== s[right])
        {
            left--;
            right++;
            count++;
        }
        int length = right - left -1;
        if(length >maxLength)
        {
            maxLength = length;
            start = left+1;
        }
    }
};
