class Solution
// 找出最高位的1，和2的n+1次方-1异或，得到的就是相反的数
{
public:
    int findComplement(int num)
    {
        vector<int> a;
        while (num != 0)
        {
            a.push_back(1 ^ (num & 1));
            num >>= 1;
        }
        // for (int i = 0; i < a.size(); i++)
        // {
        //     cout << a[i] << endl;
        // }
        int ans = 0;
        for (int i = a.size() - 1; i >= 0; i--)
        {
            ans <<= 1;
            ans |= a[i];
        }
        return ans;
    }
};