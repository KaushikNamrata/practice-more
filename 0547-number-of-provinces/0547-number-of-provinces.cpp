class Solution {
public:
    // DFS: current city se connected
    // saari cities ko visit karega
    void dfs(int city, vector<vector<int>>& isConnected, vector<int>& visited) {

        // Current city ko visited mark karo
        visited[city] = 1;

        // Check karo current city kis-kis city se connected hai
        for (int nextCity = 0; nextCity < isConnected.size(); nextCity++) {

            // Agar connection hai
            // AND next city abhi visit nahi hui
            if (isConnected[city][nextCity] == 1 && visited[nextCity] == 0) {

                // Us connected city par DFS karo
                dfs(nextCity, isConnected, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        // visited[i] = 0 → city i abhi visit nahi hui
        // visited[i] = 1 → city i visit ho chuki hai
        vector<int> visited(n, 0);

        // Total number of provinces
        int provinces = 0;

        // Har city ko check karo
        for (int city = 0; city < n; city++) {

            // Agar city abhi tak visit nahi hui,
            // iska matlab ek NEW province mila
            if (visited[city] == 0) {

                provinces++;

                // Is province ki saari connected
                // cities ko visit kar do
                dfs(city, isConnected, visited);
            }
        }

        return provinces;
    }
};