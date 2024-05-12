class Solution:
    #Function to find triplets with zero sum.    
    def findTriplets(self, arr, n):
        st=set()
        ln= len(arr)
        x=0
        st.add(arr[0])
        for i in range(1,ln-1):
            for j in range(i+1,ln):
                if x-arr[i]-arr[j] in st:
                    return True
            st.add(arr[i])
        return False