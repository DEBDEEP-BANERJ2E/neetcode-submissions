class Twitter {
private:
    int time; // Global timestamp
    unordered_map<int, unordered_set<int>> followMap; // userId -> set of followees
    unordered_map<int, vector<pair<int, int>>> tweetMap; // userId -> list of {time, tweetId}
public:
    Twitter() {
        time = 0;
    }
    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({time++, tweetId});
    }
    vector<int> getNewsFeed(int userId) {
        vector<int> result;
        priority_queue<vector<int>> maxHeap; 
        unordered_set<int> users = followMap[userId];
        users.insert(userId);
        for (int uId : users) {
            if (tweetMap.find(uId) != tweetMap.end() && !tweetMap[uId].empty()) {
                int lastIndex = tweetMap[uId].size() - 1;
                int t = tweetMap[uId][lastIndex].first;
                int tId = tweetMap[uId][lastIndex].second;
                maxHeap.push({t, tId, uId, lastIndex});
            }
        }
        while (!maxHeap.empty() && result.size() < 10) {
            vector<int> top = maxHeap.top();
            maxHeap.pop();
            result.push_back(top[1]); // Add tweetId to result
            int uId = top[2];
            int nextIndex = top[3] - 1;
            if (nextIndex >= 0) {
                int t = tweetMap[uId][nextIndex].first;
                int tId = tweetMap[uId][nextIndex].second;
                maxHeap.push({t, tId, uId, nextIndex});
            }
        }
        return result;
    }
    
    void follow(int followerId, int followeeId) {
        // Prevent a user from formally following themselves in the map
        if (followerId != followeeId) {
            followMap[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
    }
};
