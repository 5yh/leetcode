class Solution
{
    // 写的太垃圾了，有不存的方法
public:
    vector<string> words;
    string getword(string &s)
    {
        string word1 = "";
        while (s.size() > 0 && s[0] == ' ')
        {
            s = s.substr(1);
        }
        while (s.size() > 0 && s[0] != ' ')
        {
            word1 += s[0];
            s = s.substr(1);
        }
        return word1;
    }
    string reverseWords(string s)
    {
        while (s.size() != 0)
        {
            string get1 = getword(s);
            if (get1 != "")
            {
                words.emplace_back(get1);
            }
        }
        string ans;
        for (int i = words.size() - 1; i > 0; i--)
        {
            ans += words[i];
            ans += " ";
        }
        ans += words[0];
        return ans;
    }
};