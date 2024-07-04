class Solution
{
public:
    int divisorSubstrings(int num, int k)
    {
        string snum = std::to_string(num);
        string num1;
        int cntt = 0;
        for (int i = 0; i < k; i++)
        {
            num1 += snum[i];
        }
        if (stoi(num1) != 0)
        {
            if (num % std::stoi(num1) == 0)
            {
                cntt++;
            }
        }
        for (int i = k; i < snum.size(); i++)
        {
            num1 = num1.substr(1) + snum[i];
            if (stoi(num1) != 0)
            {
                if (num % std::stoi(num1) == 0)
                {
                    cntt++;
                }
            }
        }
        return cntt;
    }
};