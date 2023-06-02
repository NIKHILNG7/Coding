class Solution {
#define ll long long int
    public:
    void dfs(vector<vector<int>> &graph,vector<bool> &visited,int &count,int &startIndex)
    {
        visited[startIndex]=true;
        count++;
        for(int j=0;j<graph[startIndex].size();j++)
        {
            if(!visited[graph[startIndex][j]])
             dfs(graph,visited,count,graph[startIndex][j]);   
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {

        int n=bombs.size();
        vector<vector<int> > graph(n);
        for(int i=0;i<n;i++)
        {
            ll x1,y1,r1;
            x1=bombs[i][0];
            y1=bombs[i][1];
            r1=bombs[i][2];
            for(int j=0;j<n;j++)
            {
                if(i!=j)
                {
                     ll x2,y2,r2;
                     x2=abs(x1-bombs[j][0]);
                     y2=abs(y1-bombs[j][1]);
                    if(x2*x2+y2*y2<=r1*r1)
                    {
                        graph[i].push_back(j);
                    }
                }
            }
        }
        int maxCount=INT_MIN;
        for(int i=0;i<n;i++)
        {
            int count=0;
            vector<bool> visited(n,false);
            dfs(graph,visited,count,i);
            maxCount=max(maxCount,count);
        }
        return maxCount;
    }
};