class Solution {
  public:
    /*You are requried to complete this method */
   long long max_Books(int arr[], int n, int k) {
        // Your code here
        long long res=0;
        long long sum=0;
        for(int i=0;i<n;i++){
            if(arr[i]<=k){
                sum=sum+arr[i];
            }
            else{
                res=max(res, sum);
                sum=0;
                
            }
        }
        res=max(res, sum);
        return res;
    }
};