/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    public:
    
    Node* build( Node* node , unordered_map<int,Node*> & store)
    {      
           if( store.find(node->val) != store.end())
           {   
               return  store[node->val];
           }
  
           Node* now = new Node(node->val);
           store.insert({node->val , now});
           for(int i = 0  ; i < node->neighbors.size() ; i++)
           {
               now->neighbors.push_back(build(node->neighbors[i], store));
           }  
           return now;
    }


    Node* cloneGraph(Node* node) 
    {  if(node == NULL)
         return NULL;

        unordered_map<int , Node*> store;  
        return build( node , store);     
    }
};