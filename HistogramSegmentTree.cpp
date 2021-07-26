#include<bits/stdc++.h>
using namespace std;


int minVal(vector<int>& hist, int i, int j)
{
    if (i == -1) return j;
    if (j == -1) return i;
    return (hist[i] < hist[j])? i : j;
}

// Construction of Segment Tree
void construct(vector<int>& v,int *t,int l, int r, int temp){
	if(l==r){
		t[temp]=l;
		return;
	}	
	int mid=l+(r-l)/2;
	construct(v,t,l,mid,2*temp+1);
	construct(v,t,mid+1,r,2*temp+2);
	t[temp]=minVal(v,t[2*temp+1],t[2*temp+2]);
}

// Initialisation of Segment Tree
void build(vector<int>&v, int n, int*& t){
	
	int temp=ceil(log(n));
	int max_size=2*(int)pow(2,temp)-1;
	
	t= new int[max_size];
	construct(v,t,0,n-1,0);
	
}

// Traversing segment tree to find index of minimum element 

int findMin(vector<int>&v,int* t, int curL, int curR, int l, int r, int index){
	
	if(curL>=l && curR<=r){
		return t[index];
	}
	
	if(curL>r || curR<l){
		return -1;
	}
	
	int mid=curL+(curR-curL)/2;
	
	return minVal(v,findMin(v,t,curL,mid,l,r,2*index+1),findMin(v,t,mid+1,curR,l,r,2*index+2));
}

// Using Divide and Conquer to get the index of minimum element in the range
int maxArea(vector<int>& v, int *t, int ql, int qr, int n){
	
	if(ql>qr){
		return INT_MIN;
	}
	if(ql==qr){
		return v[ql];
	}
	int m=findMin(v,t,0,n,ql,qr,0);	
	// cerr<<m<<endl;
	return max(max(maxArea(v,t,ql,m-1,n),maxArea(v,t,m+1,qr,n)), (qr-ql+1)*v[m]);	
	
}

int main(){
	
	int n;
	cin>>n;
	vector<int>v(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	int *t;build(v,n,t);
	
	
	
	cout<<maxArea(v,t,0,n-1,n-1);
}