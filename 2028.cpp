class Solution
{
public:
    vector<int> missingRolls(vector<int> &rolls, int mean, int n)
    {
        int mlen = rolls.size();
        int msum = 0;
        for (int i = 0; i < mlen; i++)
        {
            msum += rolls[i];
        }
        int len = mlen + n;
        // cout << len << endl;
        int summ = len * mean;
        // cout << summ << endl;
        int nsum = summ - msum;
        // cout << nsum << endl;
        vector<int> ans;
        if (nsum < 0 || n * 6 < nsum || nsum < n)
        {
            return ans;
        }
        // 1-6 来分配掉nsum和n
        int shang = nsum / n;
        int canyu = nsum % n;
        ans.resize(n);
        for (int i = 0; i < n; i++)
        {
            ans[i] = shang;
        }
        int i = 0;
        while (canyu != 0)
        {
            ans[i++]++;
            canyu--;
        }
        return ans;
    }
};