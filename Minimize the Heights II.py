class Solution:
     def getMinDiff(self, arr, n, k):
        arr.sort()
        ans = arr[n-1]-arr[0]
        smallest = arr[0]+k
        largest = arr[n-1]-k
        
        for i in range(n-1):
            mini = min(smallest, arr[i+1]-k)
            maxi = max(largest, arr[i]+k)
            if mini<0:
                continue
            ans = min(ans, maxi-mini)
        
        return ans
     
if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        k = int(input())
        n = int(input())
        arr = list(map(int, input().strip().split()))
        ob = Solution()
        ans = ob.getMinDiff(arr, n, k)
        print(ans)
        tc -= 1