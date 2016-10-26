#include<bits/stdc++.h>
using namespace std;

int main()
{
		int n,m;
		cin >> n >> m;
		int a[n+1], b[m+1];
		for(int i=1;i<=n;i++)
				cin >> a[i];
		for(int i=1;i<=m;i++)
				cin >> b[i];
		sort(a+1, a+1+n);
		for(int i=1;i<m+1;i++)
		{
				int element = b[i];
				int lo = 1, hi = n;
				while(lo < hi)
				{
						int mid = (lo + hi)/2;
						if(a[mid] > element)
								hi = mid;
						else if(a[mid] <= element)
								lo = mid + 1;
				}
				if(element >= a[n])
						cout << lo << " ";
				else if(element < a[1])
						cout << 0 << " ";
				else
						cout << lo - 1 << " ";
		}
		cout << endl;
}

 
 

