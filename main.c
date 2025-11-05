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
#define mod 1e9+7 
#define inf 1e18+1
#define pi 3.141592653589793
#define eu 2.71828
#define Hi LLONG_MAX
#define Lo LLONG_MIN
#define Mf(a,b,c) for(int a=b;a<c;++a)
#define rMf(a,b,c) for(int a=b;a>c;--a)
#define Ef(a,b,c) for(int a=b;a<=c;++a)
#define rEf(a,b,c) for(int a=b;a>=c;--a)
#define Wt(a) while(a--)
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
#define sarr(a) sizeof(a)/sizeof(a[0])
#define fill(a,b) memset(a,b,sizeof(a))
#define swap(a,b) do{typeof(a) t=a;a=b;b=t;}while(0)
#define rev(a,b,c) Mf(i,0,(c-b+1)/2)swap(a[b+i],a[c-i])
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
        int n, m[105][105], h = Lo, b, k, cnt = 0;
        scanf(Fd, &n);
        Mf(i, 0, n){
            Mf(j, 0, n){
                scanf(Fd, &m[i][j]);
                if (m[i][j]>h){
                    h = m[i][j];
                    b = i;
                    k = j;
                }
            }
        }
        printf("ans: ");
        Mf(i, 0, n){
            if (i==b){
                continue;
            }
            Mf(j, 0, n){
                if (j==k){
                    continue;
                }
                printf(Fd, m[i][j]);
                cnt++;
                if (cnt!=(n-1)*(n-1)){
                    Space;
                }
            }
        }
        Enter;
    }
}
