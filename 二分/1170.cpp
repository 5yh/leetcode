class Solution
{
public:
    int f(string a)
    {

        char zh = 'z';
        // cnt应从0开始，sb了
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
        vector<int> cnts(words.size());
        for (int i = 0; i < words.size(); i++)
        {
            cnts[i] = f(words[i]);
            cout << cnts[i] << endl;
        }
        sort(cnts.begin(), cnts.end());

        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); i++)
        {
            int fq = f(queries[i]);
            // upperbound其实是对的
            // 前面错了
            int anss = cnts.end() - upper_bound(cnts.begin(), cnts.end(), fq);
            ans[i] = anss;
        }
        return ans;
    }
};