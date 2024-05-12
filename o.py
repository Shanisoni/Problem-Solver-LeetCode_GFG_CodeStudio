class Solution:
    def ispalindrome(self,a):
        return a==a[::-1]
    
    def add_1(self, a):
        return str(int(a)+1)

    def compare(self, s1, s2):# 34 & 44 ----> -1 
        # This comparision take too much time ( TLE )
        '''if int(s1)  > int(s2):return  1 #when the left is big 
        if  int(s1) <=  int(s2):return -1 #when right is big '''
        
        for i in range(len(s1)):
            if int(s1[i]) > int(s2[i]):
                return 1
            elif int(s1[i]) < int(s2[i]):
                return -1
        return 0  
        
            
    def odd_handle(self, a):
        n = len(a)
        left  = a[:n//2]
        mid   = a[n//2]
        right = a[(n//2)+1 : ]
        
        
        if self.compare(left[::-1] , right )==1 : #when the left is big  
            return left + mid+ left[::-1]
        else : 
            #13 9 45 ---> 139  45 ---> 140 45 
            left = left+ mid  #merge the left and mid and then add  one to it 
            left = self.add_1(left)
            
            return left + left[::-1][1:]   
            #140 45 ---> 140|041 --> middle charater is repeated 
            #we have to be remove the middle charatcter in reversed 
            #for that move  from [1:] one step ahead --> 41 
            # so 140|041 ----> 140|41 --- 14041<---- answer
            
            
    def even_handle(self, a):
        n = len(a)
        left  = a[:n//2]
        right = a[n//2:]
        
        if self.compare(left[::-1] ,right )==1 :#8742----> 78 > 42 ----> ans ==> 8778
            return left + left[::-1]
        else : 
            left = self.add_1(left)
            return left + left[::-1]
        
        
    
	def generateNextPalindrome(self,num, n ) :
	    
	    if n==1 : 
	        if num[0] < 9 :
	            return [num[0]+1]
	            
	    a= ""
	    for i in num :
	        a+= str(i)
	   
	    #99---> 100 ----> 101(ans) 
	    if self.ispalindrome(a) :
	        a= self.add_1(a)
	    
	    #Odd Case 
	    arr=[]
	    
	    if len(a)%2==1 : ans = self.odd_handle(a)
	    else : ans = self.even_handle(a)
	        
	    for i in ans :
	        arr.append(i)
	        
	    return arr