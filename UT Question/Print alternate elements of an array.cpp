#include<bits/stdc++.h>
using namespace std;


// ar[] is the array 
// n is the number of elements in array.
void print(int ar[], int n)
{

     for (int i = 0; i < n; i += 2)
    {
        cout << ar[i] << " ";
    }
    
    
}
int main()
{
   int t;
   cin>>t;
  while(t--)
   {
     int ar[100001]={0};
     int n;
     cin>>n;
     for(int i=0;i<n;i++)
      cin>>ar[i];
      print(ar,n);
      cout<<endl;
     }

return 0;
}