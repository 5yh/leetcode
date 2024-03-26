class FrequencyTracker
{
    // 超时了
public:
    vector<int> shuzu;
    unordered_map<int, int> cishu;
    FrequencyTracker()
    {
    }
    // o1
    void add(int number)
    {
        shuzu.push_back(number);
        cishu[number]++;
    }
    // on
    void deleteOne(int number)
    {
        if (cishu[number])
        {
            shuzu.erase(std::remove(shuzu.begin(), shuzu.end(), number), shuzu.end());
            cishu[number]--;
        }
    }

    bool hasFrequency(int frequency)
    {
        for (int i = 0; i < cishu.size(); i++)
        {
            if (cishu[i] == frequency)
            {
                cout << i << endl;
                cout << cishu[i] << endl;
                return true;
            }
        }
        return false;
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */