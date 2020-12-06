#include <bits/stdc++.h> 
using namespace std;

int findSubarraySumK(int arr[],int n,int sum) 
{
	unordered_map<int, int> prevSum; 
	int res=0; 
	int currsum=0; 

	for (int i=0;i<n; i++) { 
		currsum += arr[i];
		if (currsum == sum) 
			res++;
		if (prevSum.find(currsum - sum) != prevSum.end()) 
			res += (prevSum[currsum - sum]);
		prevSum[currsum]++; 
	}
	return res; 
} 

int main() 
{ 
	int arr[] = { 10, 2, -2, -20, 10 }; 
	int sum = -10; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	cout << findSubarraySumK(arr, n, sum); 
	return 0; 
} 
