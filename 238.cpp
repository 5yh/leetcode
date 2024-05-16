class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int len = nums.size();
        vector<int> L(len);
        vector<int> R(len);
        vector<int> ans(len);
        L[0] = 1;
        R[len - 1] = 1;
        for (int i = 1; i < len; i++)
        {
            L[i] = L[i - 1] * nums[i - 1];
            R[len - 1 - i] = R[len - i] * nums[len - i];
        }
        // ans[0] = R[1];
        // ans[len - 1] = L[len - 2];
        for (int i = 0; i < len; i++)
        {
            ans[i] = L[i] * R[i];
        }
        return ans;
    }
};