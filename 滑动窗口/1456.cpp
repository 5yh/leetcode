class Solution
{
public:
    int maxVowels(string s, int k)
    {
        // aeiou
        int maxx = 0;
        int cntt = 0;
        for (int i = 0; i < k; i++)
        {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            {
                cntt++;
            }
        }
        maxx = cntt;
        for (int i = k; i < s.size(); i++)
        {
            if (s[i - k] == 'a' || s[i - k] == 'e' || s[i - k] == 'i' || s[i - k] == 'o' || s[i - k] == 'u')
            {
                cntt--;
            }
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            {
                cntt++;
            }
            if (cntt > maxx)
            {
                maxx = cntt;
            }
        }
        return maxx;
    }
};