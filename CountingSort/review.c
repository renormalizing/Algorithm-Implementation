#include <stdio.h>

void counting(int *a, int *b, int n, int k){
    int c[k+1];
    for (int i = 0; i <= k; i++) {
        c[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        c[a[i]]++;
    }
    for (int i = 1; i <= k; i++) {
        c[i] = c[i] + c[i-1];
    }
    for (int i = n-1; i >= 0; i--) {
        b[--c[a[i]]] = a[i];
    }
}
int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    int a[n], b[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    counting(a,b,n,k);
    for(int i = 0; i < n; i++)
        printf("%d ", b[i]);
    return 0;
}
