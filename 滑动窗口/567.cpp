class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        // s2中的字串和s1长度相等，且每个字符出现的次数也相等
        // 用什么方法存储字符出现次数进行对比
        vector<int> cnt1(26);
        vector<int> cnt2(26);
        int n = s1.size();
        int n2 = s2.size();
        if (n > n2)
        {
            return false;
        }
        for (int i = 0; i < n; i++)
        {
            cnt1[s1[i] - 'a']++;
        }
        for (int i = 0; i < n - 1; i++)
        {
            cnt2[s2[i] - 'a']++;
        }
        for (int i = n - 1; i < n2; i++)
        {
            cnt2[s2[i] - 'a']++;
            if (cnt1 == cnt2)
            {
                return true;
            }
            cnt2[s2[i - n + 1] - 'a']--;
        }
        return false;
    }
};