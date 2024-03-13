class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        if (dividend == INT_MIN)
        {
            if (divisor == 1)
            {
                return INT_MIN;
            }
            else if (divisor == -1)
            {
                return INT_MAX;
            }
        }
        if (divisor == INT_MIN)
        {
            if (dividend == INT_MIN)
            {
                return 1;
            }
            else
            {
                return 0;
            }
            if (dividend == 0)
            {
                return 0;
            }
                }
    }
};