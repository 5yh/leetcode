class Solution
{
public:
    long long maxSum(vector<int> &nums, int m, int k)
    {
        deque<int> shuzu(nums.begin(), nums.begin() + 4);
        unordered_set<int> ans(nums.begin(), nums.begin() + 4);
        int summ = 0;
        for (int i = 0; i < k; i++)
        {
            summ += shuzu[i];
        }
        long long maxx = 0;
        if (ans.size() > m)
        {
            maxx = summ;
        }
        ans.clear();
        for (int i = 1; i + k < nums.size(); i++)
        {
            summ -= shuzu[0];

            shuzu.pop_front();
            shuzu.push_back(nums[i + k - 1]);
            summ += shuzu[k - 1];
            ans.insert(nums.begin() + i, nums.begin() + i + k);
            if (ans.size() > m)
            {
                if (summ > maxx)
                {
                    maxx = summ;
                }
            }
        }
        return maxx;
    }
};