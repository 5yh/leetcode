class Solution
{
public:
    int singleReplace(string &s, int k, char ch)
    {
        int n = s.size();
        int cnt = 0;
        int l = 0;
        int ans = 0;
        for (int r = 0; r < n; r++)
        {
            if (s[r] != ch)
            {
                cnt++;
                while (cnt > k)
                {
                    if (s[l] != ch)
                    {
                        cnt--;
                    }
                    l++;
                }
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }

    int characterReplacement(string s, int k)
    {
        int maxans = 0;
        for (char i = 'A'; i <= 'Z'; i++)
        {
            maxans = max(maxans, singleReplace(s, k, i));
        }
        return maxans;
    }
};