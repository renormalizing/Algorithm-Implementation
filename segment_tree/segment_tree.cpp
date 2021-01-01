#include <algorithm>
#include <iostream>

#define MAX 1000000000
 using namespace std;
 class SegementTree{
    private:
        int n;
        int *lo, *hi, *min, *delta;
        void init(int i, int a, int b){
            lo[i] = a;
            hi[i] = b;
            if(a==b)
                return;
            int m = (a+b)/2;
            init(2*i, a,m);
            init(2*i+1, m+1, b);
        }
    public:
        SegementTree(int n){
           this->n = n;
           lo = new int[4*n+1];
           hi = new int[4*n+1];
           min = new int[4*n+1];
           delta = new int[4*n+1];
           init(1, 0, n-1);
        }
        void prop(int i){
            delta[2*i] += delta[i];
            delta[2*i+1] += delta[i];
            delta[i] = 0;
            
        }
        void update(int i){
            min[i] = std::min(min[2*i] + delta[2*i], min[2*i+1] + delta[2*i+1]);
        }
        void increment(int i, int a, int b, int delta){
            if(hi[i]<a || lo[i]>b)
                return;
            if(a<=lo[i] && hi[i]<=b){
                this->delta[i] += delta;
                return;
            }
            prop(i);
            increment(2*i, a, b, delta);
            increment(2*i+1, a, b, delta);
            update(i);

        }
        int minimum(int i, int a, int b){
            if(hi[i]<a || lo[i]>b)
                return MAX;
            if(a<=lo[i] && hi[i]<=b){
                return min[i]+delta[i];
            }
            prop(i);
            int min_left = minimum(2*i, a, b);
            int min_right = minimum(2*i+1, a,b);
            update(i);
            return std::min(min_left, min_right);
        }
 };
int main(){
    int n, tmp;
    cin >> n;
    SegementTree ST(n);
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        ST.increment(1, i,i,tmp);
    }
    int m;
    cin >> m;
    int arg[3], count = 0;
    for (int i = 0; i < m; i++) {
        while(cin >> tmp){
            arg[count++] = tmp;
            char ch = getchar();
            if(ch == '\n'){
                break;
            }
        }
        if(count == 2){
            //query
           if(arg[0] <= arg[1])
               cout << ST.minimum(1, arg[0], arg[1])<< endl;
           else
               cout << std::min(ST.minimum(1,arg[1],n-1),ST.minimum(1,0,arg[0]))<<endl;

        }else{
           if(arg[0]<=arg[1])
               ST.increment(1,arg[0],arg[1],arg[2]);
           else{
               ST.increment(1,arg[0],n-1,arg[2]);
               ST.increment(1, 0,arg[1],arg[2]);
           }
        }
        count = 0;
    }
}
