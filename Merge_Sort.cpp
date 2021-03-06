//merge sort implementation using recursive funtion
#include <iostream>
#include <stdlib.h>

using namespace std;
void mergesort(int *ar,int lb,int ub);
void merge(int *ar,int lb,int mid,int ub);
void getarrayelement(int *a,int n);
void display(int *ar,int n); 

int main()
{
	int n;
	cout<<"Enter Number of element:\n";
	cin>>n;
	int *ar=new int[n];
	cout<<"Enter the elements one by one:\n";
	getarrayelement(ar,n);
	cout<<"Sorted list:\n";
	mergesort(ar,0,n-1);
	display(ar,n);
	free(ar);
	return 0;
}

void getarrayelement(int *a,int n)
{
	for(int i=0;i<n;i++)
	cin>>a[i];
}

void mergesort(int *ar,int lb,int ub)
{
	int mid;
	int i=lb;
	int j=ub;
	if(i<j)
	{
		mid=(i+j)/2;
		mergesort(ar,i,mid);
		mergesort(ar,mid+1,j);
		merge(ar,i,mid,j);
	}
}

void merge(int *a,int lb,int mid,int ub)
{
	int i=lb;
	int j=mid+1;
	int k=lb;
	int *b=new int[sizeof(a)/sizeof(int)];
	while(i<=mid&&j<=ub)
	{
		if(a[i]<=a[j])
		{
			b[k]=a[i];
			i++;
		}
		else
		{
			b[k]=a[j];
			j++;
		}
		k++;
	}
	if(i>mid)
	{
		while(j<=ub)
		{
			b[k]=a[j];
			j++;
			k++;
		}
	}
	else
	{
		while(i<=mid)
		{
			b[k]=a[i];
			i++;
			k++;
		}
	}
	for(k=lb;k<=ub;k++)
	a[k]=b[k];
	free(b);
}

void display(int *ar,int n)
{
	for(int i=0;i<n;i++)
	cout<<ar[i]<<" ";
}
