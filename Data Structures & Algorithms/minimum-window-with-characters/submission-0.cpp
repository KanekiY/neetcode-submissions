class Solution {
public:
    string minWindow(string s, string t) {
        std::unordered_map<char,int> charCount;
        std::unordered_map<char,int> target;

        int l=0;
        std::string result;
        int start = 0;
        int length = INT_MAX;
        for(char targetChar : t)
        {
            target[targetChar]++;
        }

        for(int r = 0; r <s.size();r++)
        {
            char charRight = s[r];
            charCount[charRight]++;
            int tempWindowSize = r-l+1;
            if(tempWindowSize < t.size())
            {
                continue;
            }else
            {   bool valid = true;
                for(auto const& pairValue : target)
                {
                    if (charCount[pairValue.first] < pairValue.second)
                    {
                       valid = false;
                       break;
                       
                    }

                }
                if(!valid)
                {
                    
                    continue;
                }

                if(valid && (length > tempWindowSize))
                {
                    length = tempWindowSize;
                    start = l;
                }

               //shrink left
                while(valid)
                {
                    charCount[s[l]]--;
                    l++;
                    for(auto const& pairValue : target)
                    {
                        if (charCount[pairValue.first] < pairValue.second)
                        {
                            l--;
                            charCount[s[l]]++;
                            valid = false;
                            break;
                        }
                    }
                if(valid && (length > r-l+1))
                {
                    length = r-l+1;
                    start = l;
                }
                }

            }
        }

        if(length<INT_MAX)
        {
            return s.substr(start,length);
        }

        return std::string();
    }
};
