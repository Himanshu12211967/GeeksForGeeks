class Solution {
  public:
    bool bpm(int u, vector<vector<int>> &G, vector<bool> &seen, vector<int> &matchR) {
        for (int v = 0; v < G[0].size(); v++) {
            if (G[u][v] && !seen[v]) {
                seen[v] = true;

                if (matchR[v] == -1 || bpm(matchR[v], G, seen, matchR)) {
                    matchR[v] = u;
                    return true;
                }
            }
        }
        return false;
    }

    int maximumMatch(vector<vector<int>> &G) {
        
        int people = G.size();
        int jobs = G[0].size();
        vector<int> matchR(jobs, -1);
        int result = 0;

        for (int u = 0; u < people; u++) {
            vector<bool> seen(jobs, false);
            if (bpm(u, G, seen, matchR)) {
                result++;
            }
        }

        return result;
    }
};
