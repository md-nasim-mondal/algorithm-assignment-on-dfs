#include <bits/stdc++.h>
using namespace std;

const int maxNodesNumber = 5;
bool visited[maxNodesNumber] = {false};
int graph[maxNodesNumber][maxNodesNumber] = {
  {0, 1, 0, 1, 0},
  {1, 0, 1, 0, 1},
  {0, 1, 0, 1, 0},
  {1, 0, 1, 0, 1},
  {0, 1, 0, 1, 0}
};

void dfs(int numNodes, int beginNode) {
  stack<int> stack;
  stack.push(beginNode);
  visited[beginNode] = true;

  cout << "Depth-First Traversal: ";
  while (!stack.empty()) {
    int presentNode = stack.top();
    stack.pop();
    cout << presentNode << " ";

    for (int neighbor = 0; neighbor < numNodes; ++neighbor) {
      if (graph[presentNode][neighbor] && !visited[neighbor]) {
        stack.push(neighbor);
        visited[neighbor] = true;
      }
    }
  }
  cout << endl;
}

int main() {
  int beginNode;
  cout << "Enter the beginning node (index from 0 to " << maxNodesNumber - 1 << "): ";
  cin >> beginNode;

  if (beginNode < 0 || beginNode >= maxNodesNumber) {
    cout << "Invalid beginning node!\n";
    return 1;
  }
  dfs(maxNodesNumber, beginNode);

  return 0;
}