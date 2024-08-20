class Solution
{
public:
    // 如何在移动时取到最大最小值
    // 使用单调队列
    int longestSubarray(vector<int> &nums, int limit)
    {
        int n = nums.size();
        deque<int> queMax, queMin;
        int l = 0;
        int ans = 0;
        for (int r = 0; r < n; r++)
        {
            while (!queMax.empty() && queMax.back() < nums[r])
            {
                queMax.pop_back();
            }
            while (!queMin.empty() && queMin.back() > nums[r])
            {
                queMin.pop_back();
            }
            queMax.push_back(nums[r]);
            queMin.push_back(nums[r]);
            while (!queMax.empty() && !queMin.empty() && queMax.front() - queMin.front() > limit)
            {
                if (nums[l] == queMax.front())
                {
                    queMax.pop_front();
                }
                if (nums[l] == queMin.front())
                {
                    queMin.pop_front();
                }
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};