class Solution
{
public:
    int maxValue(int n, int index, int maxSum)
    {
        // 必须要是正整数，写错了
        // 剩下的不能填0，要填1
        int l = 0;
        int r = maxSum + 1;
        while (l + 1 < r)
        {
            int m = (r - l) / 2 + l;
            // cout << "M" << m << endl;
            long long kosai = maxSum - m;
            // cout << kosai << endl;
            if (m <= index)
            {
                // cout << "q";
                kosai -= ((long long)m * (long long)m - (long long)(1 + m) * (long long)m / 2);
                kosai -= index - (m - 1);
            }
            else
            {
                // cout << "w";
                kosai -= ((long long)index * (long long)m - (long long)(1 + index) * (long long)index / 2);
            }
            // cout << kosai << endl;
            if (m <= n - index - 1)
            {
                // cout << "e";
                kosai -= ((long long)m * (long long)m - (long long)(m + 1) * (long long)(m) / 2);
                kosai -= n - index - m;
            }
            else
            {
                // cout << "r";
                kosai -= ((long long)(n - index - 1) * (long long)m - (long long)(n - index) * (long long)(n - index - 1) / 2);
            }

            // cout << kosai << endl;
            if (0 <= kosai)
            {
                l = m;
            }
            else
            {
                r = m;
            }
        }
        return l;
    }
};