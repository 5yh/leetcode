class Solution
{
public:
    int f(string a)
    {

        char zh = 'z';
        int cnt = 0;
        for (int j = 0; j < a.size(); j++)
        {
            if (a[j] == zh)
            {
                cnt++;
            }
            else if (a[j] < zh)
            {
                zh = a[j];
                cnt = 1;
            }
        }
        return cnt;
    }
    vector<int> numSmallerByFrequency(vector<string> &queries, vector<string> &words)
    {
        vector<int> cnts(12);
        for (int i = 0; i < words.size(); i++)
        {
            // 改为存储每种的个数
            cnts[f(words[i])]++;
        }

        // 要找比cnts小的，比cnts当前还小的所有都满足
        // 添加后缀和，
        for (int i = 9; i >= 1; i--)
        {
            cnts[i] += cnts[i + 1];
        }
        for (int i = 1; i <= 10; i++)
        {
            cout << cnts[i] << ' ';
        }
        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); i++)
        {
            ans[i] = cnts[f(queries[i]) + 1];
        }
        return ans;
    }
};