#include <stdio.h>
void swap(long long int a,long long int b){
	long long int c;
	c=a;
	a=b;
	b=c;
}
long long int h[300001];
int main(){
	long long int n,sum=0,i,j;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++) scanf("%lld",&h[i]);
	printf("%d",n);
	for(i=n;i>0;i--)
	for(j=0;j<n-1;j++)
	if(h[j]>h[j+1]) {
		swap(h[j],h[j+1]);sum++;}
	printf("%d\n",sum); 
}