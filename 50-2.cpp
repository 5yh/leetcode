class Solution
{
public:
    double Mul(double x, long long N)
    {
        if (N == 0)
            return 1;
        double y = Mul(x, N / 2);
        if (N % 2 == 0)
        {
            return y * y;
        }
        else
        {
            return y * y * x;
        }
    }
    double myPow(double x, int n)
    {
        long long N = n;
        if (N >= 0)
        {
            return Mul(x, N);
        }
        else
        {
            return 1 / Mul(x, -N);
        }
    }
};