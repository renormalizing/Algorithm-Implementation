#include <iostream>
#include <random>
using namespace std;
int rand(int a, int b){
    return a + rand()%(b-a+1);
}
int main(int argc, char* argv[]){
   srand(atoi(argv[1]));
   int n = rand(2,4);
   cout << n << endl;
   for(int i = 0; i < n; i++){
       cout << rand(-10,10)<<' ';
   }
}

