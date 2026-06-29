/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

public class Solution {
    public bool IsSameTree(TreeNode nodeP, TreeNode nodeQ) {
        Queue<(TreeNode, TreeNode)> queue = new();
        queue.Enqueue((nodeP,nodeQ));
        while(queue.Count > 0)
        {
            var (p, q) = queue.Dequeue();
            if(p == null && q == null )
            {
                continue;
            }

            if((p == null && q != null) || (p != null && q == null ) )
            {
                return false;
            }

            if(p.val != q.val)
            {
                return false;
            }
              queue.Enqueue((p.left,q.left));
              queue.Enqueue((p.right,q.right));
        }
        return true;
    }
}
