class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int halflen = nums.size() / 2;

        unordered_map<int, int> cnt;
        for (auto num : nums)
        {
            cnt[num]++;
            if (cnt[num] >= halflen + 1)
            {
                return num;
            }
        }
        // for (auto &[k, v] : cnt)
        // {
        //     if (v >= halflen + 1)
        //     {
        //         return k;
        //     }
        // }
        return 0;
    }
};