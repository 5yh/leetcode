class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        int len = nums.size();
        unordered_map<int, int> cntElement;
        for (int i = 0; i <= k && i < len; i++)
        {
            cntElement[nums[i]]++;
            if (cntElement[nums[i]] > 1)
            {
                return true;
            }
        }
        for (int i = k + 1; i < len; i++)
        {
            cntElement[nums[i - k - 1]]--;
            cntElement[nums[i]]++;
            if (cntElement[nums[i]] > 1)
            {
                return true;
            }
        }
        return false;
    }
};