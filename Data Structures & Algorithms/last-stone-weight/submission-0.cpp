class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        std::priority_queue<int, vector<int>, less<int>> maxHeap;

        for(int stone: stones)
        {
            maxHeap.push(stone);
        }

        while(maxHeap.size() >1)
        {
             int largest = maxHeap.top();
             maxHeap.pop();
             int secondeLargest = maxHeap.top();
            maxHeap.pop();
            maxHeap.push(largest - secondeLargest);
        }

    return maxHeap.top();
    }
};
