class Solution {
public:
    bool isPalindrome(string s)
    {
        int left = 0;
        int right = static_cast<int>(s.size()) - 1;

        while (left < right)
        {
            // 跳过非字母数字
            while (left < right &&
                !std::isalnum(s[left]))
            {
                ++left;
            }

            while (left < right &&
                !std::isalnum(s[right]))
            {
                --right;
            }

            // 忽略大小写比较
            if (std::tolower(s[left]) !=
                std::tolower(s[right]))
            {
                return false;
            }

            ++left;
            --right;
        }

        return true;
    }
};
