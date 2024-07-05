class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> cnt1(26), cnt2(26);
        vector<int> ans;
        int n1 = s.size(), n2 = p.size();
        if (n2 > n1)
        {
            return ans;
        }
        for (int i = 0; i < n2 - 1; i++)
        {
            cnt2[p[i] - 'a']++;
            cnt1[s[i] - 'a']++;
        }
        cnt2[p[n2 - 1] - 'a']++;
        for (int i = n2 - 1; i < n1; i++)
        {
            cnt1[s[i] - 'a']++;
            if (cnt1 == cnt2)
            {
                ans.emplace_back(i - n2 + 1);
            }
            cnt1[s[i - n2 + 1] - 'a']--;
        }
        return ans;
    }
};