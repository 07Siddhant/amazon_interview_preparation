class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       if(root==NULL) return NULL;
       
       if(root->data==n1 || root->data==n2){
           return root;
       }
       Node* leftroot=lca(root->left,n1,n2);
       Node* rightroot=lca(root->right,n1,n2);
       
       if(leftroot!=NULL && rightroot!=NULL){
           return root;
       }
       else if(leftroot==NULL && rightroot!=NULL)  return rightroot;
       
       else if(leftroot!=NULL && rightroot==NULL) return leftroot;
       
       else return NULL;
    }
};
