class TimeMap
{
public:
    unordered_map<string, vector<pair<int, string>>> m;
    TimeMap()
    {
        // unordered_map<string,vector<string>
    }

    void set(string key, string value, int timestamp)
    {
        m[key].emplace_back(timestamp, value);
    }

    string get(string key, int timestamp)
    {
        // m[key]可以直接用upperbound,比较的是string的大小,字典序
        auto &pairs = m[key];
        pair<int, string> p = {timestamp, string({127})};
        auto i = upper_bound(pairs.begin(), pairs.end(), p);
        // 找到第一个大于timestamp的位置,前面的就是小于或者等于的，符合要求
        if (i != pairs.begin())
        {
            return (i - 1)->second;
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */