class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int m = image.size();    // rows
        int n = image[0].size(); // columns

        // starting pixel ka original color save kr lo
        int originalColor = image[sr][sc];

        if (originalColor == color)
            return image;

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;

        q.push({sr, sc});
        visited[sr][sc] = true;

        // 4 directions
        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            image[r][c] = color;

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc] &&
                    image[nr][nc] == originalColor) {
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
        return image;
    }
};