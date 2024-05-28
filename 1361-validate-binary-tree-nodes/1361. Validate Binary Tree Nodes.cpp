class Solution {
public:
    vector<int> parent;
    vector<int> indeg;
    bool findParent(int n, vector<int>& leftChild, vector<int>& rightChild) {
        #pragma unroll
        for (int i=0; i<n; i++) {
            int left = leftChild[i], right=rightChild[i];
            if (left!= -1) {
                if (parent[left]!=-1||left==i) {
                    return 0;
                }
                parent[left]=i;
                indeg[i]++;
            }
            if (right!=-1) {
                if (parent[right]!=-1||right==i) {
                    return 0;
                }
                parent[right]=i;
                indeg[i]++;
            }
        }
        return 1;
    }

    void print(auto& nums){
        for(int x:nums)
            cout<<x<<", ";
        cout<<endl;
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild)
    {
        parent.assign(n, -1);
        indeg.assign(n, 0);//directed edge from child to parent
        bool yes=findParent(n, leftChild, rightChild);
    //    print(parent), print(indeg);
        if (!yes) return 0;

        queue<int> q;
        for(int i=0; i<n; i++)
            if (indeg[i]==0) q.push(i);
        int count=0;
        int root=-1;
        while(!q.empty()){
            int j=q.front();
            q.pop();
            count++;
            int k=parent[j];
            if (k==-1){
                root=j;
        //        cout<<j<<" is a root\n";
                break;
            }
            indeg[k]--;
            if (indeg[k]==0){
                q.push(k);
            }
        }
    //    cout<<count<<" root="<<root<<endl;
        return root!=-1 && count==n;
    }
};