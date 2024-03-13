class Solution
{
public:
    auto Mul(double x, long long n)
    {
        auto ans = 1.0;
        double cheng = x;
        while (n != 0)
        {
            if (n % 2 == 1)
            {
                ans *= cheng;
            }
            cheng *= cheng;
            n /= 2;
        }
        return ans;
    }
    double myPow(double x, int n)
    {
        long long N = n;
        if (n >= 0)
        {
            return Mul(x, N);
        }
        else
        {
            return 1 / Mul(x, -N);
        }
    }
};