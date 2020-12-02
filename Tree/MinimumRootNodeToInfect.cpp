#include "bits/stdc++.h"
#define pb push_back
using ll = long long;
using namespace std;
#define endl "\n";
const int  maxn = 200005;
vector<int> adj[maxn];
int safe[maxn];
int res =0 ;
int nodes =0;
void dfs(int u , int p =-1){
	int child = 0;
	int ct =0 ;
	// cout<<u <<" ";
	nodes++;
	bool isSafe = false;
	int countThree =0;
	for(auto to :adj[u]){
		if(to!=p){
			dfs(to,u);
			ct+= (safe[to] !=0);
			isSafe |= (safe[to] >=2);
			countThree +=(safe[to] == 3);
			child++;
		}
	}
	
	if(child ==0){
		return ;
	}
	if(ct!=child){
		res++;
		safe[u] =2;
	}else{
		if(isSafe)
			safe[u] =1;
		else {
			res++;
			safe[u] =3;
		}
	}
	if(countThree > 0){
		res -= countThree;
		res++;
		safe[u] =2;
	}
	
}
void build(vector<int> &s){
	queue<int> q;
	int ct =0;
	int nodeNo =1;
	q.push(1);
	ct =1;
	int tries = 0;
	while(ct<s.size() ){
		auto t  = q.front();
		q.pop();
		int currNode = t;
		int childNo = s[ct];
		while(childNo>0){
			adj[currNode].push_back(++nodeNo);
			q.push(nodeNo);
			childNo--;
			ct++;
		}
		ct++;
	}

}
void D(){
	string s;
	getline(cin , s);
	vector<int> v;
	string temp ="";
	for(int i=0;i<s.length();i++){
		if(s[i]!=' '){
			temp+=s[i];
		}else{
			int x = stoi(temp);
			temp.clear();
			v.push_back(x);
		}
	}
	if(!temp.empty()){
		int x = stoi(temp);
		temp.clear();
		v.push_back(x);
	}
	string n; cin>>n;
	int req = stoi(n);
	build(v);

	memset(safe ,0, sizeof safe);
	dfs(1);
	if(res ==0 and nodes > 0){
		res++;
	}
	if(res <= req ){
		cout<<res<<" "<<"Mission Successful"<<endl;
	}
	else{
		cout<<res<<" "<<"Mission Unsuccessful"<<endl;
	}


}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout.precision(0);
	cout<<fixed;

	ll n , m,k ,pt(0),ct(0) ,x,y; 
	ll t =1; 
	// cin>>t;
	while(t--){
		D();
	}

}
