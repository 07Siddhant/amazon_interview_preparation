class Solution
{
	public:
	//Function to return list containing vertices in Topological order.
	void findTopoSort(int node,vector<int> &vis,stack<int> &st,vector<int> adj[]){
	    vis[node]=1;
	    
	    for(auto it:adj[node]){
	        if(!vis[it]){
	            findTopoSort(it,vis,st,adj);
	        }
	    }
	    st.push(node);
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> vis(V,0);
	    stack<int> st;
	    for(int i=0;i<V;i++){
	        if(vis[i]==0){
	            findTopoSort(i,vis,st,adj);
	        }
	    }
	    vector<int> ans;
	    while(!st.empty()){
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
	}
};
