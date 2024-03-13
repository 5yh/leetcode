class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        if (dividend == INT_MIN)
        {
            if (divisor == INT_MIN)
            {
                return 1;
            }
            else if (divisor == -1)
            {
                return INT_MAX;
            }
            else if (divisor == 1)
            {
                return INT_MIN;
            }
        }
        if (divisor == INT_MIN)
        {
            return 0;
        }
        if (dividend == 0)
        {
            return 0;
        }
        bool zhuanhuan = false;
        if (dividend > 0)
        {
            dividend = -dividend;
            zhuanhuan = !zhuanhuan;
        }
        if (divisor > 0)
        {
            divisor = -divisor;
            zhuanhuan = !zhuanhuan;
        }
        auto quickAdd = [](int y, int z, int x)
        {
            // y,x小于0，z大于0
            // 判断y*z比x大则true
            int result = 0;
            int add = y;
            while (z)
            {
                if (z % 2 == 1)
                {
                    if (result < x - add)
                    {
                        return false;
                    }
                    result += add;
                }
                if (z != 1)
                {
                    if (add < x - add)
                    {
                        return false;
                    }
                    add += add;
                }
                z >>= 1;
            }
            return true;
        };
        int left = 1;
        int right = INT_MAX;
        int ans = 0;
        while (left <= right)
        {
            // 会溢出
            // int mid = (left + right) >> 1;
            // 右移运算符优先级低，必须要先括号
            // 左右结合性就是同样优先级的时候从左往右算还是从右往左算
            int mid = left + ((right - left) >> 1);
            bool check = quickAdd(divisor, mid, dividend);
            if (check)
            {
                ans = mid;
                if (mid == INT_MAX)
                {
                    break;
                }
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return zhuanhuan ? -ans : ans;
    }
};