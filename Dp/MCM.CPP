#include<bits/stdc++.h>
using namespace std;


    int minMultrec(vector<int> &arr,int i,int j){
        if (i+1 == j)
        {
            return 0;
        }
        int res = INT_MAX;

        for (int k = i+1; k < j; k++)
        {
            int curr = minMultrec(arr,i,k) + minMultrec(arr,k,j) + arr[i] * arr[j] * arr[k];
            res = min(curr,res);
        }
        return res;
    }

    int matrixMultiplication(vector<int> &arr){
        int n = arr.size();
        return minMultrec(arr,0,n-1);
    }
int main() {
    vector<int>arr = {1,2,3,4,3};
    cout << matrixMultiplication(arr);
    return 0;
}