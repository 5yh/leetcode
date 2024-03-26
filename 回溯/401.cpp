class Solution
{
public:
    vector<int> curnums;
    unordered_map<int, int> cnt;
    vector<string> ans;
    void dfs(int turnon, int curopen, int curnum)
    {
        if (curopen == turnon && cnt[curnum] == 0)
        {
            curnums.push_back(curnum);
            cnt[curnum] = 1;
            return;
        }
        for (int i = 0; i < 10; i++)
        {
            int cur = 1 << i;
            if (cur & curnum) // 说明此位已经有了
            {
                continue;
            }
            dfs(turnon, curopen + 1, curnum | cur);
        }
    }
    void getTime()
    {
        for (auto num : curnums)
        {
            int min = num & 63;
            int hour = (num >> 6) & 15;
            // cout << hour << ' ' << min << endl;
            string tmpans = "";
            if (min < 60 && hour < 12)
            {
                tmpans += to_string(hour);
                tmpans += ":";
                if (min < 10)
                {
                    tmpans += "0";
                }
                tmpans += to_string(min);
                ans.push_back(tmpans);
            }
        }
    }
    vector<string> readBinaryWatch(int turnedOn)
    {
        // 1023 十位
        dfs(turnedOn, 0, 0);
        // for (int i = 0; i < curnums.size(); i++)
        // {
        //     cout << curnums[i] << endl;
        // }
        getTime();
        return ans;
    }
};