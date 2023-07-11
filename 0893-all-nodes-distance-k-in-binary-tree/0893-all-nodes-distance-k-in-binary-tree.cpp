class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> result;
        unordered_map<int, TreeNode*> parent_map;
        queue<TreeNode*> node_queue;
        node_queue.push(root);

        while(!node_queue.empty()){
            int size = node_queue.size();
            for(int i = 0; i < size; i++){
                auto current = node_queue.front();
                node_queue.pop();
                
                if(current->left){
                    parent_map[current->left->val] = current;
                    node_queue.push(current->left); 
                }

                if(current->right){
                    parent_map[current->right->val] = current;
                    node_queue.push(current->right); 
                }
            }
        }

        unordered_map<int, int> visited;
        node_queue.push(target);
        while(k-- && !node_queue.empty()){
            int size = node_queue.size();

            for(int i = 0; i < size; i++){
                auto current = node_queue.front();
                node_queue.pop();

                visited[current->val] = 1;

                if(current->left && !visited[current->left->val]){
                    node_queue.push(current->left);
                }

                if(current->right && !visited[current->right->val]){
                    node_queue.push(current->right);
                }

                if(parent_map[current->val] && !visited[parent_map[current->val]->val]){
                    node_queue.push(parent_map[current->val]);
                }

            }
        }

        while(!node_queue.empty()){
            result.push_back(node_queue.front()->val);
            node_queue.pop();
        }
        return result;
    }
};
