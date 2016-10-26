#include<bits/stdc++.h>
using namespace std;
int main()
{
		int n;
		scanf("%d", &n);
		int arr[n + 1];
		for(int i=1;i<n+1;i++)
		{
				scanf("%d", &arr[i]);
		}
		sort(arr +1, arr + n+ 1);
		//upper bound is to be calculated
		int q;cin >> q;
		while(q--)
		{
		int element;
		scanf("%d", &element);
		int lo = 1,hi = n+1, mid;
		while(lo<hi)
		{
				mid = (lo + hi)/2;
				//printf("mid and arr[mid]");
				//cout << mid << " " << arr[mid] << endl;
				//printf("lo and high");
				//cout << lo << " " << hi << endl;
				if(arr[mid] <= element)
						lo = mid + 1;
				else
						hi = mid;
		}
		cout << lo - 1<< endl;
		}
		return 0;
}


