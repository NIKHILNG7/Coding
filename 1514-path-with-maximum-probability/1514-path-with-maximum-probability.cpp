class Solution {
public:
    double maxProbability(int numNodes, vector<vector<int>>& edges, vector<double>& succProb, int startNode, int endNode) {
        vector<double> probabilities(numNodes + 1, 0);
        
        vector<pair<int,double>> adjacencyList[numNodes + 1];
        for (int i = 0; i < edges.size(); i++) {
            adjacencyList[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adjacencyList[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        priority_queue<pair<double,int>> pq;
        probabilities[startNode] = 1;
        pq.push({1, startNode});
        while (!pq.empty()) {
            int currentNode = pq.top().second;
            double currentProbability = pq.top().first;
            pq.pop();
            for (auto it : adjacencyList[currentNode]) {
                if (probabilities[it.first] < (it.second * probabilities[currentNode])) {
                    probabilities[it.first] = (it.second * probabilities[currentNode]);
                    pq.push({probabilities[it.first], it.first});
                }
            }
        }
        return probabilities[endNode];
    }
};