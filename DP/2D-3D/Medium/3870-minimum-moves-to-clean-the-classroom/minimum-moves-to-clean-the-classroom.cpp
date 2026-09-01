#include <vector>
#include <string>
#include <queue>
#include <tuple>
#include <map>

using namespace std;

class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();
        
        pair<int, int> start;
        vector<pair<int, int>> litter_positions;
        
        // Find start and litter positions
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (classroom[r][c] == 'S') {
                    start = {r, c};
                } else if (classroom[r][c] == 'L') {
                    litter_positions.push_back({r, c});
                }
            }
        }
        
        int num_litter = litter_positions.size();
        int full_mask = (1 << num_litter) - 1;
        
        // Map grid positions of 'L' to bit indices
        vector<vector<int>> litter_idx(m, vector<int>(n, -1));
        for (int i = 0; i < num_litter; ++i) {
            litter_idx[litter_positions[i].first][litter_positions[i].second] = i;
        }
        
        int initial_mask = 0;
        if (litter_idx[start.first][start.second] != -1) {
            initial_mask |= (1 << litter_idx[start.first][start.second]);
        }
        
        if (initial_mask == full_mask) return 0;
        
        // max_energy[r][c][mask] stores max energy when reaching (r, c) with mask
        vector<vector<vector<int>>> max_energy(m, vector<vector<int>>(n, vector<int>(1 << num_litter, -1)));
        
        // Tuple: {moves, r, c, curr_energy, mask}
        queue<tuple<int, int, int, int, int>> q;
        q.push({0, start.first, start.second, energy, initial_mask});
        max_energy[start.first][start.second][initial_mask] = energy;
        
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while (!q.empty()) {
            auto [moves, r, c, curr_energy, mask] = q.front();
            q.pop();
            
            if (mask == full_mask) return moves;
            if (curr_energy == 0) continue;
            
            for (auto& dir : dirs) {
                int nr = r + dir[0];
                int nc = c + dir[1];
                
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && classroom[nr][nc] != 'X') {
                    int next_energy = curr_energy - 1;
                    char cell = classroom[nr][nc];
                    
                    if (cell == 'R') {
                        next_energy = energy;
                    }
                    
                    int next_mask = mask;
                    if (cell == 'L' && litter_idx[nr][nc] != -1) {
                        next_mask |= (1 << litter_idx[nr][nc]);
                    }
                    
                    // Push to queue only if we reach this state with strictly strictly more energy
                    if (max_energy[nr][nc][next_mask] < next_energy) {
                        max_energy[nr][nc][next_mask] = next_energy;
                        q.push({moves + 1, nr, nc, next_energy, next_mask});
                    }
                }
            }
        }
        
        return -1;
    }
};