class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.size();
        unordered_set<char> occ;
        int r = -1;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (i != 0)
            {
                occ.erase(s[i - 1]); // 删掉前一个
            }
            while (r + 1 < n && !occ.count(s[r + 1]))
            {
                occ.insert(s[r + 1]);
                r++;
            }
            ans = max(ans, r - i + 1);
        }
        return ans;
    }
};