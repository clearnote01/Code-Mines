#include<iostream>
#include<queue>
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
/*
Manage distance thing, Manage the segmentation fault 
*/
struct vertex
{
int x;
int y;
int distance;

	friend bool operator< (const struct vertex a, const struct vertex b) { 
		if (a.x == b.x)
			return a.y < b.y;
		return a.x < b.x;
	}

};
int min(int, int);
int max(int, int);
int gcd(int, int);
int min(int a, int b)
{
	if(a<=b)
		return a;
	else
		return b;
}
int max(int a, int b)
{
if (a>=b)
	return a;
else
	return b;
}


int gcd(int a, int b)
{

    if(b == 0) 
    {
       return a;
	}
 else {
 return gcd(b, a % b);
 }
 }


typedef struct vertex vertex;
int main()
{
	int test;
	scanf("%d",&test);
	for(int t=0;t<test;t++)
	{
		int a, b, c;
		scanf("%d%d%d",&a,&b,&c);
		if (((c>a)&&(c>b))||(c%gcd(a,b)!=0))
			printf("-1\n");
		else if ((c==a)||(c==b))
			printf("1\n");
		else
		{
			queue<vertex> visited;
			queue<vertex> waiting;
			set<vertex> waitingdict;
			set<vertex> visiteddict;
			//pushing the first vertex
			vertex myver;
			myver.x = 0;myver.y = 0; myver.distance = 0;
			waiting.push(myver);
			int distance = 0;
			waitingdict.insert(myver);
			//running loop till the end vertex is my vertex required
			while(1)
			{
				if((myver.x == c)||(myver.y==c))
					break;
				myver = waiting.front();
				visited.push(myver);
				visiteddict.insert(myver);
				waiting.pop();
				
				int x = myver.x; int y = myver.y, distance = myver.distance+1;
				vertex list[6];

				list[0].x = 0; list[0].y = y;list[0].distance = distance;
				list[1].x = x; list[1].y = 0;list[1].distance = distance;
				list[2].x = a; list[2].y = y;list[2].distance = distance;
				list[3].x = x; list[3].y = b;list[3].distance = distance;
				list[4].x = x - min(x,b-y); list[4].y = y + min(x, b-y);list[4].distance = distance;
				list[5].x = x + min(y,a-x); list[5].y = y-min(a-x,y);list[5].distance = distance;

				for(int i=0;i<6;i++)
				{
					if ((waitingdict.find(list[i])==waitingdict.end())&&(visiteddict.find(list[i])==visiteddict.end())){
						waiting.push(list[i]);
						waitingdict.insert(list[i]);
					}
				}
			}
			printf("%d\n", myver.distance);
		}
	}
return 0;
}
