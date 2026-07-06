public class KthLargest {
int k;
PriorityQueue<int,int> minHeap = new ();

public KthLargest(int k, int[] nums) {
   
  // PriorityQueue<int,int> minHeap = new PriorityQueue<int,int> ();
    this.k = k;

    foreach (int num in nums) {
        Add(num);
    }
}

public int Add(int val) {
    minHeap.Enqueue(val, val);// 注意这里是两个value

    if (minHeap.Count > k) {
        minHeap.Dequeue();
    }

    return minHeap.Peek();
}

}
