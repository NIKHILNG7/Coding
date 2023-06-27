class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& arr1, vector<int>& arr2, int k) {
        vector<vector<int>> result;
        // Edge cases
        if (arr1.empty() || arr2.empty() || k <= 0) 
            return result;
        // Custom comparison function for the priority queue
        auto compare = [&](pair<int, int>& a, pair<int, int>& b) {
            return arr1[a.first] + arr2[a.second] > arr1[b.first] + arr2[b.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> pq(compare);
        
        // Initialize the priority queue with pairs of indices (0, j) for 0 <= j < arr2.size()
        for (int j = 0; j < min(k, static_cast<int>(arr2.size())); j++) 
            pq.push({0, j});
        
        while (k-- > 0 && !pq.empty()) {
            auto [i, j] = pq.top();
            pq.pop();
            result.push_back({arr1[i], arr2[j]});
            // Explore the next pair (i+1, j) if i+1 is within the range of arr1
            if (i + 1 < arr1.size()) 
                pq.push({i + 1, j});
        }
        return result;
    }
};