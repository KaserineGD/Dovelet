#include<stdio.h>
int main() {
	int A,B,C;
	scanf("%d%d%d",&A,&B,&C);
	B+=C;
	while(B >= 60) {
		B-=60;
		A++;
	}
	while(A >= 24) {
		A-=24;
	}
	printf("%d %d",A,B);
}