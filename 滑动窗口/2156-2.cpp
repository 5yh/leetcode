class Solution
{
public:
    string subStrHash(string s, int power, int modulo, int k, int hashValue)
    {
        int n = s.size();
        long long pk = 1;
        long long hash = 0;
        // [n-k到n-1]共k个
        for (int i = n - 1; i >= n - k; i--)
        {
            hash = (hash * power + (s[i] & 31)) % modulo;
            pk = pk * power % modulo; // 只需要最大的那个
        }
        int ans = hash == hashValue ? n - k : 0;
        for (int i = n - k - 1; i >= 0; i--)
        {
            hash = (hash * power + (s[i] & 31) - pk * (s[i + k] & 31) % modulo + modulo) % modulo;
            if (hash == hashValue)
            {
                ans = i;
            }
        }
        return s.substr(ans, k);
    }
};