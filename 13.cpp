class Solution
{
public:
    int transfer(string s)
    {
        if (s.size() == 0)
        {
            return 0;
        }
        else if (s.size() == 1)
        {
            if (s[0] == 'I')
                return 1;
            else if (s[0] == 'V')
                return 5;
            else if (s[0] == 'X')
                return 10;
            else if (s[0] == 'L')
                return 50;
            else if (s[0] == 'C')
                return 100;
            else if (s[0] == 'D')
                return 500;
            else if (s[0] == 'M')
                return 1000;
        }
        else
        {
            if (s[0] == 'I' && s[1] == 'V')
            {
                return 4 + transfer(s.substr(2));
            }
            else if (s[0] == 'I' && s[1] == 'X')
            {
                return 9 + transfer(s.substr(2));
            }
            else if (s[0] == 'X' && s[1] == 'L')
            {
                return 40 + transfer(s.substr(2));
            }
            else if (s[0] == 'X' && s[1] == 'C')
            {
                return 90 + transfer(s.substr(2));
            }
            else if (s[0] == 'C' && s[1] == 'D')
            {
                return 400 + transfer(s.substr(2));
            }
            else if (s[0] == 'C' && s[1] == 'M')
            {
                return 900 + transfer(s.substr(2));
            }
            else if (s[0] == 'I')
                return 1 + transfer(s.substr(1));
            else if (s[0] == 'V')
                return 5 + transfer(s.substr(1));
            else if (s[0] == 'X')
                return 10 + transfer(s.substr(1));
            else if (s[0] == 'L')
                return 50 + transfer(s.substr(1));
            else if (s[0] == 'C')
                return 100 + transfer(s.substr(1));
            else if (s[0] == 'D')
                return 500 + transfer(s.substr(1));
            else if (s[0] == 'M')
                return 1000 + transfer(s.substr(1));
        }
        return 0;
    }
    int romanToInt(string s)
    {
        return transfer(s);
    }
};