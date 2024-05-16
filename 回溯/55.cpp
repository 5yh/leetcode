class Solution
{
public:
    // 写爆了
    bool canJump(vector<int> &nums)
    {
        int len = nums.size();
        vector<int> cishu(len, 999999999);
        int rightmost = 0;
        for (int i = 0; i < len; i++)
        {
            if (i > rightmost)
            {
                break;
            }
            if (i <= rightmost)
            {
                rightmost = max(rightmost, i + nums[i]);
            }
            for (int j = 0; j <= nums[i] && i + j < len; j++)
            {
                cout << i << ' ' << j << endl;
                cishu[i + j] = min(i + 1, cishu[i + j]);
            }
        }
        for (int i = 0; i < len; i++)
        {
            cout << cishu[i] << endl;
        }
        if (cishu[len - 1] != 999999999)
        {
            return true;
        }
        return false;
    }
};