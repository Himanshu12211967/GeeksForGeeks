//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define N 1000


// } Driver Code Ends

// you are required to complete this function 
// function should print the required range
class Solution{
    public:
    
    pair<int,int> findSmallestRange(int KSortedArray[][N], int n, int k)
    {
        //code here
        int mini = INT_MAX;
        int maxi = INT_MIN;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        
        for(int i=0; i<k; i++){
            maxi = max(maxi,KSortedArray[i][0]);
            mini = min(mini,KSortedArray[i][0]);
            pq.push({KSortedArray[i][0],{i,0}});
        }
        
        pair<int,int> p = {mini,maxi};
        
        while(pq.size() == k){
            
            int mini = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            
            if( (p.second-p.first) > (maxi-mini) ){
                p.first = mini;
                p.second = maxi;
            }
            
            if(y+1 < n){
                pq.push({KSortedArray[x][y+1],{x,y+1}});
                maxi = max(maxi,KSortedArray[x][y+1]);
            }
            
        }
        
        return p;
        
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    
cout << "~" << "\n";
}   
	return 0;
}


// } Driver Code Ends