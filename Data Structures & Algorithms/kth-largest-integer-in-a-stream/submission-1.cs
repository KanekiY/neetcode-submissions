public class KthLargest {
int k;
PriorityQueue<int,int> minHeap;

public KthLargest(int k, int[] nums) {
   
    this.minHeap = new ();
    this.k = k;

    foreach (int num in nums) {
        Add(num);
    }
}

public int Add(int val) {
    minHeap.Enqueue(val, val);

    if (minHeap.Count > k) {
        minHeap.Dequeue();
    }

    return minHeap.Peek();
}

}
