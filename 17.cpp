class Solution
{
public:
    vector<char> c2 = {'a', 'b', 'c'};
    vector<char> c3 = {'d', 'e', 'f'};
    vector<char> c4 = {'g', 'h', 'i'};
    vector<char> c5 = {'j', 'k', 'l'};
    vector<char> c6 = {'m', 'n', 'o'};
    vector<char> c7 = {'p', 'q', 'r', 's'};
    vector<char> c8 = {'t', 'u', 'v'};
    vector<char> c9 = {'w', 'x', 'y', 'z'};
    vector<vector<char>> twoDVector = {c2, c3, c4, c5, c6, c7, c8, c9};
    vector<string> ans;
    void dfs(string digits, string tmp, int len)
    {
        // cout << int(digits[0]) - 2 << endl;
        // cout << twoDVector[int(digits[0]) - 2][0] << endl;
        if (tmp.length() == len)
        {
            ans.push_back(tmp);
            return;
        }
        for (int i = 0; i < twoDVector[int(digits[0]) - '0' - 2].size(); i++)
        {
            tmp.push_back(twoDVector[int(digits[0]) - '0' - 2][i]);
            dfs(digits.substr(1), tmp, len);
            tmp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits)
    {
        if (digits.length() == 0)
        {
            return vector<string>(0);
        }
        string tmp = "";
        dfs(digits, tmp, digits.length());
        return ans;
    }
};