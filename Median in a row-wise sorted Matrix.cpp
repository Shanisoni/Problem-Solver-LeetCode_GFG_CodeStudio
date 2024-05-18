class Solution{   
public:
   int check(vector<vector<int>> &mat,int r,int mid)
    {
        int count=0;
            for(int i=0;i<r;i++)
            {
                count+=lower_bound(mat[i].begin(), mat[i].end(), mid)-mat[i].begin();
            }
            return count;
    }

    int median(vector<vector<int>> &mat, int r, int c){
                  
        int low=0,high=INT_MAX;
        int split=((r*c)+1)/2;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int val=check(mat,r,mid);
            if(val<split)
            low=mid+1;
            else
            high=mid-1;
        }
        return high;
    }
};