class Solution
{
public:
    bool isPowerOfFour(int n)
    {
        return n > 0 && (n & (n - 1)) == 0 && ((0xaaaaaaaa) & n) == 0;
    }
};