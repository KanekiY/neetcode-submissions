class Solution {
public:
    int maxArea(const vector<int>& heights)
    {
        int left = 0;
        int right = static_cast<int>(heights.size()) - 1;

        int maxArea = 0;

        while (left < right)
        {
            int width = right - left;
            int height = min(heights[left], heights[right]);
            int area = width * height;

            maxArea = max(maxArea, area);

            if (heights[left] < heights[right])
            {
                ++left;
            }
            else
            {
                --right;
            }
        }

        return maxArea;
    }
};
