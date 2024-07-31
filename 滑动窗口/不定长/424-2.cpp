class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int n = s.size();
        int vis[26] = {0};
        int l = 0, r = 0;
        int ans = 0;
        int maxCount = 0;
        while (r < n)
        {
            vis[s[r] - 'A']++;
            maxCount = max(maxCount, vis[s[r] - 'A']);
            r++;
            if (r - l > maxCount + k)
            {
                vis[s[l] - 'A']--;
                l++;
            }
            ans = max(ans, r - l);
        }
        return ans;
    }
};