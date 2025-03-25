#include <iostream>
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;

struct State {
    string config;
    int cost;
};

// Goal state
const string GOAL = "ABCDEFGHIJKLMNO#";

// Possible movements of the empty tile (#)
const int moves[4] = {-4, 4, -1, 1}; // Up, Down, Left, Right

// Checks if a move is valid
bool isValidMove(int pos, int move) {
    if (move == -1 && pos % 4 == 0) return false; // Prevent left wraparound
    if (move == 1 && pos % 4 == 3) return false; // Prevent right wraparound
    return (pos + move >= 0 && pos + move < 16);
}

// BFS function to find the shortest path
int bfs(string start) {
    queue<State> q;
    unordered_set<string> visited;
    unordered_map<string, int> cost;
    
    q.push({start, 0});
    visited.insert(start);
    cost[start] = 0;
    
    while (!q.empty()) {
        State current = q.front();
        q.pop();
        
        if (current.config == GOAL) {
            return current.cost;
        }
        
        int emptyPos = current.config.find('#');
        
        for (int move : moves) {
            if (isValidMove(emptyPos, move)) {
                string newConfig = current.config;
                swap(newConfig[emptyPos], newConfig[emptyPos + move]);
                
                if (visited.find(newConfig) == visited.end()) {
                    visited.insert(newConfig);
                    cost[newConfig] = current.cost + 1;
                    q.push({newConfig, current.cost + 1});
                }
            }
        }
    }
    return -1; // Should never reach here if the goal is always reachable
}

int main() {
    string initialState;
    cin >> initialState;
    
    int result = bfs(initialState);
    cout << result << endl;
    
    return 0;
}
