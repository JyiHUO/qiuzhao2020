//
// Created by 霍俊毅 on 2019/5/6.
//



#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
  Node* cloneGraph(Node* node) {
    queue<Node*> q;
    q.push(node);
    old_new[node] = new Node(node->val, {});

    // bfs
    while (!q.empty()){
      Node* temp_node = q.front();
      q.pop();

      for (Node* neighbor_node: temp_node->neighbors){
        if (old_new.find(neighbor_node) == old_new.end()){
          // not been visited
          old_new[neighbor_node] = new Node(neighbor_node->val, {});
          q.push(neighbor_node);
        }
        old_new[temp_node]->neighbors.push_back(old_new[neighbor_node]);
      }
    }
    return old_new[node];
  }


  unordered_map<Node*, Node*> old_new;
};



int main (){
  Node* n1 = new Node(1, {});
  Node* n2 = new Node(2, {});
  Node* n3 = new Node(3, {});
  Node* n4 = new Node(4, {});
  n1->neighbors.push_back(n2);
  n1->neighbors.push_back(n4);
  n2->neighbors.push_back(n1);
  n2->neighbors.push_back(n3);
  n3->neighbors.push_back(n2);
  n3->neighbors.push_back(n4);
  n4->neighbors.push_back(n1);
  n4->neighbors.push_back(n3);

  Solution s;
  Node* new_node = s.cloneGraph(n1);
  cout <<endl;
  cout << new_node->val <<endl;
  cout << new_node->neighbors[0]->val << endl;
  cout << new_node->neighbors[1]->val << endl;
  cout << new_node->neighbors[0]->neighbors.size() << endl;

  cout << endl;
  cout << s.old_new[n4]->val <<endl;
  cout << s.old_new[n1]->val << endl;
  cout << s.old_new[n2]->val << endl;
  cout << s.old_new[n3]->neighbors.size() << endl;

  cout << endl;
  cout << s.old_new[n2] <<endl;
  cout << s.old_new[n1]->neighbors[0] << endl;

  return 0;
}