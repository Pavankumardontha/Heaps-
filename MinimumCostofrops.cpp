class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) 
    {
        //priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq; dijsktra shortest path from source to target 
        priority_queue<long long int,vector<long long int>,greater<long long int>> pq; 
        // always if you pop you will get the least element 
        for(int i=0;i<n;i++)
        pq.push(arr[i]);
        
        long long int sum = 0;
        while(pq.size()!=1)
        {
            long long int temp1 = pq.top();
            pq.pop();
            long long int temp2 = pq.top();
            pq.pop();
            sum = sum + temp1 + temp2;
            pq.push(temp1 + temp2);
        }
        return sum;
    }
    
};
