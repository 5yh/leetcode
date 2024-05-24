class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_set<int> set1;
        int len = nums.size();
        for (int i = 0; i < len; i++)
        {
            if (i > k)
            {
                set1.erase(nums[i - k - 1]);
            }
            if (set1.count(nums[i]))
            {
                return true;
            }
            set1.emplace(nums[i]);
        }
        return false;
    }
};