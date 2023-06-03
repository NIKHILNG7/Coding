// question is copied

class Solution {
public:
    // Function to calculate the time taken to inform all employees.
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        // Create a map to store the hierarchy of managers and their subordinates.
        unordered_map<int,vector<int> > hierarchyMap;
        for(int i=0;i<manager.size();i++) {
            hierarchyMap[manager[i]].push_back(i);
        }
        // Create a queue to store the head of the hierarchy and the time taken to inform them.
        queue<pair<int,int>> queueOfHeads;
        queueOfHeads.push(make_pair(headID,0));
        int maxTimeTaken=0;
        // Traverse the hierarchy tree to calculate the maximum time taken to inform all employees.
        while(!queueOfHeads.empty()) {
            int numberOfHeads=queueOfHeads.size();
            for(int i=0;i<numberOfHeads;i++) {
                int head=queueOfHeads.front().first;
                int timeTaken=queueOfHeads.front().second;
                queueOfHeads.pop();
                int duration=informTime[head]+timeTaken;
                maxTimeTaken=max(maxTimeTaken,duration);
                for(auto it:hierarchyMap[head]) {
                    queueOfHeads.push(make_pair(it,duration));
                }
            }
        }
        return maxTimeTaken;
    }
};