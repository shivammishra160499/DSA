class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> nums,  int N){
                   stack<long long int>st;
       // map<long long int,long long int>mp;
        long long int n=nums.size();
        long long int i=n-1;
        vector<long long int>ans(n,-1);
        while(i>=0)
        {
        while(!st.empty()&&nums[i ]>=st.top())
            st.pop();
        if(!st.empty())
        {
            ans[i ]=st.top();
            st.push(nums[i ]);
        }
            else
            {
               ans[i ]=-1;
            st.push(nums[i ]) ;
            }
            --i;
        
        }
        
        return ans;
    }
};