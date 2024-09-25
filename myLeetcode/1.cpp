class Solution {
    public int minChanges(int n, int k) {
        int ans=0;
        
        for(int i=30;i>0;i--){
           if((n&(1<<i))&&(!(k&(1<<i)))){
               ans++;
           }
            else if(!(n&(1<<i))&&(k&(1<<i))){
                return -1;
            }
        }
        return ans;
    }
}