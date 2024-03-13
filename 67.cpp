// 大整数加法
class Solution
{
public:
    string addBinary(string a, string b)
    {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string c, d;
        // c是长的
        if (a.length() >= b.length())
        {
            c = a;
            d = b;
        }
        else
        {
            c = b;
            d = a;
        }
        // cout << c << endl
        //      << d << endl;
        int jinwei = 0;
        int ciwei = 0;
        for (int i = 0; i < d.length(); i++)
        {
            int ciwei = int(d[i] - '0') + int(c[i] - '0') + jinwei;
            // cout << "ciwei" << ciwei << endl;
            if (ciwei == 2)
            {
                ciwei = 0;
                jinwei = 1;
            }
            else if (ciwei == 3)
            {
                ciwei = 1;
                jinwei = 1;
            }
            else
            {
                jinwei = 0;
            }
            if (ciwei == 0)
            {
                c[i] = '0';
            }
            else if (ciwei == 1)
            {
                c[i] = '1';
            }
            // cout << "c" << c << endl;
        }
        for (int i = d.length(); i < c.length(); i++)
        {
            int ciwei = int(c[i] - '0') + jinwei;
            if (ciwei == 2)
            {
                ciwei = 0;
                jinwei = 1;
            }
            else
            {
                jinwei = 0;
            }
            if (ciwei == 0)
            {
                c[i] = '0';
            }
            else if (ciwei == 1)
            {
                c[i] = '1';
            }
        }
        reverse(c.begin(), c.end());
        if (jinwei == 1)
            return '1' + c;
        else
            return c;
    }
};