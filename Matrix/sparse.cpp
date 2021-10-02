#include<iostream>
using namespace std;

template<class T>
class sparse
{
	public:
		sparse(int N=10);
		int n;
		void set(int ,int , T&);
		void display();
		T  **ar;
		
};

template<class T>
sparse<T>::sparse(int N)
{
	if(N<1)
		throw ("Matrix size must be greater than zero");
	n=N;
	ar=new T *[n];
	for(int i=0;i<n;i++){
		ar[i]=new int[n];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			ar[i][j]=0;
	}
}
template<class T>
void sparse<T>::set(int i,int j, T& val)
{
	if(i<0||j<0||i>n||j>n)
	throw ("Matrix Index out of bounds");

    ar[i][j]=val;

}

template<class T>
void sparse<T>:: display()
{
	cout<<"The array is :"<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<ar[i][j]<<" ";
		}
		cout<<endl;
	}
}


int main()
{
	int **arr;int n,k;
	cout<<"Enter the order of the matrix"<<endl;
	cin>>n;
	sparse<int> d(n);
	cout<<"Enter the number of nonzero elements"<<endl;
	cin>>k;
	arr=new int*[k];
	for(int i=0;i<k;i++)
		arr[i]=new int[3];
	cout<<"Enter the non zero element and the index respectively"<<endl;
	for(int i=0;i<k;i++)
	{
		cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
	}

	for(int i=0;i<k;i++)
	{
		d.set(arr[i][1],arr[i][2],arr[i][0]);
	}	
	d.display();

return 0;
}