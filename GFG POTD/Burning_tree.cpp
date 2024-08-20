class Solution {
  public:
  void findParent(Node* root,unordered_map<Node*,Node*>&parent){
      queue<Node*>q;
      q.push(root);
      parent[root]==NULL;
      
      while(!q.empty()){
          int size=q.size();
          for(int i=0;i<size;i++){
              Node* front=q.front();
              q.pop();
              if(front->left!=NULL){
                  parent[front->left]=front;
                  q.push(front->left);
              }
              if(front->right!=NULL){
                  parent[front->right]=front;
                  q.push(front->right);
              }
          }
      }
  }
  
  Node* findRefNode(Node* root,int target){
      if(root==NULL) return NULL;
      
      Node* left=findRefNode(root->left,target);
      Node* right=findRefNode(root->right,target);
      
      if(root->data==target) return root;
      if(left!=NULL) return left;
      else if(right!=NULL) return right;
      else return NULL;
  }
  
    int minTime(Node* root, int target) 
    {
        unordered_map<Node*,Node*>parent;
        findParent(root,parent);
        
        Node* targetNode=findRefNode(root,target);
        
        queue<pair<int,Node*>>q;
        unordered_map<Node*,bool>vis;
        
        q.push({0,targetNode});
        vis[targetNode]=true;
        int ans=0;
        
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                Node* front=q.front().second;
                int level=q.front().first;
                ans=max(ans,level);
                q.pop();
                
                if(front->left!=NULL and !vis[front->left]){
                    q.push({level+1,front->left});
                    vis[front->left]=true;
                }
                if(front->right!=NULL and !vis[front->right]){
                    q.push({level+1,front->right});
                    vis[front->right]=true;
                }
                if(parent[front]!=NULL and !vis[parent[front]]){
                    q.push({level+1,parent[front]});
                    vis[parent[front]]=front;
                }
            }
        }
        return ans;
    }
};