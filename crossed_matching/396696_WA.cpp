#include<iostream>
#include<algorithm>
using namespace std;
int a[10000];
int b[10000];
int n,m;
struct A {
	int a,b,c,d;
	bool operator<(const A &dd) const {
		return min(a,c) < min(dd.a,dd.c);
	}
};
int dp[200][200];
A input[100000];
int ind=1;
int main() {
	cin>>n>>m;
	int i,j,k,l;
	for(i=1;i<=n;i++) cin>>a[i];
	for(i=1;i<=m;i++) cin>>b[i];
	int ans=0;
	for(i=1;i<=n;i++) { //a
		for(j=1;j<=m;j++) {//b
			dp[i][j] = max(dp[i][j],dp[i-1][j-1]);
			for(k=1;k<j;k++) {
				for(l=1;l<i;l++) {
					int g = (a[l] == b[j] && a[i] == b[k] && a[l] != a[i]);
					if(dp[l-1][k-1]+g*2 > dp[i][j]) dp[i][j] = dp[l-1][k-1]+g*2;
				}
			}
			if(dp[i][j] > ans) ans = dp[i][j];
		}
	}
	cout<<ans;
}