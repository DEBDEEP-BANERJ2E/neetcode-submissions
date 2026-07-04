class TimeMap {

private:
    unordered_map<string, vector<pair<int, string>>> store;

public:
    TimeMap() {

    }
    
    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (store.find(key) == store.end()) {
            return "";
        }

        const auto& values = store[key];
        int low = 0, high = values.size() - 1;
        string res = "";

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (values[mid].first <= timestamp) {
                res = values[mid].second;
                low = mid + 1;          
            } else {
                high = mid - 1;
            }
        }

        return res;
    }
};
