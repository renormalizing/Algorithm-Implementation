#include <iostream>
using namespace std;
int get_index(const char& a){
	return a?a-'a':a;
}
void MSD_sort(string s[], int low, int high,  int d, int R){
	if(low>=high)
		return;
	int count[R+2];
	for (int i = 0; i < R+2 ; ++i) {
		count[i] = 0;
	}
	for(int i = low; i <=high; i++){
		count[get_index(s[i][d]) + 1] ++;
	}
	for (int i = 0; i < R+1; ++i) {
		count[i+1] += count[i];
	}
	string aux[high - low+1];
	for (int i = low; i <= high ; ++i) {
		aux[count[get_index(s[i][d])]++] = s[i];
	}
	for (int j = low; j <=high ; ++j) {
		s[j] = aux[j-low];
	}
	for (int i = 0; i < R; ++i) {
		MSD_sort(s, low + count[i], low + count[i+1]-1, d+1, R);
	}


}
int main() {
	string s[100];
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}
	MSD_sort(s, 0, n-1,0,26);
	for (int i = 0; i < n; ++i) {
		cout << s[i] <<endl;
	}

	return 0;
}
