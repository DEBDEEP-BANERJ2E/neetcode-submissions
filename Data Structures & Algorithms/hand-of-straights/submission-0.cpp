class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
// If the total number of cards can't be evenly divided by the group size
        if (hand.size() % groupSize != 0) return false;
// Ordered map to store frequencies and automatically keep keys sorted
        map<int, int> countMap;
        for (int card : hand)
            countMap[card]++;
// Iterate through the uniquely sorted cards
        for (auto it = countMap.begin(); it != countMap.end(); ++it) {
            int startCard = it->first;
            int count = it->second;
// If there are cards available of this value, we must start sequences with it
            if (count > 0) {
    // Check if we can form 'count' valid sequences of length 'groupSize'
                for (int i = 0; i < groupSize; ++i) {
                    int currentCard = startCard + i;
                    
                // If we don't have enough of the required consecutive card
                    if (countMap[currentCard] < count)
                        return false;
                    // Consume the cards used in these sequences
                    countMap[currentCard] -= count;
                }
            }
        }
        return true;
    }
};
