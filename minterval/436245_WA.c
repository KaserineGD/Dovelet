#include<stdio.h>
long long max(long long a,long long b) {
	if(a>b) return a;
	return b;
}
long long arr[100001];
long long dp[100001];
long long n;
int main() {
	long long i;
	while(scanf("%lld",&arr[i])!=-1) i++,n++;
	long long ans=-2147483647000000;
	for(i=1;i<=n;i++) {
		dp[i] = max(dp[i-1]+arr[i],arr[i]);
		if(dp[i] > ans) ans = dp[i];
	}
	printf("%lld",ans);
}