class Solution
{
public:
    string subStrHash(string s, int power, int modulo, int k, int hashValue)
    {
        int val = 0;
        vector<int> p(k);
        p[0] = 1;
        for (int i = 1; i < k; i++)
        {
            p[i] = p[i - 1] * power;
        }
        for (int i = 0; i < k - 1; i++)
        {
            val += ((s[i] - 'a' + 1) * p[i]) % modulo;
            val %= modulo;
        }
        int anspos = 0;
        for (int i = k - 1; i < s.size(); i++)
        {
            val += ((s[i] - 'a' + 1) * p[k - 1]) % modulo;
            val %= modulo;
            if (hashValue == val)
            {
                anspos = i - k + 1;
                break;
            }
            val -= ((s[i - k + 1] - 'a' + 1) * p[0]) % modulo;
            if (val < 0)
            {
                val += modulo;
            }
            val /= power;
        }
        return s.substr(anspos, k);
    }
};