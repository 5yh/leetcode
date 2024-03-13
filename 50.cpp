class Solution
{
public:
    unordered_map<int, double> cun;
    double myPow(double x, int n)
    {
        cun[1] = x;
        cun[0] = 1;
        cun[-1] = 1 / x;
        int n2 = n / 2;
        if (n > 0)
        {
            if (cun[n2] == 0)
            {
                cun[n2] = myPow(x, n2);
            }
            return cun[n2] * cun[n2] * cun[n - n2 - n2];
        }

        else if (n < 0)
        {
            if (cun[n2] == 0)
            {
                cun[n2] = myPow(x, n2);
            }
            return cun[n2] * cun[n2] * cun[n - n2 - n2];
        }
        else
            return 1;
    }
};