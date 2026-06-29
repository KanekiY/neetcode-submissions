public class Solution {
    public bool IsValid(string s) {
        Stack<char> parent = new Stack<char>();
        foreach(var c in s)
        {
            if(c == '(')
            {
                parent.Push(')');
                continue;
            }
            else if(c == '{')
            {
                 parent.Push('}');
                 continue;
            }
            else if( c == '[')
            {
                 parent.Push(']');
                 continue;
            }

            if (parent.Count == 0)
            {
                return false;
            }
            if(parent.Peek() != c)
            {
                return false;
            }else
            {
                parent.Pop();
            }

        }
        return parent.Count == 0;
        
    }
}
