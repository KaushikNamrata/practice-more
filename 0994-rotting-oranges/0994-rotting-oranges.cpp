class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        // Number of minutes passed
        int minutes = 0;

        // Count total fresh oranges
        int fresh = 0;

        // These arrays help us move in 4 directions:
        //
        // k = 0 -> Down
        // k = 1 -> Up
        // k = 2 -> Right
        // k = 3 -> Left
        //
        // dr = change in row
        // dc = change in column
        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        // Queue stores the position of rotten oranges
        // pair = {row, column}
        queue<pair<int, int>> q;


        // --------------------------------------------------
        // STEP 1: Find all rotten and fresh oranges
        // --------------------------------------------------

        for(int i = 0; i < grid.size(); i++) {

            for(int j = 0; j < grid[0].size(); j++) {

                // If orange is already rotten,
                // put its position into the queue
                if(grid[i][j] == 2) {
                    q.push({i, j});
                }

                // Count fresh oranges
                if(grid[i][j] == 1) {
                    fresh++;
                }
            }
        }


        // --------------------------------------------------
        // STEP 2: BFS
        // --------------------------------------------------

        // Continue until:
        // 1. Queue becomes empty OR
        // 2. No fresh oranges are left
        while(!q.empty() && fresh > 0) {

            // Number of rotten oranges at the
            // beginning of this minute
            int size = q.size();


            // Process all oranges that are currently rotten
            for(int i = 0; i < size; i++) {

                // Get the position of the current
                // rotten orange
                int r = q.front().first;
                int c = q.front().second;

                // Remove it from queue
                q.pop();


                // --------------------------------------------------
                // Check all 4 directions
                // --------------------------------------------------

                for(int k = 0; k < 4; k++) {

                    // Calculate neighbour's row and column
                    //
                    // k = 0 -> Down
                    // k = 1 -> Up
                    // k = 2 -> Right
                    // k = 3 -> Left

                    int nr = r + dr[k];
                    int nc = c + dc[k];


                    // Check whether the neighbour:
                    // 1. Is inside the grid
                    // 2. Is a fresh orange
                    if(nr >= 0 && nr < grid.size() &&
                       nc >= 0 && nc < grid[0].size() &&
                       grid[nr][nc] == 1) {

                        // Make the fresh orange rotten
                        grid[nr][nc] = 2;

                        // One fresh orange has become rotten
                        fresh--;

                        // Put the newly rotten orange
                        // into queue
                        //
                        // It will spread rot in the NEXT minute
                        q.push({nr, nc});
                    }
                }
            }

            // We have completed one level of BFS
            // Therefore, 1 minute has passed
            minutes++;
        }


        // --------------------------------------------------
        // STEP 3: Check if any fresh orange is still left
        // --------------------------------------------------

        if(fresh > 0) {
            // Some fresh orange could never become rotten
            return -1;
        }

        // All fresh oranges became rotten
        return minutes;
    }
};