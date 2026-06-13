class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int minPrice = INT_MAX;
        for(int price: prices)
        {
            minPrice = std::min(minPrice, price);
            maxProfit = std::max(maxProfit,price - minPrice );
        }
        return maxProfit;
    }
};
