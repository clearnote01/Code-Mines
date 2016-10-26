#include<bits/stdc++.h>
using namespace std;

int main()
{
		int n,m;
		cin >> n >> m;
		int cities[n];
		int towers[m+1];
		for(int i=0;i<n;i++)
		{
				scanf("%d", &cities[i]);
		}
		for(int i=1;i<=m;i++)
				scanf("%d", &towers[i]);

		// In the sorted array of towers, we are searching the position of
		// the cities using the lower bound in binary search, If not at the
		// ends, we are considering both the distances in from the lower bound 
		// and the lowerbound - 1 tower. Thus then taking the max of the distances
		// gives us the required answer.
		sort(towers + 1,towers + m + 1);
		int distance = -1;
		for(int i=0;i<n;i++)
		{
				int element = cities[i];
				int lo = 1,hi = m,mid;
				int dist1, dist2, fin;
				while(lo < hi)
				{
						mid = (lo + hi)/2;
						if(towers[mid] >= element)
								hi = mid;
						else
								lo = mid + 1;
				}
				if(element > towers[m])
						lo = m+1;
				if((lo!=1)&&(lo!=m+1))
				{
						// that is the lower 
						// bound is not 1 and
						// is not in the end
						dist1 = towers[lo] - element;
						dist2 = element - towers[lo-1];
						fin = min(dist1, dist2);
				}
				else
				{
						if(lo == 1)
								fin = abs(towers[lo] - element);
						else if(lo == m+1)
								fin = abs(towers[lo-1] - element);
				}
				//printf("distance=%d and fin=%d when city=%d and lo=%d\n",distance, fin, element, lo);
				distance = max(distance, fin);
		}
		cout << distance << endl;
return 0;
}

