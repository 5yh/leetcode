class Solution
{
public:
    string convert(string s, int numRows)
    {
        vector<string> aa(numRows);
        bool zeng = true;
        int idx = 0;
        int i = 0;
        while (i != s.size())
        {
            if (idx == numRows - 1)
            {
                zeng = false;
            }
            else if (idx == 0)
            {
                zeng = true;
            }
            if (zeng)
            {
                aa[idx] += s[i++];
                if (numRows != 1)
                {
                    idx++;
                }
            }
            else
            {
                aa[idx] += s[i++];
                if (numRows != 1)
                {
                    idx--;
                }
            }
        }
        string ans;
        for (int i = 0; i < numRows; i++)
        {
            ans += aa[i];
        }
        return ans;
    }
};