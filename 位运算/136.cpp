class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int a[32];
        for (int num : nums)
        {
            for (int j = 31; j >= 0; j--)
            {
                a[j] += num & 1;

                num >>= 1;
            }
        }
        int ans = 0;
        for (int j = 0; j <= 31; j++)
        {
            ans <<= 1;
            ans += a[j] % 2;
            // cout << ans << endl;
        }
        return ans;
    }
};