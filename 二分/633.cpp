class Solution
{
public:
    // long long
    // (long long)
    bool manzu(int c, int m, int a)
    {
        // cout << "c" << c << "m" << m << "a" << a << endl;
        if (a * a <= c - m * m)
        {
            return true;
        }
        return false;
    }
    bool judgeSquareSum(int c)
    {
        int sc = sqrt(c);
        for (int i = 0; i <= sc; i++)
        {
            int l = -1;
            int r = sc + 1;
            // cout << "l" << l << "r" << r << endl;
            while (l + 1 < r)
            {
                int m = (r - l) / 2 + l;
                // cout << m << endl;
                if (manzu(c, m, i))
                {
                    l = m;
                }
                else
                {
                    r = m;
                }
            }
            // cout << "l" << l << "r" << r << endl;
            if (i * i + l * l == c)
            {
                return true;
            }
        }
        return false;
    }
};