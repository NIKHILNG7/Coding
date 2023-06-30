class Solution {
    public static final int[][] directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int numRows, numCols;
    boolean[][] visited, isLand;
    
    private boolean dfs(int i, int j) {
        if(i == numRows - 1) {
            return true;
        }
        if(!visited[i][j] || (visited[i][j] && !isLand[i][j])) {
            if(visited[i][j]) {
                isLand[i][j] = true;
            }
            visited[i][j] = true;
            for (int[] direction : directions) {
                int x = direction[0] + i, y = direction[1] + j;
                if(x >= 0 && x < numRows && y >= 0 && y < numCols) {
                    if(!visited[x][y] && isLand[x][y]) {
                        if(dfs(x, y)) {
                            return true;
                        }
                    }
                    else if(!isLand[x][y]) {
                        visited[x][y] = true;
                    } 
                }
            }
        }
        return false;
    }
    
    public int latestDayToCross(int numRows, int numCols, int[][] cells) {
        this.numRows = numRows;
        this.numCols = numCols;
        isLand = new boolean[numRows][numCols];
        visited = new boolean[numRows][numCols];
        
        for (int i = cells.length - 1; i >= 0; i--) {
            int r = --cells[i][0], c = --cells[i][1];
            if(visited[r][c] && isLand[r][c]) {
                continue;
            }
            if(r == 0) {
                isLand[r][c] = true;
                visited[r][c] = false;
                if(dfs(r, c)) {
                    return i;
                }
            }
            else if(visited[r][c]) {
                if(dfs(r, c)) {
                    return i;
                }
            }
            isLand[r][c] = true;
        }
        return 0;
    }
}