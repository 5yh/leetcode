class Solution
{
public:
    string addBinary(string a, string b)
    {
        string c;
        int ciwei = 0;
        int jinwei = 0;
        for (int i = a.length() - 1, j = b.length() - 1; i >= 0 || j >= 0; i--, j--)
        {
            ciwei = jinwei;
            ciwei += (i >= 0) ? (a[i] - '0') : 0;
            ciwei += (j >= 0) ? (b[j] - '0') : 0;
            jinwei = ciwei / 2;
            ciwei %= 2;
            // cout << "ciwei" << ciwei << endl
            //      << "jinwei" << jinwei << endl;
            c += '0' + ciwei;
        }
        if (jinwei == 1)
        {
            c += '1';
        }
        reverse(c.begin(), c.end());
        return c;
    }
};