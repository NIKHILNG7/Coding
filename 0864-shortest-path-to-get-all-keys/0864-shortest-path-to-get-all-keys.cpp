class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int numberOfRows = grid.size();
        int numberOfColumns = grid[0].size();

        unordered_map<char, int> keyMap;
        int keyStart = 0;
        for (int i = 0; i < numberOfRows; i++)
            for (int j = 0; j < numberOfColumns; j++)
                if (islower(grid[i][j]))
                    keyMap[grid[i][j]] = keyStart++;
        
        int endMask = (1 << keyStart) - 1;
        int maskSize = (1 << keyStart);

        vector<vector<vector<bool>>> memo(numberOfRows, vector<vector<bool>>(numberOfColumns, vector<bool>(maskSize, false)));

        vector<int> startPosition;
        for (int i = 0; i < numberOfRows; i++)
            for (int j = 0; j < numberOfColumns; j++)
                if (grid[i][j] == '@')
                    startPosition = {i, j, 0}; // 0 denoting no key state

        queue<vector<int>> q;
        q.push(startPosition);
        int steps = 0;
        while (!q.empty())
        {
            int size = q.size();
            for (int k = 0; k < size; k++)
            {
                int row = q.front()[0];
                int col = q.front()[1];
                int mask = q.front()[2];
                q.pop();

                if (row < 0 || row >= numberOfRows || col < 0 || col >= numberOfColumns)
                    continue;

                if (grid[row][col] == '#') continue;

                if (isupper(grid[row][col]))
                    if ((mask & (1 << keyMap[tolower(grid[row][col])])) == 0)
                        continue;

                if (islower(grid[row][col]))
                    mask = mask | (1 << keyMap[grid[row][col]]);

                if (mask == endMask) return steps;

                if (memo[row][col][mask]) continue;
                memo[row][col][mask] = true;

                q.push({row + 1, col, mask});
                q.push({row - 1, col, mask});
                q.push({row, col + 1, mask});
                q.push({row, col - 1, mask});
            }
            steps++;
        }
        return -1;
    }
};
