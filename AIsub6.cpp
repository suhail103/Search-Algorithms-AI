#include <iostream>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;

struct State {
    string config;
    int g_cost;
    int h_cost;
    int f_cost;
    
    bool operator>(const State &other) const {
        return f_cost > other.f_cost;
    }
};

const string GOAL = "ABCDEFGHIJKLMNO#";
const int moves[4] = {-4, 4, -1, 1}; // Up, Down, Left, Right

// Heuristic: Manhattan Distance
int manhattanDistance(const string &state) {
    int distance = 0;
    for (int i = 0; i < 16; i++) {
        if (state[i] != '#') {
            int goalIndex = GOAL.find(state[i]);
            int x1 = i % 4, y1 = i / 4;
            int x2 = goalIndex % 4, y2 = goalIndex / 4;
            distance += abs(x1 - x2) + abs(y1 - y2);
        }
    }
    return distance;
}

bool isValidMove(int pos, int move) {
    if (move == -1 && pos % 4 == 0) return false;
    if (move == 1 && pos % 4 == 3) return false;
    return (pos + move >= 0 && pos + move < 16);
}

// A* Search Algorithm
int aStar(string start) {
    priority_queue<State, vector<State>, greater<State>> pq;
    unordered_set<string> visited;
    unordered_map<string, int> g_cost_map;
    
    int h = manhattanDistance(start);
    pq.push({start, 0, h, h});
    g_cost_map[start] = 0;
    
    while (!pq.empty()) {
        State current = pq.top();
        pq.pop();
        
        if (current.config == GOAL) {
            return current.g_cost;
        }
        
        visited.insert(current.config);
        int emptyPos = current.config.find('#');
        
        for (int move : moves) {
            if (isValidMove(emptyPos, move)) {
                string newConfig = current.config;
                swap(newConfig[emptyPos], newConfig[emptyPos + move]);
                
                if (visited.find(newConfig) == visited.end()) {
                    int new_g = current.g_cost + 1;
                    int new_h = manhattanDistance(newConfig);
                    int new_f = new_g + new_h;
                    
                    if (g_cost_map.find(newConfig) == g_cost_map.end() || new_g < g_cost_map[newConfig]) {
                        g_cost_map[newConfig] = new_g;
                        pq.push({newConfig, new_g, new_h, new_f});
                    }
                }
            }
        }
    }
    return -1; // Should never reach here if goal is always reachable
}

int main() {
    string initialState;
    cin >> initialState;
    
    int result = aStar(initialState);
    cout << result << endl;
    
    return 0;
}
