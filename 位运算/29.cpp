// -2147483648~2147483647
// int min取abs会失效，此方法不行
class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        if (dividend == -2147483648)
        {
            if (divisor < 0)
            {
                int cnt = 0;
                while (dividend <= divisor)
                {
                    // 超时了
                    dividend -= divisor;
                    cnt++;
                }
                return cnt;
            }
            else
            {
                int cnt = 0;
                while (dividend >= -divisor)
                {
                    dividend += divisor;
                    cnt++;
                }
                return -cnt;
            }
        }
        int chuzheng = (dividend >= 0) ? 1 : 0;
        int beichuzheng = (divisor >= 0) ? 1 : 0;
        int zhengdividend = abs(dividend);
        int zhengdivisor = abs(divisor);
        int cnt = 0;
        while (zhengdividend >= zhengdivisor)
        {
            zhengdividend -= zhengdivisor;
            cnt++;
        }
        if (chuzheng ^ beichuzheng)
        {
            return -cnt;
        }
        else
        {
            return cnt;
        }
    }
};