class Solution
{
public:
    int binaryGap(int n)
    {
        if (n & (n - 1) == 0)
        {
            return 0;
        }
        int last1 = -1;
        int ans = 0;
        for (int i = 0; n; i++)
        {
            int tmpc = n & 1;
            if (tmpc == 1)
            {
                if (last1 < 0)
                {
                    last1 = i;
                }
                else
                {
                    ans = ans < (i - last1) ? (i - last1) : ans;
                    last1 = i;
                }
            }
            n >>= 1;
        }
        return ans;
    }
};