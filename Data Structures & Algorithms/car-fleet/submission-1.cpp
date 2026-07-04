class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        unordered_map<int, double> mp;
        int n = position.size();
        for(int i=0; i<n; i++){
            mp[position[i]] = (double)(target-position[i])/speed[i];
        }
        sort(position.begin(), position.end(), greater<int>());
        int fleet_cnt=0;
        stack<int> s;
        double last_car_time=0;
        for(int i=0; i<n; i++){
            if(last_car_time < mp[position[i]]){
                fleet_cnt++;
                last_car_time = mp[position[i]];
            }
        }
        return fleet_cnt;
    }
};
