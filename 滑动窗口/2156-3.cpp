class Solution
{
public:
    string subStrHash(string s, int power, int modulo, int k, int hashValue)
    {
        long long hash = 0;
        long long p = 1;
        int n = s.size();
        int ans = 0;
        for (int i = n - 1; i >= n - k; i--)
        {
            hash = (hash + (s[i] % 31)) * power % modulo;
            p = p * power % modulo;
        }
        ans = hash == hashValue ? n - k : 0;
        for (int i = n - k - 1; i >= 0; i--)
        {
            hash = (hash * power + (s[i] % 31) - (s[i + k] % 31) * p + modulo) % modulo;
            if (hash == hashValue)
            {
                ans = i;
            }
        }
        return s.substr(ans, k);
    }
};