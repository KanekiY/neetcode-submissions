class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto compareFn = [](vector<int> const& i_a,vector<int> const& i_b )->bool
        {

            return i_a[0]*i_a[0] + i_a[1]*i_a[1] < i_b[0]*i_b[0] + i_b[1]*i_b[1] ;
        };
        std::priority_queue<vector<int>,vector<vector<int>>, decltype(compareFn)> maxHeap;

        for(auto& point: points)
        {
            maxHeap.push(point);
            if(maxHeap.size()> k)
            {
                maxHeap.pop();
            }
        }

         vector<vector<int>> result(k);
         for(auto& data : result)
         {
            data =  maxHeap.top();
            maxHeap.pop();
         }
         return result;
    }
};
