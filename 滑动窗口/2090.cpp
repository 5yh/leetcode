class Solution
{
public:
    vector<int> getAverages(vector<int> &nums, int k)
    {
        int len = k + k + 1;
        vector<int> ans(nums.size());
        int summ = 0;
        for (int i = 0; i < nums.size() && i < k; i++)
        {
            // cout<<i<<' '<<k<<endl;
            ans[i] = -1;
        }
        if (k >= nums.size())
        {
            return ans;
        }
        for (int i = 0; i < len; i++)
        {
            summ += nums[i];
        }
        ans[k] = summ / len;
        for (int i = k + 1; i + k < nums.size(); i++)
        {
            cout << "i" << i << "k" << k << endl;
            summ -= ans[i - k - 1];
            summ += ans[i + k];
            ans[i] = summ / len;
        }
        for (int i = 0; i < k; i++)
        {
            ans[nums.size() - 1 - i] = -1;
        }
        return ans;
    }
};