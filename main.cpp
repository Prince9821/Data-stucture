#include<iostream>
#include<fstream>
#include<windows.h>
using namespace std;
LARGE_INTEGER frequency;
int A[1000001],temp[1000001];
int count=0;
void Init(ifstream &infile)
{
	int a; 
	while(!infile.eof())
	{
		infile>>a;
		A[count]=a;
		count++;
	}
}
void print(ofstream &outfile)
{
	for(int i=0;i<count;i++)
	{
		outfile<<A[i]<<' ';
	}
}
int partition(int A[],int l,int r,int p)
{
	do
	{
		while(A[++l]<p);
		while(l<r&&A[--r]>p);
		swap(A[l],A[r]);
	}
	while(l<r);
	return l;
}
void qsort(int A[],int i,int j)
{
	if(j<=i) 
		return;
	int p=(i+j)/2;
	swap(A[p],A[j]);
	int k=partition(A,i-1,j,A[j]);
	swap(A[k],A[j]);
	qsort(A,i,k-1);
	qsort(A,k+1,j);
}
bool cmp(int x,int y)
{
	return x<y;
} 
void mergesort(int A[],int temp[],int left,int right)
{
	if(left==right)
		return;
	int mid=(left+right)/2;
	mergesort(A,temp,left,mid);
	mergesort(A,temp,mid+1,right);
	for(int i=left;i<=right;i++)
		temp[i]=A[i];
	int i1=left;
	int i2=mid+1;
	for(int curr=left;curr<=right;curr++)
	{
		if(i1==mid+1)
			A[curr]=temp[i2++];
		else if(i2>right)
			A[curr]=temp[i1++];
		else if(cmp(temp[i1],temp[i2]))
			A[curr]=temp[i1++];
		else 
			A[curr]=temp[i2++];
	}
} 

int main()
{
	ifstream test_100("100.txt"); 
	ifstream test_1K("1K.txt"); 
	ifstream test_10K("10K.txt"); 
	ifstream test_100K("100K.txt"); 
	ifstream test_1M("1M.txt");
	ofstream output_100("output_100.txt");
	ofstream output_1K("output_1K.txt");
	ofstream output_10K("output_10K.txt");
	ofstream output_100K("output_100K.txt");
	ofstream output_1M("output_1M.txt");
	double dff,begin,end,dfm,dft;
	Init(test_100);
	QueryPerformanceFrequency(&frequency);//获得时钟频率
	dff=(double)frequency.QuadPart;
	QueryPerformanceCounter(&frequency);//获得初始值
	begin=frequency.QuadPart;
	qsort(A,0,100);
	QueryPerformanceCounter(&frequency);//获得终止值
	end=frequency.QuadPart;
	dfm=(double)(end-begin);
	dft=dfm/dff;
	print(output_100);
	cout<< "快速排序100："<<dft*1000<<"ms"<<endl; 
	QueryPerformanceFrequency(&frequency);//获得时钟频率
	dff=(double)frequency.QuadPart;
	QueryPerformanceCounter(&frequency);//获得初始值
	begin=frequency.QuadPart;
	mergesort(A,temp,0,100);
	QueryPerformanceCounter(&frequency);//获得终止值
	end=frequency.QuadPart;
	dfm=(double)(end-begin);
	dft=dfm/dff;
	cout<<"归并排序100："<<dft*1000<<"ms"<<endl;
	
	Init(test_1K);
	QueryPerformanceFrequency(&frequency);//获得时钟频率
	dff=(double)frequency.QuadPart;
	QueryPerformanceCounter(&frequency);//获得初始值
	begin=frequency.QuadPart;
	qsort(A,0,1000);
	QueryPerformanceCounter(&frequency);//获得终止值
	end=frequency.QuadPart;
	dfm=(double)(end-begin);
	dft=dfm/dff;
	print(output_1K);
	cout<<"快速排序1K："<<dft*1000<<"ms"<<endl; 
	QueryPerformanceFrequency(&frequency);//获得时钟频率
	dff=(double)frequency.QuadPart;
	QueryPerformanceCounter(&frequency);//获得初始值
	begin=frequency.QuadPart;
	mergesort(A,temp,0,1000);
	QueryPerformanceCounter(&frequency);//获得终止值
	end=frequency.QuadPart;
	dfm=(double)(end-begin);
	dft=dfm/dff;
	cout<<"归并排序1K："<<dft*1000<<"ms"<<endl; 
	
	Init(test_10K);
	QueryPerformanceFrequency(&frequency);//获得时钟频率
	dff=(double)frequency.QuadPart;
	QueryPerformanceCounter(&frequency);//获得初始值
	begin=frequency.QuadPart;
	qsort(A,0,10000);
	QueryPerformanceCounter(&frequency);//获得终止值
	end=frequency.QuadPart;
	dfm=(double)(end-begin);
	dft=dfm/dff;
	print(output_10K);
	cout<<"快速排序10K："<<dft*1000<<"ms"<<endl; 
	QueryPerformanceFrequency(&frequency);//获得时钟频率
	dff=(double)frequency.QuadPart;
	QueryPerformanceCounter(&frequency);//获得初始值
	begin=frequency.QuadPart;
	mergesort(A,temp,0,10000);
	QueryPerformanceCounter(&frequency);//获得终止值
	end=frequency.QuadPart;
	dfm=(double)(end-begin);
	dft=dfm/dff;
	cout<<"归并排序10K："<<dft*1000<<"ms"<<endl; 
	
	Init(test_100K);
	QueryPerformanceFrequency(&frequency);//获得时钟频率
	dff=(double)frequency.QuadPart;
	QueryPerformanceCounter(&frequency);//获得初始值
	begin=frequency.QuadPart;
	qsort(A,0,100000);
	QueryPerformanceCounter(&frequency);//获得终止值
	end=frequency.QuadPart;
	dfm=(double)(end-begin);
	dft=dfm/dff;
	print(output_100K);
	cout<<"快速排序100K："<<dft*1000<<"ms"<<endl; 
	QueryPerformanceFrequency(&frequency);//获得时钟频率
	dff=(double)frequency.QuadPart;
	QueryPerformanceCounter(&frequency);//获得初始值
	begin=frequency.QuadPart;
	mergesort(A,temp,0,100000);
	QueryPerformanceCounter(&frequency);//获得终止值
	end=frequency.QuadPart;
	dfm=(double)(end-begin);
	dft=dfm/dff;
	cout<<"归并排序100K："<<dft*1000<<"ms"<<endl; 
	
	Init(test_1M);
	QueryPerformanceFrequency(&frequency);//获得时钟频率
	dff=(double)frequency.QuadPart;
	QueryPerformanceCounter(&frequency);//获得初始值
	begin=frequency.QuadPart;
	qsort(A,0,1000000);
	QueryPerformanceCounter(&frequency);//获得终止值
	end=frequency.QuadPart;
	dfm=(double)(end-begin);
	dft=dfm/dff;
	print(output_1M);
	cout<<"快速排序1M："<<dft*1000<<"ms"<<endl;
	QueryPerformanceFrequency(&frequency);//获得时钟频率
	dff=(double)frequency.QuadPart;
	QueryPerformanceCounter(&frequency);//获得初始值
	begin=frequency.QuadPart;
	mergesort(A,temp,0,1000000);
	QueryPerformanceCounter(&frequency);//获得终止值
	end=frequency.QuadPart;
	dfm=(double)(end-begin);
	dft=dfm/dff;
	cout<<"归并排序1M："<<dft*1000<<"ms"<<endl;  
	return 0;
}
