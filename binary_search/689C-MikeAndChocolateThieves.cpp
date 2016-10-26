#include<bits/stdc++.h>
using namespace std;
#define MAXSIZE 	1e16
long long int powerof3(long long int k)
{
		return k*k*k;
}
long long int number_of_ways(long long int n)
{
		long long int count = 0;
		//cout <<"calculating for " << n << endl;
		for(long long int k=2;k*k*k<=n;k++)
		{
				count += n/(powerof3(k));
		}
		return count;
}
int main()
{
	    long long	int m;
		cin >> m;
		long long int hi = MAXSIZE , lo = 8;
		int flag =1;
		while(lo<hi)
		{
				long long int mid = (lo + hi)/2;
				long long int noOfways = number_of_ways(mid);
				if(noOfways == m)
				{
						flag =0;
						hi = mid;
				}
				else if(noOfways > m)
				{
						hi = mid;
				}
				else
						lo = mid + 1;
				//cout << "lo is "<< lo << " hi is "<< hi << " noOfways" << noOfways << " and mid is " << mid << endl;
		}
		if(flag ==1)
				cout << "-1" << endl;
		else
				cout << lo << endl;
return 0;
}
