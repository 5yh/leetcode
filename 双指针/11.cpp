class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int left = 0;
        int right = height.size() - 1;
        int maxx = 0;
        while (left <= right)
        {
            int duanbian = height[left] < height[right] ? height[left] : height[right];
            int tmp = duanbian * (right - left);
            // cout << tmp;
            maxx = maxx > tmp ? maxx : tmp;
            if (duanbian == height[left])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return maxx;
    }
};