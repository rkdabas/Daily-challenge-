  // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        if(node==NULL or (node->left==NULL and node->right==NULL)){
            return;
        }
        mirror(node->left);
        mirror(node->right);
        swap(node->left,node->right);
    }