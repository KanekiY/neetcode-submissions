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
    public List<List<int>> LevelOrder(TreeNode root) {
        List<List<int>> result = new();
        Queue<TreeNode> queue = new();
        queue.Enqueue(root);
        while(queue.Count > 0)
        {
            int nodeNumOfLevel = queue.Count;
            List<int> nodes = new ();
            for(int i =0; i<nodeNumOfLevel;i++)
            {
                TreeNode node = queue.Dequeue();
                if(node == null) continue;
                nodes.Add(node.val);
                queue.Enqueue(node.left);
                queue.Enqueue(node.right);
            }
            if(nodes.Count > 0) result.Add(nodes);
        }
        return result;
    }
}
