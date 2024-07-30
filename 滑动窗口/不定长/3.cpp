class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.size();
        int maxlen = 0;

        for (int i = 0; i < n; i++)
        {
            map<char, int> cnt;
            for (int j = i; j < n; j++)
            {
                // cout << i << ' ' << j << endl;
                // cout << cntj << cnt[j] << endl;
                if (cnt[s[j]])
                {
                    break;
                }
                cnt[s[j]]++;
                maxlen = (j - i + 1) > maxlen ? (j - i + 1) : maxlen;
                // cout << "maxlen" << maxlen << endl;
            }
        }
        return maxlen;
    }
};