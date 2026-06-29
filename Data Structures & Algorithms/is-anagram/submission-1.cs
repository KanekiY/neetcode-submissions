public class Solution {
    public bool IsAnagram(string s, string t) {
        Dictionary<char, int> dict = new Dictionary<char, int>();
        foreach(char c in s )
        {
            if(dict.TryGetValue(c, out var value))
            {
               dict[c] = ++value; 
            }else
            {
                dict[c] = 1;
            }
        }

        foreach (var c in t)
        {
            if(dict.TryGetValue(c, out var value))
            {
               --value;
               if(value == 0)
               {
                dict.Remove(c);
               }else
               {
                dict[c] = value;
               }
            }else
            {
                return false;
            }
        }
        return dict.Count == 0;
    }
}
