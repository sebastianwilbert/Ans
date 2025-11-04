#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <float.h>
#include <ctype.h>
#define int long long
#define db long double
#define pi 3.141592653589793
#define eu 2.71828
#define Hi LLONG_MAX
#define Lo LLONG_MIN
#define mod (int)1e9 + 7 
#define inf (int)1e18 + 1
#define Mf(a,b,c) for(int a=b;a<c;++a)
#define rMf(a,b,c) for(int a=b;a>c;--a)
#define Ef(a,b,c) for(int a=b;a<=c;++a)
#define rEf(a,b,c) for(int a=b;a>=c;--a)
#define Wt(a) while(a--)
#define pair(a,b) (struct{int F, S;}{a,b})
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define sarr(a) (sizeof(a)/sizeof(a[0]))
#define fill(a,b) memset(a,b,sizeof(a))
#define swap(a,b) do{__typeof__(a) t=a;a=b;b=t;}while(0)
#define rev(a,b) Mf(i,0,b/2) swap(a[i],a[b-i-1])
#define sfindf(a,b) strchr(a,b)==NULL?-1:strchr(a,b)-a
#define sfindb(a,b) strrchr(a,b)==NULL?-1:strrchr(a,b)-a
#define ssub(a,b) strstr(a,b)==NULL?-1:strstr(a,b)-a
#define Enter printf("\n")
#define Space printf(" ")
#define Yc printf("YES")
#define Nc printf("NO")
#define Yl printf("Yes")
#define Nl printf("No")
#define Fd "%lld"
#define Ff "%Lf"
#define Fe "%e"
#define Fc "%c"
#define Fs "%s"
#define Fss "%[^\n]"
#define Fp "%p"
#define Ft "%td"
#define Fz "%zu"

int gcd(int a, int b){ 
    return b==0?a:gcd(b, a%b);
}

int lcm(int a, int b){
    return a*b/gcd(a, b);
}

int power(int a, int b){
    int n=1;
    while(b>0){
        if (b%2==1) n=(n*a);
        a=a*a;
        b/=2;
    }
    return n;
}

int powmod(int a, int b, int m){
    int n=1;
    a%=m;
    while(b>0){
        if (b%2==1) n=(n*a)%m;
        a=a*a%m;
        b/=2;
    }
    return n;
}

int lb(int *a, int b, int l, int r) {
    while (l<r){
        int m=(l+r)/2;
        a[m]<b?(l=m+1):(r=m);
    }
    return l;
}

int ub(int *a, int b, int l, int r) {
    while (l<r){
        int m=(l+r)/2;
        a[m]<=b?(l=m+1):(r=m);
    }
    return l;
}

void merge(int a[], int l, int m, int r){
    int x=m-l+1, y=r-m;
    int larr[x], rarr[y];
    Mf(i, 0, x) larr[i]=a[l+i];
    Mf(j, 0, y) rarr[j]=a[m+j+1];
    int i=0, j=0, k=l;
    while (i<x && j<y) a[k++]=(larr[i]<=rarr[j])?larr[i++]:rarr[j++];
    while (i<x) a[k++]=larr[i++];
    while (j<y) a[k++]=rarr[j++];
}

void msort(int a[], int l, int r) {
    if (l<r){
        int m=(l+r)/2;
        msort(a, l, m);
        msort(a, m +1, r);
        merge(a, l, m, r);
    }
}

int32_t main(){
    int T = 1;
    //scanf(Fd, &T);
    Mf(t, 0, T){
        char k[105], c[105];
        char *p = k;
        int cnt = 0;
        scanf(Fs, k);
        scanf(Fs, c);
        while(strstr(p, c)!=NULL){
            cnt++;
            p = strstr(p, c)+strlen(c);
        }
        printf(Fd, cnt);
        Enter;
    }
}
