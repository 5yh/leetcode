class Solution
{
public:
    // 贪心+单调栈
    vector<int> mostCompetitive(vector<int> &nums, int k)
    {
        vector<int> s1;
        int len = nums.size();
        for (int i = 0; i < len; i++)
        {
            while (!s1.empty() && s1.size() + len - i > k && nums[i] < s1.back())
            {
                s1.pop_back();
            }
            s1.push_back(nums[i]);
        }
        s1.resize(k);
        return s1;
    }
};