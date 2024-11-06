class Solution
{
public:
    // 这是字串不是子序列
    bool iszichuan(string &a, string &b)
    {
        int i = 0;
        int j = 0;
        int m = a.size();
        int n = b.size();
        while (i < m && j < n)
        {
            if (a[i] == b[j])
            {

                j++;
            }
            else
            {
                j = 0;
            }
            i++;
        }
        if (j == n)
        {
            return true;
        }
        return false;
    }
    int maximumRemovals(string s, string p, vector<int> &removable)
    {
        string a = "aa1bc";
        string b = "a1b";
        cout << iszichuan(a, b);
    }
};