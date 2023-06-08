#include <bits/stdc++.h>

using namespace std;
void merge_sort(vector<int> &out, vector<vector<int>> arr,int n,int k){
    for (int i = 0; i < k; i++) {
		for (int j = 0; j < n; j++) {
			out[(i * n) + j] = arr[i][j];
		}
	}
	sort(out.begin(),out.end());
}
int main()
{
    vector<vector<int>> arr; int n,k;
    cin>>k>>n;
    for(int i=0;i<k;i++){
        vector<int> temp(n);
        for(int j=0;j<n;j++){
            cin>>temp[j];
        }
        arr.push_back(temp);
    }
    vector<int> out(n*k);
    merge_sort(out,arr,n,k);
    for (int i = 0; i < n * k; i++)
		cout << out[i] << " ";
    return 0;
}
