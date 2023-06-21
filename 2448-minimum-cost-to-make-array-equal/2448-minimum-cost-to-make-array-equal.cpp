class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        vector<pair<int, int>> numCost;
        int size = nums.size();
        for(int i=0; i<size; i++){
            numCost.push_back({nums[i],cost[i]});
        }
        sort(numCost.begin(), numCost.end());
        vector<long long> prefixSum(size);
        prefixSum[0] = numCost[0].second;
        long long totalCost = 0;
        for(int i=1; i<size; i++){
            prefixSum[i] = prefixSum[i-1] + numCost[i].second;
        }
        for(int i=1; i<size; i++){
            totalCost += (long long)numCost[i].second*(numCost[i].first - numCost[0].first);
        }
        long long ans = totalCost;
        for(int i=1; i<size; i++){
            int del = numCost[i].first - numCost[i-1].first;
            totalCost += prefixSum[i-1]*del;
            totalCost -= (prefixSum[size-1]-prefixSum[i-1])*del;
            ans = min(ans, totalCost);
        }
        return ans;
    }
};