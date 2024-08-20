class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int n = s.size();
        int l = 0;
        int ans = 0;
        int vis[26] = {0};
        int maxCount = 0;
        for (int r = 0; r < n; r++)
        {
            vis[s[r] - 'A']++;
            maxCount = max(maxCount, vis[s[r] - 'A']);
            if (maxCount + k < r - l + 1)
            {
                vis[s[l] - 'A']--;
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};