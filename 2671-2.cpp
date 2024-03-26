class FrequencyTracker
{
public:
    unordered_map<int, int> cishu;
    unordered_map<int, int> meigecishu;
    FrequencyTracker()
    {
    }

    void add(int number)
    {
        meigecishu[cishu[number]]--;
        cishu[number]++;
        meigecishu[cishu[number]]++;
    }

    void deleteOne(int number)
    {
        if (cishu[number])
        {
            meigecishu[cishu[number]]--;
            cishu[number]--;
            meigecishu[cishu[number]]++;
        }
    }

    bool hasFrequency(int frequency)
    {
        return meigecishu[frequency] != 0;
        // return false;
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */