#include<bits//stdc++.h>
using namespace std;


class segment{
    int size;
    vector<int>T;
    private:
        int changeT(int f,int s){                           // change it accordingly
            return __gcd(f,s);
        }
        
        void build(vector<int>&v,int pos,int left,int right){
            int mid=left+(right-left)/2;
            if(left==right){
                if(left<v.size()){
                    T[pos]=v[left];
                }
                return;
            }
            
            build(v,2*pos+1,left,mid);
            build(v,2*pos+2,mid+1,right);
            
            T[pos]=changeT(T[2*pos+1],T[2*pos+2]);
            return;
        }
        
        int get(int low,int high,int pos,int left,int right){
            int mid=left+(right-left)/2;
            if(left>high)   return 0;
            if(right<low)   return 0;
            if(low<=left && high>=right)    return T[pos];
            
            int x1=get(low,high,2*pos+1,left,mid);
            int x2=get(low,high,2*pos+2,mid+1,right);
            
            return changeT(x1,x2);
        }
        
        void update(int ind,int val,int pos,int left,int right){
            if(left==right){
                T[pos]=val;
                return;
            }
            
            int mid=left+(right-left)/2;
            if(ind<=mid){
                update(ind,val,2*pos+1,left,mid);
            }
            else{
                update(ind,val,2*pos+2,mid+1,right);
            }
            
            T[pos]=changeT(T[2*pos+1],T[2*pos+2]);
        }
        
    public:
        segment(vector<int>&v){
            int n=v.size();
            size=1;
            while(size<n)   size*=2;
            T.assign(2*size,0ll);
            build(v,0,0,size-1);
            // cout << size << endl;
        }
        int getsum(int l,int r){                        // gives sum in close interval [l,r];
            return get(l,r,0,0,size-1);                 // l and r are 0-based index;
        }
        void setval(int pos,int val){                   // pos is 0-based index
            update(pos,val,0,0,size-1);
        }
};    







class NumArray {
    inline static int n;
    int* segTree;
public:
    NumArray(vector<int>& nums) {
        n = size(nums);
        segTree = (int*)malloc(4 * n * sizeof(int));
        build(nums, 1, 0, n - 1);
    }
    
    void build(vector<int>& nums, int segIdx, int l, int r) {
        if(l == r) segTree[segIdx] = nums[l];      // can't split further - assign corresponding index of segTree as nums[l]
        else {
            int mid = (l + r) / 2;                 // divide array into two halves (left and right child of current node of segment tree)
            build(nums, 2*segIdx, l, mid);         // calculate result for left child
            build(nums, 2*segIdx + 1, mid + 1, r); // calculate result for right child
            segTree[segIdx] = segTree[2*segIdx] + segTree[2*segIdx + 1];  // merge result into parent - parent val = sum of left & right child
        }
    }
    
    void update(int index, int val, int segIdx = 1, int l = 0, int r = n - 1) {
        if(l == r) segTree[segIdx] = val;           // update segment tree index corresponding to the array index to be updated
        else {
            int mid = (l + r) / 2;
            if (index <= mid) update(index, val, 2*segIdx, l, mid);       // if node holding [nums[index]] segment lies in left child, recurse for it
            else update(index, val, 2*segIdx + 1, mid + 1, r);            // other wise recurse the right child
            segTree[segIdx] = segTree[2*segIdx] + segTree[2*segIdx + 1];  // child nodes got updated - so parent need to be updated again as sum of left + right child nodes
        }
    }
    
    int sumRange(int left, int right, int segIdx = 1, int l = 0, int r = n - 1) {
        if(left > right) return 0;   
        if(l == left && r == right) return segTree[segIdx];  // case - 1
        int mid = (l + r) / 2;
		// case - 2 and 3
		// Here, we are picking min(right, mid) & max(left, mid+1) to ensure that [left, right] is always subrange of [l, r] for recursive call 
		// otherwise base condition would never be reached in some cases
        return  sumRange(left, min(right, mid), 2*segIdx, l, mid) + 
                sumRange(max(left, mid + 1), right, 2*segIdx + 1, mid + 1, r);
    }
};






int32_t main(){


    return 0;
}