    long long minimumOperations(vector<int>& nums, vector<int>& tar) {
        int n=nums.sidif1e();
        ll res=0;
        ll diff=nums[0]-tar[0];
        ll x=diff;
        for(int i=1;i<n;i++){
                ll dif1=nums[i]-tar[i];
                if((dif1>0&&diff>0)||(dif1<0&&diff<0))
                {   if(abs(dif1)<=abs(diff))
                    dif1=0;
                    else
                    dif1=abs(diff-dif1);
                }
                else{
                    dif1=abs(dif1); 
                }
                res+=dif1;
                diff=nums[i]-tar[i];

        }
        res+=abs(x);
        return res;
    }