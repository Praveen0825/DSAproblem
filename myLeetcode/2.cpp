class Solution {
public:
    int maxOperations(string s) {
        int n=s.length();
        int res=0;
        int z;
        if(s[n-1]=='0')
        z=1;
        else
        z=0;
        for(int i=n-2;i>=0;i--){
            if(s[i]=='0'&&s[i+1]=='1')
                z++;
            else if(s[i]=='1')
              { 
                res+=z;
                
            }
        }
        return res;
    }
};