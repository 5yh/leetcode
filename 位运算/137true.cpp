class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int anszong = 0;
        for (int i = 0; i < 32; i++)
        {
            int ans = 0;
            for (int num : nums)
            {
                ans += (num >> i) & 1;
            }
            if (ans % 3)
            {
                anszong |= (1 << i);
            }
        }
        return anszong;
    }
};